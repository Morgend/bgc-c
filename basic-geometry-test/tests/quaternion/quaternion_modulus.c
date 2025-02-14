#include "./quaternion_modulus.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_QUATERNION_AMOUNT = 4;

static const BgcQuaternionFP32 _TEST_FP32_QUATERNION_LIST[] = {
    { 0.0f, 4.0f, 3.0f, 0.0f },
    { -1.0f, 1.0f, -1.0f, 1.0f },
    { 100.0f, -100.0f, 0.0f, 100.0f },
    { -0.86602540378f, 0.5f, -1.0f, 1.0f }
};

static const float _TEST_FP32_SQUARE_MODULUS_LIST[] = {
    25.0f,
    4.0f,
    30000.0f,
    3.0f
};

static const float _TEST_FP32_MODULUS_LIST[] = {
    5.0f,
    2.0f,
    173.20508076f,
    1.7320508076f
};

void test_quaternion_square_modulus_fp32()
{
    print_testing_name("bgc_quaternion_get_square_modulus_fp32");

    for (int i = 0; i < _TEST_FP32_QUATERNION_AMOUNT; i++) {
        if (!bgc_are_close_fp32(bgc_quaternion_get_square_modulus_fp32(&_TEST_FP32_QUATERNION_LIST[i]), _TEST_FP32_SQUARE_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_quaternion_modulus_fp32()
{
    print_testing_name("bgc_quaternion_get_modulus_fp32");

    for (int i = 0; i < _TEST_FP32_QUATERNION_AMOUNT; i++) {
        if (!bgc_are_close_fp32(bgc_quaternion_get_modulus_fp32(&_TEST_FP32_QUATERNION_LIST[i]), _TEST_FP32_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_QUATERNION_AMOUNT = 4;

static const BgcQuaternionFP64 _TEST_FP64_QUATERNION_LIST[] = {
    { 0.0, 4.0, 3.0, 0.0 },
    { -1.0, 1.0, -1.0, 1.0 },
    { 100.0, -100.0, 0.0, 100.0 },
    { -0.866025403784438647, 0.5, -1.0, 1.0 }
};

static const double _TEST_FP64_SQUARE_MODULUS_LIST[] = {
    25.0,
    4.0,
    30000.0,
    3.0
};

static const double _TEST_FP64_MODULUS_LIST[] = {
    5.0,
    2.0,
    173.20508075688772935,
    1.7320508075688772935
};

void test_quaternion_square_modulus_fp64()
{
    print_testing_name("bgc_quaternion_get_square_modulus_fp64");

    for (int i = 0; i < _TEST_FP64_QUATERNION_AMOUNT; i++) {
        if (!bgc_are_close_fp64(bgc_quaternion_get_square_modulus_fp64(&_TEST_FP64_QUATERNION_LIST[i]), _TEST_FP64_SQUARE_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_quaternion_modulus_fp64()
{
    print_testing_name("bgc_quaternion_get_modulus_fp64");

    for (int i = 0; i < _TEST_FP64_QUATERNION_AMOUNT; i++) {
        if (!bgc_are_close_fp64(bgc_quaternion_get_modulus_fp64(&_TEST_FP64_QUATERNION_LIST[i]), _TEST_FP64_MODULUS_LIST[i])) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_quaternion_modulus()
{
    test_quaternion_square_modulus_fp32();
    test_quaternion_square_modulus_fp64();
    test_quaternion_modulus_fp32();
    test_quaternion_modulus_fp64();
}
