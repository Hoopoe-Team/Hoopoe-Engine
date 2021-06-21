#include "../include/TestSuite.h"

Hoopoe::Test::TestSuite::TestSuite() {}

Hoopoe::Test::TestSuite::~TestSuite() {
    for (TestBase *test : tests) {
        delete test;
    }
}

void Hoopoe::Test::TestSuite::add(TestBase *test) {
    if(test != nullptr)
        tests.push_back(test);
}

void Hoopoe::Test::TestSuite::run() {
    for(TestBase *test : tests)
        test->run();
}

std::string Hoopoe::Test::TestSuite::getName() { return this->name; }