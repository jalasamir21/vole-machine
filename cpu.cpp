#include "alu.h"
#include "controlunit.h"
#include "Machine.h"
#include "register.h"
#include "memory.h"
#include "cpu.h"
#include <algorithm>




class CPU {
private:
    Register& reg;
    Memory& mem;
    Alu alu;
    Cu cu;
    vector<int> breakpoints;
    int instructionCount;
    int breakpointHits;
    clock_t startTime;
    unordered_map<string, int> registers;
    unordered_map<string, int> instructionSet;
public:
    CPU(Register& r, Memory& m) : reg(r), mem(m), instructionCount(0), breakpointHits(0) {
        startTime = clock();
    }

    void run() {
        string instruction;
        int lineNumber = 0;
        while (true) {
            cout << "Enter instruction (): ";
            getline(cin, instruction);
            if (instruction == "halt") {
                break;
            }
            executeInstruction(lineNumber,instruction);
            lineNumber++;
        }
    }
    void runNextStep() {
        static int lineNumber = 0;
        string instruction;

        if (lineNumber < instructionCount) {
            instruction = getInstruction(lineNumber);
            executeInstruction(lineNumber, instruction);
            lineNumber++;
        } else {
            cout << "All instructions executed" << endl;
        }
    }

    vector<string> instructions;
    string getInstruction(int lineNumber) {

        return instructions[lineNumber];
    }

    void executeInstruction(int currentLine,const string& instruction) {
        int instructionCode = stoi(instruction);


        if (find(breakpoints.begin(), breakpoints.end(), currentLine) != breakpoints.end()) {
            cout << "Breakpoint hit at line: " << currentLine << ". Execution paused." << endl;
            breakpointHits++;
            cin.get();
        }

        cu.executeMachineCode(instructionCode, instruction);
        logInstruction(instruction);
        displayRegisters();

        instructionCount++;
    }

    void logInstruction(const string& instruction) {
        ofstream logFile("cpu_log.txt", ios::app);
        if (logFile.is_open()) {
            logFile << instruction << endl;
            logFile.close();
        } else {
            cerr << "Unable to open log file." << endl;
        }
    }

    void displayRegisters() {
        cout << "Current Register Values:\n";
        for (const auto& regPair : cu.getRegisters()) {
            cout << regPair.first << ": " << regPair.second << endl;
        }
    }

    void fetch(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open file: " << filename << endl;
            return;
        }

        string instruction;
        while (getline(file, instruction)) {
            if (!instruction.empty()) {
                instructions.push_back(instruction);
            }
        }
        file.close();
        cout << "Program fetched successfully from " << filename << endl;
    }

    void loadInstructionsFromFile(const string& filename) {
        int lineNumber = 0;
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open file: " << filename << endl;
            return;
        }

        string instruction;
        while (getline(file, instruction)) {
            if (!instruction.empty()) {
                executeInstruction(lineNumber, instruction);
            }
            lineNumber++;
        }
        file.close();
    }

    void saveState(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {

            for (const auto& regPair : cu.getRegisters()) {
                file << regPair.first << " " << regPair.second << std::endl;
            }

            file.close();
        } else {
            cerr << "Unable to open file for saving state." << std::endl;
        }
    }

    void restoreState(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string regName;
            int regValue;

            if (iss >> regName >> regValue) {

                if (cu.setRegisterValue(regName, regValue)) {
                    cout << "Restored " << regName << " to " << regValue << endl;
                } else {
                    cerr << "Error: Register " << regName << " not found." << endl;
                }
            }
        }
        file.close();
    }


    void manageMemory(int numLocations = 10, int multiplier = 10) {
        for (int i = 0; i < numLocations; ++i) {
            mem.write(i, i * multiplier);
        }

        mem.displayMemory(numLocations);

        int value = mem.read(numLocations);
        cout << "Value at address " << numLocations << ": " << value << endl;

        mem.deallocate();
    }


    void handleError(const string& errorMessage) {
        cerr << "Error: " << errorMessage << endl;
    }

    void setBreakpoint(int line) {
        if (find(breakpoints.begin(), breakpoints.end(), line) == breakpoints.end()) {
            breakpoints.push_back(line);
            cout << "Breakpoint set at line: " << line << endl;
        } else {
            cout << "Breakpoint already exists at line: " << line << endl;
        }
    }
    void manageIO() {
        string command;
        cout << "Enter I/O command (read/write/exit): ";
        while (true) {
            getline(cin, command);
            if (command == "exit") {
                break;
            } else if (command == "read") {
                string filename;
                cout << "Enter filename to read instructions: ";
                getline(cin, filename);
                loadInstructionsFromFile(filename);
            } else if (command == "write") {
                string filename;
                cout << "Enter filename to save state: ";
                getline(cin, filename);
                saveState(filename);
            } else {
                cout << "Invalid command. Please enter 'read', 'write', or 'exit'." << endl;
            }
            cout << "Enter I/O command (read/write/exit): ";
        }
    }
    void userInterface() {
        string command;
        cout << "Welcome to the CPU Simulator!" << endl;
        cout << "Available commands: run, io, set_breakpoint, exit" << endl;

        while (true) {
            cout << "> ";
            getline(cin, command);

            if (command == "run") {
                run();
            } else if (command == "io") {
                manageIO();
            } else if (command.substr(0, 14) == "set_breakpoint") {
                int line = stoi(command.substr(15));
                setBreakpoint(line);
            } else if (command == "exit") {
                cout << "Exiting the CPU Simulator." << endl;
                break;
            } else {
                cout << "Invalid command. Please try again." << endl;
            }
        }
    }
    void monitorPerformance() {

        clock_t endTime = clock();
        double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;

        cout << "Performance Metrics:" << endl;
        cout << "Instructions Executed: " << instructionCount << endl;
        cout << "Breakpoints Hit: " << breakpointHits << endl;
        cout << "Elapsed Time: " << elapsedTime << " seconds" << endl;
    }
    bool setRegisterValue(const string& regName, int value) {

        if (registers.find(regName) != registers.end()) {
            registers[regName] = value;
            return true;
        }
        return false;
    }


};

