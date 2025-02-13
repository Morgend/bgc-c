#include "./vector2_set_values.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

void test_vector2_set_values_fp32()
{
    BgcVector2FP32 vector;

    print_testing_name("bgc_vector2_set_values_fp32");

    bgc_vector2_set_values_fp32(1.0f, 2.0f, &vector);

    if (vector.x1 != 1.0f || vector.x2 != 2.0f) {
        print_testing_error("First step failed");
        return;
    }

    bgc_vector2_set_values_fp32(-3.0f, -5.0f, &vector);

    if (vector.x1 != -3.0f || vector.x2 != -5.0f) {
        print_testing_error("Second step failed");
        return;
    }

    bgc_vector2_set_values_fp32(-2.0f, 2.0f, &vector);

    if (vector.x1 != -2.0f || vector.x2 != 2.0f) {
        print_testing_error("Third step failed");
        return;
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

void test_vector2_set_values_fp64()
{
    BgcVector2FP64 vector;

    print_testing_name("bgc_vector2_set_values_fp64");


    bgc_vector2_set_values_fp64(1.0, 2.0, &vector);

    if (vector.x1 != 1.0 || vector.x2 != 2.0) {
        print_testing_error("First step failed");
        return;
    }

    bgc_vector2_set_values_fp64(-3.0, -5.0, &vector);

    if (vector.x1 != -3.0 || vector.x2 != -5.0) {
        print_testing_error("Second step failed");
        return;
    }

    bgc_vector2_set_values_fp64(-2.0, 2.0, &vector);

    if (vector.x1 != -2.0 || vector.x2 != 2.0) {
        print_testing_error("Third step failed");
        return;
    }

    print_testing_success();
}

void test_vector2_set_values()
{
    test_vector2_set_values_fp32();
    test_vector2_set_values_fp64();
}
