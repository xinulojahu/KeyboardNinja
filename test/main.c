#define CTEST_MAIN
#include "ctest.h"
#include <stdio.h>

int main(int argc, const char* argv[])
{
    int result = ctest_main(argc, argv);
    printf("End of tests!\n");
    return result;
}
