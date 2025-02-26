#include "./complex_set_values.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

void test_complex_set_values_fp32()
{
    BgcComplexFP32 vector;

    print_testing_name("bgc_complex_set_values_fp32");

    bgc_complex_set_values_fp32(1.0f, 2.0f, &vector);

    if (vector.real != 1.0f || vector.imaginary != 2.0f) {
        print_testing_error("First step failed");
        return;
    }

    bgc_complex_set_values_fp32(-1.0f, -3.0f, &vector);

    if (vector.real != -1.0f || vector.imaginary != -3.0f) {
        print_testing_error("Second step failed");
        return;
    }

    bgc_complex_set_values_fp32(-8.0f, -2.0f, &vector);

    if (vector.real != -8.0f || vector.imaginary != -2.0f) {
        print_testing_error("Third step failed");
        return;
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

void test_complex_set_values_fp64()
{
    BgcComplexFP64 vector;

    print_testing_name("bgc_complex_set_values_fp64");

    bgc_complex_set_values_fp64(1.0, 2.0, &vector);

    if (vector.real != 1.0 || vector.imaginary != 2.0) {
        print_testing_error("First step failed");
        return;
    }

    bgc_complex_set_values_fp64(-1.0, -3.0, &vector);

    if (vector.real != -1.0 || vector.imaginary != -3.0) {
        print_testing_error("Second step failed");
        return;
    }

    bgc_complex_set_values_fp64(-8.0, -2.0, &vector);

    if (vector.real != -8.0 || vector.imaginary != -2.0) {
        print_testing_error("Third step failed");
        return;
    }

    print_testing_success();
}

void test_complex_set_values()
{
    test_complex_set_values_fp32();
    test_complex_set_values_fp64();
}
