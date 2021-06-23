#ifndef __HOOPOE_ENGINE_UTEST_TESTBASE_H__
#define __HOOPOE_ENGINE_UTEST_TESTBASE_H__

#include "../../include/TestBase.h"

namespace Hoopoe { namespace Test {

class TestUTest : public TestBase
{
public:
    TestUTest(const String name) : TestBase(name) {}
    ~TestUTest() {}

    void run() override 
    {
        test1();
        test2();
    }

private:
    void test1() 
    {
        UTEST_ASSERT(2 * 2 == 5);
    }

    void test2() 
    {
        UTEST_ASSERT(2 * 2 == 4);
    }

};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_UTEST_TESTBASE_H__