cmake_minimum_required(VERSION 3.7)
project(mafiac)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Gangster.cpp Gangster.h Mafia.cpp Mafia.h)
add_executable(mafiac ${SOURCE_FILES})