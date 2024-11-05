#include "cpu.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <algorithm>

using namespace std;

void Cpu::runNextStep()
{
    static int lineNumber = 0;
    if (lineNumber < instructionCount)
    {
        string instruction = getInstruction(lineNumber);
        executeInstruction(lineNumber, instruction);
        lineNumber++;
    }
    else
    {
        cout << "All instructions executed" << endl;
    }
}

void Cpu::fetch(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return;
    }
    string instruction;
    while (getline(file, instruction))
    {
        if (!instruction.empty())
        {
            instructions.push_back(instruction);
        }
    }
    file.close();
    instructionCount = instructions.size();
    cout << "Program fetched successfully from " << filename << endl;
}

void Cpu::reset()
{
    programCounter = 0;
    instructionRegister.clear();
}

string Cpu::getInstruction(int lineNumber)
{
    return instructions[lineNumber];
}

void Cpu::logInstruction(const string &instruction)
{
    ofstream logFile("cpu_log.txt", ios::app);
    if (logFile.is_open())
    {
        logFile << instruction << endl;
    }
    else
    {
        cerr << "Unable to open log file." << endl;
    }
}

void Cpu::displayRegisters()
{
    cout << "Current Register Values:\n";
    for (const auto &regPair : registers)
    {
        cout << regPair.first << ": " << regPair.second << endl;
    }
}

void Cpu::executeInstruction(int currentLine, const string &instruction)
{
    try
    {
        int instructionCode = stoi(instruction);
        // Handle breakpoints
        if (find(breakpoints.begin(), breakpoints.end(), currentLine) != breakpoints.end())
        {
            cout << "Breakpoint hit at line: " << currentLine << ". Execution paused." << endl;
            breakpointHits++;
            cin.get();
        }
        // Here we would execute the machine code using ALU/Control Unit logic
        // alu.execute(instructionCode, instruction); // example placeholder

        alu.execute(instruction, reg, programCounter);
        programCounter++;
        logInstruction(instruction);
        displayRegisters();
    }
    catch (const invalid_argument &e)
    {
        cerr << "Invalid instruction at line " << currentLine << ": " << instruction << endl;
    }
    catch (const out_of_range &e)
    {
        cerr << "Instruction out of range at line " << currentLine << ": " << instruction << endl;
    }
}
void Cpu::loadInstructionsFromFile(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return;
    }
    string instruction;
    int lineNumber = 0;
    while (getline(file, instruction))
    {
        if (!instruction.empty())
        {
            executeInstruction(lineNumber, instruction);
        }
        lineNumber++;
    }
    file.close();
}

void Cpu::saveState(const string &filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        for (const auto &regPair : registers)
        {
            file << regPair.first << " " << regPair.second << endl;
        }
    }
    else
    {
        cerr << "Unable to open file for saving state." << endl;
    }
}

void Cpu::restoreState(const string &filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Could not open file: " << filename << endl;
        return;
    }
    string regName;
    int regValue;
    while (file >> regName >> regValue)
    {
        setRegister(regName, regValue);
        cout << "Restored " << regName << " to " << regValue << endl;
    }
}

void Cpu::manageMemory(int numLocations, int multiplier)
{
    for (int i = 0; i < numLocations; ++i)
    {
        mem.write(i, i * multiplier);
    }
    mem.displayMemory(numLocations);
    int value = mem.read(numLocations);
    cout << "Value at address " << numLocations << ": " << value << endl;
}

void Cpu::handleError(const string &errorMessage)
{
    cerr << "Error: " << errorMessage << endl;
}

void Cpu::setBreakpoint(int line)
{
    if (find(breakpoints.begin(), breakpoints.end(), line) == breakpoints.end())
    {
        breakpoints.push_back(line);
        cout << "Breakpoint set at line: " << line << endl;
    }
    else
    {
        cout << "Breakpoint already exists at line: " << line << endl;
    }
}

void Cpu::manageIO()
{
    string command;
    cout << "Enter I/O command (read/write/exit): ";
    while (true)
    {
        getline(cin, command);
        if (command == "exit")
        {
            break;
        }
        else if (command == "read")
        {
            string filename;
            cout << "Enter filename to read instructions: ";
            getline(cin, filename);
            loadInstructionsFromFile(filename);
        }
        else if (command == "write")
        {
            string filename;
            cout << "Enter filename to save state: ";
            getline(cin, filename);
            saveState(filename);
        }
        else
        {
            cout << "Invalid command. Please enter 'read', 'write', or 'exit'." << endl;
        }
        cout << "Enter I/O command (read/write/exit): ";
    }
}

void Cpu::userInterface()
{
    string command;
    cout << "Welcome to the CPU Simulator!" << endl;
    cout << "Available commands: run, io, set_breakpoint, exit" << endl;
    while (true)
    {
        cout << "> ";
        getline(cin, command);
        if (command == "run")
        {
            run();
        }
        else if (command == "io")
        {
            manageIO();
        }
        else if (command.substr(0, 14) == "set_breakpoint")
        {
            int line = stoi(command.substr(15));
            setBreakpoint(line);
        }
        else if (command == "exit")
        {
            cout << "Exiting the CPU Simulator." << endl;
            break;
        }
        else
        {
            cout << "Invalid command. Please try again." << endl;
        }
    }
}

void Cpu::monitorPerformance()
{
    clock_t endTime = clock();
    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Performance Metrics:" << endl;
    cout << "Instructions Executed: " << instructionCount << endl;
    cout << "Breakpoints Hit: " << breakpointHits << endl;
    cout << "Elapsed Time: " << elapsedTime << " seconds" << endl;
}

bool Cpu::setRegisterValue(const string &regName, int value)
{
    if (registers.find(regName) != registers.end())
    {
        int index = stoi(regName.substr(1)); // Assuming regName is in format "R0", "R1", etc.
        if (index >= 0 && index < NUM_REGISTERS)
        {
            registers_arr[index]->setValue(value);
            registers[regName] = value;
            return true;
        }
    }
    return false;
}

void Cpu::run()
{
    string instruction;
    int lineNumber = 0;
    while (true)
    {
        cout << "Enter instruction (or 'halt' to stop): ";
        getline(cin, instruction);
        if (instruction == "halt")
        {
            break;
        }
        executeInstruction(lineNumber, instruction);
        lineNumber++;
    }
}

int Cpu::getProgramCounter() const { return programCounter; }

void Cpu::setProgramCounter(int value) { programCounter = value; }

string Cpu::getInstructionRegister() const { return instructionRegister; }

void Cpu::setInstructionRegister(const string &value) { instructionRegister = value; }

int Cpu::getRegister(const string &regName) const
{
    auto it = registers.find(regName);
    if (it != registers.end())
    {
        return it->second;
    }
    cerr << "Register " << regName << " not found." << endl;
    return 0;
}

unordered_map<string, int> Cpu::getAllRegisters() const
{
    return registers;
}

void Cpu::setRegister(const string &regName, int value)
{
    if (registers.find(regName) != registers.end())
    {
        int index = stoi(regName.substr(1)); // Assuming regName is in format "R0", "R1", etc.
        if (index >= 0 && index < NUM_REGISTERS)
        {
            registers_arr[index]->setValue(value);
            registers[regName] = value;
        }
    }
}