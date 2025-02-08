#include "vector3.h"

int test_bgc_vector3_reset()
{
    if (test_bgc_vector3_reset_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_reset_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_vector3_set_values()
{
    if (test_bgc_vector3_set_values_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_set_values_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_vector3_copy()
{
    if (test_bgc_vector3_copy_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_copy_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_vector3_swap()
{
    if (test_bgc_vector3_swap_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector3_swap_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

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

    return TEST_SUCCES;
}
