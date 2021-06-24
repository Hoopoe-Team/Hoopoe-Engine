#include "FileSystem.h"

namespace Hoopoe
{

DataStreamPtr FileSystem::openFileStream(const String& fullPath, std::ios::openmode mode, const String& name)
{
    struct stat tagStat;
    int ret = stat(fullPath.c_str(), &tagStat);
    size_t st_size = ret == 0 ? tagStat.st_size : 0;

    std::istream* baseStream = 0;
    std::ifstream* roStream = 0;
    std::fstream* rwStream = 0;

    if (mode & std::ios::out)
    {
        rwStream = HE_NEW_T(std::fstream);
        rwStream->open(fullPath.c_str(), mode);

        baseStream = rwStream;
    }
    else
    {
        roStream = HE_NEW_T(std::ifstream);
        roStream->open(fullPath.c_str(), mode);

        baseStream = roStream;
    }


    // Should check ensure open succeeded, in case fail for some reason.
    if (baseStream->fail())
    {
        HE_DELETE(roStream);
        HE_DELETE(rwStream);
        HE_EXCEPT(Exception::ERR_FILE_NOT_FOUND, "Cannot open file: " + fullPath);
    }

    /// Construct return stream, tell it to delete on destroy
    FileStream* stream = 0;
    const String& streamname = name.empty() ? fullPath : name;
    if (rwStream)
    {
        // use the writeable stream
        stream = new FileStream(streamname, rwStream, st_size);
    }
    else
    {
        HE_ASSERT(ret == 0, "Problem getting file size");
        // read-only stream
        stream = new FileStream(streamname, roStream, st_size);
    }

    return DataStreamPtr(stream);
}

} // Hoopoe