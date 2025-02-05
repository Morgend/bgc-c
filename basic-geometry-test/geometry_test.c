#include "geometry_test.h"

#include <stdio.h>

void print_test_section(const char * name)
{
    printf("================ %s ================\n", name);
}

void print_test_name(const char * name)
{
    printf("    Testing of %s:    ", name);
}

void print_test_success()
{
    printf("[ \x1b[32mSuccess\x1b[0m ]\n");
}

void print_test_failed()
{
    printf("[ \x1b[31mFailed\x1b[0m ]\n");
}
