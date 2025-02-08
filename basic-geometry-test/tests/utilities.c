#include "./utilities.h"

#include "./../helpers.h"

int test_bgc_is_zero()
{
    if (test_bgc_is_zero_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_is_zero_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_is_unit()
{
    if (test_bgc_is_unit_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_is_unit_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_is_sqare_value_unit_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_is_sqare_value_unit_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_are_close()
{
    if (test_bgc_are_close_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_are_close_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_utilities()
{
    print_testing_section("BGC Utilities");

    if (test_bgc_is_zero() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_is_unit() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_are_close() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}