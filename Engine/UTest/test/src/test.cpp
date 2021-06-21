#include "../../include/TestSuite.h"
#include "TestUTest.cpp"

int main(int argc, char *argv[]) 
{
    UTEST_BEGIN_SUITE
        UTEST_ADD_TEST(TestUTest("TestUTest"))
    UTEST_END_SUITE

    return 0;
}