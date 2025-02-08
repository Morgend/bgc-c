#include "./vector3_swap.h"

#include <math.h>

#include "./../../helpers.h"



// ==================== FP32 ==================== //

static const int _TEST_FP32_VECTOR3_AMOUNT = 4;

static const BgcVector3FP32 _TEST_FP32_VECTOR3_LIST1[] = {
    { 1.0f, 2.0f, 3.0f },
    { -3.0f, -2.0f, -1.0f },
    { 100.0f, -100.0f, 344.7f },
    { -100.1f, 100.2f, -271.3f }
};

static const BgcVector3FP32 _TEST_FP32_VECTOR3_LIST2[] = {
    { 3.6f, 5.3f, -0.123f },
    { 204.07f, -781.89f, 891.3f },
    { -20.02f, -1.0003f, 0.9275f },
    { 1000.0f, -0.00025f, -0.419f }
};

int test_bgc_vector3_swap_fp32()
{
    BgcVector3FP32 vector1, vector2;

    print_testing_name("bgc_vector3_swap_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR3_AMOUNT; i++) {
        bgc_vector3_copy_fp32(&_TEST_FP32_VECTOR3_LIST1[i], &vector1);
        bgc_vector3_copy_fp32(&_TEST_FP32_VECTOR3_LIST2[i], &vector2);

        bgc_vector3_swap_fp32(&vector1, &vector2);

        if (vector1.x1 != _TEST_FP32_VECTOR3_LIST2[i].x1 ||
            vector1.x2 != _TEST_FP32_VECTOR3_LIST2[i].x2 ||
            vector1.x3 != _TEST_FP32_VECTOR3_LIST2[i].x3 ||
            vector2.x1 != _TEST_FP32_VECTOR3_LIST1[i].x1 ||
            vector2.x2 != _TEST_FP32_VECTOR3_LIST1[i].x2 ||
            vector2.x3 != _TEST_FP32_VECTOR3_LIST1[i].x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VECTOR3_AMOUNT = 4;

static const BgcVector3FP64 _TEST_FP64_VECTOR3_LIST1[] = {
    { 1.0, 2.0, 3.0 },
    { -3.0, -2.0, -1.0 },
    { 100.0, -100.0, 344.7 },
    { -100.1, 100.2, -271.3 }
};

static const BgcVector3FP64 _TEST_FP64_VECTOR3_LIST2[] = {
    { 3.6, 5.3, -0.123 },
    { 204.07, -781.89, 891.3 },
    { -20.02, -1.0003, 0.9275 },
    { 1000.0, -0.00025, -0.419 }
};

int test_bgc_vector3_swap_fp64()
{
    BgcVector3FP64 vector1, vector2;

    print_testing_name("bgc_vector3_swap_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR3_AMOUNT; i++) {
        bgc_vector3_copy_fp64(&_TEST_FP64_VECTOR3_LIST1[i], &vector1);
        bgc_vector3_copy_fp64(&_TEST_FP64_VECTOR3_LIST2[i], &vector2);

        bgc_vector3_swap_fp64(&vector1, &vector2);

        if (vector1.x1 != _TEST_FP64_VECTOR3_LIST2[i].x1 ||
            vector1.x2 != _TEST_FP64_VECTOR3_LIST2[i].x2 ||
            vector1.x3 != _TEST_FP64_VECTOR3_LIST2[i].x3 ||
            vector2.x1 != _TEST_FP64_VECTOR3_LIST1[i].x1 ||
            vector2.x2 != _TEST_FP64_VECTOR3_LIST1[i].x2 ||
            vector2.x3 != _TEST_FP64_VECTOR3_LIST1[i].x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}
