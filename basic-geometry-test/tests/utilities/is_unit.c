#include "./is_unit.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_UNIT_NUMBERS_AMOUNT = 3;
static const int _TEST_FP32_NONUNIT_NUMBERS_AMOUNT = 4;

static const float _TEST_FP32_UNIT_NUMBERS[] = {
    1.0f,
    1.0f + 0.75f * BGC_EPSYLON_FP32,
    1.0f - 0.75f * BGC_EPSYLON_FP32
};

static const float _TEST_FP32_NONUNIT_NUMBERS[] = {
    0.0f,
    -1.0f,
    1.0f + 1.25f * BGC_EPSYLON_FP32,
    1.0f - 1.25f * BGC_EPSYLON_FP32
};

void test_is_unit_fp32()
{
    print_testing_name("bgc_is_unit_fp32");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP32_UNIT_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_unit_fp32(_TEST_FP32_UNIT_NUMBERS[i])) {
            print_testing_error("A unit value was not recognized");
            return;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP32_NONUNIT_NUMBERS_AMOUNT; i++) {
        if (bgc_is_unit_fp32(_TEST_FP32_NONUNIT_NUMBERS[i])) {
            print_testing_error("A non-unit value was recognized as a unit value");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_UNIT_NUMBERS_AMOUNT = 3;
static const int _TEST_FP64_NONUNIT_NUMBERS_AMOUNT = 4;

static const double _TEST_FP64_UNIT_NUMBERS[] = {
    1.0,
    1.0 + 0.75 * BGC_EPSYLON_FP64,
    1.0 - 0.75 * BGC_EPSYLON_FP64
};

static const double _TEST_FP64_NONUNIT_NUMBERS[] = {
    0.0,
    -1.0,
    1.0 + 1.25 * BGC_EPSYLON_FP64,
    1.0 - 1.25 * BGC_EPSYLON_FP64
};

void test_is_unit_fp64()
{
    print_testing_name("bgc_is_unit_fp64");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP64_UNIT_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_unit_fp64(_TEST_FP64_UNIT_NUMBERS[i])) {
            print_testing_error("A unit value was not recognized");
            return;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP64_NONUNIT_NUMBERS_AMOUNT; i++) {
        if (bgc_is_unit_fp64(_TEST_FP64_NONUNIT_NUMBERS[i])) {
            print_testing_error("A non-unit value was recognized as a unit value");
            return;
        }
    }

    print_testing_success();
}

// ================ Square FP32 ================= //

static const int _TEST_FP32_DATA_SQUARE_UNIT_AMOUNT = 3;
static const int _TEST_FP32_DATA_SQUARE_NONUNIT_AMOUNT = 4;

static const float _TEST_FP32_DATA_SQUARE_UNIT[] = {
    1.0f,
    1.0f + 1.75f * BGC_EPSYLON_FP32,
    1.0f - 1.75f * BGC_EPSYLON_FP32
};

static const float _TEST_FP32_DATA_SQUARE_NONUNIT[] = {
    0.0f,
    -1.0f,
    1.0f + 2.25f * BGC_EPSYLON_FP32,
    1.0f - 2.25f * BGC_EPSYLON_FP32
};

void test_is_sqare_unit_fp32()
{
    print_testing_name("bgc_is_sqare_unit_fp32");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP32_DATA_SQUARE_UNIT_AMOUNT; i++) {
        if (!bgc_is_sqare_unit_fp32(_TEST_FP32_DATA_SQUARE_UNIT[i])) {
            print_testing_error("A square unit value was not recognized");
            return;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP32_DATA_SQUARE_NONUNIT_AMOUNT; i++) {
        if (bgc_is_sqare_unit_fp32(_TEST_FP32_DATA_SQUARE_NONUNIT[i])) {
            print_testing_error("A non-unit value was recognized as a square unit value");
            return;
        }
    }

    print_testing_success();
}

// ================ Square FP64 ================= //

static const int _TEST_FP64_DATA_SQUARE_UNIT_AMOUNT = 3;
static const int _TEST_FP64_DATA_SQUARE_NONUNIT_AMOUNT = 4;

static const double _TEST_FP64_DATA_SQUARE_UNIT[] = {
    1.0,
    1.0 + 1.75 * BGC_EPSYLON_FP64,
    1.0 - 1.75 * BGC_EPSYLON_FP64
};

static const double _TEST_FP64_DATA_SQUARE_NONUNIT[] = {
    0.0,
    -1.0,
    1.0 + 2.25 * BGC_EPSYLON_FP64,
    1.0 - 2.25 * BGC_EPSYLON_FP64
};

void test_is_sqare_unit_fp64()
{
    print_testing_name("bgc_is_sqare_unit_fp64");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP64_DATA_SQUARE_UNIT_AMOUNT; i++) {
        if (!bgc_is_sqare_unit_fp64(_TEST_FP64_DATA_SQUARE_UNIT[i])) {
            print_testing_error("A square unit value was not recognized");
            return;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP64_DATA_SQUARE_NONUNIT_AMOUNT; i++) {
        if (bgc_is_sqare_unit_fp64(_TEST_FP64_DATA_SQUARE_NONUNIT[i])) {
            print_testing_error("A non-unit value was recognized as a square unit value");
            return;
        }
    }

    print_testing_success();
}

void test_is_unit()
{
    test_is_unit_fp32();
    test_is_unit_fp64();

    test_is_sqare_unit_fp32();
    test_is_sqare_unit_fp64();
}
