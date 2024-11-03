#include "memory.h"
//#include <stdexcept>

using namespace std;

// get the string stored at the specified address in memory
string Memory::getCell(int address) {
    if (address < 0 || address >= size) {
        throw out_of_range("Address out of range");
    }
    return memory[address];
}

// set the string value at the specified address in memory
void Memory::setCell(int address, const string &Val) {
    if (address < 0 || address >= size) {
        throw out_of_range("Address out of range");

    }
    memory[address] = Val ;
}
//made the getter and setter++++++++++++++++++++++++++++++++++++++++++++++++++++
int Memory::getSize() const {
    return size;
}
void Memory::write(int address, int value) {
    if (address >= 0 && address < size) {
        memory[address] = to_string(value);
    } else {
        throw out_of_range("Address out of range");
    }
}
int Memory::read(int address) const {
    if (address >= 0 && address < size) {
        return stoi(memory[address]);
    }
    return -1;
}
int Memory::getValue(int address) {
    if (address >= 0 && address < size) {
        return stoi(memory[address]);
    }
    throw out_of_range("Address out of range");
}
void Memory::displayMemory(int count) const {
    for (int i = 0; i < count && i < size; ++i) {
        cout << "Memory[" << i << "]: " << memory[i] << endl; // Display memory values
    }
}
void Memory::deallocate() {
    delete[] mem;
    mem = nullptr;
}
void Memory::setSize(int size) {

}
