#include "./vector3_copy.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VECTOR3_AMOUNT = 4;
static const BgcVector3FP32 _TEST_FP32_VECTOR3_LIST[] = {
    { 1.0f, 2.0f, 3.0f },
    { -3.0f, -2.0f, -1.0f },
    { 100.0f, -100.0f, 0.001f },
    { -100.0f, 100.0f, -0.001f }
};

int test_vector3_copy_fp32()
{
    BgcVector3FP32 vector;

    print_testing_name("bgc_vector3_copy_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR3_AMOUNT; i++) {
        
        bgc_vector3_copy_fp32(&_TEST_FP32_VECTOR3_LIST[i], &vector);

        if (vector.x1 != _TEST_FP32_VECTOR3_LIST[i].x1 ||
            vector.x2 != _TEST_FP32_VECTOR3_LIST[i].x2 ||
            vector.x3 != _TEST_FP32_VECTOR3_LIST[i].x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VECTOR3_AMOUNT = 4;
static const BgcVector3FP64 _TEST_FP64_VECTOR3_LIST[] = {
    { 1.0, 2.0, 3.0 },
    { -3.0, -2.0, -1.0 },
    { 100.0, -100.0, 0.001 },
    { -100.0, 100.0, -0.001 }
};

int test_vector3_copy_fp64()
{
    BgcVector3FP64 vector;

    print_testing_name("bgc_vector3_copy_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR3_AMOUNT; i++) {

        bgc_vector3_copy_fp64(&_TEST_FP64_VECTOR3_LIST[i], &vector);

        if (vector.x1 != _TEST_FP64_VECTOR3_LIST[i].x1 ||
            vector.x2 != _TEST_FP64_VECTOR3_LIST[i].x2 ||
            vector.x3 != _TEST_FP64_VECTOR3_LIST[i].x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_vector3_copy()
{
    if (test_vector3_copy_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_vector3_copy_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
