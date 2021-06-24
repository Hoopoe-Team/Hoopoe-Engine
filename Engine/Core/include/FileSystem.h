#ifndef __HOOPOE_ENGINE_CORE_FILESYSTEM_H__
#define __HOOPOE_ENGINE_CORE_FILESYSTEM_H__

#include <fstream>
#include <dirent.h>
#include <sys/stat.h>

#include "CoreHeaders.h"
#include "DataStream.h"

namespace Hoopoe
{

class FileSystem : public FileSystemAlloc
{
public:
    static DataStreamPtr openFileStream(const String& path, std::ios::openmode mode, const String& name = "");

}; // FileSystem

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_FILESYSTEM_H__