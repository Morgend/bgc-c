#include "./vector2_reset.h"

#include "./../../helpers.h"

int test_bgc_vector2_reset_fp32()
{
    BgcVector2FP32 vector;

    print_testing_name("bgc_vector2_reset_fp32");

    bgc_vector2_reset_fp32(&vector);

    if (vector.x1 != 0.0f || vector.x2 != 0.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_bgc_vector2_reset_fp64()
{
    BgcVector2FP64 vector;

    print_testing_name("bgc_vector2_reset_fp64");

    bgc_vector2_reset_fp64(&vector);

    if (vector.x1 != 0.0 || vector.x2 != 0.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_bgc_vector2_reset()
{
    if (test_bgc_vector2_reset_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector2_reset_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
