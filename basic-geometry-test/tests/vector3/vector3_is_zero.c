#include "./vector3_is_zero.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_ZERO_VECTOR3_AMOUNT = 7;
static const int _TEST_FP32_NONZERO_VECTOR3_AMOUNT = 9;

static const BgcVector3FP32 _TEST_FP32_ZERO_VECTOR3_LIST[] = {
    { 0.0f, 0.0f, 0.0f },
    { 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { -0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, -0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, 0.75f * BGC_EPSYLON_FP32 },
    { 0.0f, 0.0f, -0.75f * BGC_EPSYLON_FP32 }
};

static const BgcVector3FP32 _TEST_FP32_NONZERO_VECTOR3_LIST[] = {
    { 0.0f, 1.0f, 0.0f },
    { 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { -1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 0.0f, 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, -1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 0.0f, 1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, 0.0f, -1.25f * BGC_EPSYLON_FP32 },
    { 1.25f * BGC_EPSYLON_FP32, 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { -1.25f * BGC_EPSYLON_FP32, -1.25f * BGC_EPSYLON_FP32, 0.0f }
};

void test_vector3_is_zero_fp32()
{
    print_testing_name("bgc_vector3_is_zero_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_ZERO_VECTOR3_AMOUNT; i++) {
        if (!bgc_vector3_is_zero_fp32(&_TEST_FP32_ZERO_VECTOR3_LIST[i])) {
            print_testing_error("A zero vector was not recongized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONZERO_VECTOR3_AMOUNT; i++) {
        if (bgc_vector3_is_zero_fp32(&_TEST_FP32_NONZERO_VECTOR3_LIST[i])) {
            print_testing_error("A non-zero vector was recongized as a zero vector");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_ZERO_VECTOR3_AMOUNT = 7;
static const int _TEST_FP64_NONZERO_VECTOR3_AMOUNT = 9;

static const BgcVector3FP64 _TEST_FP64_ZERO_VECTOR3_LIST[] = {
    { 0.0, 0.0, 0.0 },
    { 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { -0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, -0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, 0.75 * BGC_EPSYLON_FP64 },
    { 0.0, 0.0, -0.75 * BGC_EPSYLON_FP64 }
};

static const BgcVector3FP64 _TEST_FP64_NONZERO_VECTOR3_LIST[] = {
    { 0.0, 1.0, 0.0 },
    { 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { -1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 0.0, 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, -1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 0.0, 1.25 * BGC_EPSYLON_FP64 },
    { 0.0, 0.0, -1.25 * BGC_EPSYLON_FP64 },
    { 1.25 * BGC_EPSYLON_FP64, 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { -BGC_EPSYLON_FP64, -BGC_EPSYLON_FP64, 0.0 }
};

void test_vector3_is_zero_fp64()
{
    print_testing_name("bgc_vector3_is_zero_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_ZERO_VECTOR3_AMOUNT; i++) {
        if (!bgc_vector3_is_zero_fp64(&_TEST_FP64_ZERO_VECTOR3_LIST[i])) {
            print_testing_error("A zero vector was not recongized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONZERO_VECTOR3_AMOUNT; i++) {
        if (bgc_vector3_is_zero_fp64(&_TEST_FP64_NONZERO_VECTOR3_LIST[i])) {
            print_testing_error("A non-zero vector was recongized as a zero vector");
            return;
        }
    }

    print_testing_success();
}

void test_vector3_is_zero()
{
    test_vector3_is_zero_fp32();
    test_vector3_is_zero_fp64();
}
