#include "./vector2_copy.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VECTOR2_AMOUNT = 4;
static const BgcVector2FP32 _TEST_FP32_VECTOR2_LIST[] = {
    { 1.0f, 2.0f },
    { -2.0f, -1.0f },
    { 100.0f, -100.0f },
    { -100.0f, 100.0f }
};

int test_bgc_vector2_copy_fp32()
{
    BgcVector2FP32 vector;

    print_testing_name("bgc_vector2_copy_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR2_AMOUNT; i++) {
        
        bgc_vector2_copy_fp32(&_TEST_FP32_VECTOR2_LIST[i], &vector);

        if (vector.x1 != _TEST_FP32_VECTOR2_LIST[i].x1 || vector.x2 != _TEST_FP32_VECTOR2_LIST[i].x2) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VECTOR2_AMOUNT = 4;
static const BgcVector2FP64 _TEST_FP64_VECTOR2_LIST[] = {
    { 1.0, 2.0 },
    { -2.0, -1.0 },
    { 100.0, -100.0 },
    { -100.0, 100.0 }
};

int test_bgc_vector2_copy_fp64()
{
    BgcVector2FP64 vector;

    print_testing_name("bgc_vector2_copy_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR2_AMOUNT; i++) {

        bgc_vector2_copy_fp64(&_TEST_FP64_VECTOR2_LIST[i], &vector);

        if (vector.x1 != _TEST_FP64_VECTOR2_LIST[i].x1 || vector.x2 != _TEST_FP64_VECTOR2_LIST[i].x2) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_bgc_vector2_copy()
{
    if (test_bgc_vector2_copy_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_vector2_copy_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
