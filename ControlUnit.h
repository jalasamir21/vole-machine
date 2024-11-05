#ifndef VOLE_MACHINE_CONTROLUNIT_H
#define VOLE_MACHINE_CONTROLUNIT_H
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "machine.h"
#include "register.h"
#include "memory.h"
#include "cpu.h"
#include "Alu.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Cu
{
private:
    unordered_map<std::string, int> registers;
    static const int NUM_REGISTERS = 16;
    Register *registers_arr[NUM_REGISTERS];
    Alu alu;
    int PC;

public:
    Cu()
    {
        for (int i = 0; i < NUM_REGISTERS; ++i)
        {
            registers_arr[i] = new Register();
        }
    }

    ~Cu()
    {
        for (int i = 0; i < NUM_REGISTERS; ++i)
        {
            delete registers_arr[i];
        }
    }

    void resetRegister(int registerIndex);
    void executeInstruction(const std::string &instruction, Memory &memory);
    bool setRegisterValue(const std::string &regName, int value);
    std::unordered_map<std::string, int> getRegisters();
};

#endif // VOLE_MACHINE_CONTROLUNIT_H_CONTROLUNIT_H