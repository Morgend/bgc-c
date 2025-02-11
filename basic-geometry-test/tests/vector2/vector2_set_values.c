#include "./vector2_set_values.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

int test_vector2_set_values_fp32()
{
    BgcVector2FP32 vector;

    print_testing_name("bgc_vector2_set_values_fp32");

    bgc_vector2_set_values_fp32(1.0f, 2.0f, &vector);

    if (vector.x1 != 1.0f || vector.x2 != 2.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector2_set_values_fp32(-3.0f, -5.0f, &vector);

    if (vector.x1 != -3.0f || vector.x2 != -5.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector2_set_values_fp32(-2.0f, 2.0f, &vector);

    if (vector.x1 != -2.0f || vector.x2 != 2.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

int test_vector2_set_values_fp64()
{
    BgcVector2FP64 vector;

    print_testing_name("bgc_vector2_set_values_fp64");


    bgc_vector2_set_values_fp64(1.0, 2.0, &vector);

    if (vector.x1 != 1.0 || vector.x2 != 2.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector2_set_values_fp64(-3.0, -5.0, &vector);

    if (vector.x1 != -3.0 || vector.x2 != -5.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    bgc_vector2_set_values_fp64(-2.0, 2.0, &vector);

    if (vector.x1 != -2.0 || vector.x2 != 2.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_vector2_set_values()
{
    if (test_vector2_set_values_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_vector2_set_values_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
