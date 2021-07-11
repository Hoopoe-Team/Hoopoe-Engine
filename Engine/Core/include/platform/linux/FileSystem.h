#include <fstream>
#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ftw.h>

#include "DataStream.h"

namespace Hoopoe
{

class FileSystem
{
public:
    // Files
    static DataStreamPtr openFileStream(const String &path, std::ios::openmode mode, const String &name = "");
    
    static bool createFile(const String &fileName);   
    static bool deleteFile(const String &fileName);
    static bool moveFile(const String &oldPath, const String &newPath);
    static bool isFile(const String &path);
    static size_t getFileSize(const String &path);

    // Folders
    static String getFullPath(const String &path);
    static bool createFolder(const String &path);
    static bool deleteEmptyFolder(const String &folderPath);
    static bool deleteFolderContents(const String &folderPath);
    static bool deleteFolderAndContents(const String &folderPath);
    static bool isFolder(const String &path);
    static String getCurrentDirectory();

private:
    static struct stat pathStat;
}; // FileSystem

} // Hoopoe