#include "./complex_copy.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_COMPLEX_AMOUNT = 4;
static const BgcComplexFP32 _TEST_FP32_COMPLEX_LIST[] = {
    { 1.0f, 2.0f },
    { -4.0f, -3.0f },
    { -0.001f, 100.0f },
    { 0.001f, -100.0f }
};

void test_complex_copy_fp32()
{
    BgcComplexFP32 vector;

    print_testing_name("bgc_complex_copy_fp32");

    for (int i = 0; i < _TEST_FP32_COMPLEX_AMOUNT; i++) {

        bgc_complex_copy_fp32(&_TEST_FP32_COMPLEX_LIST[i], &vector);

        if (vector.real != _TEST_FP32_COMPLEX_LIST[i].real ||
            vector.imaginary != _TEST_FP32_COMPLEX_LIST[i].imaginary) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_COMPLEX_AMOUNT = 4;
static const BgcComplexFP64 _TEST_FP64_COMPLEX_LIST[] = {
    { 1.0, 2.0 },
    { -4.0, -3.0 },
    { -0.001, 100.0 },
    { 0.001, -100.0 }
};

void test_complex_copy_fp64()
{
    BgcComplexFP64 vector;

    print_testing_name("bgc_complex_copy_fp64");

    for (int i = 0; i < _TEST_FP64_COMPLEX_AMOUNT; i++) {

        bgc_complex_copy_fp64(&_TEST_FP64_COMPLEX_LIST[i], &vector);

        if (vector.real != _TEST_FP64_COMPLEX_LIST[i].real ||
            vector.imaginary != _TEST_FP64_COMPLEX_LIST[i].imaginary) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_complex_copy()
{
    test_complex_copy_fp32();
    test_complex_copy_fp64();
}
