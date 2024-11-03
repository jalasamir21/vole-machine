
#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H
#include<string>
#include<vector>
#include <iostream>
using namespace std;

class Memory{
public :
    string getCell(int address);
    void setCell(int address,const string &Val);

    void write(int address, int value) {
        if (address >= 0 && address < size) {
            memory[address] = to_string(value);
        } else {
            throw out_of_range("Address out of range");
        }
    }
    int read(int address) const {
        if (address >= 0 && address < size) {
            return stoi(memory[address]);
        }
        return -1;
    }
    void displayMemory(int count) const {
        for (int i = 0; i < count && i < size; ++i) {
            cout << "Memory[" << i << "]: " << memory[i] << endl; // Display memory values
        }
    }
    int getValue(int address) {
        if (address >= 0 && address < size) {
            return stoi(memory[address]);
        }
        throw out_of_range("Address out of range");
    }

    int getSize() const;

    Memory(int s) : size(s) {
        mem = new int[size]; // Allocate memory
    }

    ~Memory() {
        deallocate();
    }

    void deallocate() {
        delete[] mem;
        mem = nullptr;
    }
//    why no implemenytion++++++++++++++++++++++++++++++++++++=

    void setSize(int size);

private:
    string memory[256];
    int size = 256;
    vector<string> memry;
    int* mem;
};
#endif //VOLE_MACHINE_MEMORY_H