#include "./vector2_arithmetics.h"
#include "./../../helpers.h"

// ==================== Add ===================== //

void test_vector2_add_fp32()
{
    BgcVector2FP32 vector1, vector2, result;

    print_testing_name("bgc_vector2_add_fp32");

    bgc_vector2_set_values_fp32(10.0f, -20.0f, &vector1);
    bgc_vector2_set_values_fp32(4.0f, 5.0f, &vector2);

    bgc_vector2_add_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 14.0f) || !bgc_are_close_fp32(result.x2, -15.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp32(-0.28f, 100.1f, &vector1);
    bgc_vector2_set_values_fp32(1.78f, -0.1f, &vector2);

    bgc_vector2_add_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 1.5f) || !bgc_are_close_fp32(result.x2, 100.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_add_scaled_fp32()
{
    BgcVector2FP32 vector1, vector2, result;

    print_testing_name("bgc_vector2_add_scaled_fp32");

    bgc_vector2_set_values_fp32(10.0f, -20.0f, &vector1);
    bgc_vector2_set_values_fp32(4.0f, 5.0f, &vector2);

    bgc_vector2_add_scaled_fp32(&vector1, & vector2, -2.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 2.0f) || !bgc_are_close_fp32(result.x2, -30.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp32(-0.27f, 100.3f, &vector1);
    bgc_vector2_set_values_fp32(1.59f, -0.1f, &vector2);

    bgc_vector2_add_scaled_fp32(&vector1, &vector2, 3.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 4.5f) || !bgc_are_close_fp32(result.x2, 100.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_add_fp64()
{
    BgcVector2FP64 vector1, vector2, result;

    print_testing_name("bgc_vector2_add_fp64");

    bgc_vector2_set_values_fp64(10.0, -20.0, &vector1);
    bgc_vector2_set_values_fp64(4.0, 8.0, &vector2);

    bgc_vector2_add_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, 14.0) || !bgc_are_close_fp64(result.x2, -12.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp64(-0.27, 100.3, &vector1);
    bgc_vector2_set_values_fp64(1.29, -0.2, &vector2);

    bgc_vector2_add_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, 1.02) || !bgc_are_close_fp64(result.x2, 100.1)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_add_scaled_fp64()
{
    BgcVector2FP64 vector1, vector2, result;

    print_testing_name("bgc_vector2_add_scaled_fp64");

    bgc_vector2_set_values_fp64(10.0, -20.0, &vector1);
    bgc_vector2_set_values_fp64(4.0, 5.0, &vector2);

    bgc_vector2_add_scaled_fp64(&vector1, &vector2, -2.0, &result);

    if (!bgc_are_close_fp64(result.x1, 2.0) || !bgc_are_close_fp64(result.x2, -30.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp64(-0.27, 100.3, &vector1);
    bgc_vector2_set_values_fp64(1.59, -0.1, &vector2);

    bgc_vector2_add_scaled_fp64(&vector1, &vector2, 3.0, &result);

    if (!bgc_are_close_fp64(result.x1, 4.5) || !bgc_are_close_fp64(result.x2, 100.0)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_add()
{
    test_vector2_add_fp32();
    test_vector2_add_fp64();

    test_vector2_add_scaled_fp32();
    test_vector2_add_scaled_fp64();
}

// ================== Subtract ================== //

void test_vector2_subtract_fp32()
{
    BgcVector2FP32 vector1, vector2, result;

    print_testing_name("bgc_vector2_subtract_fp32");

    bgc_vector2_set_values_fp32(10.0f, -20.0f, &vector1);
    bgc_vector2_set_values_fp32(4.0f, 5.0f, &vector2);

    bgc_vector2_subtract_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 6.0f) || !bgc_are_close_fp32(result.x2, -25.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp32(-0.28f, 99.9f, &vector1);
    bgc_vector2_set_values_fp32(-1.78f, -0.1f, &vector2);

    bgc_vector2_subtract_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 1.5f) || !bgc_are_close_fp32(result.x2, 100.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_subtract_scaled_fp32()
{
    BgcVector2FP32 vector1, vector2, result;

    print_testing_name("bgc_vector2_subtract_scaled_fp32");

    bgc_vector2_set_values_fp32(10.0f, -20.0f, &vector1);
    bgc_vector2_set_values_fp32(4.0f, 5.0f, &vector2);

    bgc_vector2_subtract_scaled_fp32(&vector1, &vector2, 2.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 2.0f) || !bgc_are_close_fp32(result.x2, -30.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp32(0.36f, 100.4f, &vector1);
    bgc_vector2_set_values_fp32(1.09f, 0.1f, &vector2);

    bgc_vector2_subtract_scaled_fp32(&vector1, &vector2, 4.0f, &result);

    if (!bgc_are_close_fp32(result.x1, -4.0f) || !bgc_are_close_fp32(result.x2, 100.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_subtract_fp64()
{
    BgcVector2FP64 vector1, vector2, result;

    print_testing_name("bgc_vector2_subtract_fp64");

    bgc_vector2_set_values_fp64(10.0, -20.0, &vector1);
    bgc_vector2_set_values_fp64(4.0, 8.0, &vector2);

    bgc_vector2_subtract_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, 6.0) || !bgc_are_close_fp64(result.x2, -28.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp64(-0.27, 100.3, &vector1);
    bgc_vector2_set_values_fp64(1.29, -0.2, &vector2);

    bgc_vector2_subtract_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, -1.56) || !bgc_are_close_fp64(result.x2, 100.5)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_subtract_scaled_fp64()
{
    BgcVector2FP64 vector1, vector2, result;

    print_testing_name("bgc_vector2_subtract_scaled_fp64");

    bgc_vector2_set_values_fp64(10.0, 20.0, &vector1);
    bgc_vector2_set_values_fp64(4.0, 5.0, &vector2);

    bgc_vector2_subtract_scaled_fp64(&vector1, &vector2, 2.5, &result);

    if (!bgc_are_close_fp64(result.x1, 0.0) || !bgc_are_close_fp64(result.x2, 7.5)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp64(-0.27, 100.3, &vector1);
    bgc_vector2_set_values_fp64(-1.29, -0.1, &vector2);

    bgc_vector2_subtract_scaled_fp64(&vector1, &vector2, 3.0, &result);

    if (!bgc_are_close_fp64(result.x1, 3.6) || !bgc_are_close_fp64(result.x2, 100.6)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_subtract()
{
    test_vector2_subtract_fp32();
    test_vector2_subtract_fp64();

    test_vector2_subtract_scaled_fp32();
    test_vector2_subtract_scaled_fp64();
}

// ================== Multiply ================== //

void test_vector2_multiply_fp32()
{
    BgcVector2FP32 vector, result;

    print_testing_name("bgc_vector2_multiply_fp32");

    bgc_vector2_set_values_fp32(10.0f, -20.0f, &vector);

    bgc_vector2_multiply_fp32(&vector, 0.5f, &result);

    if (!bgc_are_close_fp32(result.x1, 5.0f) || !bgc_are_close_fp32(result.x2, -10.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp32(1.78f, -0.1f, &vector);

    bgc_vector2_multiply_fp32(&vector, 2.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 3.56f) || !bgc_are_close_fp32(result.x2, -0.2f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_multiply_fp64()
{
    BgcVector2FP64 vector, result;

    print_testing_name("bgc_vector2_multiply_fp64");

    bgc_vector2_set_values_fp64(30.0, -10.0, &vector);

    bgc_vector2_multiply_fp64(&vector, 0.3, &result);

    if (!bgc_are_close_fp64(result.x1, 9.0) || !bgc_are_close_fp64(result.x2, -3.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp64(1.18, -0.25, &vector);

    bgc_vector2_multiply_fp64(&vector, 4.0, &result);

    if (!bgc_are_close_fp64(result.x1, 4.72) || !bgc_are_close_fp64(result.x2, -1.0)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_multiply()
{
    test_vector2_multiply_fp32();
    test_vector2_multiply_fp64();
}

// =================== Divide =================== //

void test_vector2_divide_fp32()
{
    BgcVector2FP32 vector, result;

    print_testing_name("bgc_vector2_divide_fp32");

    bgc_vector2_set_values_fp32(10.0f, -20.0f, &vector);

    bgc_vector2_divide_fp32(&vector, 10.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 1.0f) || !bgc_are_close_fp32(result.x2, -2.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp32(1.78f, -0.1f, &vector);

    bgc_vector2_divide_fp32(&vector, 0.2f, &result);

    if (!bgc_are_close_fp32(result.x1, 8.9f) || !bgc_are_close_fp32(result.x2, -0.5f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_divide_fp64()
{
    BgcVector2FP64 vector, result;

    print_testing_name("bgc_vector2_divide_fp64");

    bgc_vector2_set_values_fp64(30.0, -10.0, &vector);

    bgc_vector2_divide_fp64(&vector, 5.0, &result);

    if (!bgc_are_close_fp64(result.x1, 6.0) || !bgc_are_close_fp64(result.x2, -2.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector2_set_values_fp64(1.18, -0.25, &vector);

    bgc_vector2_divide_fp64(&vector, 0.5, &result);

    if (!bgc_are_close_fp64(result.x1, 2.36) || !bgc_are_close_fp64(result.x2, -0.5)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector2_divide()
{
    test_vector2_divide_fp32();
    test_vector2_divide_fp64();
}
