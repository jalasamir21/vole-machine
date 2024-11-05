#include "cpu.h"
#include "mainUi.h"

// mainUi.cpp
MainUi::MainUi() : reg(), memory(256), cpu(reg, memory), machine(cpu, memory), cu()
{
    // Initialization list in correct dependency order
}

void MainUi::enterAndExecuteInstruction()
{
    string instruction;
    cout << "Enter an instruction to execute: ";
    cin.ignore(); // Clear any leftover newline character from previous input
    getline(cin, instruction);

    // Execute the entered instruction
    cu.executeInstruction(instruction, memory);
    cout << "Instruction executed: " << instruction << "\n";
}

void MainUi::displayMenu()
{
    cout << "\n--- CPU Simulation Menu ---\n";
    cout << "1. Load Program\n";
    cout << "2. Set Breakpoint\n";
    cout << "3. Run Program\n";
    cout << "4. Step Through Program\n";
    cout << "5. Display State\n";
    cout << "6. Enter Instruction\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

void MainUi::handleUserInput()
{
    int choice;
    bool running = true;

    while (running)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            loadProgram();
            break;
        case 2:
            setBreakpoint();
            break;
        case 3:
            runProgram();
            break;
        case 4:
            stepThroughProgram();
            break;
        case 5:
            displayState();
            break;
        case 6:
            enterAndExecuteInstruction();
            break;
        case 7:
            running = false;
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

void MainUi::setBreakpoint()
{
    int line;
    cout << "Enter the line number to set breakpoint: ";
    cin >> line;
    cpu.setBreakpoint(line);
}

void MainUi::runProgram()
{
    cout << "Running program...\n";
    cpu.run();
    cout << "Program execution completed.\n";
}

void MainUi::stepThroughProgram()
{
    cout << "Stepping through the program...\n";
    cpu.runNextStep(); // Run one instruction and stop
}

void MainUi::displayState()
{
    cout << "Displaying current CPU and memory state:\n";
    machine.outputState(); // Calls Machine’s outputState() to print registers, memory, etc.
}

void MainUi::loadProgram()
{
    string filename;
    cout << "Enter program filename: ";
    cin >> filename;
    cpu.fetch(filename); // Load instructions into the CPU
    cout << "Program loaded from " << filename << "\n";
}