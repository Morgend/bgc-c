#include "./complex_reset.h"

#include "./../../helpers.h"

void test_complex_reset_fp32()
{
    BgcComplexFP32 vector;

    print_testing_name("bgc_complex_reset_fp32");

    bgc_complex_reset_fp32(&vector);

    if (vector.real != 0.0f || vector.imaginary != 0.0f) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_complex_reset_fp64()
{
    BgcComplexFP64 vector;

    print_testing_name("bgc_complex_reset_fp64");

    bgc_complex_reset_fp64(&vector);

    if (vector.real != 0.0 || vector.imaginary != 0.0) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_complex_reset()
{
    test_complex_reset_fp32();
    test_complex_reset_fp64();
}
