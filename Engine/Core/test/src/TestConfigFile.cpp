#include "../include/TestConfigFile.h"

namespace Hoopoe { namespace Test {

void TestConfigFile::run()
{
    testConfig1();
    testConfig2();
    testConfig3();
}

void TestConfigFile::testConfig1() 
{
    ConfigFile testCfg;
    testCfg.load("utests/resources/TestConfigFile.cfg");

    UTEST_ASSERT(testCfg.getSetting("option1", "NULL") == "1");
}

void TestConfigFile::testConfig2() 
{
    ConfigFile testCfg;
    testCfg.load("utests/resources/TestConfigFile.cfg");

    UTEST_ASSERT(testCfg.getSetting("option2", "NULL") == "2");
}

void TestConfigFile::testConfig3() 
{
    ConfigFile testCfg;
    testCfg.load("utests/resources/TestConfigFile.cfg");

    UTEST_ASSERT(testCfg.getSetting("option3", "NULL") == "3");
}

} // Test
} // Hoopoe