cmake_minimum_required(VERSION 3.19)
project(3BHIT_Uebung20_Bitoperatoren C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-lm")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lm")

add_executable(3BHIT_Uebung20_Bitoperatoren main.c)
