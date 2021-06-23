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
    void run();
    String getName();

private:
    String name;
    std::list<TestBase *> tests;
};

} // Test
} // Hoopoe

#define UTEST_BEGIN_SUITE(suiteName) \
Hoopoe::LogManager::Init(); \
Hoopoe::LogManager::setPattern("%v%$"); \
HE_CORE_TRACE(Hoopoe::String(suiteName) + Hoopoe::String(": ")); \
Hoopoe::Test::TestSuite suite; \

#define UTEST_ADD_TEST(TestClassName) suite.add(new Hoopoe::Test::TestClassName);

#define UTEST_END_SUITE suite.run(); 

#endif