#include "./is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_NUMBERS_AMOUNT = 5;
static const int _TEST_FP32_NONZERO_NUMBERS_AMOUNT = 4;

static const float _TEST_FP32_ZERO_NUMBERS[] = {
    0.0f,
    BGC_EPSYLON_FP32,
    -BGC_EPSYLON_FP32,
    BGC_SQUARE_EPSYLON_FP32,
    -BGC_SQUARE_EPSYLON_FP32
};

static const float _TEST_FP32_NONZERO_NUMBERS[] = {
    1.0f,
    -1.0f,
    (1.5f * BGC_EPSYLON_FP32),
    -(1.5f * BGC_EPSYLON_FP32)
};

int test_is_zero_fp32()
{
    print_testing_name("bgc_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_zero_fp32(_TEST_FP32_ZERO_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONZERO_NUMBERS_AMOUNT; i++) {
        if (bgc_is_zero_fp32(_TEST_FP32_NONZERO_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_NUMBERS_AMOUNT = 5;
static const int _TEST_FP64_NONZERO_NUMBERS_AMOUNT = 4;

static const double _TEST_FP64_ZERO_NUMBERS[] = {
    0.0,
    BGC_EPSYLON_FP64,
    -BGC_EPSYLON_FP64,
    BGC_SQUARE_EPSYLON_FP64,
    -BGC_SQUARE_EPSYLON_FP64
};

static const double _TEST_FP64_NONZERO_NUMBERS[] = {
    1.0,
    -1.0,
    (1.5 * BGC_EPSYLON_FP64),
    -(1.5 * BGC_EPSYLON_FP64)
};

int test_is_zero_fp64()
{
    print_testing_name("bgc_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_zero_fp64(_TEST_FP64_ZERO_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONZERO_NUMBERS_AMOUNT; i++) {
        if (bgc_is_zero_fp64(_TEST_FP64_NONZERO_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_is_zero()
{
    if (test_is_zero_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_is_zero_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
