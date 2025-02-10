#include "vector3.h"

int test_vector3()
{
    print_testing_section("BGC Vector3");

    if (test_bgc_vector3_reset() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_set_values() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_copy() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_swap() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_is_zero() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
