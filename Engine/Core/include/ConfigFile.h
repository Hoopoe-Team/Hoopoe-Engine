#ifndef __HOOPOE_ENGINE_CORE_CONFIGFILE_H__
#define __HOOPOE_ENGINE_CORE_CONFIGFILE_H__

#include <map>
#include <fstream>

#include "CoreHeaders.h"
#include "DataStream.h"
#include "FileSystem.h"
#include "ResourceManager.h"

namespace Hoopoe
{

typedef std::map<String, String> SettingsMap;

class ConfigFile : public ConfigAlloc
{
public:
    ConfigFile();

    void load(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true)
    {
        
        DataStreamPtr stream = FileSystem::openFileStream(filename, std::ios::in | std::ios::binary), separators, trimWhitespace);

        /* Process the file line for line */
        String line, optName, optVal;
        while (!stream->eof())
        {
            line = stream->getLine();

            /* Ignore comments & blanks */
            if (line.length() > 0 && line.at(0) != '#' && line.at(0) != '@')
            {
                if (line.at(0) == '[' && line.at(line.length()-1) == ']')
                {
                    // Section
                }
                else
                {

                }
            }
        }
    }

    const String& getSetting(const String& key, const String& defaultValue)
    {
        SettingsMap::const_iterator i = mSettings.find(key);
        if (i == mSettings.end()) 
        {
            return defaultValue;
        } 
        else 
        {
            return i->second;
        }
    }

    const SettingsMap& getSettings()
    {
        return mSettings;
    }

private:
    SettingsMap mSettings;

};

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_CONFIG_H__

/*

    option1    := value1
    option2    := value2
    option3    := value3

*/