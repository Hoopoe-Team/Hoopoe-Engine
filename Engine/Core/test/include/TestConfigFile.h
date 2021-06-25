#ifndef __HOOPOE_ENGINE_CORE_TEST_CONFIGFILE_H__
#define __HOOPOE_ENGINE_CORE_TEST_CONFIGFILE_H__

#include "../../include/ConfigFile.h"
#include "../../../UTest/include/TestBase.h"

namespace Hoopoe { namespace Test {

class TestConfigFile : public TestBase
{
public:
    TestConfigFile(const String name) : TestBase(name) {}
    ~TestConfigFile() {}

    void run() override;

private:
    void testConfig1();
    void testConfig2();
    void testConfig3();
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_TEST_CONFIGFILE_H__