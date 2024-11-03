#ifndef MAIN_UI_H
#define MAIN_UI_H
#include "Register.h"
#include "Memory.h"
#include "Cpu.h"
#include "Machine.h"
#include <iostream>
#include <string>

class MainUi {
private:
    machine machine;
    Cpu cpu;
    Memory memory;
    Register reg;

public:
    MainUi();
    void displayMenu();
    void handleUserInput();
    void setBreakpoint();
    void runProgram();
    void stepThroughProgram();
    void displayState();
    void loadProgram();
};

#endif // MAIN_UI_H