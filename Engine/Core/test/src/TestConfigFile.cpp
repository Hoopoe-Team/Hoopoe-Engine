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
    testCfg.load("utests/resources/TestConfigFile/TestConfigFile.cfg");

    UTEST_ASSERT(testCfg.getSetting("option1", HE_BLANK_CONFIG_SECTION, "1") == "1");
}

void TestConfigFile::testConfig2() 
{
    ConfigFile testCfg;
    testCfg.load("utests/resources/TestConfigFile/TestConfigFile.cfg");

    UTEST_ASSERT(testCfg.getSetting("option2", HE_ALL_CONFIG_SECTIONS, "NULL") == "2");
}

void TestConfigFile::testConfig3() 
{
    ConfigFile testCfg;
    testCfg.load("utests/resources/TestConfigFile/TestConfigFile.cfg");

    UTEST_ASSERT(testCfg.getSetting("option3", "Section 2", "NULL") == "3");
}

} // Test
} // Hoopoe