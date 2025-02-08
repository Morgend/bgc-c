#ifndef __GEOMETRY_TEST_H__
#define __GEOMETRY_TEST_H__

#include <basic-geometry.h>

#define TEST_SUCCES 0
#define TEST_FAILED -1

void print_testing_section(const char * name);

void print_testing_name(const char * name);

void print_testing_success();

void print_testing_failed();

void print_testing_warning(const char* message);

#endif
