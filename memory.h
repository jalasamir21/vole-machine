#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H

#include <string>
#include <vector>
#include <iostream>
#include <stdexcept>

class Memory
{
public:
    explicit Memory(int s) : size(s), memory(s, "0") {} // Initialize memory with default "0"
    Memory(const Memory &) = delete;                    // Prevent copying
    Memory &operator=(const Memory &) = delete;         // Prevent assignment
    ~Memory() = default;

    std::string getCell(int address) const; // Mark as const
    void setCell(int address, const std::string &val);
    void write(int address, int value);
    int read(int address) const;
    void displayMemory(int count) const;
    int getValue(int address) const; // Mark as const
    int getSize() const;

    void setSize(int newSize); // Better naming convention

private:
    int size;
    std::vector<std::string> memory;
};

#endif // VOLE_MACHINE_MEMORY_H
