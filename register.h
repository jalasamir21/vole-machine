

#ifndef VOLE_MACHINE_REGISTER_H
#define VOLE_MACHINE_REGISTER_H
using namespace std;

class Register {
public:
    int value;
    int getCell(int address);
    void setCell(int address ,int value);
    int getValue() const;
    int setValue() const;
private:
    int memory[16];
    int size=16;
};
#endif //VOLE_MACHINE_REGISTER_H