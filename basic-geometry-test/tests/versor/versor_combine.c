#include "./versor_combine.h"

#include <math.h>

#include "./../../helpers.h"

typedef struct {
    BgcVersorFP32 first, second, result;
} _TestVersorTripletFP32;

typedef struct {
    BgcVersorFP64 first, second, result;
} _TestVersorTripletFP64;

// ==================== FP32 ==================== //

static const int _TEST_FP32_VERSOR_TRIPLET_AMOUNT = 5;

static const _TestVersorTripletFP32 _TEST_FP32_VERSOR_TRIPLET_LIST[] = {
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f, 0.0f, 0.0f, 0.0f }
    },
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { -1.0f, 0.0f, 0.0f, 0.0f },
        { -1.0f, 0.0f, 0.0f, 0.0f }
    },
    {
        { 0.182574185835f, 0.36514837167f, 0.54772255751f, 0.73029674334f },
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.182574185835f, 0.36514837167f, 0.54772255751f, 0.73029674334f }
    },
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 0.182574185835f, 0.36514837167f, 0.54772255751f, 0.73029674334f },
        { 0.182574185835f, 0.36514837167f, 0.54772255751f, 0.73029674334f }
    },
    {
        { 0.7071067812f, 0.7071067812f, 0.0f, 0.0f },
        { 0.7071067812f, 0.0f, 0.0f, 0.7071067812f },
        { 0.5f, 0.5f, 0.5f, 0.5f }
    }
};

int test_versor_combine_fp32()
{
    BgcVersorFP32 versor;

    print_testing_name("bgc_versor_combine_fp32");

    for (int i = 0; i < _TEST_FP32_VERSOR_TRIPLET_AMOUNT; i++) {
        bgc_versor_combine_fp32(&_TEST_FP32_VERSOR_TRIPLET_LIST[i].second, &_TEST_FP32_VERSOR_TRIPLET_LIST[i].first, &versor);

        if (!bgc_versor_are_close_fp32(&versor, &_TEST_FP32_VERSOR_TRIPLET_LIST[i].result)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VERSOR_TRIPLET_AMOUNT = 5;

static const _TestVersorTripletFP64 _TEST_FP64_VERSOR_TRIPLET_LIST[] = {
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 1.0, 0.0, 0.0, 0.0 },
        { 1.0, 0.0, 0.0, 0.0 }
    },
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { -1.0, 0.0, 0.0, 0.0 },
        { -1.0, 0.0, 0.0, 0.0 }
    },
    {
        { 0.1825741858350553712, 0.3651483716701107423, 0.5477225575051661135, 0.7302967433402214846 },
        { 1.0, 0.0, 0.0, 0.0 },
        { 0.1825741858350553712, 0.3651483716701107423, 0.5477225575051661135, 0.7302967433402214846 }
    },
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 0.1825741858350553712, 0.3651483716701107423, 0.5477225575051661135, 0.7302967433402214846 },
        { 0.1825741858350553712, 0.3651483716701107423, 0.5477225575051661135, 0.7302967433402214846 }
    },
    {
        { 0.7071067811865475, 0.7071067811865475, 0.0, 0.0 },
        { 0.7071067811865475, 0.0, 0.0, 0.7071067811865475 },
        { 0.5, 0.5, 0.5, 0.5 }
    }
};

int test_versor_combine_fp64()
{
    BgcVersorFP64 versor;

    print_testing_name("bgc_versor_combine_fp64");

    for (int i = 0; i < _TEST_FP64_VERSOR_TRIPLET_AMOUNT; i++) {
        bgc_versor_combine_fp64(&_TEST_FP64_VERSOR_TRIPLET_LIST[i].second, &_TEST_FP64_VERSOR_TRIPLET_LIST[i].first, &versor);

        if (!bgc_versor_are_close_fp64(&versor, &_TEST_FP64_VERSOR_TRIPLET_LIST[i].result)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_versor_combine()
{
    if (test_versor_combine_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_versor_combine_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
