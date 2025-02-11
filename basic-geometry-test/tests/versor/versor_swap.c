#include "./versor_swap.h"

#include <math.h>

#include "./../../helpers.h"

typedef struct {
    float s0, x1, x2, x3;
} _TestVersorDataFP32;

typedef struct {
    double s0, x1, x2, x3;
} _TestVersorDataFP64;

// ==================== FP32 ==================== //

static const int _TEST_FP32_VERSOR_AMOUNT = 3;

static const _TestVersorDataFP32 _TEST_FP32_VERSOR_LIST1[] = {
    { 1.0f, 2.0f, 3.0f, 4.0f },
    { -4.0f, -3.0f, -2.0f, -1.0f },
    { 0.5f, -0.5f, -0.5f, -0.5f }
};

static const _TestVersorDataFP32 _TEST_FP32_VERSOR_LIST2[] = {
    { -0.5f, 0.5f, 0.5f, 0.5f },
    { -1.0f, -2.0f, -3.0f, -4.0f },
    { 4.0f, 3.0f, 2.0f, 1.0f }
};

int test_versor_swap_fp32()
{
    BgcVersorFP32 versor1a, versor2a, versor1b, versor2b;

    print_testing_name("bgc_versor_swap_fp32");

    for (int i = 0; i < _TEST_FP32_VERSOR_AMOUNT; i++) {
        bgc_versor_set_values_fp32(
            _TEST_FP32_VERSOR_LIST1[i].s0,
            _TEST_FP32_VERSOR_LIST1[i].x1,
            _TEST_FP32_VERSOR_LIST1[i].x2,
            _TEST_FP32_VERSOR_LIST1[i].x3,
            &versor1a
        );

        bgc_versor_set_values_fp32(
            _TEST_FP32_VERSOR_LIST2[i].s0,
            _TEST_FP32_VERSOR_LIST2[i].x1,
            _TEST_FP32_VERSOR_LIST2[i].x2,
            _TEST_FP32_VERSOR_LIST2[i].x3,
            &versor2a
        );

        bgc_versor_copy_fp32(&versor1a, &versor1b);
        bgc_versor_copy_fp32(&versor2a, &versor2b);

        bgc_versor_swap_fp32(&versor1b, &versor2b);

        if (versor1a.s0 != versor2b.s0 || versor1a.x1 != versor2b.x1 || versor1a.x2 != versor2b.x2 || versor1a.x3 != versor2b.x3 ||
            versor2a.s0 != versor1b.s0 || versor2a.x1 != versor1b.x1 || versor2a.x2 != versor1b.x2 || versor2a.x3 != versor1b.x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

int test_versor_swap_fp64()
{
    BgcVersorFP64 versor1a, versor2a, versor1b, versor2b;

    print_testing_name("bgc_versor_swap_fp64");

    for (int i = 0; i < _TEST_FP32_VERSOR_AMOUNT; i++) {
        bgc_versor_set_values_fp64(
            _TEST_FP32_VERSOR_LIST1[i].s0,
            _TEST_FP32_VERSOR_LIST1[i].x1,
            _TEST_FP32_VERSOR_LIST1[i].x2,
            _TEST_FP32_VERSOR_LIST1[i].x3,
            &versor1a
        );

        bgc_versor_set_values_fp64(
            _TEST_FP32_VERSOR_LIST2[i].s0,
            _TEST_FP32_VERSOR_LIST2[i].x1,
            _TEST_FP32_VERSOR_LIST2[i].x2,
            _TEST_FP32_VERSOR_LIST2[i].x3,
            &versor2a
        );

        bgc_versor_copy_fp64(&versor1a, &versor1b);
        bgc_versor_copy_fp64(&versor2a, &versor2b);

        bgc_versor_swap_fp64(&versor1b, &versor2b);

        if (versor1a.s0 != versor2b.s0 || versor1a.x1 != versor2b.x1 || versor1a.x2 != versor2b.x2 || versor1a.x3 != versor2b.x3 ||
            versor2a.s0 != versor1b.s0 || versor2a.x1 != versor1b.x1 || versor2a.x2 != versor1b.x2 || versor2a.x3 != versor1b.x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_versor_swap()
{
    if (test_versor_swap_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_versor_swap_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
