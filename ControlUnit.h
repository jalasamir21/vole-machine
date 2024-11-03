#ifndef VOLE_MACHINE_CONTROLUNIT_H
#define VOLE_MACHINE_CONTROLUNIT_H
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include "Machine.h"
#include "register.h"
#include "memory.h"
#include "cpu.h"
#include "Alu.h"
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

class Cu {
private:
    unordered_map<string, int>registers;
public:

    bool setRegisterValue(const string& regName, int value) {

        if (registers.find(regName) != registers.end()) {
            registers[regName] = value;
            return true;
        }
        return false;
    }
    unordered_map<string, int> getRegisters() {
        return registers;
    }
};
#endif //VOLE_MACHINE_CONTROLUNIT_H