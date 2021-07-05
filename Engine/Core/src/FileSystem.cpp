#include "FileSystem.h"

#define HOOPOE_MAX_DIR_FILES_REMOVE 64

namespace Hoopoe
{

struct stat FileSystem::pathStat;

DataStreamPtr FileSystem::openFileStream(const String &fullPath, std::ios::openmode mode, const String &name)
{
    int ret = stat(fullPath.c_str(), &pathStat);
    size_t st_size = ret == 0 ? pathStat.st_size : 0;

    std::istream* baseStream = 0;
    std::ifstream* roStream = 0;
    std::fstream* rwStream = 0;

    if (mode &std::ios::out)
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

// Only for UNIX
String FileSystem::getFullPath(const String &path)
{
    return String(FileSystem::getCurrentDirectory() + String("/") + path);
}

bool FileSystem::createFile(const String &fileName)
{
    return creat(fileName.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != -1;
}

bool FileSystem::deleteFile(const String &fileName)
{
    return remove(fileName.c_str()) != -1;
}

bool FileSystem::moveFile(const String &oldPath, const String &newPath)
{
    return rename(oldPath.c_str(), newPath.c_str()) != -1;
}

bool FileSystem::isFile(const String &path)
{
    stat(path.c_str(), &pathStat);

    return S_ISREG(pathStat.st_mode);
}

size_t FileSystem::getFileSize(const String &path)
{
    stat(path.c_str(), &pathStat);

    return pathStat.st_size;
}

bool FileSystem::createFolder(const String &path)
{
    if (stat(path.c_str(), &pathStat) == -1)
        return mkdir(path.c_str(), 0700) != -1;

    return 0;
}

bool FileSystem::deleteEmptyFolder(const String &folderPath)
{
    return rmdir(folderPath.c_str()) != -1;
}

bool FileSystem::deleteFolderContents(const String &folderPath)
{
    auto unlink_cb = [](
            const char *fpath, 
            const struct stat *sb, 
            int typeflag, 
            struct FTW *ftwbuf
        )
    {
        // Do not delete if this is the current directory 
        if(ftwbuf->level == 0 && typeflag == FTW_DP)
            return 0;

        return remove(fpath);
    };


    return nftw(folderPath.c_str(), unlink_cb, HOOPOE_MAX_DIR_FILES_REMOVE, FTW_DEPTH | FTW_PHYS) != -1;
}

bool FileSystem::deleteFolderAndContents(const String &folderPath)
{
    auto unlink_cb = [](
            const char *fpath, 
            const struct stat *sb, 
            int typeflag, 
            struct FTW *ftwbuf
        )
    {
        return remove(fpath);
    };


    return nftw(folderPath.c_str(), unlink_cb, HOOPOE_MAX_DIR_FILES_REMOVE, FTW_DEPTH | FTW_PHYS) != -1;
}

bool FileSystem::moveFolder(const String &oldPath, const String &newPath)
{

    // if(!createFolder(newPath))
    // {
    //     HE_CORE_ERROR(String("Can't create folder " + newPath));
    //     return 0;
    // }

    // auto create_folders = [](
    //         const char *fpath, 
    //         const struct stat *sb, 
    //         int typeflag, 
    //         struct FTW *ftwbuf
    //     )
    // {
    //     // if (stat(fpath, &pathStat) == -1)
    //     //     return mkdir(fpath, 0700);

    //     // return 0;
    //     if(typeflag != FTW_F)
    //         std::cout << fpath << std::endl;
            
    //     return 0;
    // };

    // nftw(oldPath.c_str(), create_folders, HOOPOE_MAX_DIR_FILES_REMOVE, FTW_DEPTH | FTW_PHYS) != -1;
    
    //HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "This code doesn't implemented.", "FileSystem::moveFolder");

    return 0;
}

bool FileSystem::copyFolder(const String &oldPath, const String &newPath)
{
    //HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "This code doesn't implemented.", "FileSystem::copyFolder");

    return 0;
}

bool FileSystem::isFolder(const String &path)
{
    stat(path.c_str(), &pathStat);

    return S_ISDIR(pathStat.st_mode);
}

String FileSystem::getCurrentDirectory()
{
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        return String(cwd);
    }

    HE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot get current directory", "FileSystem::getCurrentDirectory()");
}

} // Hoopoe