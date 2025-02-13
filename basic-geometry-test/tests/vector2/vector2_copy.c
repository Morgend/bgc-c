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

void test_vector2_copy_fp32()
{
    BgcVector2FP32 vector;

    print_testing_name("bgc_vector2_copy_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR2_AMOUNT; i++) {

        bgc_vector2_copy_fp32(&_TEST_FP32_VECTOR2_LIST[i], &vector);

        if (vector.x1 != _TEST_FP32_VECTOR2_LIST[i].x1 || vector.x2 != _TEST_FP32_VECTOR2_LIST[i].x2) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VECTOR2_AMOUNT = 4;
static const BgcVector2FP64 _TEST_FP64_VECTOR2_LIST[] = {
    { 1.0, 2.0 },
    { -2.0, -1.0 },
    { 100.0, -100.0 },
    { -100.0, 100.0 }
};

void test_vector2_copy_fp64()
{
    BgcVector2FP64 vector;

    print_testing_name("bgc_vector2_copy_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR2_AMOUNT; i++) {

        bgc_vector2_copy_fp64(&_TEST_FP64_VECTOR2_LIST[i], &vector);

        if (vector.x1 != _TEST_FP64_VECTOR2_LIST[i].x1 || vector.x2 != _TEST_FP64_VECTOR2_LIST[i].x2) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_vector2_copy()
{
    test_vector2_copy_fp32();
    test_vector2_copy_fp64();
}
