//
// Created by Ahmed Atef on 25/10/2024.
//

#ifndef VOLE_MACHINE_MACHINE_H
#define VOLE_MACHINE_MACHINE_H
#include "cpu.h"
#include "memory.h"
class machine{

private:
    Cpu* processor;
    Memory* mem;

public:
    machine(Cpu* cpu, Memory* memo) : processor(reinterpret_cast<Cpu *>(cpu)), mem(memo) {}
    void loadProgramFile();
    void outputState();

};

#endif //VOLE_MACHINE_MACHINE_H