cmake_minimum_required(VERSION 3.24)
project(sistemaZoo)

set(CMAKE_CXX_STANDARD 17)

add_executable(sistemaZoo main.cpp Habitat.cpp Habitat.h Animal.cpp Animal.h Zoo.cpp Zoo.h Terrestres.h Terrestres.cpp Acuatico.cpp Acuatico.h Aereo.cpp Aereo.h)
