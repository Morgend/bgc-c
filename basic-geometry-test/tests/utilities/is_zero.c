#include "./is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_NUMBERS_AMOUNT = 3;
static const int _TEST_FP32_NONZERO_NUMBERS_AMOUNT = 4;

static const float _TEST_FP32_ZERO_NUMBERS[] = {
    0.0f,
    0.75f * BGC_EPSYLON_FP32,
    -0.75f * BGC_EPSYLON_FP32
};

static const float _TEST_FP32_NONZERO_NUMBERS[] = {
    1.0f,
    -1.0f,
    1.25f * BGC_EPSYLON_FP32,
    -1.25f * BGC_EPSYLON_FP32
};

void test_is_zero_fp32()
{
    print_testing_name("bgc_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_zero_fp32(_TEST_FP32_ZERO_NUMBERS[i])) {
            print_testing_error("A zero value was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONZERO_NUMBERS_AMOUNT; i++) {
        if (bgc_is_zero_fp32(_TEST_FP32_NONZERO_NUMBERS[i])) {
            print_testing_error("A non-zero value was recognized as a zero value");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_NUMBERS_AMOUNT = 3;
static const int _TEST_FP64_NONZERO_NUMBERS_AMOUNT = 4;

static const double _TEST_FP64_ZERO_NUMBERS[] = {
    0.0,
    0.75 * BGC_EPSYLON_FP64,
    -0.75 * BGC_EPSYLON_FP64
};

static const double _TEST_FP64_NONZERO_NUMBERS[] = {
    1.0,
    -1.0,
    1.25 * BGC_EPSYLON_FP64,
    -1.25 * BGC_EPSYLON_FP64
};

void test_is_zero_fp64()
{
    print_testing_name("bgc_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_zero_fp64(_TEST_FP64_ZERO_NUMBERS[i])) {
            print_testing_error("A zero value was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONZERO_NUMBERS_AMOUNT; i++) {
        if (bgc_is_zero_fp64(_TEST_FP64_NONZERO_NUMBERS[i])) {
            print_testing_error("A non-zero value was recognized as a zero value");
            return;
        }
    }

    print_testing_success();
}

void test_is_zero()
{
    test_is_zero_fp32();
    test_is_zero_fp64();
}
