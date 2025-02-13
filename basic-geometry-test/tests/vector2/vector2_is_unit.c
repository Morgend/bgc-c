#include "./vector2_is_unit.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_UNIT_VECTOR2_AMOUNT = 6;
static const int _TEST_FP32_NONUNIT_VECTOR2_AMOUNT = 7;

static const BgcVector2FP32 _TEST_FP32_UNIT_VECTOR2_LIST[] = {
    { 1.0f, 0.0f },
    { 0.0f, -1.0f },
    { 1.0f + 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 1.0f - 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 1.0f + 0.75f * BGC_EPSYLON_FP32 },
    { 0.0f, 1.0f - 0.75f * BGC_EPSYLON_FP32 }
};

static const BgcVector2FP32 _TEST_FP32_NONUNIT_VECTOR2_LIST[] = {
    { 0.0f, 0.0f },
    { 1.0f + 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 1.0f - 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 1.0f + 1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, 1.0f - 1.25f * BGC_EPSYLON_FP32 },
    { 0.8f + 1.25f * BGC_EPSYLON_FP32, 0.6f + 1.25f * BGC_EPSYLON_FP32 },
    { 0.6f - 1.25f * BGC_EPSYLON_FP32, 0.8f - 1.25f * BGC_EPSYLON_FP32 }
};

void test_vector2_is_unit_fp32()
{
    print_testing_name("bgc_vector2_is_unit_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_UNIT_VECTOR2_AMOUNT; i++) {
        if (!bgc_vector2_is_unit_fp32(&_TEST_FP32_UNIT_VECTOR2_LIST[i])) {
            print_testing_error("A unit vector was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONUNIT_VECTOR2_AMOUNT; i++) {
        if (bgc_vector2_is_unit_fp32(&_TEST_FP32_NONUNIT_VECTOR2_LIST[i])) {
            print_testing_error("A non-unit vector was recognized as a unit vector");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_UNIT_VECTOR2_AMOUNT = 6;
static const int _TEST_FP64_NONUNIT_VECTOR2_AMOUNT = 7;

static const BgcVector2FP64 _TEST_FP64_UNIT_VECTOR2_LIST[] = {
    { -1.0, 0.0 },
    { 0.0, 1.0 },
    { 1.0 + 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 1.0 - 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 1.0 + 0.75 * BGC_EPSYLON_FP64 },
    { 0.0, 1.0 - 0.75 * BGC_EPSYLON_FP64 }
};

static const BgcVector2FP64 _TEST_FP64_NONUNIT_VECTOR2_LIST[] = {
    { 0.0, 0.0 },
    { 1.0 + 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 1.0 - 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 1.0 + 1.25 * BGC_EPSYLON_FP64 },
    { 0.0, 1.0 - 1.25 * BGC_EPSYLON_FP64 },
    { 0.6 + 1.25 * BGC_EPSYLON_FP64, 0.8 + 1.25 * BGC_EPSYLON_FP64 },
    { 0.8 - 1.25 * BGC_EPSYLON_FP64, 0.6 - 1.25 * BGC_EPSYLON_FP64 }
};

void test_vector2_is_unit_fp64()
{
    print_testing_name("bgc_vector2_is_unit_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_UNIT_VECTOR2_AMOUNT; i++) {
        if (!bgc_vector2_is_unit_fp64(&_TEST_FP64_UNIT_VECTOR2_LIST[i])) {
            print_testing_error("A unit vector was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONUNIT_VECTOR2_AMOUNT; i++) {
        if (bgc_vector2_is_unit_fp64(&_TEST_FP64_NONUNIT_VECTOR2_LIST[i])) {
            print_testing_error("A non-unit vector was recognized as a unit vector");
            return;
        }
    }

    print_testing_success();
}

void test_vector2_is_unit()
{
    test_vector2_is_unit_fp32();
    test_vector2_is_unit_fp64();
}
