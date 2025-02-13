#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

void print_testing_section(const char * name)
{
    puts("\n======================================\n");
    puts(name);
}

void print_testing_name(const char * name)
{
    printf("    Testing of %s:    ", name);
}

void print_testing_success()
{
    puts("[ \x1b[32mSuccess\x1b[0m ]");
}

void print_testing_error(const char * message)
{
    printf("[ \x1b[31mFailed\x1b[0m: %s ]\n", message);
    exit(TEST_FAILED);
}

void print_testing_failed()
{
    puts("[ \x1b[31mFailed\x1b[0m ]");
    exit(TEST_FAILED);
}
