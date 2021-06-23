#include "../include/TestSuite.h"

namespace Hoopoe { namespace Test {

TestSuite::TestSuite() {}

TestSuite::~TestSuite() {
    for (TestBase *test : tests) {
        delete test;
    }
}

void TestSuite::add(TestBase *test) {
    if(test != nullptr)
        tests.push_back(test);
}

void TestSuite::run() {
    for(TestBase *test : tests)
        test->run();
}

String TestSuite::getName() { return this->name; }

}
}