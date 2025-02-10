#include "./versor_copy.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VERSOR_AMOUNT = 8;
static const BgcVersorFP32 _TEST_FP32_VERSOR_LIST[] = {
    { 1.0f, 0.0f, 0.0f, 0.0f },
    { -1.0f, 0.0f, 0.0f, 0.0f },
    { 0.182574185835f, 0.36514837167f, 0.54772255751f, 0.73029674334f },
    { 0.182574185835f, -0.36514837167f, 0.54772255751f, -0.73029674334f },
    { 0.5f, 0.5f, 0.5f, 0.5f },
    { 0.5f, -0.5f, -0.5f, -0.5f },
    { 0.7071067812f, -0.7071067812f, 0.0f, 0.0f },
    { 0.7071067812f, 0.0f, 0.0f, -0.7071067812f }
};

int test_bgc_versor_copy_fp32()
{
    BgcVersorFP32 versor;

    print_testing_name("bgc_versor_copy_fp32");

    for (int i = 0; i < _TEST_FP32_VERSOR_AMOUNT; i++) {
        
        bgc_versor_copy_fp32(&_TEST_FP32_VERSOR_LIST[i], &versor);

        if (versor.s0 != _TEST_FP32_VERSOR_LIST[i].s0 ||
            versor.x1 != _TEST_FP32_VERSOR_LIST[i].x1 ||
            versor.x2 != _TEST_FP32_VERSOR_LIST[i].x2 ||
            versor.x3 != _TEST_FP32_VERSOR_LIST[i].x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VERSOR_AMOUNT = 8;
static const BgcVersorFP64 _TEST_FP64_VERSOR_LIST[] = {
    { 1.0f, 0.0f, 0.0f, 0.0f },
    { -1.0f, 0.0f, 0.0f, 0.0f },
    { 0.1825741858350553712, 0.3651483716701107423, 0.5477225575051661135, 0.7302967433402214846 },
    { 0.1825741858350553712, -0.3651483716701107423, 0.5477225575051661135, -0.7302967433402214846 },
    { 0.5f, 0.5f, 0.5f, 0.5f },
    { 0.5f, -0.5f, -0.5f, -0.5f },
    { 0.7071067811865475, -0.7071067811865475, 0.0, 0.0 },
    { 0.7071067811865475, 0.0, 0.0, -0.7071067811865475 }
};

int test_bgc_versor_copy_fp64()
{
    BgcVersorFP64 versor;

    print_testing_name("bgc_versor_copy_fp64");

    for (int i = 0; i < _TEST_FP64_VERSOR_AMOUNT; i++) {

        bgc_versor_copy_fp64(&_TEST_FP64_VERSOR_LIST[i], &versor);

        if (versor.s0 != _TEST_FP64_VERSOR_LIST[i].s0 ||
            versor.x1 != _TEST_FP64_VERSOR_LIST[i].x1 ||
            versor.x2 != _TEST_FP64_VERSOR_LIST[i].x2 ||
            versor.x3 != _TEST_FP64_VERSOR_LIST[i].x3) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_bgc_versor_copy()
{
    if (test_bgc_versor_copy_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_bgc_versor_copy_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
