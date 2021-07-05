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
    UTEST_ASSERT(FileSystem::createFile(FileSystem::getFullPath("utests/resources/TestFileSystem/testCreateFile")));
}

void TestFileSystem::testDeleteFile()
{
    UTEST_ASSERT(FileSystem::deleteFile(FileSystem::getFullPath("utests/resources/TestFileSystem/testDeleteFile")));
}

void TestFileSystem::testMoveFile()
{
    UTEST_ASSERT(FileSystem::moveFile(FileSystem::getFullPath("utests/resources/TestFileSystem/dir1/testMoveFile"), FileSystem::getFullPath("utests/resources/TestFileSystem/dir2/testMoveFile")));
}

void TestFileSystem::testIsFile()
{
    UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("utests/resources/TestFileSystem/testIsFile")));
}

void TestFileSystem::testGetFileSize()
{
    UTEST_ASSERT(FileSystem::getFileSize(FileSystem::getFullPath("utests/resources/TestFileSystem/testGetFileSize")) == 9);
}

void TestFileSystem::testCreateFolder()
{
    UTEST_ASSERT(FileSystem::createFolder(FileSystem::getFullPath("utests/resources/TestFileSystem/testCreateFolder")));
}

void TestFileSystem::testDeleteEmptyFolder()
{
    UTEST_ASSERT(FileSystem::deleteEmptyFolder(FileSystem::getFullPath("utests/resources/TestFileSystem/testDeleteEmptyFolder")));
}

void TestFileSystem::testDeleteFolderContents()
{
    UTEST_ASSERT(FileSystem::deleteFolderContents(FileSystem::getFullPath("utests/resources/TestFileSystem/testDelDirContents")));
}

void TestFileSystem::testDeleteFolderAndContents()
{
    UTEST_ASSERT(FileSystem::deleteFolderAndContents(FileSystem::getFullPath("utests/resources/TestFileSystem/testDelDirAndContents")));
}

void TestFileSystem::testMoveFolder()
{
    UTEST_ASSERT(FileSystem::moveFolder(FileSystem::getFullPath("utests/resources/TestFileSystem/dir1/dir3"), FileSystem::getFullPath("utests/resources/TestFileSystem/dir2/dir3")));
}

void TestFileSystem::testCopyFolder()
{
    UTEST_ASSERT(FileSystem::copyFolder(FileSystem::getFullPath("utests/resources/TestFileSystem/dir1"), FileSystem::getFullPath("utests/resources/TestFileSystem/dir4")));
}

void TestFileSystem::testIsFolder()
{
    UTEST_ASSERT(FileSystem::isFolder(FileSystem::getFullPath("utests/resources/TestFileSystem/dir1")));
}

void TestFileSystem::testGetCurrentDirectory()
{
    UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("utests/resources/TestFileSystem/testGetStringDir")));
}

} // Test
} // Hoopoe