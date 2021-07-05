#include "../include/TestFileSystem.h"

namespace Hoopoe { namespace Test {

void TestFileSystem::run()
{
    testCreateFile();
    testDeleteFile();
    testMoveFile();
    testIsFile();
    testGetFileSize();
    testCreateFolder();
    testDeleteEmptyFolder();
    testDeleteFolderContents();
    testDeleteFolderAndContents();
    testMoveFolder();
    testCopyFolder();
    testIsFolder();
    testGetCurrentDirectory();
}

void TestFileSystem::testCreateFile()
{
    UTEST_ASSERT(FileSystem::createFile(FileSystem::getFullPath("resources/TestFileSystem/testCreateFile")));
}

void TestFileSystem::testDeleteFile()
{
    UTEST_ASSERT(FileSystem::deleteFile(FileSystem::getFullPath("resources/TestFileSystem/testDeleteFile")));
}

void TestFileSystem::testMoveFile()
{
    UTEST_ASSERT(FileSystem::moveFile(FileSystem::getFullPath("resources/TestFileSystem/dir1/testMoveFile"), FileSystem::getFullPath("resources/TestFileSystem/dir2/testMoveFile")));
}

void TestFileSystem::testIsFile()
{
    UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("resources/TestFileSystem/testIsFile")));
}

void TestFileSystem::testGetFileSize()
{
    UTEST_ASSERT(FileSystem::getFileSize(FileSystem::getFullPath("resources/TestFileSystem/testGetFileSize")) == 9);
}

void TestFileSystem::testCreateFolder()
{
    UTEST_ASSERT(FileSystem::createFolder(FileSystem::getFullPath("resources/TestFileSystem/testCreateFolder")));
}

void TestFileSystem::testDeleteEmptyFolder()
{
    UTEST_ASSERT(FileSystem::deleteEmptyFolder(FileSystem::getFullPath("resources/TestFileSystem/testDeleteEmptyFolder")));
}

void TestFileSystem::testDeleteFolderContents()
{
    UTEST_ASSERT(FileSystem::deleteFolderContents(FileSystem::getFullPath("resources/TestFileSystem/testDelDirContents")));
}

void TestFileSystem::testDeleteFolderAndContents()
{
    UTEST_ASSERT(FileSystem::deleteFolderAndContents(FileSystem::getFullPath("resources/TestFileSystem/testDelDirAndContents")));
}

void TestFileSystem::testMoveFolder()
{
    UTEST_ASSERT(FileSystem::moveFolder(FileSystem::getFullPath("resources/TestFileSystem/dir1/dir3"), FileSystem::getFullPath("resources/TestFileSystem/dir2/dir3")));
}

void TestFileSystem::testCopyFolder()
{
    UTEST_ASSERT(FileSystem::copyFolder(FileSystem::getFullPath("resources/TestFileSystem/dir1"), FileSystem::getFullPath("resources/TestFileSystem/dir4")));
}

void TestFileSystem::testIsFolder()
{
    UTEST_ASSERT(FileSystem::isFolder(FileSystem::getFullPath("resources/TestFileSystem/dir1")));
}

void TestFileSystem::testGetCurrentDirectory()
{
    UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("resources/TestFileSystem/testGetStringDir")));
}

} // Test
} // Hoopoe