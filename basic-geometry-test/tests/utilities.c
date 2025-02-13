#include "./utilities.h"

#include "./../helpers.h"

void test_utilities()
{
    print_testing_section("BGC Utilities");

    test_is_zero();
    test_is_unit();
    test_are_close();
}
