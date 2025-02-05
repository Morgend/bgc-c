#include "fp32_vector2_test.h"

const int TEST_FP32_VECTOR2_AMOUNT_1 = 5;

const BgcVector2FP32 TEST_FP32_VECTOR2_COMMON_1[] = {
    { 3.0f, 4.0f },
    { -3.0f, -4.0f },
    { 10000.0f, -20000.0f },
    { 0.1f, -10.0f },
    { -123.5f, 3.7283f }
};

const BgcVector2FP32 TEST_FP32_VECTOR2_COMMON_2[] = {
    { -3.0f, -4.0f },
    { -3.0f, -4.0f },
    { 0.002f, -0.05f },
    { -0.2f, 12.0f },
    { 1.5f, -23.35f }
};

// =============== Square modulus =============== //

const float FP32_VECTOR2_SQUARE_MODULUS_1[] = { 25.0f, 25.0f, 500000000.0f, 100.01f, 15266.150221f };

int test_vector2_fp32_square_modulus()
{
    print_test_name("vector2_fp32_t square modulus");

    float square_modulus;

    for (int i = 0; i < TEST_FP32_VECTOR2_AMOUNT_1; i++) {
        square_modulus = bgc_vector2_get_square_modulus_fp32(&TEST_FP32_VECTOR2_COMMON_1[i]);

        if (!test_are_equal_fp32(square_modulus, FP32_VECTOR2_SQUARE_MODULUS_1[i], TEST_BGC_TWO_EPSYLON_FP32)) {
            print_test_failed();
            return TEST_RESULT_FAILED;
        }
    }

    print_test_success();
    return TEST_RESULT_SUCCES;
}

// =================== Module =================== //

const float FP32_VECTOR2_MODULUS_1[] = { 5.0f, 5.0f, 22360.68f, 10.0005f, 123.55626338f };

int test_vector2_fp32_modulus()
{
    print_test_name("vector2_fp32_t modulus");

    float square_modulus;

    for (int i = 0; i < TEST_FP32_VECTOR2_AMOUNT_1; i++) {
        square_modulus = bgc_vector2_get_modulus_fp32(&TEST_FP32_VECTOR2_COMMON_1[i]);

        if (!test_are_equal_fp32(square_modulus, FP32_VECTOR2_MODULUS_1[i], TEST_BGC_EPSYLON_FP32)) {
            print_test_failed();
            return TEST_RESULT_FAILED;
        }
    }

    print_test_success();
    return TEST_RESULT_SUCCES;
}

// ===================== Add ==================== //

const BgcVector2FP32 TEST_FP32_VECTOR2_COMMON_1_2_SUM[] = {
    { 0.0f, 0.0f },
    { -6.0f, -8.0f },
    { 10000.002f, -20000.05f },
    { -0.1f, 2.0f },
    { -122.0f, -19.6217f }
};

int test_vector2_add_fp32()
{
    print_test_name("vector2_fp32_t add");

    BgcVector2FP32 vector;

    for (int i = 0; i < TEST_FP32_VECTOR2_AMOUNT_1; i++) {
        bgc_vector2_add_fp32(&TEST_FP32_VECTOR2_COMMON_1[i], &TEST_FP32_VECTOR2_COMMON_2[i], &vector);

        if (!test_are_equal_fp32(vector.x1, TEST_FP32_VECTOR2_COMMON_1_2_SUM[i].x1, TEST_BGC_EPSYLON_FP32) ||
            !test_are_equal_fp32(vector.x2, TEST_FP32_VECTOR2_COMMON_1_2_SUM[i].x2, TEST_BGC_EPSYLON_FP32)) {
            print_test_failed();
            return TEST_RESULT_FAILED;
        }
    }

    print_test_success();
    return TEST_RESULT_SUCCES;
}

// ================== Subtract ================== //

const BgcVector2FP32 TEST_FP32_VECTOR2_COMMON_1_2_DIFF[] = {
    { 6.0f, 8.0f },
    { 0.0f, 0.0f },
    { 9999.998f, -19999.95f },
    { 0.3f, -22.0f },
    { -125.0f, 27.0783f }
};

int test_vector2_subtract_fp32()
{
    print_test_name("vector2_fp32_t subtract");

    BgcVector2FP32 vector;

    for (int i = 0; i < TEST_FP32_VECTOR2_AMOUNT_1; i++) {
        bgc_vector2_subtract_fp32(&TEST_FP32_VECTOR2_COMMON_1[i], &TEST_FP32_VECTOR2_COMMON_2[i], &vector);

        if (!test_are_equal_fp32(vector.x1, TEST_FP32_VECTOR2_COMMON_1_2_DIFF[i].x1, TEST_BGC_EPSYLON_FP32) ||
            !test_are_equal_fp32(vector.x2, TEST_FP32_VECTOR2_COMMON_1_2_DIFF[i].x2, TEST_BGC_EPSYLON_FP32)) {
            print_test_failed();
            return TEST_RESULT_FAILED;
        }
    }

    print_test_success();
    return TEST_RESULT_SUCCES;
}

// ==================== 1234 ==================== //

int test_fp32_vector2()
{
    print_test_section("vector2_fp32_t");

    if (test_vector2_fp32_square_modulus() != TEST_RESULT_SUCCES) {
        return TEST_RESULT_FAILED;
    }

    if (test_vector2_fp32_modulus() != TEST_RESULT_SUCCES) {
        return TEST_RESULT_FAILED;
    }

    if (test_vector2_add_fp32() != TEST_RESULT_SUCCES) {
        return TEST_RESULT_FAILED;
    }

    if (test_vector2_subtract_fp32() != TEST_RESULT_SUCCES) {
        return TEST_RESULT_FAILED;
    }

    return TEST_RESULT_SUCCES;
}
