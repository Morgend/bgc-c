#include "./versor.h"

#include "./../helpers.h"

int test_bgc_versor_reset()
{
    if (test_bgc_versor_reset_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_reset_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_versor_set_values()
{
    if (test_bgc_versor_set_values_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_set_values_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_versor_copy()
{
    if (test_bgc_versor_copy_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_copy_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_versor_swap()
{
    if (test_bgc_versor_swap_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_swap_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_versor_are_close()
{
    if (test_bgc_versor_are_close_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_are_close_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_bgc_versor_combine()
{
    if (test_bgc_versor_combine_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_combine_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}

int test_versor()
{
    print_testing_section("BGC Versor");

    if (test_bgc_versor_reset() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_set_values() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_copy() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_swap() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_are_close() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_combine() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
