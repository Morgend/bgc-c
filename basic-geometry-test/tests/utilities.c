#include "./utilities.h"

#include "./../helpers.h"

int test_utilities()
{
    print_testing_section("BGC Utilities");

    if (test_is_zero() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_is_unit() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_are_close() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}