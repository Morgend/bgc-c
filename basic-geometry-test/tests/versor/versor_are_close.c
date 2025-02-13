#include "versor_are_close.h"

#include "../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_CLOSE_VERSOR_PAIR_AMOUNT = 10;

static const TestVersorPairFP32 _TEST_FP32_CLOSE_VERSOR_PAIR_LIST[] = {
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f + 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f }
    },
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f - 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f }
    },
    {
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f + 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f }
    },
    {
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f - 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f }
    },
    {
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f + 0.75f * BGC_EPSYLON_FP32, 0.0f }
    },
    {
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f - 0.75f * BGC_EPSYLON_FP32, 0.0f }
    },
    {
        { 0.0f, 0.0f, 0.0f, 1.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f + 0.75f * BGC_EPSYLON_FP32 }
    },
    {
        { 0.0f, 0.0f, 0.0f, 1.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f - 0.75f * BGC_EPSYLON_FP32 }
    },
    {
        { 0.70710678f, 0.0f, 0.70710675f, 0.0f },
        { 0.70710675f, 0.0f, 0.70710678f, 0.0f }
    },
    {
        { 0.0f, -0.70710678f, 0.0f, -0.70710675f },
        { 0.0f, -0.70710675f, 0.0f, -0.70710678f }
    }
};

static const int _TEST_FP32_DIFFERENT_VERSOR_PAIR_AMOUNT = 10;

static const TestVersorPairFP32 _TEST_FP32_DIFFERENT_VERSOR_PAIR_LIST[] = {
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f + 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f }
    },
    {
        { 1.0f, 0.0f, 0.0f, 0.0f },
        { 1.0f - 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f }
    },
    {
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f + 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f }
    },
    {
        { 0.0f, 1.0f, 0.0f, 0.0f },
        { 0.0f, 1.0f - 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f }
    },
    {
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f + 1.25f * BGC_EPSYLON_FP32, 0.0f }
    },
    {
        { 0.0f, 0.0f, 1.0f, 0.0f },
        { 0.0f, 0.0f, 1.0f - 1.25f * BGC_EPSYLON_FP32, 0.0f }
    },
    {
        { 0.0f, 0.0f, 0.0f, 1.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f + 1.25f * BGC_EPSYLON_FP32 }
    },
    {
        { 0.0f, 0.0f, 0.0f, 1.0f },
        { 0.0f, 0.0f, 0.0f, 1.0f - 1.25f * BGC_EPSYLON_FP32 }
    },
    {
        { 0.707106f, 0.0f, 0.707107f, 0.0f },
        { 0.707107f, 0.0f, 0.707106f, 0.0f }
    },
    {
        { 0.0f, -0.707107f, 0.0f, -0.707106f },
        { 0.0f, -0.707106f, 0.0f, -0.707107f }
    }
};

void test_versor_are_close_fp32()
{
    print_testing_name("bgc_versor_are_close_fp32");

    // Testing close pairs of versors:
    for (int i = 0; i < _TEST_FP32_CLOSE_VERSOR_PAIR_AMOUNT; i++) {
        if (!bgc_versor_are_close_fp32(&_TEST_FP32_CLOSE_VERSOR_PAIR_LIST[i].first, &_TEST_FP32_CLOSE_VERSOR_PAIR_LIST[i].second)) {
            print_testing_error("A pair of close versors was not recognized");
            return;
        }
    }

    // Testing different pairs of versors:
    for (int i = 0; i < _TEST_FP32_DIFFERENT_VERSOR_PAIR_AMOUNT; i++) {
        if (bgc_versor_are_close_fp32(&_TEST_FP32_DIFFERENT_VERSOR_PAIR_LIST[i].first, &_TEST_FP32_DIFFERENT_VERSOR_PAIR_LIST[i].second)) {
            print_testing_error("A pair of different versors was recognized as close versors");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //


static const int _TEST_FP64_CLOSE_VERSOR_PAIR_AMOUNT = 10;

static const TestVersorPairFP64 _TEST_FP64_CLOSE_VERSOR_PAIR_LIST[] = {
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 1.0 + 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 }
    },
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 1.0 - 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 }
    },
    {
        { 0.0, 1.0, 0.0, 0.0 },
        { 0.0, 1.0 + 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 }
    },
    {
        { 0.0, 1.0, 0.0, 0.0 },
        { 0.0, 1.0 - 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 }
    },
    {
        { 0.0, 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 1.0 + 0.75 * BGC_EPSYLON_FP64, 0.0 }
    },
    {
        { 0.0, 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 1.0 - 0.75 * BGC_EPSYLON_FP64, 0.0 }
    },
    {
        { 0.0, 0.0, 0.0, 1.0 },
        { 0.0, 0.0, 0.0, 1.0 + 0.75 * BGC_EPSYLON_FP64 }
    },
    {
        { 0.0, 0.0, 0.0, 1.0 },
        { 0.0, 0.0, 0.0, 1.0 - 0.75 * BGC_EPSYLON_FP64 }
    },
    {
        { 0.7071067811865475244, 0.0, 0.7071067811865465244, 0.0 },
        { 0.7071067811865465244, 0.0, 0.7071067811865475244, 0.0 }
    },
    {
        { 0.0, -0.7071067811865475244, 0.0, -0.7071067811865465244 },
        { 0.0, -0.7071067811865465244, 0.0, -0.7071067811865475244 }
    }
};

