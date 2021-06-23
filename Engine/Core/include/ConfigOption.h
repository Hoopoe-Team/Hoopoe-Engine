#ifndef __HOOPOE_ENGINE_CORE_CONFIG_H__
#define __HOOPOE_ENGINE_CORE_CONFIG_H__

#include <map>

#include "Types.h"

namespace Hoopoe
{

    struct ConfigOption
    {
        String name;
        String value;
        String defautValue;
    };

    typedef std::map<String, ConfigOption> ConfigOptionMap;

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_CONFIG_H__