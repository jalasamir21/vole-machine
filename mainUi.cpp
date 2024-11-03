#include "Memory.h"
#include "cpu.h"    // Include cpu.h instead of cpu.cpp
#include "MainUi.h"
#include "Alu.h"

MainUi::MainUi() : reg(), memory(256), cpu(reg, memory), machine(cpu, memory) {
    // Initialization list in correct dependency order
    // No need to initialize memory inside the constructor body
}



void MainUi::displayMenu() {
    std::cout << "\n--- CPU Simulation Menu ---\n";
    std::cout << "1. Load Program\n";
    std::cout << "2. Set Breakpoint\n";
    std::cout << "3. Run Program\n";
    std::cout << "4. Step Through Program\n";
    std::cout << "5. Display State\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
}

void MainUi::handleUserInput() {
    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cin >> choice;

        switch (choice) {
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
                running = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

void MainUi::setBreakpoint() {
    int line;
    cout << "Enter the line number to set breakpoint: ";
    cin >> line;
    cpu.setBreakpoint(line);
}

void MainUi::runProgram() {
    cout << "Running program...\n";
    cpu.run();
    cout << "Program execution completed.\n";
}

void MainUi::stepThroughProgram() {
    cout << "Stepping through the program...\n";
    cpu.runNextStep();  // Run one instruction and stop
}

void MainUi::displayState() {
    cout << "Displaying current CPU and memory state:\n";
    machine.outputState();  // Calls Machine’s outputState() to print registers, memory, etc.
}

void MainUi::loadProgram() {
    string filename;
    cout << "Enter program filename: ";
    cin >> filename;
    cpu.fetch(filename);  // Load instructions into the CPU
    cout << "Program loaded from " << filename << "\n";
}
