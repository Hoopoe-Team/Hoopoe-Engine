#ifndef __HOOPOE_ENGINE_CORE_TEST_RESOURCEMANAGER_H__
#define __HOOPOE_ENGINE_CORE_TEST_RESOURCEMANAGER_H__

#include "../../include/ResourceManager.h"
#include "../../../UTest/include/TestBase.h"

namespace Hoopoe { namespace Test {

class TestResourceManager : public TestBase
{
public:
    TestResourceManager(const String name) : TestBase(name) {}
    ~TestResourceManager() {}

    void run() override 
    {
        testFileInput();
    }

private:
    void testFileInput() 
    {
        String testString1 = "This is the test string!\nSecond line of the test string!\nEnd of test string";
        String testString2 = ResourceManager::syncFileRead("utests/resources/TestResourceManager.txt");

        UTEST_ASSERT(testString1 == testString2);
    }

};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_TEST_RESOURCEMANAGER_H__