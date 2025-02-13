#include "./quaternion_swap.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_QUATERNION_AMOUNT = 4;

static const BgcQuaternionFP32 _TEST_FP32_QUATERNION_LIST1[] = {
    { 1.0f, 2.0f, 3.0f, 4.0f },
    { -4.0f, -3.0f, -2.0f, -1.0f },
    { -244.8f, 100.0f, -100.0f, 344.7f },
    { 1000.32f, -100.1f, 100.2f, -271.3f }
};

static const BgcQuaternionFP32 _TEST_FP32_QUATERNION_LIST2[] = {
    { 3.6f, -0.123f, 5.3f, 1003.28f },
    { 204.07f, -781.89f, -0.0032f, 891.3f },
    { -20.02f, -1.0003f, 5.322f, 0.9275f },
    { 1000.0f, -0.00025f, -0.419f, 0.844f }
};

void test_quaternion_swap_fp32()
{
    BgcQuaternionFP32 quaternion1, quaternion2;

    print_testing_name("bgc_quaternion_swap_fp32");

    for (int i = 0; i < _TEST_FP32_QUATERNION_AMOUNT; i++) {
        bgc_quaternion_copy_fp32(&_TEST_FP32_QUATERNION_LIST1[i], &quaternion1);
        bgc_quaternion_copy_fp32(&_TEST_FP32_QUATERNION_LIST2[i], &quaternion2);

        bgc_quaternion_swap_fp32(&quaternion1, &quaternion2);

        if (quaternion1.s0 != _TEST_FP32_QUATERNION_LIST2[i].s0 ||
            quaternion1.x1 != _TEST_FP32_QUATERNION_LIST2[i].x1 ||
            quaternion1.x2 != _TEST_FP32_QUATERNION_LIST2[i].x2 ||
            quaternion1.x3 != _TEST_FP32_QUATERNION_LIST2[i].x3 ||
            quaternion2.s0 != _TEST_FP32_QUATERNION_LIST1[i].s0 ||
            quaternion2.x1 != _TEST_FP32_QUATERNION_LIST1[i].x1 ||
            quaternion2.x2 != _TEST_FP32_QUATERNION_LIST1[i].x2 ||
            quaternion2.x3 != _TEST_FP32_QUATERNION_LIST1[i].x3) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_QUATERNION_AMOUNT = 4;

static const BgcQuaternionFP64 _TEST_FP64_QUATERNION_LIST1[] = {
    { 1.0, 2.0, 3.0, 4.0 },
    { -4.0, -3.0, -2.0, -1.0 },
    { -244.8, 100.0, -100.0, 344.7 },
    { 1000.32, -100.1, 100.2, -271.3 }
};

static const BgcQuaternionFP64 _TEST_FP64_QUATERNION_LIST2[] = {
    { 3.6, -0.123, 5.3, 1003.28 },
    { 204.07, -781.89, -0.0032, 891.3 },
    { -20.02, -1.0003, 5.322, 0.9275 },
    { 1000.0, -0.00025, -0.419, 0.844 }
};

void test_quaternion_swap_fp64()
{
    BgcQuaternionFP64 quaternion1, quaternion2;

    print_testing_name("bgc_quaternion_swap_fp64");

    for (int i = 0; i < _TEST_FP64_QUATERNION_AMOUNT; i++) {
        bgc_quaternion_copy_fp64(&_TEST_FP64_QUATERNION_LIST1[i], &quaternion1);
        bgc_quaternion_copy_fp64(&_TEST_FP64_QUATERNION_LIST2[i], &quaternion2);

        bgc_quaternion_swap_fp64(&quaternion1, &quaternion2);

        if (quaternion1.s0 != _TEST_FP64_QUATERNION_LIST2[i].s0 ||
            quaternion1.x1 != _TEST_FP64_QUATERNION_LIST2[i].x1 ||
            quaternion1.x2 != _TEST_FP64_QUATERNION_LIST2[i].x2 ||
            quaternion1.x3 != _TEST_FP64_QUATERNION_LIST2[i].x3 ||
            quaternion2.s0 != _TEST_FP64_QUATERNION_LIST1[i].s0 ||
            quaternion2.x1 != _TEST_FP64_QUATERNION_LIST1[i].x1 ||
            quaternion2.x2 != _TEST_FP64_QUATERNION_LIST1[i].x2 ||
            quaternion2.x3 != _TEST_FP64_QUATERNION_LIST1[i].x3) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_quaternion_swap()
{
    test_quaternion_swap_fp32();
    test_quaternion_swap_fp64();
}
