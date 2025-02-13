#include "./quaternion_square_modulus.h"

#include "./../../helpers.h"

void test_quaternion_square_modulus_fp32()
{
    print_testing_name("bgc_quaternion_is_zero_fp32");

    print_testing_success();
}

void test_quaternion_square_modulus_fp64()
{
    print_testing_name("bgc_quaternion_is_zero_fp64");

    print_testing_success();
}

void test_quaternion_square_modulus()
{
    test_quaternion_square_modulus_fp32();
    test_quaternion_square_modulus_fp64();
}
