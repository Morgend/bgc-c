#include "./quaternion_is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_QUATERNION_AMOUNT = 9;
static const int _TEST_FP32_NONZERO_QUATERNION_AMOUNT = 11;

static const BgcQuaternionFP32 _TEST_FP32_ZERO_QUATERNION_LIST[] = {
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { -BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { 0.0f, BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, -BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, 0.0f, BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, -BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, 0.0f, BGC_EPSYLON_FP32 },
    { 0.0f, 0.0f, 0.0f, -BGC_EPSYLON_FP32 }
};

static const BgcQuaternionFP32 _TEST_FP32_NONZERO_NUMBERS[] = {
    { 0.0f, 1.0f, 0.0f, 0.0f },
    { 1.5f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { -1.5f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { 0.0f, 1.5f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, -1.5f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.5f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, -1.5f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, 0.0f, 1.5f * BGC_EPSYLON_FP32 },
    { 0.0f, 0.0f, 0.0f, -1.5f * BGC_EPSYLON_FP32 },
    { BGC_EPSYLON_FP32, BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { -BGC_EPSYLON_FP32, -BGC_EPSYLON_FP32, 0.0f, 0.0f }
};

int test_bgc_quaternion_is_zero_fp32()
{
    print_testing_name("bgc_quaternion_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_QUATERNION_AMOUNT; i++) {
        if (!bgc_quaternion_is_zero_fp32(&_TEST_FP32_ZERO_QUATERNION_LIST[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_QUATERNION_AMOUNT; i++) {
        if (bgc_quaternion_is_zero_fp32(&_TEST_FP32_NONZERO_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_QUATERNION_AMOUNT = 9;
static const int _TEST_FP64_NONZERO_QUATERNION_AMOUNT = 11;

static const BgcQuaternionFP64 _TEST_FP64_ZERO_QUATERNION_LIST[] = {
    { 0.0, 0.0, 0.0, 0.0 },
    { BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { -BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { 0.0, BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, -BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, 0.0, BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, -BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, 0.0, BGC_EPSYLON_FP64 },
    { 0.0, 0.0, 0.0, -BGC_EPSYLON_FP64 }
};

static const BgcQuaternionFP64 _TEST_FP64_NONZERO_NUMBERS[] = {
    { 0.0, 1.0, 0.0, 0.0 },
    { 1.5 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { -1.5 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { 0.0, 1.5 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, -1.5 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, 0.0, 1.5 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, -1.5 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, 0.0, 1.5 * BGC_EPSYLON_FP64 },
    { 0.0, 0.0, 0.0, -1.5 * BGC_EPSYLON_FP64 },
    { BGC_EPSYLON_FP64, BGC_EPSYLON_FP64, 0.0, 0.0 },
    { -BGC_EPSYLON_FP64, -BGC_EPSYLON_FP64, 0.0, 0.0 }
};

int test_bgc_quaternion_is_zero_fp64()
{
    print_testing_name("bgc_quaternion_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_QUATERNION_AMOUNT; i++) {
        if (!test_bgc_quaternion_is_zero_fp64(&_TEST_FP64_ZERO_QUATERNION_LIST[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_QUATERNION_AMOUNT; i++) {
        if (test_bgc_quaternion_is_zero_fp64(&_TEST_FP64_NONZERO_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_bgc_quaternion_is_zero()
{
    if (test_bgc_quaternion_is_zero_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_quaternion_is_zero_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
