#include "FileSystem.h"

#define HOOPOE_MAX_DIR_FILES_REMOVE 64

namespace Hoopoe
{

DataStreamPtr FileSystem::openFileStream(const String &fullPath, std::ios::openmode mode, const String &name)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::getFullPath(const String &path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::createFile(const String &fileName)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteFile(const String &fileName)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::moveFile(const String &oldPath, const String &newPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");1;
}

bool FileSystem::isFile(const String &path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

size_t FileSystem::getFileSize(const String &path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::createFolder(const String &path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteEmptyFolder(const String &folderPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteFolderContents(const String &folderPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteFolderAndContents(const String &folderPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::isFolder(const String &path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::getCurrentDirectory()
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

} // Hoopoe