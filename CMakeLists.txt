cmake_minimum_required(VERSION 3.21)
project(theRegulators)

set(CMAKE_CXX_STANDARD 20)

include_directories(include)
add_executable(theRegulators main.cpp src/pomieszczenie.cpp src/simulation.cpp include/simulation.h src/heater.cpp src/regulator.cpp include/regulator.h src/regulatorBB.cpp)
