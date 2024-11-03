#include <stdexcept>
#include "register.h"
int Register::getCell(int address) {
    if (address < 0 || address >= size) {
        throw std::out_of_range("Address out of range");
    }
    return memory[address];
}

void Register::setCell(int address, int value) {
    if (address < 0 || address >= size) {
        throw std::out_of_range("Address out of range");
    }
    memory[address] = value;
}
int Register::getValue() const {
    return value;
}
int Register::setValue() const {
    return value;
}