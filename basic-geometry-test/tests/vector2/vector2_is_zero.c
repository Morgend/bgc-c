#include "./vector2_is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_VECTOR2_AMOUNT = 5;
static const int _TEST_FP32_NONZERO_VECTOR2_AMOUNT = 7;

static const BgcVector2FP32 _TEST_FP32_ZERO_VECTOR2_LIST[] = {
    { 0.0f, 0.0f },
    { 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { -0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.75f * BGC_EPSYLON_FP32 },
    { 0.0f, -0.75f * BGC_EPSYLON_FP32 }
};

static const BgcVector2FP32 _TEST_FP32_NONZERO_VECTOR2_LIST[] = {
    { 0.0f, 1.0f },
    { 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { -1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, -1.25f * BGC_EPSYLON_FP32 },
    { BGC_EPSYLON_FP32, BGC_EPSYLON_FP32 },
    { -BGC_EPSYLON_FP32, -BGC_EPSYLON_FP32 }
};

int test_vector2_is_zero_fp32()
{
    print_testing_name("bgc_vector2_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_VECTOR2_AMOUNT; i++) {
        if (!bgc_vector2_is_zero_fp32(&_TEST_FP32_ZERO_VECTOR2_LIST[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONZERO_VECTOR2_AMOUNT; i++) {
        if (bgc_vector2_is_zero_fp32(&_TEST_FP32_NONZERO_VECTOR2_LIST[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_VECTOR2_AMOUNT = 5;
static const int _TEST_FP64_NONZERO_VECTOR2_AMOUNT = 7;

static const BgcVector2FP64 _TEST_FP64_ZERO_VECTOR2_LIST[] = {
    { 0.0, 0.0 },
    { 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { -0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.75 * BGC_EPSYLON_FP64 },
    { 0.0, -0.75 * BGC_EPSYLON_FP64 }
};

static const BgcVector2FP64 _TEST_FP64_NONZERO_VECTOR2_LIST[] = {
    { 0.0, 1.0 },
    { 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { -1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 1.25 * BGC_EPSYLON_FP64 },
    { 0.0, -1.25 * BGC_EPSYLON_FP64 },
    { 1.25 * BGC_EPSYLON_FP64, 1.25 * BGC_EPSYLON_FP64 },
    { -1.25 * BGC_EPSYLON_FP64, -1.25 * BGC_EPSYLON_FP64 }
};

int test_vector2_is_zero_fp64()
{
    print_testing_name("bgc_vector2_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_VECTOR2_AMOUNT; i++) {
        if (!bgc_vector2_is_zero_fp64(&_TEST_FP64_ZERO_VECTOR2_LIST[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONZERO_VECTOR2_AMOUNT; i++) {
        if (bgc_vector2_is_zero_fp64(&_TEST_FP64_NONZERO_VECTOR2_LIST[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_vector2_is_zero()
{
    if (test_vector2_is_zero_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_vector2_is_zero_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
