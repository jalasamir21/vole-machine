#include <string>
#include "register.h"
using namespace std;
#ifndef VOLE_MACHINE_ALU_H
#define VOLE_MACHINE_ALU_H
class Alu
{
private:
    bool isHalted = false;
    int programCounter = 0;

public:
    // Convert hexadecimal to decimal string
    string
    hexToDec(const string &hexValue);

    // Convert decimal to hexadecimal string
    string decToHex(int decValue);

    // Validates if the input is in a correct format for the ALU operations
    bool isValid(const string &value);
    void execute(const std::string &instruction, Register &reg, int &instructionPointer);

    // Arithmetic and logical operations
    void add(int destinationIdx, int srcIdx1, int srcIdx2, Register &reg);
    void addFloat(int destinationIdx, int srcIdx1, int srcIdx2, Register &reg);
    void Or(int destinationIdx, int srcIdx1, int srcIdx2, Register &reg);
    void And(int destinationIdx, int srcIdx1, int srcIdx2, Register &reg);
    void Xor(int destinationIdx, int srcIdx1, int srcIdx2, Register &reg);
    void load1(int destinationIdx, int srcIdx1, Register &reg);
    void load2(int destinationIdx, int srcIdx1, Register &reg);
    void jump(int r, Register &reg, int &instructionPointer);
    void rotate(int regIdx, int numBits, Register &reg);
    void copyRegister(int destinationIdx, int sourceIdx, Register &reg);
    void jumpIfGreater(int r, int xy, Register &reg, int &instructionPointer);
    void halt();
};

#endif // VOLE_MACHINE_ALU_H