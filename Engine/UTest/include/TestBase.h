#ifndef __HOOPOE_ENGINE_TESTBASE_H__
#define __HOOPOE_ENGINE_TESTBASE_H__

#include "../../Core/include/LogManager.h"

#include "TestReporter.h"

#define UTEST_ASSERT(x) \
    if(x) { \
        reporter->saveResult(this->getName(), __func__, true); \
    } else { \
        reporter->saveResult(this->getName(), __func__, false); \
    } \

namespace Hoopoe { namespace Test {

class TestBase 
{
public:
    TestBase(const String name) : name(name) {}
    virtual ~TestBase() {}

    virtual void run() = 0;
    virtual void setReporter(TestReporter *reporter) { this->reporter = reporter; }
    virtual String getName() { return this->name; };

protected:
    String name;
    TestReporter *reporter;
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_TESTBASE_H__