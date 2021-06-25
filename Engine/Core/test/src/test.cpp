#include "../../../UTest/include/TestSuite.h"
#include "../include/TestConfigFile.h"

int main(int argc, char *argv[]) 
{
    UTEST_BEGIN_SUITE("Core")
        //UTEST_ADD_TEST(TestResourceManager("TestResourceManager"))
        UTEST_ADD_TEST(TestConfigFile("TestConfigFile"))
    UTEST_END_SUITE

    return 0;
}