static const int _TEST_FP64_DIFFERENT_VERSOR_PAIR_AMOUNT = 10;

static const TestVersorPairFP64 _TEST_FP64_DIFFERENT_VERSOR_PAIR_LIST[] = {
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 1.0 + 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 }
    },
    {
        { 1.0, 0.0, 0.0, 0.0 },
        { 1.0 - 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 }
    },
    {
        { 0.0, 1.0, 0.0, 0.0 },
        { 0.0, 1.0 + 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 }
    },
    {
        { 0.0, 1.0, 0.0, 0.0 },
        { 0.0, 1.0 - 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0 }
    },
    {
        { 0.0, 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 1.0 + 1.25 * BGC_EPSYLON_FP64, 0.0 }
    },
    {
        { 0.0, 0.0, 1.0, 0.0 },
        { 0.0, 0.0, 1.0 - 1.25 * BGC_EPSYLON_FP64, 0.0 }
    },
    {
        { 0.0, 0.0, 0.0, 1.0 },
        { 0.0, 0.0, 0.0, 1.0 + 1.25 * BGC_EPSYLON_FP64 }
    },
    {
        { 0.0, 0.0, 0.0, 1.0 },
        { 0.0, 0.0, 0.0, 1.0 - 1.25 * BGC_EPSYLON_FP64 }
    },
    {
        { 0.7071067811866, 0.0, 0.7071067811865, 0.0 },
        { 0.7071067811865, 0.0, 0.7071067811866, 0.0 }
    },
    {
        { 0.0, -0.7071067811866, 0.0, -0.7071067811865 },
        { 0.0, -0.7071067811865, 0.0, -0.7071067811866 }
    }
};

void test_versor_are_close_fp64()
{
    print_testing_name("bgc_versor_are_close_fp64");

    // Testing close pairs of versors:
    for (int i = 0; i < _TEST_FP64_CLOSE_VERSOR_PAIR_AMOUNT; i++) {
        if (!bgc_versor_are_close_fp64(&_TEST_FP64_CLOSE_VERSOR_PAIR_LIST[i].first, &_TEST_FP64_CLOSE_VERSOR_PAIR_LIST[i].second)) {
            print_testing_error("A pair of close versors was not recognized");
            return;
        }
    }

    // Testing different pairs of versors:
    for (int i = 0; i < _TEST_FP64_DIFFERENT_VERSOR_PAIR_AMOUNT; i++) {
        if (bgc_versor_are_close_fp64(&_TEST_FP64_DIFFERENT_VERSOR_PAIR_LIST[i].first, &_TEST_FP64_DIFFERENT_VERSOR_PAIR_LIST[i].second)) {
            print_testing_error("A pair of different versors was recognized as close versors");
            return;
        }
    }

    print_testing_success();
}

void test_versor_are_close()
{
    test_versor_are_close_fp32();
    test_versor_are_close_fp64();
}
