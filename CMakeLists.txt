cmake_minimum_required(VERSION 3.7)
project(mafiac)
set(CMAKE_CXX_STANDARD 11)

enable_testing()
find_package(CppUnit REQUIRED)
include_directories(${CPPUNIT_INCLUDE_DIR})
LIST(APPEND testingLibs ${CPPUNIT_LIBRARY})

set(SOURCE_FILES_TESTING Test/Tests.cpp Test/Tests.h Test/tests.cpp)
add_executable(tests ${SOURCE_FILES_TESTING})
target_link_libraries(tests ${testingLibs})

set(SOURCE_FILES main.cpp Gangster.cpp Gangster.h Mafia.cpp Mafia.h)
add_executable(mafiac ${SOURCE_FILES})
