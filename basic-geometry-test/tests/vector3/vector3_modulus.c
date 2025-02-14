#include "./vector3_modulus.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VECTOR3_AMOUNT = 4;

static const BgcVector3FP32 _TEST_FP32_VECTOR3_LIST[] = {
    { 4.0f, 3.0f, 0.0f },
    { 0.0f, -3.0f, -4.0f },
    { 100.0f, -100.0f, 100.0f },
    { -0.86602540378f, 0.5f, -1.0f }
};

static const float _TEST_FP32_SQUARE_MODULUS_LIST[] = {
    25.0f,
    25.0f,
    30000.0f,
    2.0f
};

static const float _TEST_FP32_MODULUS_LIST[] = {
    5.0f,
    5.0f,
    173.20508076f,
    1.4142135624f
};

void test_vector3_square_modulus_fp32()
{
    print_testing_name("bgc_vector3_get_square_modulus_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR3_AMOUNT; i++) {
        if (!bgc_are_close_fp32(bgc_vector3_get_square_modulus_fp32(&_TEST_FP32_VECTOR3_LIST[i]), _TEST_FP32_SQUARE_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_vector3_modulus_fp32()
{
    print_testing_name("bgc_vector3_get_modulus_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR3_AMOUNT; i++) {
        if (!bgc_are_close_fp32(bgc_vector3_get_modulus_fp32(&_TEST_FP32_VECTOR3_LIST[i]), _TEST_FP32_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VECTOR3_AMOUNT = 4;

static const BgcVector3FP64 _TEST_FP64_VECTOR3_LIST[] = {
    { 0.0, 4.0, 3.0 },
    { -3.0, 0.0, -4.0 },
    { 100.0, -100.0, 100.0 },
    { -0.866025403784438647, 0.5, 1.0 }
};

static const double _TEST_FP64_SQUARE_MODULUS_LIST[] = {
    25.0,
    25.0,
    30000.0,
    2.0
};

static const double _TEST_FP64_MODULUS_LIST[] = {
    5.0,
    5.0,
    173.20508075688772935,
    1.4142135623730950488
};

void test_vector3_square_modulus_fp64()
{
    print_testing_name("bgc_vector3_get_square_modulus_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR3_AMOUNT; i++) {
        if (!bgc_are_close_fp64(bgc_vector3_get_square_modulus_fp64(&_TEST_FP64_VECTOR3_LIST[i]), _TEST_FP64_SQUARE_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_vector3_modulus_fp64()
{
    print_testing_name("bgc_vector3_get_modulus_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR3_AMOUNT; i++) {
        if (!bgc_are_close_fp64(bgc_vector3_get_modulus_fp64(&_TEST_FP64_VECTOR3_LIST[i]), _TEST_FP64_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_vector3_modulus()
{
    test_vector3_square_modulus_fp32();
    test_vector3_square_modulus_fp64();
    test_vector3_modulus_fp32();
    test_vector3_modulus_fp64();
}
