cmake_minimum_required(VERSION 3.24)
project(project)

set(CMAKE_CXX_STANDARD 17)

add_executable(project main.cpp equation.cpp systemOfEquations.cpp slesolver.cpp)
