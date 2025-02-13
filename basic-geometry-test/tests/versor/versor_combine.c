#include "./versor_combine.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VERSOR_TRIPLET_AMOUNT = 5;

static const TestVersorTripletFP32 _TEST_FP32_VERSOR_TRIPLET_LIST[] = {
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

void test_versor_combine_fp32()
{
    BgcVersorFP32 versor;

    print_testing_name("bgc_versor_combine_fp32");

    for (int i = 0; i < _TEST_FP32_VERSOR_TRIPLET_AMOUNT; i++) {
        bgc_versor_combine_fp32(&_TEST_FP32_VERSOR_TRIPLET_LIST[i].second, &_TEST_FP32_VERSOR_TRIPLET_LIST[i].first, &versor);

        if (!bgc_versor_are_close_fp32(&versor, &_TEST_FP32_VERSOR_TRIPLET_LIST[i].result)) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VERSOR_TRIPLET_AMOUNT = 5;

static const TestVersorTripletFP64 _TEST_FP64_VERSOR_TRIPLET_LIST[] = {
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

void test_versor_combine_fp64()
{
    BgcVersorFP64 versor;

    print_testing_name("bgc_versor_combine_fp64");

    for (int i = 0; i < _TEST_FP64_VERSOR_TRIPLET_AMOUNT; i++) {
        bgc_versor_combine_fp64(&_TEST_FP64_VERSOR_TRIPLET_LIST[i].second, &_TEST_FP64_VERSOR_TRIPLET_LIST[i].first, &versor);

        if (!bgc_versor_are_close_fp64(&versor, &_TEST_FP64_VERSOR_TRIPLET_LIST[i].result)) {
            print_testing_failed();
            return;
        }
    }

    print_testing_success();
}

void test_versor_combine()
{
    test_versor_combine_fp32();
    test_versor_combine_fp64();
}
