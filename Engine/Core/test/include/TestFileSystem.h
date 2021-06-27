#ifndef __HOOPOE_ENGINE_CORE_TEST_FILESYSTEM_H__
#define __HOOPOE_ENGINE_CORE_TEST_FILESYSTEM_H__

#include "../../include/FileSystem.h"
#include "../../../UTest/include/TestBase.h"

namespace Hoopoe { namespace Test {

class TestFileSystem : public TestBase
{
public:
    TestFileSystem(const String name) : TestBase(name) {}
    ~TestFileSystem() {}

    void run() override;

private:
    void testCreateFile();
    void testDeleteFile();
    void testMoveFile();
    void testIsFile();
    void testGetFileSize();
    void testCreateFolder();
    void testDeleteEmptyFolder();
    void testDeleteFolderContents();
    void testDeleteFolderAndContents();
    void testMoveFolder();
    void testCopyFolder();
    void testIsFolder();
    void testGetCurrentDirectory();
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_TEST_FILESYSTEM_H__