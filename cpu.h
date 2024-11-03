
#ifndef VOLE_MACHINE_CPU_H
#define VOLE_MACHINE_CPU_H
#include "Alu.h"

#include "ControlUnit.h"

#include <iostream>
#include <string>
#include <vector>


#include "register.h"
#include "memory.h"
using namespace std;
class Cpu : public Register, public Alu, public Cu{
public:

    Cpu(Register aRegister, Memory memory1) : programCounter(0), instructionRegister("") {}

    void reset() { programCounter = 0; instructionRegister = ""; }

    string getState() const { return "Program Counter : " + to_string(programCounter) + ", Instruction Register: " + instructionRegister; }

    void runNextStep();

    void fetch(const string& filename);

private:
//    need the setter and gettter functions++++++++++++++++++++++++++++++++++++++++++
    int programCounter;
    string instructionRegister;
    Register reg;
    Alu alu;
    Cu cu;



};

#endif //VOLE_MACHINE_CPU_H