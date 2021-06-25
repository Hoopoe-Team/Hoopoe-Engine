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
                // TODO: Options by sections
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

                    mSettings.emplace(optName, optVal);
                }
            }
        }
    }
}

const String& ConfigFile::getSetting(const String& key, const String& defaultValue)
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

const SettingsMap& ConfigFile::getSettings()
{
    return mSettings;
}

} // Hoopoe