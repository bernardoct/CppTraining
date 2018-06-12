cmake_minimum_required(VERSION 3.10)
project(CppTraining)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp")

add_executable(CppTraining1 HW1/ReservoirMassBalance1.cpp)
add_executable(CppTraining2 HW2/ReservoirMassBalance2.cpp)
add_executable(CppTraining3 HW3/ReservoirMassBalance3.cpp HW3/WaterSources/Reservoir.cpp HW3/WaterSources/Reservoir.h
        HW3/WaterSources/StorageInfrastructure.cpp HW3/WaterSources/StorageInfrastructure.h)
add_executable(CppTraining4 HW4/ReservoirMassBalance4.cpp HW4/WaterSources/Reservoir.cpp HW4/WaterSources/Reservoir.h
        HW4/WaterSources/StorageInfrastructure.cpp HW4/WaterSources/StorageInfrastructure.h HW4/WaterSources/Quarry.cpp
        HW4/WaterSources/Quarry.h HW4/Constants.h)