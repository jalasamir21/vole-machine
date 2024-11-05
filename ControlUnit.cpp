#include "ControlUnit.h"
using namespace std;

// Method to reset the value of the specified register to zero
void Cu::resetRegister(int registerIndex)
{
    if (registerIndex >= 0 && registerIndex < NUM_REGISTERS)
    {
        registers_arr[registerIndex]->setValue(0);
    }
}

// Instruction execution method
void Cu::executeInstruction(const string &instruction, Memory &memory)
{
    size_t spacePos = instruction.find(' ');
    if (spacePos == string::npos)
    {
        cerr << "That's an invalid instruction format." << endl;
        return;
    }

    string command = instruction.substr(0, spacePos);
    string registerName = instruction.substr(spacePos + 1);
    int value;

    // Handling instructions
    if (command == "add")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for add instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string srcRegName = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int srcRegIndex = stoi(srcRegName.substr(1));

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        registers_arr[destRegIndex]->setValue(registers_arr[destRegIndex]->getValue() + memory.getValue(registers_arr[srcRegIndex]->getValue()));
    }
    else if (command == "addfloat")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for addfloat instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string srcRegName = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int srcRegIndex = stoi(srcRegName.substr(1));

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        registers_arr[destRegIndex]->setValue(registers_arr[destRegIndex]->getValue() + static_cast<float>(memory.getValue(registers_arr[srcRegIndex]->getValue())));
    }
    else if (command == "or")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for or instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string srcRegName = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int srcRegIndex = stoi(srcRegName.substr(1));

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        registers_arr[destRegIndex]->setValue(registers_arr[destRegIndex]->getValue() | memory.getValue(srcRegIndex));
    }
    else if (command == "and")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for and instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string srcRegName = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int srcRegIndex = stoi(srcRegName.substr(1));

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        registers_arr[destRegIndex]->setValue(registers_arr[destRegIndex]->getValue() & memory.getValue(srcRegIndex));
    }
    else if (command == "xor")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for xor instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string srcRegName = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int srcRegIndex = stoi(srcRegName.substr(1));

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        registers_arr[destRegIndex]->setValue(registers_arr[destRegIndex]->getValue() ^ memory.getValue(srcRegIndex));
    }
    else if (command == "load1")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for load1 instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string addressStr = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int address = stoi(addressStr);

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }
        registers_arr[destRegIndex]->setValue(memory.getValue(address));
    }
    else if (command == "load2")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for load2 instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string addressStr = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int address = stoi(addressStr);

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }
        registers_arr[destRegIndex]->setValue(memory.getValue(address));
    }
    else if (command == "jump")
    {
        int targetAddress = stoi(registerName);
        PC = targetAddress;
    }
    else if (command == "rotate")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for rotate instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string bitsStr = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int bits = stoi(bitsStr);

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        int value = registers_arr[destRegIndex]->getValue();
        int rotatedValue = (value << bits) | (value >> (32 - bits));
        registers_arr[destRegIndex]->setValue(rotatedValue);
    }
    else if (command == "copyregister")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for copyregister instruction." << endl;
            return;
        }

        string destRegName = registerName.substr(0, commaPos);
        string srcRegName = registerName.substr(commaPos + 1);

        int destRegIndex = stoi(destRegName.substr(1));
        int srcRegIndex = stoi(srcRegName.substr(1));

        if (destRegIndex < 0 || destRegIndex >= NUM_REGISTERS || srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        registers_arr[destRegIndex]->setValue(registers_arr[srcRegIndex]->getValue());
    }
    else if (command == "jumpifgreater")
    {
        size_t commaPos = registerName.find(',');
        if (commaPos == string::npos)
        {
            cerr << "Invalid format for jumpifgreater instruction." << endl;
            return;
        }

        string srcRegName = registerName.substr(0, commaPos);
        string targetAddressStr = registerName.substr(commaPos + 1);

        int srcRegIndex = stoi(srcRegName.substr(1));
        int targetAddress = stoi(targetAddressStr);

        if (srcRegIndex < 0 || srcRegIndex >= NUM_REGISTERS)
        {
            cerr << "Invalid register index." << endl;
            return;
        }

        if (registers_arr[srcRegIndex]->getValue() > 0)
        {
            PC = targetAddress;
        }
    }
    else if (command == "halt")
    {
        cout << "Halting execution." << endl;
        return;
    }
    else
    {
        cerr << "Unknown instruction: " << command << endl;
    }
}

bool Cu::setRegisterValue(const std::string &regName, int value)
{
    if (registers.find(regName) != registers.end())
    {
        int index = std::stoi(regName.substr(1)); // Assuming regName is in format "R0", "R1", etc.
        if (index >= 0 && index < NUM_REGISTERS)
        {
            registers_arr[index]->setValue(value);
            registers[regName] = value;
            return true;
        }
    }
    return false;
}

unordered_map<string, int> Cu::getRegisters()
{
    return registers;
}