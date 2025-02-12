#include "./quaternion_square_modulus.h"

#include "./../../helpers.h"

int test_quaternion_square_modulus_fp32()
{
    print_testing_name("bgc_quaternion_is_zero_fp32");

    print_testing_success();

    return TEST_SUCCES;
}

int test_quaternion_square_modulus_fp64()
{
    print_testing_name("bgc_quaternion_is_zero_fp64");

    print_testing_success();

    return TEST_SUCCES;
}

int test_quaternion_square_modulus()
{
    if (test_quaternion_square_modulus_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_quaternion_square_modulus_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
