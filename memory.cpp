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

void Memory::setSize(int s) {
    if (s <= 0) {
        throw invalid_argument("Memory size must be positive");
    }
    size = s;
    memory.resize(size);  // Resize the vector to the new size if it changes
}
