#include "memory.h"

std::string Memory::getCell(int address) const
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    return memory[address];
}

void Memory::setCell(int address, const std::string &val)
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    memory[address] = val;
}

int Memory::getSize() const
{
    return size;
}

void Memory::write(int address, int value)
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    memory[address] = std::to_string(value);
}

int Memory::read(int address) const
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    return std::stoi(memory[address]);
}

int Memory::getValue(int address) const
{
    if (address < 0 || address >= size)
    {
        throw std::out_of_range("Address out of range");
    }
    return std::stoi(memory[address]);
}

void Memory::displayMemory(int count) const
{
    for (int i = 0; i < count && i < size; ++i)
    {
        std::cout << "Memory[" << i << "]: " << memory[i] << std::endl;
    }
}

void Memory::setSize(int newSize)
{
    if (newSize < 0)
    {
        throw std::invalid_argument("Size must be non-negative");
    }
    size = newSize;
    memory.resize(size, "0"); // Initialize new cells with "0"
}
