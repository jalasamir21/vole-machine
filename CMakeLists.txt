cmake_minimum_required(VERSION 3.27)
project(A1_Task4_S19_20230104)

set(CMAKE_CXX_STANDARD 17)

add_executable(A1_Task4_S19_20230104 main.cpp
        machine.cpp
        memory.h
        cpu.h
        register.h
        ControlUnit.h
        Alu.h
        cpu.cpp
        ControlUnit.cpp
        register.cpp
        memory.cpp
        mainUi.cpp
        mainUi.h
        Alu.cpp)
