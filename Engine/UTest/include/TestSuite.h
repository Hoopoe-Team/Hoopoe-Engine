#ifndef __HOOPOE_ENGINE_TESTSUITE_H__
#define __HOOPOE_ENGINE_TESTSUITE_H__

#include "TestBase.h"

namespace Hoopoe { namespace Test {

class TestSuite 
{
public:
    TestSuite();
    ~TestSuite();

    void add(TestBase *test); 
    void run(TestReporter *reporter);

private:
    std::list<TestBase *> tests;
};

} // Test
} // Hoopoe

#define UTEST_BEGIN_SUITE(suiteName) \
Hoopoe::Test::TestSuite suite; \
Hoopoe::Test::TestReporter reporter(suiteName); \

#define UTEST_ADD_TEST(TestClassName) suite.add(new Hoopoe::Test::TestClassName);

#define UTEST_END_SUITE \
suite.run(&reporter); \
reporter.printResults(); \

#endif // __HOOPOE_ENGINE_TESTSUITE_H__