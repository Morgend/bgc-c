#include "./vector2_swap.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VECTOR2_AMOUNT = 4;

static const BgcVector2FP32 _TEST_FP32_VECTOR2_LIST1[] = {
    { 1.0f, 2.0f },
    { -2.0f, -1.0f },
    { 100.0f, -100.0f },
    { -100.1f, 100.2f }
};

static const BgcVector2FP32 _TEST_FP32_VECTOR2_LIST2[] = {
    { 3.6f, 5.3f },
    { 204.07f, -781.89f },
    { -20.02f, -1.0003f },
    { 1000.0f, -0.00025f }
};

void test_vector2_swap_fp32()
{
    BgcVector2FP32 vector1, vector2;

    print_testing_name("bgc_vector2_swap_fp32");

    for (int i = 0; i < _TEST_FP32_VECTOR2_AMOUNT; i++) {
        bgc_vector2_copy_fp32(&_TEST_FP32_VECTOR2_LIST1[i], &vector1);
        bgc_vector2_copy_fp32(&_TEST_FP32_VECTOR2_LIST2[i], &vector2);

        bgc_vector2_swap_fp32(&vector1, &vector2);

        if (vector1.x1 != _TEST_FP32_VECTOR2_LIST2[i].x1 ||
            vector1.x2 != _TEST_FP32_VECTOR2_LIST2[i].x2 ||
            vector2.x1 != _TEST_FP32_VECTOR2_LIST1[i].x1 ||
            vector2.x2 != _TEST_FP32_VECTOR2_LIST1[i].x2) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VECTOR2_AMOUNT = 4;

static const BgcVector2FP64 _TEST_FP64_VECTOR2_LIST1[] = {
    { 1.0, 2.0 },
    { -2.0, -1.0 },
    { 100.0, -100.0 },
    { -100.1, 100.2 }
};

static const BgcVector2FP64 _TEST_FP64_VECTOR2_LIST2[] = {
    { 3.6, 5.3 },
    { 204.07, -781.89 },
    { -20.02, -1.0003 },
    { 1000.0, -0.00025 }
};

void test_vector2_swap_fp64()
{
    BgcVector2FP64 vector1, vector2;

    print_testing_name("bgc_vector2_swap_fp64");

    for (int i = 0; i < _TEST_FP64_VECTOR2_AMOUNT; i++) {
        bgc_vector2_copy_fp64(&_TEST_FP64_VECTOR2_LIST1[i], &vector1);
        bgc_vector2_copy_fp64(&_TEST_FP64_VECTOR2_LIST2[i], &vector2);

        bgc_vector2_swap_fp64(&vector1, &vector2);

        if (vector1.x1 != _TEST_FP64_VECTOR2_LIST2[i].x1 ||
            vector1.x2 != _TEST_FP64_VECTOR2_LIST2[i].x2 ||
            vector2.x1 != _TEST_FP64_VECTOR2_LIST1[i].x1 ||
            vector2.x2 != _TEST_FP64_VECTOR2_LIST1[i].x2) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_vector2_swap()
{
    test_vector2_swap_fp32();
    test_vector2_swap_fp64();
}
