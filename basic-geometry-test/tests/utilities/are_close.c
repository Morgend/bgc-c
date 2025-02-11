#include "./are_close.h"

#include "./../../helpers.h"

typedef struct {
    float number1, number2;
} _TestNumberPairFP32;

typedef struct {
    double number1, number2;
} _TestNumberPairFP64;

// ==================== FP32 ==================== //

static const int _TEST_FP32_CLOSE_NUMBERS_AMOUNT = 16;
static const int _TEST_FP32_DIFFERENT_NUMBERS_AMOUNT = 12;

static const _TestNumberPairFP32 _TEST_FP32_DATA_CLOSE[] = {
    {0.0f, 0.0f},
    {1.0f, 1.0f},
    {-1.0f, -1.0f},

    {-0.4f * BGC_EPSYLON_FP32, 0.4f * BGC_EPSYLON_FP32},

    {1.0f, 1.0f + 0.75f * BGC_EPSYLON_FP32},
    {1.0f, 1.0f - 0.75f * BGC_EPSYLON_FP32},
    {1.0f + 0.75f * BGC_EPSYLON_FP32, 1.0f},
    {1.0f - 0.75f * BGC_EPSYLON_FP32, 1.0f},

    {-1.0f, -1.0f + 0.75f * BGC_EPSYLON_FP32},
    {-1.0f, -1.0f - 0.75f * BGC_EPSYLON_FP32},
    {-1.0f + 0.75f * BGC_EPSYLON_FP32, -1.0f},
    {-1.0f - 0.75f * BGC_EPSYLON_FP32, -1.0f},

    {100.0f, 100.0f * (1.0f + 0.75f * BGC_EPSYLON_FP32)},
    {100.0f, 100.0f * (1.0f - 0.75f * BGC_EPSYLON_FP32)},
    {-100.0f, -100.0f * (1.0f + 0.75f * BGC_EPSYLON_FP32)},
    {-100.0f, -100.0f * (1.0f - 0.75f * BGC_EPSYLON_FP32)}
};

static const _TestNumberPairFP32 _TEST_FP32_DATA_DIFFERENT[] = {
    {0.0f, 0.001f},
    {1.0f, 0.999f},
    {-1.0f, -0.999f},

    {-0.6f * BGC_EPSYLON_FP32, 0.6f * BGC_EPSYLON_FP32},

    {1.0f, 1.0f + 1.25f * BGC_EPSYLON_FP32},
    {1.0f, 1.0f - 1.25f * BGC_EPSYLON_FP32},
    {1.0f + 1.25f * BGC_EPSYLON_FP32, 1.0f},
    {1.0f - 1.25f * BGC_EPSYLON_FP32, 1.0f},

    {-1.0f, -1.0f + 1.25f * BGC_EPSYLON_FP32},
    {-1.0f, -1.0f - 1.25f * BGC_EPSYLON_FP32},
    {-1.0f + 1.25f * BGC_EPSYLON_FP32, -1.0f},
    {-1.0f - 1.25f * BGC_EPSYLON_FP32, -1.0f},

    {100.0f, 100.0f * (1.0f + 1.25f * BGC_EPSYLON_FP32)},
    {100.0f, 100.0f * (1.0f - 1.25f * BGC_EPSYLON_FP32)},
    {-100.0f, -100.0f * (1.0f + 1.25f * BGC_EPSYLON_FP32)},
    {-100.0f, -100.0f * (1.0f - 1.25f * BGC_EPSYLON_FP32)}
};

