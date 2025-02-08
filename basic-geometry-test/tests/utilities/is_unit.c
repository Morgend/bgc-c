#include "./is_unit.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_UNIT_NUMBERS_AMOUNT = 3;
static const int _TEST_FP32_NONUNIT_NUMBERS_AMOUNT = 4;

static const float _TEST_FP32_UNIT_NUMBERS[] = {
    1.0f,
    1.0f + BGC_EPSYLON_FP32,
    1.0f - BGC_EPSYLON_FP32
};

static const float _TEST_FP32_NONUNIT_NUMBERS[] = {
    0.0f,
    -1.0f,
    1.0f + 2.0f * BGC_EPSYLON_FP32,
    1.0f - 2.0f * BGC_EPSYLON_FP32
};

int test_bgc_is_unit_fp32()
{
    print_testing_name("bgc_is_unit_fp32");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP32_UNIT_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_unit_fp32(_TEST_FP32_UNIT_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP32_NONUNIT_NUMBERS_AMOUNT; i++) {
        if (bgc_is_unit_fp32(_TEST_FP32_NONUNIT_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_UNIT_NUMBERS_AMOUNT = 3;
static const int _TEST_FP64_NONUNIT_NUMBERS_AMOUNT = 4;

static const double _TEST_FP64_UNIT_NUMBERS[] = {
    1.0,
    1.0 + BGC_EPSYLON_FP64,
    1.0 - BGC_EPSYLON_FP64
};

static const double _TEST_FP64_NONUNIT_NUMBERS[] = {
    0.0,
    -1.0,
    1.0 + 2.0 * BGC_EPSYLON_FP64,
    1.0 - 2.0 * BGC_EPSYLON_FP64
};

int test_bgc_is_unit_fp64()
{
    print_testing_name("bgc_is_unit_fp64");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP64_UNIT_NUMBERS_AMOUNT; i++) {
        if (!bgc_is_unit_fp64(_TEST_FP64_UNIT_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP64_NONUNIT_NUMBERS_AMOUNT; i++) {
        if (bgc_is_unit_fp64(_TEST_FP64_NONUNIT_NUMBERS[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ================ Square FP32 ================= //

static const int _TEST_FP32_DATA_SQUARE_UNIT_AMOUNT = 5;
static const int _TEST_FP32_DATA_SQUARE_NONUNIT_AMOUNT = 4;

static const float _TEST_FP32_DATA_SQUARE_UNIT[] = {
    1.0f,
    1.0f + BGC_EPSYLON_FP32,
    1.0f - BGC_EPSYLON_FP32,
    1.0f + 2.0f * BGC_EPSYLON_FP32,
    1.0f - 2.0f * BGC_EPSYLON_FP32
};

static const float _TEST_FP32_DATA_SQUARE_NONUNIT[] = {
    0.0f,
    -1.0f,
    1.0f + 2.5f * BGC_EPSYLON_FP32,
    1.0f - 2.5f * BGC_EPSYLON_FP32
};

int test_bgc_is_sqare_value_unit_fp32()
{
    print_testing_name("bgc_is_sqare_value_unit_fp32");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP32_DATA_SQUARE_UNIT_AMOUNT; i++) {
        if (!bgc_is_sqare_value_unit_fp32(_TEST_FP32_DATA_SQUARE_UNIT[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP32_DATA_SQUARE_NONUNIT_AMOUNT; i++) {
        if (bgc_is_sqare_value_unit_fp32(_TEST_FP32_DATA_SQUARE_NONUNIT[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ================ Square FP64 ================= //

static const int _TEST_FP64_DATA_SQUARE_UNIT_AMOUNT = 5;
static const int _TEST_FP64_DATA_SQUARE_NONUNIT_AMOUNT = 4;

static const double _TEST_FP64_DATA_SQUARE_UNIT[] = {
    1.0,
    1.0 + BGC_EPSYLON_FP64,
    1.0 - BGC_EPSYLON_FP64,
    1.0 + 2.0 * BGC_EPSYLON_FP64,
    1.0 - 2.0 * BGC_EPSYLON_FP64
};

static const double _TEST_FP64_DATA_SQUARE_NONUNIT[] = {
    0.0,
    -1.0,
    1.0 + 2.5 * BGC_EPSYLON_FP64,
    1.0 - 2.5 * BGC_EPSYLON_FP64
};

int test_bgc_is_sqare_value_unit_fp64()
{
    print_testing_name("bgc_is_sqare_value_unit_fp64");

    // Testing unit values:
    for (int i = 0; i < _TEST_FP64_DATA_SQUARE_UNIT_AMOUNT; i++) {
        if (!bgc_is_sqare_value_unit_fp64(_TEST_FP64_DATA_SQUARE_UNIT[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing non-unit values:
    for (int i = 0; i < _TEST_FP64_DATA_SQUARE_NONUNIT_AMOUNT; i++) {
        if (bgc_is_sqare_value_unit_fp64(_TEST_FP64_DATA_SQUARE_NONUNIT[i])) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}
