#include <stdexcept>
#include "register.h"

// Constructor
Register::Register()
{
    memory = new int[size](); // Allocate and initialize memory to zero
}

// Destructor
Register::~Register()
{
    delete[] memory; // Deallocate memory
}

// Get value from specified cell
int Register::getCell(int address)
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    return memory[address];
}

// Set value in specified cell
void Register::setCell(int address, int value)
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    memory[address] = value;
}

// Get the current value of the register
int Register::getValue() const
{
    return value;
}

// Set the current value of the register
void Register::setValue(int value)
{
    this->value = value;
}
