#include <stdio.h>

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
    printf("[ \x1b[32mSuccess\x1b[0m ]\n");
}

void print_testing_failed()
{
    printf("[ \x1b[31mFailed\x1b[0m ]\n");
}

void print_testing_warning(const char * message)
{
    printf("    Warning: \x1b[30m%s\x1b[0m\n", message);
}
