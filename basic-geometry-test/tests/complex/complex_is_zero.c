#include "./complex_is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_COMPLEX_AMOUNT = 4;
static const int _TEST_FP32_NONZERO_COMPLEX_AMOUNT = 7;

static const BgcComplexFP32 _TEST_FP32_ZERO_COMPLEX_LIST[] = {
    { 0.0f, 0.0f },
    { 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { -0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.75f * BGC_EPSYLON_FP32 },
    { 0.0f, -0.75f * BGC_EPSYLON_FP32 }
};

static const BgcComplexFP32 _TEST_FP32_NONZERO_QUATERION_LIST[] = {
    { 0.0f, 1.0f },
    { 1.25f * BGC_EPSYLON_FP32 },
    { -1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, 1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, -1.25f * BGC_EPSYLON_FP32 },
    { 1.25f * BGC_EPSYLON_FP32, 1.25f * BGC_EPSYLON_FP32 },
    { -1.25f * BGC_EPSYLON_FP32, -1.25f * BGC_EPSYLON_FP32 }
};

void test_complex_is_zero_fp32()
{
    print_testing_name("bgc_complex_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_COMPLEX_AMOUNT; i++) {
        if (!bgc_complex_is_zero_fp32(&_TEST_FP32_ZERO_COMPLEX_LIST[i])) {
            print_testing_error("A zero complex number was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONZERO_COMPLEX_AMOUNT; i++) {
        if (bgc_complex_is_zero_fp32(&_TEST_FP32_NONZERO_QUATERION_LIST[i])) {
            print_testing_error("A non-zero complex number was recognized as a zero complex number");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_COMPLEX_AMOUNT = 4;
static const int _TEST_FP64_NONZERO_COMPLEX_AMOUNT = 7;

static const BgcComplexFP64 _TEST_FP64_ZERO_COMPLEX_LIST[] = {
    { 0.0, 0.0 },
    { 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { -0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.75 * BGC_EPSYLON_FP64 },
    { 0.0, -0.75 * BGC_EPSYLON_FP64 }
};

static const BgcComplexFP64 _TEST_FP64_NONZERO_QUATERION_LIST[] = {
    { 0.0, 1.0 },
    { 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { -1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 1.25 * BGC_EPSYLON_FP64 },
    { 0.0, -1.25 * BGC_EPSYLON_FP64 },
    { 1.25 * BGC_EPSYLON_FP64, 1.25 * BGC_EPSYLON_FP64 },
    { -1.25 * BGC_EPSYLON_FP64, -1.25 * BGC_EPSYLON_FP64 }
};

void test_complex_is_zero_fp64()
{
    print_testing_name("bgc_complex_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_COMPLEX_AMOUNT; i++) {
        if (!bgc_complex_is_zero_fp64(&_TEST_FP64_ZERO_COMPLEX_LIST[i])) {
            print_testing_error("A zero complex number was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONZERO_COMPLEX_AMOUNT; i++) {
        if (bgc_complex_is_zero_fp64(&_TEST_FP64_NONZERO_QUATERION_LIST[i])) {
            print_testing_error("A non-zero complex number was recognized as a zero complex number");
            return;
        }
    }

    print_testing_success();
}

void test_complex_is_zero()
{
    test_complex_is_zero_fp32();
    test_complex_is_zero_fp64();
}
