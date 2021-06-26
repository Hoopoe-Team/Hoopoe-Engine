#include "ConfigFile.h"

namespace Hoopoe
{

ConfigFile::ConfigFile(const String& filename, const String& separators, bool trimWhiteSpace)
{
    load(filename, separators, trimWhiteSpace);
}

void ConfigFile::load(const String& filename, const String& separators, bool trimWhiteSpace)
{
    DataStreamPtr stream = FileSystem::openFileStream(filename, std::ios::in | std::ios::binary);

    String currentSection = HE_BLANK_CONFIG_SECTION;
    SettingsMultiMap* currentSettings = &mSettings[currentSection];

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
                // Sections
                currentSection = line.substr(1, line.length() - 2);
                currentSettings = &mSettings[currentSection];
            }
            else
            {
                String::size_type separator_pos = line.find_first_of(separators, 0);
                if (separator_pos != String::npos)
                {
                    optName = line.substr(0, separator_pos);

                    /* Find the first non-separator character following the name */
                    String::size_type nonseparator_pos = line.find_first_not_of(separators, separator_pos);

                    /* ... and extract the value */
                    /* Make sure we don't crash on an empty setting (it might be a valid value) */
                    optVal = (nonseparator_pos == String::npos) ? "" : line.substr(nonseparator_pos);
                    if (trimWhiteSpace)
                    {
                        Utils::String::trim(optVal);
                        Utils::String::trim(optName);
                    }

                    currentSettings->emplace(optName, optVal);
                }
            }
        }
    }
}

const String& ConfigFile::getSetting(const String& key, const String& section, const String& defaultValue) const
{

    if(section == HE_ALL_CONFIG_SECTIONS) 
    {
        for(const auto &currentSection : mSettings)
        {
            SettingsMultiMap::const_iterator i = currentSection.second.find(key);
            if (i != currentSection.second.end()) 
            {
                return i->second;
            } 
        }

        return defaultValue;
    }
    else
    {
        SettingsBySection::const_iterator seci = mSettings.find(section);
        if (seci == mSettings.end())
        {
            return defaultValue;
        }
        else
        {
            SettingsMultiMap::const_iterator i = seci->second.find(key);
            if (i == seci->second.end()) 
            {
                return defaultValue;
            } 
            else 
            {
                return i->second;
            }
        }
    }
}

const SettingsBySection& ConfigFile::getSettingsBySection()
{
    return mSettings;
}

} // Hoopoe