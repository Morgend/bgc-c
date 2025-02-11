#include "versor_are_close.h"

#include "../../helpers.h"

typedef struct {
    BgcVersorFP32 versor1, versor2;
} _TestVersorPairFP32;

typedef struct {
    BgcVersorFP64 versor1, versor2;
} _TestVersorPairFP64;

// ==================== FP32 ==================== //

static const int _TEST_FP32_CLOSE_VERSOR_PAIR_AMOUNT = 10;

static const _TestVersorPairFP32 _TEST_FP32_CLOSE_VERSOR_PAIR_LIST[] = {
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

static const _TestVersorPairFP32 _TEST_FP32_DIFFERENT_VERSOR_PAIR_LIST[] = {
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

int test_versor_are_close_fp32()
{
    print_testing_name("bgc_versor_are_close_fp32");

    // Testing close pairs of versors:
    for (int i = 0; i < _TEST_FP32_CLOSE_VERSOR_PAIR_AMOUNT; i++) {
        if (!bgc_versor_are_close_fp32(&_TEST_FP32_CLOSE_VERSOR_PAIR_LIST[i].versor1, &_TEST_FP32_CLOSE_VERSOR_PAIR_LIST[i].versor2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing different pairs of versors:
    for (int i = 0; i < _TEST_FP32_DIFFERENT_VERSOR_PAIR_AMOUNT; i++) {
        if (bgc_versor_are_close_fp32(&_TEST_FP32_DIFFERENT_VERSOR_PAIR_LIST[i].versor1, &_TEST_FP32_DIFFERENT_VERSOR_PAIR_LIST[i].versor2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //


static const int _TEST_FP64_CLOSE_VERSOR_PAIR_AMOUNT = 10;

static const _TestVersorPairFP64 _TEST_FP64_CLOSE_VERSOR_PAIR_LIST[] = {
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

static const _TestVersorPairFP64 _TEST_FP64_DIFFERENT_VERSOR_PAIR_LIST[] = {
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

int test_versor_are_close_fp64()
{
    print_testing_name("bgc_versor_are_close_fp64");

    // Testing close pairs of versors:
    for (int i = 0; i < _TEST_FP64_CLOSE_VERSOR_PAIR_AMOUNT; i++) {
        if (!bgc_versor_are_close_fp64(&_TEST_FP64_CLOSE_VERSOR_PAIR_LIST[i].versor1, &_TEST_FP64_CLOSE_VERSOR_PAIR_LIST[i].versor2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing different pairs of versors:
    for (int i = 0; i < _TEST_FP64_DIFFERENT_VERSOR_PAIR_AMOUNT; i++) {
        if (bgc_versor_are_close_fp64(&_TEST_FP64_DIFFERENT_VERSOR_PAIR_LIST[i].versor1, &_TEST_FP64_DIFFERENT_VERSOR_PAIR_LIST[i].versor2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_versor_are_close()
{
    if (test_versor_are_close_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_versor_are_close_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
