#include "./complex_swap.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_COMPLEX_AMOUNT = 4;

static const BgcComplexFP32 _TEST_FP32_COMPLEX_LIST1[] = {
    { 3.0f, 4.0f },
    { -2.0f, -1.0f },
    { -244.8f, 100.0f },
    { 1000.32f, -100.1f }
};

static const BgcComplexFP32 _TEST_FP32_COMPLEX_LIST2[] = {
    { 5.3f, 1003.28f },
    { -0.0032f, 891.3f },
    { 5.322f, 0.9275f },
    { 1000.0f, -0.00025f }
};

void test_complex_swap_fp32()
{
    BgcComplexFP32 compleimaginary, complex2;

    print_testing_name("bgc_complex_swap_fp32");

    for (int i = 0; i < _TEST_FP32_COMPLEX_AMOUNT; i++) {
        bgc_complex_copy_fp32(&_TEST_FP32_COMPLEX_LIST1[i], &compleimaginary);
        bgc_complex_copy_fp32(&_TEST_FP32_COMPLEX_LIST2[i], &complex2);

        bgc_complex_swap_fp32(&compleimaginary, &complex2);

        if (compleimaginary.real != _TEST_FP32_COMPLEX_LIST2[i].real ||
            compleimaginary.imaginary != _TEST_FP32_COMPLEX_LIST2[i].imaginary ||
            complex2.real != _TEST_FP32_COMPLEX_LIST1[i].real ||
            complex2.imaginary != _TEST_FP32_COMPLEX_LIST1[i].imaginary) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_COMPLEX_AMOUNT = 4;

static const BgcComplexFP64 _TEST_FP64_COMPLEX_LIST1[] = {
    { 1.0, 4.0 },
    { -4.0, -3.0 },
    { -244.8, 344.7 },
    { 1000.32, -271.3 }
};

static const BgcComplexFP64 _TEST_FP64_COMPLEX_LIST2[] = {
    { -0.123, 1003.28 },
    { 204.07, -781.89 },
    { 5.322, 0.9275 },
    { -0.419, 0.844 }
};

void test_complex_swap_fp64()
{
    BgcComplexFP64 compleimaginary, complex2;

    print_testing_name("bgc_complex_swap_fp64");

    for (int i = 0; i < _TEST_FP64_COMPLEX_AMOUNT; i++) {
        bgc_complex_copy_fp64(&_TEST_FP64_COMPLEX_LIST1[i], &compleimaginary);
        bgc_complex_copy_fp64(&_TEST_FP64_COMPLEX_LIST2[i], &complex2);

        bgc_complex_swap_fp64(&compleimaginary, &complex2);

        if (compleimaginary.real != _TEST_FP64_COMPLEX_LIST2[i].real ||
            compleimaginary.imaginary != _TEST_FP64_COMPLEX_LIST2[i].imaginary ||
            complex2.real != _TEST_FP64_COMPLEX_LIST1[i].real ||
            complex2.imaginary != _TEST_FP64_COMPLEX_LIST1[i].imaginary) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_complex_swap()
{
    test_complex_swap_fp32();
    test_complex_swap_fp64();
}
