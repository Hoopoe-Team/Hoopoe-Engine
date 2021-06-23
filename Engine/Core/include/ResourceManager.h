#ifndef __HOOPOE_ENGINE_CORE_RESOURCEMANAGER_H__
#define __HOOPOE_ENGINE_CORE_RESOURCEMANAGER_H__

#include "Exception.h"

#include <fstream>

namespace Hoopoe
{

// some shit. TODO: replace to custom DataStream type;
typedef std::ifstream DataStream;

class ResourceManager 
{
public:
    ResourceManager();
    ~ResourceManager();

    static DataStream getFileReadStream(const String &filepath)
    {
        std::ifstream fileStream(filepath);

        if(fileStream.is_open()) {
            return fileStream;
        } else {
            HE_EXCEPT(Hoopoe::Exception::ERR_FILE_NOT_FOUND, String("Failed to open ") + filepath, "static DataStreamPtr getFileReadStream(const String &filepath)");
        }
    }

    static String syncFileRead(const String &filepath)
    {
        DataStream fileStream = getFileReadStream(filepath);

        fileStream.seekg(0, fileStream.end);
        int length = fileStream.tellg();
        fileStream.seekg(0, fileStream.beg);

        char* buffer = new char[length + 1];
        buffer[length] = '\0';

        fileStream.read(buffer, length);

        return String(buffer);
    }

    static void syncFileWrite(const String &filepath)
    {
        HE_EXCEPT(Hoopoe::Exception::ERR_NOT_IMPLEMENTED, "sync file read does not implemented", "static void syncFileWrite(const String &filepath)");
    }

    static String asyncFileRead(const String &filepath)
    {
        HE_EXCEPT(Hoopoe::Exception::ERR_NOT_IMPLEMENTED, "async file read does not implemented", "static String asyncFileRead(const String &filepath)");
    }

    static void asyncFileWrite(const String &filepath)
    {
        HE_EXCEPT(Hoopoe::Exception::ERR_NOT_IMPLEMENTED, "async file write does not implemented", "static void asyncFileWrite(const String &filepath)");
    }

private:

};

}

#endif