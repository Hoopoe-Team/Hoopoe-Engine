#ifndef __HOOPOE_ENGINE_CORE_CONFIGFILE_H__
#define __HOOPOE_ENGINE_CORE_CONFIGFILE_H__

#include <map>
#include <fstream>

#include "CoreHeaders.h"
#include "DataStream.h"
#include "FileSystem.h"

#include "../../Utils/include/String.h"

namespace Hoopoe
{

typedef std::multimap<String, String> SettingsMultiMap;
typedef std::map<String, SettingsMultiMap> SettingsBySection;

class ConfigFile : public ConfigAlloc
{
public:
    #define HE_ALL_CONFIG_SECTIONS "__ALL"
    #define HE_BLANK_CONFIG_SECTION ""

    ConfigFile() {}
    ConfigFile(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true);

    void load(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true);
    const String& getSetting(const String& key, const String& section = HE_ALL_CONFIG_SECTIONS, const String& defaultValue = "") const;
    const SettingsBySection& getSettingsBySection();

private:
    SettingsBySection mSettings;
}; // ConfigFile

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_CONFIGFILE_H__