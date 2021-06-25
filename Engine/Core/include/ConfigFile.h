#ifndef __HOOPOE_ENGINE_CORE_CONFIGFILE_H__
#define __HOOPOE_ENGINE_CORE_CONFIGFILE_H__

#include <map>
#include <fstream>

#include "CoreHeaders.h"
#include "DataStream.h"
#include "FileSystem.h"

namespace Hoopoe
{

typedef std::map<String, String> SettingsMap;

class ConfigFile : public ConfigAlloc
{
public:
    ConfigFile() {}
    ConfigFile(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true);

    void load(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true);
    const String& getSetting(const String& key, const String& defaultValue);
    const SettingsMap& getSettings();

private:
    SettingsMap mSettings;
};

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_CONFIG_H__
