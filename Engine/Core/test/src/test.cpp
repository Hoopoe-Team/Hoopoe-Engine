#include "../../../UTest/include/TestSuite.h"
#include "TestResourceManager.cpp"

int main(int argc, char *argv[]) 
{
    UTEST_BEGIN_SUITE("Core")
        UTEST_ADD_TEST(TestResourceManager("TestResourceManager"))
    UTEST_END_SUITE

    return 0;
}