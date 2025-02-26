#include "./complex_modulus.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_COMPLEX_AMOUNT = 4;

static const BgcComplexFP32 _TEST_FP32_COMPLEX_LIST[] = {
    { 4.0f, 3.0f },
    { -1.0f, 1.0f },
    { 100.0f, -100.0f },
    { -0.86602540378f, 0.5f }
};

static const float _TEST_FP32_SQUARE_MODULUS_LIST[] = {
    25.0f,
    2.0f,
    20000.0f,
    1.0f
};

static const float _TEST_FP32_MODULUS_LIST[] = {
    5.0f,
    1.414213562373f,
    141.4213562373f,
    1.0f
};

void test_complex_square_modulus_fp32()
{
    print_testing_name("bgc_complex_get_square_modulus_fp32");

    for (int i = 0; i < _TEST_FP32_COMPLEX_AMOUNT; i++) {
        if (!bgc_are_close_fp32(bgc_complex_get_square_modulus_fp32(&_TEST_FP32_COMPLEX_LIST[i]), _TEST_FP32_SQUARE_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_complex_modulus_fp32()
{
    print_testing_name("bgc_complex_get_modulus_fp32");

    for (int i = 0; i < _TEST_FP32_COMPLEX_AMOUNT; i++) {
        if (!bgc_are_close_fp32(bgc_complex_get_modulus_fp32(&_TEST_FP32_COMPLEX_LIST[i]), _TEST_FP32_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_COMPLEX_AMOUNT = 4;

static const BgcComplexFP64 _TEST_FP64_COMPLEX_LIST[] = {
    { 4.0, 3.0 },
    { -1.0, -1.0 },
    { -100.0, 100.0 },
    { -0.5, 0.866025403784438647 }
};

static const double _TEST_FP64_SQUARE_MODULUS_LIST[] = {
    25.0,
    2.0,
    20000.0,
    1.0
};

static const double _TEST_FP64_MODULUS_LIST[] = {
    5.0,
    1.4142135623730950488,
    141.42135623730950488,
    1.0
};

void test_complex_square_modulus_fp64()
{
    print_testing_name("bgc_complex_get_square_modulus_fp64");

    for (int i = 0; i < _TEST_FP64_COMPLEX_AMOUNT; i++) {
        if (!bgc_are_close_fp64(bgc_complex_get_square_modulus_fp64(&_TEST_FP64_COMPLEX_LIST[i]), _TEST_FP64_SQUARE_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_complex_modulus_fp64()
{
    print_testing_name("bgc_complex_get_modulus_fp64");

    for (int i = 0; i < _TEST_FP64_COMPLEX_AMOUNT; i++) {
        if (!bgc_are_close_fp64(bgc_complex_get_modulus_fp64(&_TEST_FP64_COMPLEX_LIST[i]), _TEST_FP64_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_complex_modulus()
{
    test_complex_square_modulus_fp32();
    test_complex_square_modulus_fp64();
    test_complex_modulus_fp32();
    test_complex_modulus_fp64();
}
