#include "./versor_is_identity.h"

#include "./../../helpers.h"

// ==================== FP32 ==================== //

static const int _TEST_FP32_IDENTIYTY_VERSOR_AMOUNT = 9;
static const int _TEST_FP32_NON_IDENTIYTY_VERSOR_AMOUNT = 5;

static const BgcVersorFP32 _TEST_FP32_IDENTIYTY_VERSOR_LIST[] = {
    { 1.0f, 0.0f, 0.0f, 0.0f },
    { 1.0f + 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { 1.0f - 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f },
    { 1.0f, 0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 1.0f, -0.75f * BGC_EPSYLON_FP32, 0.0f, 0.0f },
    { 1.0f, 0.0f, 0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 1.0f, 0.0f, -0.75f * BGC_EPSYLON_FP32, 0.0f },
    { 1.0f, 0.0f, 0.0f, 0.75f * BGC_EPSYLON_FP32 },
    { 1.0f, 0.0f, 0.0f, -0.75f * BGC_EPSYLON_FP32 }
};

static const BgcVersorFP32 _TEST_FP32_NON_IDENTIYTY_VERSOR_LIST[] = {
    { 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f },
    { 0.5f, 0.5f, 0.5f, 0.5f },
    { 1.0f - 1.25f * BGC_EPSYLON_FP32, 0.0f, 0.0f, 0.0f }
};

void test_versor_is_identity_fp32()
{
    print_testing_name("bgc_versor_is_identity_fp32");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP32_IDENTIYTY_VERSOR_AMOUNT; i++) {
        if (!bgc_versor_is_identity_fp32(&_TEST_FP32_IDENTIYTY_VERSOR_LIST[i])) {
            print_testing_error("An identity versor was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP32_NON_IDENTIYTY_VERSOR_AMOUNT; i++) {
        if (bgc_versor_is_identity_fp32(&_TEST_FP32_NON_IDENTIYTY_VERSOR_LIST[i])) {
            print_testing_error("A non-identity versor was recognized as an identity versor");
            return;
        }
    }

    print_testing_success();
}

// ==================== FP64 ==================== //

static const int _TEST_FP64_IDENTIYTY_VERSOR_AMOUNT = 9;
static const int _TEST_FP64_NON_IDENTIYTY_VERSOR_AMOUNT = 5;

static const BgcVersorFP64 _TEST_FP64_IDENTIYTY_VERSOR_LIST[] = {
    { 1.0, 0.0, 0.0, 0.0 },
    { 1.0 + 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { 1.0 - 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 },
    { 1.0, -0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 1.0, 0.75 * BGC_EPSYLON_FP64, 0.0, 0.0 },
    { 1.0, 0.0, 0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 1.0, 0.0, -0.75 * BGC_EPSYLON_FP64, 0.0 },
    { 1.0, 0.0, 0.0, 0.75 * BGC_EPSYLON_FP64 },
    { 1.0, 0.0, 0.0, -0.75 * BGC_EPSYLON_FP64 }
};

static const BgcVersorFP64 _TEST_FP64_NON_IDENTIYTY_VERSOR_LIST[] = {
    { 0.0, 1.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0, 0.0 },
    { 0.0, 0.0, 0.0, 1.0 },
    { 0.5, 0.5, 0.5, 0.5 },
    { 1.0 - 1.25 * BGC_EPSYLON_FP64, 0.0, 0.0, 0.0 }
};

void test_versor_is_identity_fp64()
{
    print_testing_name("bgc_versor_is_identity_fp64");

    // Testing zero values:
    for (int i = 0; i < _TEST_FP64_IDENTIYTY_VERSOR_AMOUNT; i++) {
        if (!bgc_versor_is_identity_fp64(&_TEST_FP64_IDENTIYTY_VERSOR_LIST[i])) {
            print_testing_error("An identity versor was not recognized");
            return;
        }
    }

    // Testing non-zero values:
    for (int i = 0; i < _TEST_FP64_NON_IDENTIYTY_VERSOR_AMOUNT; i++) {
        if (bgc_versor_is_identity_fp64(&_TEST_FP64_NON_IDENTIYTY_VERSOR_LIST[i])) {
            print_testing_error("A non-identity versor was recognized as an identity versor");
            return;
        }
    }

    print_testing_success();
}

void test_versor_is_identity()
{
    test_versor_is_identity_fp32();
    test_versor_is_identity_fp64();
}
