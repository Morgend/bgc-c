#include "./versor_set_values.h"

#include <math.h>

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_VERSOR_DATA_AMOUNT = 4;
static const BgcQuaternionFP32 _TEST_FP32_VERSOR_DATA_LIST[] = {
    { 1.0f, 2.0f, 3.0f, 4.0f },
    { 4.0f, 3.0f, 2.0f, 1.0f },
    { -1.0f, 0.0f, 0.0f, 0.0f },
    { 1.0f, 0.0f, 1.0f, 0.0f }
};

void test_versor_set_values_fp32()
{
    float versor_module, ratio;
    BgcVersorFP32 versor;

    print_testing_name("bgc_versor_set_values_fp32");

    for (int i = 0; i < _TEST_FP32_VERSOR_DATA_AMOUNT; i++) {
        bgc_versor_set_values_fp32(
            _TEST_FP32_VERSOR_DATA_LIST[i].s0,
            _TEST_FP32_VERSOR_DATA_LIST[i].x1,
            _TEST_FP32_VERSOR_DATA_LIST[i].x2,
            _TEST_FP32_VERSOR_DATA_LIST[i].x3,
            &versor
        );

        versor_module = sqrtf(versor.s0 * versor.s0 + versor.x1 * versor.x1 + versor.x2 * versor.x2 + versor.x3 * versor.x3);

        if (!bgc_is_unit_fp32(versor_module)) {
            print_testing_error("Versor module is not equal to one.");
            return;
        }

        if (bgc_is_zero_fp32(_TEST_FP32_VERSOR_DATA_LIST[i].s0)) {
            continue;
        }

        ratio = _TEST_FP32_VERSOR_DATA_LIST[i].s0 / versor.s0;

        if (!bgc_is_zero_fp32(_TEST_FP32_VERSOR_DATA_LIST[i].x1) && !bgc_are_close_fp32(ratio, _TEST_FP32_VERSOR_DATA_LIST[i].x1 / versor.x1)) {
            print_testing_error("Versor was not normalized proportionally (x1).");
            return;
        }

        if (!bgc_is_zero_fp32(_TEST_FP32_VERSOR_DATA_LIST[i].x2) && !bgc_are_close_fp32(ratio, _TEST_FP32_VERSOR_DATA_LIST[i].x2 / versor.x2)) {
            print_testing_error("Versor was not normalized proportionally (x2).");
            return;
        }

        if (!bgc_is_zero_fp32(_TEST_FP32_VERSOR_DATA_LIST[i].x3) && !bgc_are_close_fp32(ratio, _TEST_FP32_VERSOR_DATA_LIST[i].x3 / versor.x3)) {
            print_testing_error("Versor was not normalized proportionally (x3).");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_VERSOR_DATA_AMOUNT = 4;
static const BgcQuaternionFP64 _TEST_FP64_VERSOR_DATA_LIST[] = {
    { 1.0, 2.0, 3.0, 4.0 },
    { 4.0, 3.0, 2.0, 1.0 },
    { -1.0, 0.0, 0.0, 0.0 },
    { 1.0, 0.0, 1.0, 0.0 }
};

void test_versor_set_values_fp64()
{
    double versor_module, ratio;
    BgcVersorFP64 versor;

    print_testing_name("bgc_versor_set_values_fp64");

    for (int i = 0; i < _TEST_FP64_VERSOR_DATA_AMOUNT; i++) {
        bgc_versor_set_values_fp64(
            _TEST_FP64_VERSOR_DATA_LIST[i].s0,
            _TEST_FP64_VERSOR_DATA_LIST[i].x1,
            _TEST_FP64_VERSOR_DATA_LIST[i].x2,
            _TEST_FP64_VERSOR_DATA_LIST[i].x3,
            &versor
        );

        versor_module = sqrt(versor.s0 * versor.s0 + versor.x1 * versor.x1 + versor.x2 * versor.x2 + versor.x3 * versor.x3);

        if (!bgc_is_unit_fp64(versor_module)) {
            print_testing_error("Versor module is not equal to one.");
            return;
        }

        if (bgc_is_zero_fp64(_TEST_FP64_VERSOR_DATA_LIST[i].s0)) {
            continue;
        }

        ratio = _TEST_FP64_VERSOR_DATA_LIST[i].s0 / versor.s0;

        if (!bgc_is_zero_fp64(_TEST_FP64_VERSOR_DATA_LIST[i].x1) && !bgc_are_close_fp64(ratio, _TEST_FP64_VERSOR_DATA_LIST[i].x1 / versor.x1)) {
            print_testing_error("Versor was not normalized proportionally (x1).");
            return;
        }

        if (!bgc_is_zero_fp64(_TEST_FP64_VERSOR_DATA_LIST[i].x2) && !bgc_are_close_fp64(ratio, _TEST_FP64_VERSOR_DATA_LIST[i].x2 / versor.x2)) {
            print_testing_error("Versor was not normalized proportionally (x2).");
            return;
        }

        if (!bgc_is_zero_fp64(_TEST_FP64_VERSOR_DATA_LIST[i].x3) && !bgc_are_close_fp64(ratio, _TEST_FP64_VERSOR_DATA_LIST[i].x3 / versor.x3)) {
            print_testing_error("Versor was not normalized proportionally (x3).");
            return;
        }
    }

    print_testing_success();
}

void test_versor_set_values()
{
    test_versor_set_values_fp32();
    test_versor_set_values_fp64();
}
