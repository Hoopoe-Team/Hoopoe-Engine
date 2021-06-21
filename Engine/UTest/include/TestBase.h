#ifndef __HOOPOE_ENGINE_TESTBASE_H__
#define __HOOPOE_ENGINE_TESTBASE_H__

#include <list>
#include <string>

#include "../../Core/include/LogManager.h"

#define UTEST_ASSERT(x) \
    std::string message = \
        std::string("\t - [") + this->getName() + std::string("]: ") + \
        std::string(__func__) + std::string(" --- ") + \
        ((x) ? std::string("PASSED.") : std::string("NOT PASSED!")) \
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
    TestBase(const std::string name) : name(name) {}
    virtual ~TestBase() {}

    virtual void run() = 0;
    virtual std::string getName() { return this->name; };

protected:
    std::string name;
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_TESTBASE_H__