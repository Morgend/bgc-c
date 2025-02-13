#include "./quaternion_is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_QUATERNION_AMOUNT = 9;
static const int _TEST_FP32_NONZERO_QUATERNION_AMOUNT = 11;

static const BgcQuaternionFP32 _TEST_FP32_ZERO_QUATERNION_LIST[] = {
    { 0.0f, 0.0f, 0.0f, 0.0f },
    { 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { -0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { 0.0f, 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, -0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, 0.0f, 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, -0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, 0.0f, 0.75f * BGC_EPSYLON_FP32 },
    { 0.0f, 0.0f, 0.0f, -0.75f * BGC_EPSYLON_FP32 }
};

static const BgcQuaternionFP32 _TEST_FP32_NONZERO_QUATERION_LIST[] = {
    { 0.0f, 1.0f, 0.0f, 0.0f },
    { 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { -1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { 0.0f, 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, -1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, -1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, 0.0f, 1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, 0.0f, 0.0f, -1.25f * BGC_EPSYLON_FP32 },
    { 1.25f * BGC_EPSYLON_FP32, 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { -1.25f * BGC_EPSYLON_FP32, -1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f }
};

void test_quaternion_is_zero_fp32()
{
    print_testing_name("bgc_quaternion_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_QUATERNION_AMOUNT; i++) {
        if (!bgc_quaternion_is_zero_fp32(&_TEST_FP32_ZERO_QUATERNION_LIST[i])) {
            print_testing_error("A zero quaternion was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONZERO_QUATERNION_AMOUNT; i++) {
        if (bgc_quaternion_is_zero_fp32(&_TEST_FP32_NONZERO_QUATERION_LIST[i])) {
            print_testing_error("A non-zero quaternion was recognized as a zero quaternion");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_QUATERNION_AMOUNT = 9;
static const int _TEST_FP64_NONZERO_QUATERNION_AMOUNT = 11;

static const BgcQuaternionFP64 _TEST_FP64_ZERO_QUATERNION_LIST[] = {
    { 0.0, 0.0, 0.0, 0.0 },
    { 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { -0.75 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { 0.0, 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, -0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, 0.0, 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, -0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, 0.0, 0.75 * BGC_EPSYLON_FP64 },
    { 0.0, 0.0, 0.0, -0.75 * BGC_EPSYLON_FP64 }
};

static const BgcQuaternionFP64 _TEST_FP64_NONZERO_QUATERION_LIST[] = {
    { 0.0, 1.0, 0.0, 0.0 },
    { 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { -1.25 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { 0.0, 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, -1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, 0.0, 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, -1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, 0.0, 1.25 * BGC_EPSYLON_FP64 },
    { 0.0, 0.0, 0.0, -1.25 * BGC_EPSYLON_FP64 },
    { 1.25 * BGC_EPSYLON_FP64, 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { -1.25 * BGC_EPSYLON_FP64, -1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 }
};

void test_quaternion_is_zero_fp64()
{
    print_testing_name("bgc_quaternion_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_QUATERNION_AMOUNT; i++) {
        if (!bgc_quaternion_is_zero_fp64(&_TEST_FP64_ZERO_QUATERNION_LIST[i])) {
            print_testing_error("A zero quaternion was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONZERO_QUATERNION_AMOUNT; i++) {
        if (bgc_quaternion_is_zero_fp64(&_TEST_FP64_NONZERO_QUATERION_LIST[i])) {
            print_testing_error("A non-zero quaternion was recognized as a zero quaternion");
            return;
        }
    }

    print_testing_success();
}

void test_quaternion_is_zero()
{
    test_quaternion_is_zero_fp32();
    test_quaternion_is_zero_fp64();
}
