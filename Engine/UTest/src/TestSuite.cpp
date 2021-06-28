#include "../include/TestSuite.h"

namespace Hoopoe { namespace Test {

TestSuite::TestSuite() {}

TestSuite::~TestSuite() 
{
    for (TestBase *test : tests) 
        delete test;
}

void TestSuite::add(TestBase *test) 
{
    if(test != nullptr)
        tests.push_back(test);
}

void TestSuite::run(TestReporter *reporter) 
{
    for(TestBase *test : tests)
    {
        test->setReporter(reporter);
        test->run();
    }
}

} // Hoopoe
} // Test