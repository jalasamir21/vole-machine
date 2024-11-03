

#include "machine.h"
#include "memory.h"

#include <fstream>
//#include <iostream>
using namespace std;

void machine::loadProgramFile() {

    fstream file;
    string line;
    cout << "Enter filename";
    string filename;
    cin >> filename;
    file.open(filename, ios::in);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }
    int i = 0;
    while (getline(file, line)){
        mem.setCell(i, line.substr(0, 2));
        mem.setCell(i + 1, line.substr(2, 4));
        i+=2;

    }
    file.close();
}

void machine::outputState() {

    if (&processor && &mem) {
        // Output the program counter
        cout << "Program Counter: " << processor.getProgramCounter() <<endl;

        // Output the instruction register
        cout << "Instruction Register: " << processor.getInstructionRegister() << endl;

        // Output all register values
        cout << "Registers:" << endl;
        auto registers = processor.getAllRegisters();
        for (const auto& [regName, regValue] : registers) {
            cout << regName << " = " << regValue << endl;
        }

        // Output memory contents
        cout << "Memory:" << endl;
        for (int address = 0; address < mem.getSize(); ++address) {
            cout << address << " | " << mem.getCell(address) << endl;
        }
    } else {
        cerr << "Error: Processor or Memory not initialized." << endl;
    }
}

