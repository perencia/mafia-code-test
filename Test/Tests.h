//
// Created by pedro on 8/28/17.
//

#ifndef MAFIAC_TEST_H
#define MAFIAC_TEST_H

#include <cppunit/TestFixture.h>
#include <cppunit/TestCase.h>

class Testing : public CppUnit::TestFixture {

public:
    void setUp() override {}
    void tearDown() override {}
    void test1();
};


#endif //MAFIAC_TEST_H
