#include "quaternion.h"

int test_quaternion()
{
    print_testing_section("BGC Quaternion");

    if (test_bgc_quaternion_reset() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_quaternion_set_to_identity() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_quaternion_set_values() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_quaternion_copy() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_quaternion_swap() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
