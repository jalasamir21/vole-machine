#include "controlunit.h"



class ControlUnit {
private:
    static const int NUM_REGISTERS = 16;
    Register* registers[NUM_REGISTERS];
    Alu alu;
    int PC;
public:
    ControlUnit() {
        // initialization of registers 
        for (int i = 0; i < NUM_REGISTERS; ++i) {
            registers[i] = new Register();
        }
    }

    ~ControlUnit() {
        // loop for destructing dynamically allocated registers
        for (int i = 0; i < NUM_REGISTERS; ++i) {
            delete registers[i];
        }
    }

    // method to reset value of specified register to zero
    void resetRegister(int registerIndex) {
        if (registerIndex >= 0 && registerIndex < NUM_REGISTERS) {
            registers[registerIndex]->value = 0;
        } else {
            cerr << "Register index " << registerIndex << " not found." << endl;
        }
    }
    // instruction execution method
    void executeInstruction(const string& instruction, Memory& memory) {
        size_t spacePos = instruction.find(' ');
        if (spacePos == string::npos) {
            cerr << "That's an invalid instruction format." << endl;
            return;
        }

        string command = instruction.substr(0, spacePos);
        string registerName = instruction.substr(spacePos + 1, instruction.find(' ', spacePos + 1) - spacePos - 1);
        int value;

        //handling instructions
        if (command == "add") {
            // extracting the destination and source register names
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for add instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string srcRegName = registerName.substr(commaPos + 1);

            // convert register names to indices
            int destRegIndex = stoi(destRegName.substr(1));
            int srcRegIndex = stoi(srcRegName.substr(1));

            // check if register indices are valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // perform the addition instruction
            registers[destRegIndex]->value += memory.getValue(registers[srcRegIndex]->value);

        } else if (command == "addfloat") {
            // extracting the destination and source register names
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for addfloat instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string srcRegName = registerName.substr(commaPos + 1);

            // convert register names to indices 
            int destRegIndex = stoi(destRegName.substr(1));
            int srcRegIndex = stoi(srcRegName.substr(1));

            // check if register indices are valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // perform the floating-point addition instruction
            registers[destRegIndex]->value += static_cast<float>(memory.getValue(registers[srcRegIndex]->value));

        } else if (command == "or") {
            // extracting the destination and source register names
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for or instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string srcRegName = registerName.substr(commaPos + 1);

            // convert register names to indices
            int destRegIndex = stoi(destRegName.substr(1));
            int srcRegIndex = stoi(srcRegName.substr(1));

            // check if register indices are valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // perform the bitwise OR operation instruction
            registers[destRegIndex]->value |= memory.getValue(srcRegIndex);

        } else if (command == "and") {
            // extracting the destination and source register names
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for and instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string srcRegName = registerName.substr(commaPos + 1);

            // convert register names to indices 
            int destRegIndex = stoi(destRegName.substr(1));
            int srcRegIndex = stoi(srcRegName.substr(1));

            // check if register indices are valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // perform the bitwise AND operation instruction
            registers[destRegIndex]->value &= memory.getValue(srcRegIndex);

        } else if (command == "xor") {
            // extracting the destination and source register names
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for xor instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string srcRegName = registerName.substr(commaPos + 1);

            // convert register names to indices 
            int destRegIndex = stoi(destRegName.substr(1));
            int srcRegIndex = stoi(srcRegName.substr(1));

            // check if register indices are valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // perform the bitwise XOR operation instruction
            registers[destRegIndex]->value ^= memory.getValue(srcRegIndex);

        } else if (command == "load1") {
            // extract the destination register and memory address
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for load1 instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string addressStr = registerName.substr(commaPos + 1);

            // convert register name to index 
            int destRegIndex = stoi(destRegName.substr(1));
            int address = stoi(addressStr);

            // check if register index is valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }
            registers[destRegIndex]->value = memory.getValue(address);

        } else if (command == "load2") {
            // extracting the destination register and memory address
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for load2 instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string addressStr = registerName.substr(commaPos + 1);

            // convert register name to index 
            int destRegIndex = stoi(destRegName.substr(1));
            int address = stoi(addressStr);

            // check if register index is valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }
            registers[destRegIndex]->value = memory.getValue(address);

        } else if (command == "jump") {
            // extract the target address
            int targetAddress = stoi(registerName);
            //pc is the program counter
            PC = targetAddress;

        } else if (command == "rotate") {
            // extract the destination register and the number of bits to rotate
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for rotate instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string bitsStr = registerName.substr(commaPos + 1);

            // convert register name to index 
            int destRegIndex = stoi(destRegName.substr(1));
            int bits = stoi(bitsStr);

            // check if register index is valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // perform the left rotation
            int value = registers[destRegIndex]->value;
            int rotatedValue = (value << bits) | (value >> (32 - bits));
            registers[destRegIndex]->value = rotatedValue;
        } else if (command == "copyregister") {
            // extract the destination and source register names
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for copyregister instruction." << endl;
                return;
            }

            string destRegName = registerName.substr(0, commaPos);
            string srcRegName = registerName.substr(commaPos + 1);

            // convert register names to indices 
            int destRegIndex = stoi(destRegName.substr(1));
            int srcRegIndex = stoi(srcRegName.substr(1));

            // check if register indices are valid
            if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // Perform the copy operation
            registers[destRegIndex]->value = registers[srcRegIndex]->value;

        } else if (command == "jumpifgreater") {
            // Extract the source register and the target address
            size_t commaPos = registerName.find(',');
            if (commaPos == string::npos) {
                cerr << "Invalid format for jumpifgreater instruction." << endl;
                return;
            }

            string srcRegName = registerName.substr(0, commaPos);
            string targetAddressStr = registerName.substr(commaPos + 1);

            // Convert register name to index
            int srcRegIndex = stoi(srcRegName.substr(1));
            int targetAddress = stoi(targetAddressStr);
            // Check if register index is valid
            if (srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS) {
                cerr << "Invalid register index." << endl;
                return;
            }

            // Check if the value in the source register is greater than zero
            if (registers[srcRegIndex]->value > 0) {
                PC = targetAddress;
            }
        } else if (command == "halt") {
            cout << "Halting execution." << endl;
            return;

        } else {
            cerr << "Unknown instruction: " << command << endl;
        }
    }

};
    