//
// Created by pedro on 8/29/17.
//

#include "Tests.h"
#include <cppunit/TestSuite.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestCaller.h>
#include <cppunit/ui/text/TestRunner.h>

int main(int argc, char **argv) {
    CppUnit::TestSuite suite;

    suite.addTest(new CppUnit::TestCaller<Testing>("test1", &Testing::test1));
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(&suite);
    runner.run();
    return 0;
}
