#include "./versor.h"

#include "./../helpers.h"

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
