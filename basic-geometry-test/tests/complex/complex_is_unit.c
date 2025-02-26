#include "./complex_is_unit.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_UNIT_COMPLEX_AMOUNT = 10;
static const int _TEST_FP32_NONUNIT_COMPLEX_AMOUNT = 6;

static const BgcComplexFP32 _TEST_FP32_UNIT_COMPLEX_LIST[] = {
    { 1.0f, 0.0f },
    { -1.0f, 0.0f },
    { 0.6f, -0.8f },
    { 1.0f + 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 1.0f - 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 1.0f + 0.75f * BGC_EPSYLON_FP32 },
    { 0.0f, 1.0f - 0.75f * BGC_EPSYLON_FP32 },
    { 0.7071067812f, 0.7071067812f },
    { 0.7071067812f + 0.75f * BGC_EPSYLON_FP32, 0.7071067812f },
    { 0.7071067812f, 0.7071067812f - 0.75f * BGC_EPSYLON_FP32 }
};

static const BgcComplexFP32 _TEST_FP32_NONUNIT_QUATERION_LIST[] = {
    { 1.0f + 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 1.0f - 1.25f * BGC_EPSYLON_FP32, 0.0f },
    { 0.0f, 1.0f + 1.25f * BGC_EPSYLON_FP32 },
    { 0.0f, 1.0f - 1.25f * BGC_EPSYLON_FP32 },
    { 0.7071067812f + 1.25f * BGC_EPSYLON_FP32, 0.7071067812f + 1.25f * BGC_EPSYLON_FP32 },
    { 0.7071067812f - 1.25f * BGC_EPSYLON_FP32, 0.7071067812f - 1.25f * BGC_EPSYLON_FP32 }
};

void test_complex_is_unit_fp32()
{
    print_testing_name("bgc_complex_is_unit_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_UNIT_COMPLEX_AMOUNT; i++) {
        if (!bgc_complex_is_unit_fp32(&_TEST_FP32_UNIT_COMPLEX_LIST[i])) {
            print_testing_error("A unit complex number was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NONUNIT_COMPLEX_AMOUNT; i++) {
        if (bgc_complex_is_unit_fp32(&_TEST_FP32_NONUNIT_QUATERION_LIST[i])) {
            print_testing_error("A non-unit complex number was recognized a unit complex number");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_UNIT_COMPLEX_AMOUNT = 10;
static const int _TEST_FP64_NONUNIT_COMPLEX_AMOUNT = 6;

static const BgcComplexFP64 _TEST_FP64_UNIT_COMPLEX_LIST[] = {
    { 1.0, 0.0 },
    { -1.0, 0.0 },
    { -0.6, 0.8 },
    { 1.0 + 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 1.0 - 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 1.0 + 0.75 * BGC_EPSYLON_FP64 },
    { 0.0, 1.0 - 0.75 * BGC_EPSYLON_FP64 },
    { 0.7071067811865475244, 0.7071067811865475244 },
    { 0.7071067811865475244 + 0.75 * BGC_EPSYLON_FP64, 0.7071067811865475244 },
    { 0.7071067811865475244, 0.7071067811865475244 - 0.75 * BGC_EPSYLON_FP64 }
};

static const BgcComplexFP64 _TEST_FP64_NONUNIT_QUATERION_LIST[] = {
    { 1.0 + 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 1.0 - 1.25 * BGC_EPSYLON_FP64, 0.0 },
    { 0.0, 1.0 + 1.25 * BGC_EPSYLON_FP64 },
    { 0.0, 1.0 - 1.25 * BGC_EPSYLON_FP64 },
    { 0.7071067811865475244 + 1.25 * BGC_EPSYLON_FP64, 0.7071067811865475244 + 1.25 * BGC_EPSYLON_FP64 },
    { 0.7071067811865475244 - 1.25 * BGC_EPSYLON_FP64, 0.7071067811865475244 - 1.25 * BGC_EPSYLON_FP64 }
};

void test_complex_is_unit_fp64()
{
    print_testing_name("bgc_complex_is_unit_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_UNIT_COMPLEX_AMOUNT; i++) {
        if (!bgc_complex_is_unit_fp64(&_TEST_FP64_UNIT_COMPLEX_LIST[i])) {
            print_testing_error("A unit complex number was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NONUNIT_COMPLEX_AMOUNT; i++) {
        if (bgc_complex_is_unit_fp64(&_TEST_FP64_NONUNIT_QUATERION_LIST[i])) {
            print_testing_error("A non-unit complex number was recognized a unit complex number");
            return;
        }
    }

    print_testing_success();
}

void test_complex_is_unit()
{
    test_complex_is_unit_fp32();
    test_complex_is_unit_fp64();
}
