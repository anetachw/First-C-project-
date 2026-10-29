
cmake_minimum_required(VERSION 3.10)
project(StudentuValdymoSistema)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

add_executable(studentu_programa
    mainproject.cpp
    basic_funkcijos.cpp
    Lfunkcijos.cpp 
    Vfunkcijos.cpp
)