#include "./vector3_set_values.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

int test_bgc_vector3_set_values_fp32()
{
    BgcVector3FP32 vector;

    print_testing_name("bgc_vector3_set_values_fp32");

    bgc_vector3_set_values_fp32(1.0f, 2.0f, 3.0f, &vector);

    if (vector.x1 != 1.0f || vector.x2 != 2.0f || vector.x3 != 3.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector3_set_values_fp32(-3.0f, -5.0f, -7.0f, &vector);

    if (vector.x1 != -3.0f || vector.x2 != -5.0f || vector.x3 != -7.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector3_set_values_fp32(-2.0f, 2.0f, 4.0f, &vector);

    if (vector.x1 != -2.0f || vector.x2 != 2.0f || vector.x3 != 4.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

int test_bgc_vector3_set_values_fp64()
{
    BgcVector3FP64 vector;

    print_testing_name("bgc_vector3_set_values_fp64");


    bgc_vector3_set_values_fp64(1.0, 2.0, 3.0, &vector);

    if (vector.x1 != 1.0 || vector.x2 != 2.0 || vector.x3 != 3.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector3_set_values_fp64(-3.0, -5.0, -7.0, &vector);

    if (vector.x1 != -3.0 || vector.x2 != -5.0 || vector.x3 != -7.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector3_set_values_fp64(-2.0, 2.0, 4.0, &vector);

    if (vector.x1 != -2.0 || vector.x2 != 2.0 || vector.x3 != 4.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

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
