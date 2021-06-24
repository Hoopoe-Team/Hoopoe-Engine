#ifndef __HOOPOE_ENGINE_CORE_STRINGUTIL_H__
#define __HOOPOE_ENGINE_CORE_STRINGUTIL_H__

#include "Types.h"
#include <cstring>

namespace Hoopoe
{

class StringUtil
{
public:
    static void trim(String& str, bool left = true, bool right = true);
}; // StringUtil

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_STRINGUTIL_H__