#include "./vector3_reset.h"

#include "./../../helpers.h"

int test_vector3_reset_fp32()
{
    BgcVector3FP32 vector;

    print_testing_name("bgc_vector3_reset_fp32");

    bgc_vector3_reset_fp32(&vector);

    if (vector.x1 != 0.0f || vector.x2 != 0.0f || vector.x3 != 0.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_vector3_reset_fp64()
{
    BgcVector3FP64 vector;

    print_testing_name("bgc_vector3_reset_fp64");

    bgc_vector3_reset_fp64(&vector);

    if (vector.x1 != 0.0 || vector.x2 != 0.0 || vector.x3 != 0.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_vector3_reset()
{
    if (test_vector3_reset_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_vector3_reset_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