int test_are_close_fp32()
{
    print_testing_name("bgc_are_close_fp32");

    // Testing close pairs of values:
    for (int i = 0; i < _TEST_FP32_CLOSE_NUMBERS_AMOUNT; i++) {
        if (!bgc_are_close_fp32(_TEST_FP32_DATA_CLOSE[i].number1, _TEST_FP32_DATA_CLOSE[i].number2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing different pairs of values:
    for (int i = 0; i < _TEST_FP32_DIFFERENT_NUMBERS_AMOUNT; i++) {
        if (bgc_are_close_fp32(_TEST_FP32_DATA_DIFFERENT[i].number1, _TEST_FP32_DATA_DIFFERENT[i].number2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_CLOSE_NUMBERS_AMOUNT = 16;
static const int _TEST_FP64_DIFFERENT_NUMBERS_AMOUNT = 16;

static const _TestNumberPairFP64 _TEST_FP64_DATA_CLOSE[] = {
    {0.0, 0.0},
    {1.0, 1.0},
    {-1.0, -1.0},

    {-0.4 * BGC_EPSYLON_FP64, 0.4 * BGC_EPSYLON_FP64},

    {1.0, 1.0 + 0.75 * BGC_EPSYLON_FP64},
    {1.0, 1.0 - 0.75 * BGC_EPSYLON_FP64},
    {1.0 + 0.75 * BGC_EPSYLON_FP64, 1.0},
    {1.0 - 0.75 * BGC_EPSYLON_FP64, 1.0},

    {-1.0, -1.0 + 0.75 * BGC_EPSYLON_FP64},
    {-1.0, -1.0 - 0.75 * BGC_EPSYLON_FP64},
    {-1.0 + 0.75 * BGC_EPSYLON_FP64, -1.0},
    {-1.0 - 0.75 * BGC_EPSYLON_FP64, -1.0},

    {100.0, 100.0 * (1.0 + 0.75 * BGC_EPSYLON_FP64)},
    {100.0, 100.0 * (1.0 - 0.75 * BGC_EPSYLON_FP64)},
    {-100.0, -100.0 * (1.0 + 0.75 * BGC_EPSYLON_FP64)},
    {-100.0, -100.0 * (1.0 - 0.75 * BGC_EPSYLON_FP64)}
};

static const _TestNumberPairFP64 _TEST_FP64_DATA_DIFFERENT[] = {
    {0.0, 0.000001},
    {1.0, 0.999999},
    {-1.0, -0.999999},

    {-0.6 * BGC_EPSYLON_FP64, 0.6 * BGC_EPSYLON_FP64},

    {1.0, 1.0 + 1.25 * BGC_EPSYLON_FP64},
    {1.0, 1.0 - 1.25 * BGC_EPSYLON_FP64},
    {1.0 + 1.25 * BGC_EPSYLON_FP64, 1.0},
    {1.0 - 1.25 * BGC_EPSYLON_FP64, 1.0},

    {-1.0, -1.0 + 1.25 * BGC_EPSYLON_FP64},
    {-1.0, -1.0 - 1.25 * BGC_EPSYLON_FP64},
    {-1.0 + 1.25 * BGC_EPSYLON_FP64, -1.0},
    {-1.0 - 1.25 * BGC_EPSYLON_FP64, -1.0},

    {100.0, 100.0 * (1.0 + 1.25 * BGC_EPSYLON_FP64)},
    {100.0, 100.0 * (1.0 - 1.25 * BGC_EPSYLON_FP64)},
    {-100.0, -100.0 * (1.0 + 1.25 * BGC_EPSYLON_FP64)},
    {-100.0, -100.0 * (1.0 - 1.25 * BGC_EPSYLON_FP64)}
};

int test_are_close_fp64()
{
    print_testing_name("bgc_are_close_fp64");

    // Testing close pairs of values:
    for (int i = 0; i < _TEST_FP64_CLOSE_NUMBERS_AMOUNT; i++) {
        if (!bgc_are_close_fp64(_TEST_FP64_DATA_CLOSE[i].number1, _TEST_FP64_DATA_CLOSE[i].number2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    // Testing different pairs of values:
    for (int i = 0; i < _TEST_FP64_DIFFERENT_NUMBERS_AMOUNT; i++) {
        if (bgc_are_close_fp64(_TEST_FP64_DATA_DIFFERENT[i].number1, _TEST_FP64_DATA_DIFFERENT[i].number2)) {
            print_testing_failed();
            return TEST_FAILED;
        }
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_are_close()
{
    if (test_are_close_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_are_close_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
