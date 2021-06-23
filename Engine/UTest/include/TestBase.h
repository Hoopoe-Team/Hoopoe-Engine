#ifndef __HOOPOE_ENGINE_TESTBASE_H__
#define __HOOPOE_ENGINE_TESTBASE_H__

#include <list>

#include "../../Core/include/LogManager.h"

#define UTEST_ASSERT(x) \
    String message = \
        String("\t - [") + this->getName() + String("]: ") + \
        String(__func__) + String(" --- ") + \
        ((x) ? String("PASSED.") : String("NOT PASSED!")) \
    ; \
    \
    if(x) { \
        HE_CORE_INFO(message); \
    } else { \
        HE_CORE_CRITICAL(message); \
    } \

namespace Hoopoe { namespace Test {

class TestBase 
{
public:
    TestBase(const String name) : name(name) {}
    virtual ~TestBase() {}

    virtual void run() = 0;
    virtual String getName() { return this->name; };

protected:
    String name;
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_TESTBASE_H__