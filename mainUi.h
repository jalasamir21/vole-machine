#ifndef MAIN_UI_H
#define MAIN_UI_H
#include "machine.h"

#include "cpu.h"
#include "memory.h"

#include "register.h"
#include "ControlUnit.h"

#include <iostream>
#include <string>

class MainUi
{
private:
    machine machine;
    Cpu cpu;
    Memory memory;
    Register reg;
    Cu cu;

public:
    MainUi();
    void enterAndExecuteInstruction();
    void displayMenu();
    void handleUserInput();
    void setBreakpoint();
    void runProgram();
    void stepThroughProgram();
    void displayState();
    void loadProgram();
};

#endif // MAIN_UI_H