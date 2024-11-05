#ifndef VOLE_MACHINE_REGISTER_H
#define VOLE_MACHINE_REGISTER_H

class Register
{
public:
    Register();  // Constructor
    ~Register(); // Destructor

    int getCell(int address);
    void setCell(int address, int value);
    int getValue() const;
    void setValue(int value);

private:
    int *memory;   // Pointer to dynamically allocated memory
    int size = 16; // Size of the register
    int value;     // Current value of the register
};

#endif // VOLE_MACHINE_REGISTER_H
