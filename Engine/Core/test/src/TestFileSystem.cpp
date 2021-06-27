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
    UTEST_ASSERT(FileSystem::createFile(FileSystem::getFullPath("utests/resources/testCreateFile")));
}

void TestFileSystem::testDeleteFile()
{
    UTEST_ASSERT(FileSystem::deleteFile(FileSystem::getFullPath("utests/resources/testDeleteFile")));
}

void TestFileSystem::testMoveFile()
{
    UTEST_ASSERT(FileSystem::moveFile(FileSystem::getFullPath("utests/resources/dir1/testMoveFile"), FileSystem::getFullPath("utests/resources/dir2/testMoveFile")));
}

void TestFileSystem::testIsFile()
{
    UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("utests/resources/testIsFile")));
}

void TestFileSystem::testGetFileSize()
{
    UTEST_ASSERT(FileSystem::getFileSize(FileSystem::getFullPath("utests/resources/testGetFileSize")) == 9);
}

void TestFileSystem::testCreateFolder()
{
    UTEST_ASSERT(FileSystem::createFolder(FileSystem::getFullPath("utests/resources/testCreateFolder")));
}

void TestFileSystem::testDeleteEmptyFolder()
{
    UTEST_ASSERT(FileSystem::deleteEmptyFolder(FileSystem::getFullPath("utests/resources/testDeleteEmptyFolder")));
}

void TestFileSystem::testDeleteFolderContents()
{
    UTEST_ASSERT(FileSystem::deleteFolderContents(FileSystem::getFullPath("utests/resources/tesDelDirWithContents")));
}

void TestFileSystem::testDeleteFolderAndContents()
{
    UTEST_ASSERT(FileSystem::deleteFolderAndContents(FileSystem::getFullPath("utests/resources/testDelDirAndContents")));
}

void TestFileSystem::testMoveFolder()
{
    UTEST_ASSERT(FileSystem::moveFolder(FileSystem::getFullPath("utests/resources/dir1/dir3"), FileSystem::getFullPath("utests/resources/dir2/dir3")));
}

void TestFileSystem::testCopyFolder()
{
    UTEST_ASSERT(FileSystem::copyFolder(FileSystem::getFullPath("utests/resources/dir1"), FileSystem::getFullPath("utests/resources/dir4")));
}

void TestFileSystem::testIsFolder()
{
    UTEST_ASSERT(FileSystem::isFolder(FileSystem::getFullPath("utests/resources/dir1")));
}

void TestFileSystem::testGetCurrentDirectory()
{
    UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("utests/resources/testGetStringDir")));
}

} // Test
} // Hoopoe