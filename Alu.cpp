#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <iomanip>
#include "Alu.h"
#include "register.h"
#include "memory.h"
//Method to convert hexadecimal string to decimal string
std::string Alu::hexToDec(const std::string& hexValue) {
    return std::to_string(stoi(hexValue, nullptr, 16));
}

//Method to convert decimal to hexadecimal string
std::string Alu::decToHex(int decValue) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << decValue;
    return ss.str();
}

// Validates if the input is in a correct format for the ALU operations
bool Alu::isValid(const std::string& value) {
    if (value.length() != 4) {
        return false; // Must be exactly 4 characters
    }
    if (value.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return false; // Contains invalid characters
    }
    if (value.substr(0, 2) != "0x") {
        return false; // Must start with "0x"
    }

    std::map<std::string, int> opcodes = {
            {"0x1", 1},   // LOAD
            {"0x2", 2},   // LOAD immediate
            {"0x4", 3},   // COPYREGISTER
            {"0x5", 4},   // ADD
            {"0x6", 5},   // ADD FLOAT
            {"0x7", 6},   // OR
            {"0x8", 7},   // AND
            {"0x9", 8},   // XOR
            {"0xA", 9},   // ROTATE
            {"0xB", 10},  // JUMP
            {"0xC", 11},  // HALT
            {"0xD", 12}   // JUMPIFGREATER
    };

    // Extract the opcode from the input string
    std::string opcode = value.substr(0, 4);

    if (opcodes.find(opcode) == opcodes.end()) {
        return false; // Opcode is not valid
    }

    return true; // Valid input
}

// Arithmetic and logical operations
void Alu::load1(int destinationIdx, int srcIdx1, Register& reg) {
    int value = reg.getCell(srcIdx1);
    reg.setCell(destinationIdx, value);
}

void Alu::load2(int destinationIdx, int srcIdx1, Register& reg) {
    int value = reg.getCell(srcIdx1);
    reg.setCell(destinationIdx, value);
}
void Alu::add(int destinationIdx, int srcIdx1, int srcIdx2, Register& reg) {
    int x1 = reg.getCell(srcIdx1);
    int x2 = reg.getCell(srcIdx2);
    reg.setCell(destinationIdx, x1 + x2);
}

void Alu::addFloat(int destinationIdx, int srcIdx1, int srcIdx2, Register& reg) {
    int intValue1 = reg.getCell(srcIdx1);
    int intValue2 = reg.getCell(srcIdx2);
    float x1 = *reinterpret_cast<float*>(&intValue1);
    float x2 = *reinterpret_cast<float*>(&intValue2);
    float result = x1 + x2;
    reg.setCell(destinationIdx, *reinterpret_cast<int*>(&result));
}

void Alu::Or(int destinationIdx, int srcIdx1, int srcIdx2, Register& reg) {
    int x1 = reg.getCell(srcIdx1);
    int x2 = reg.getCell(srcIdx2);
    reg.setCell(destinationIdx, x1 | x2);
}

void Alu::And(int destinationIdx, int srcIdx1, int srcIdx2, Register& reg) {
    int x1 = reg.getCell(srcIdx1);
    int x2 = reg.getCell(srcIdx2);
    reg.setCell(destinationIdx, x1 & x2);
}

void Alu::Xor(int destinationIdx, int srcIdx1, int srcIdx2, Register& reg) {
    int x1 = reg.getCell(srcIdx1);
    int x2 = reg.getCell(srcIdx2);
    reg.setCell(destinationIdx, x1 ^ x2);
}


void Alu::rotate(int regIdx, int numBits, Register& reg) {
    int value = reg.getCell(regIdx);
    numBits = numBits % 16;
    int rotatedValue = (value >> numBits) | (value << (16 - numBits));
    reg.setCell(regIdx, rotatedValue);
}

void Alu::jump(int r, Register& reg, int& instructionPointer) {
    if (reg.getCell(r) == reg.getCell(0)) {
        instructionPointer = reg.getCell(r);
    }
}


void Alu::copyRegister(int srcIdx, int destIdx, Register& reg) {
    int value = reg.getCell(srcIdx);
    reg.setCell(destIdx, value);
}

void Alu::jumpIfGreater(int r, int xy, Register& reg, int& instructionPointer) {
    int regValue = reg.getCell(r);
    int zeroValue = reg.getCell(0);

    int ramValue = reg.getCell(xy);

    if (regValue > zeroValue) {
        instructionPointer = ramValue;
    }
}


void Alu::halt() {
    isHalted = true;
    std::cout << "ALU operations halted." << std::endl;
}
