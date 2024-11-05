//
// Created by Ahmed Atef on 25/10/2024.
//

#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H
#include "cpu.h"
#include "memory.h"
class Cpu;
class Memory;
class machine
{

private:
    Cpu &processor;
    Memory &mem;

public:
    machine(Cpu &cpuRef, Memory &memRef) : processor(cpuRef), mem(memRef) {}

    void loadProgramFile();
    void outputState();
};

#endif // VOLE_MACHINE_MACHINE_H