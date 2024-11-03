#ifndef VOLE_MACHINE_CPU_H
#define VOLE_MACHINE_CPU_H

#include "ControlUnit.h"
#include "Alu.h"
#include "register.h"
#include "memory.h"

#include <unordered_map>
#include <string>
#include <vector>
#include <ctime>

class Cpu : public Register, public Alu { // Removed Cu, assuming it's not needed or defined
public:
    Cpu(Register& reg, Memory& mem) : reg(reg), mem(mem) {}

    int getProgramCounter() const;
    void setProgramCounter(int value);

    std::string getInstructionRegister() const;
    void setInstructionRegister(const std::string& value);

    int getRegister(const std::string& regName) const;
    void setRegister(const std::string& regName, int value);

    void run();
    void reset();
    std::string getState() const;
    void runNextStep();
    void fetch(const std::string& filename);

    std::string getInstruction(int lineNumber);
    void logInstruction(const std::string& instruction);
    void displayRegisters();
    void executeInstruction(int currentLine, const std::string& instruction);
    void loadInstructionsFromFile(const std::string& filename);
    void saveState(const std::string& filename);
    void restoreState(const std::string& filename);

    void manageMemory(int numLocations = 10, int multiplier = 10);
    void handleError(const std::string& errorMessage);
    void setBreakpoint(int line);
    void manageIO();
    void userInterface();
    void monitorPerformance();
    bool setRegisterValue(const std::string& regName, int value);
    std::unordered_map<std::string, int> getAllRegisters() const;

private:
    int programCounter;
    std::string instructionRegister;
    Alu alu;
    Register& reg;
    Memory& mem;
    std::vector<int> breakpoints;
    int instructionCount;
    vector<string> instructions;
    int breakpointHits;
    clock_t startTime;
    std::unordered_map<std::string, int> registers;
    std::unordered_map<std::string, int> instructionSet;
};

#endif // VOLE_MACHINE_CPU_H
