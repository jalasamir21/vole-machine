#ifndef VOLE_MACHINE_MEMORY_H
#define VOLE_MACHINE_MEMORY_H
#include<string>
#include<vector>
#include <iostream>
using namespace std;

class Memory{
public :
    string getCell(int address);
    void setCell(int address,const string &Val);

    void write(int address, int value);


    int read(int address) const;


    void displayMemory(int count) const;

    int getValue(int address);

    int getSize() const;

    Memory(int s) : size(s) {
        mem = new int[size]; // Allocate memory
    }

    ~Memory() {
        deallocate();
    }

    void deallocate();
//    why no implemenytion++++++++++++++++++++++++++++++++++++=

    void setSize(int size);

private:
    string memory[256];
    int size = 256;
    vector<string> memry;
    int* mem;
};
#endif //VOLE_MACHINE_MEMORY_H