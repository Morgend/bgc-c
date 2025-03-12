#include "./vector3_arithmetics.h"
#include "./../../helpers.h"

// ==================== Add ===================== //

void test_vector3_add_fp32()
{
    BgcVector3FP32 vector1, vector2, result;

    print_testing_name("bgc_vector3_add_fp32");

    bgc_vector3_set_values_fp32(10.0f, -20.0f, 30.0f, &vector1);
    bgc_vector3_set_values_fp32(4.0f, 5.0f, -6.0f, &vector2);

    bgc_vector3_add_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 14.0f) || !bgc_are_close_fp32(result.x2, -15.0f) || !bgc_are_close_fp32(result.x3, 24.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp32(-0.28f, 100.1f, -1.6f, &vector1);
    bgc_vector3_set_values_fp32(1.78f, -0.1f, 0.4f, &vector2);

    bgc_vector3_add_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 1.5f) || !bgc_are_close_fp32(result.x2, 100.0f) || !bgc_are_close_fp32(result.x3, -1.2f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_add_scaled_fp32()
{
    BgcVector3FP32 vector1, vector2, result;

    print_testing_name("bgc_vector3_add_scaled_fp32");

    bgc_vector3_set_values_fp32(10.0f, -20.0f, 24.0f, &vector1);
    bgc_vector3_set_values_fp32(4.0f, 5.0f, 6.0f, &vector2);

    bgc_vector3_add_scaled_fp32(&vector1, & vector2, -2.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 2.0f) || !bgc_are_close_fp32(result.x2, -30.0f) || !bgc_are_close_fp32(result.x3, 12.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp32(-0.27f, 100.3f, -1.2f, &vector1);
    bgc_vector3_set_values_fp32(1.59f, -0.1f, 0.4f, &vector2);

    bgc_vector3_add_scaled_fp32(&vector1, &vector2, 3.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 4.5f) || !bgc_are_close_fp32(result.x2, 100.0f) || !bgc_are_close_fp32(result.x3, 0.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_add_fp64()
{
    BgcVector3FP64 vector1, vector2, result;

    print_testing_name("bgc_vector3_add_fp64");

    bgc_vector3_set_values_fp64(10.0, -20.0, 30.0, &vector1);
    bgc_vector3_set_values_fp64(4.0, 8.0, -9.0, &vector2);

    bgc_vector3_add_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, 14.0) || !bgc_are_close_fp64(result.x2, -12.0) || !bgc_are_close_fp64(result.x3, 21.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp64(-0.27, 100.3, -8.2, &vector1);
    bgc_vector3_set_values_fp64(1.29, -0.2, 14.1, &vector2);

    bgc_vector3_add_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, 1.02) || !bgc_are_close_fp64(result.x2, 100.1) || !bgc_are_close_fp64(result.x3, 5.9)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_add_scaled_fp64()
{
    BgcVector3FP64 vector1, vector2, result;

    print_testing_name("bgc_vector3_add_scaled_fp64");

    bgc_vector3_set_values_fp64(10.0, -20.0, 7.5, &vector1);
    bgc_vector3_set_values_fp64(4.0, 5.0, 1.25, &vector2);

    bgc_vector3_add_scaled_fp64(&vector1, &vector2, -2.0, &result);

    if (!bgc_are_close_fp64(result.x1, 2.0) || !bgc_are_close_fp64(result.x2, -30.0) || !bgc_are_close_fp64(result.x3, 5.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp64(-0.27, 100.3, -20.0, &vector1);
    bgc_vector3_set_values_fp64(1.59, -0.1, 5.0, &vector2);

    bgc_vector3_add_scaled_fp64(&vector1, &vector2, 3.0, &result);

    if (!bgc_are_close_fp64(result.x1, 4.5) || !bgc_are_close_fp64(result.x2, 100.0) || !bgc_are_close_fp64(result.x3, -5.0)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_add()
{
    test_vector3_add_fp32();
    test_vector3_add_fp64();

    test_vector3_add_scaled_fp32();
    test_vector3_add_scaled_fp64();
}

// ================== Subtract ================== //

void test_vector3_subtract_fp32()
{
    BgcVector3FP32 vector1, vector2, result;

    print_testing_name("bgc_vector3_subtract_fp32");

    bgc_vector3_set_values_fp32(10.0f, -20.0f, 16.0f, &vector1);
    bgc_vector3_set_values_fp32(4.0f, 5.0f, -4.0f, &vector2);

    bgc_vector3_subtract_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 6.0f) || !bgc_are_close_fp32(result.x2, -25.0f) || !bgc_are_close_fp32(result.x3, 20.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp32(-0.28f, 99.9f, -0.2f, &vector1);
    bgc_vector3_set_values_fp32(-1.78f, -0.1f, 2.8f, &vector2);

    bgc_vector3_subtract_fp32(&vector1, &vector2, &result);

    if (!bgc_are_close_fp32(result.x1, 1.5f) || !bgc_are_close_fp32(result.x2, 100.0f) || !bgc_are_close_fp32(result.x3, -3.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_subtract_scaled_fp32()
{
    BgcVector3FP32 vector1, vector2, result;

    print_testing_name("bgc_vector3_subtract_scaled_fp32");

    bgc_vector3_set_values_fp32(10.0f, -20.0f, 1.25f, &vector1);
    bgc_vector3_set_values_fp32(4.0f, 5.0f, -0.4f, &vector2);

    bgc_vector3_subtract_scaled_fp32(&vector1, &vector2, 2.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 2.0f) || !bgc_are_close_fp32(result.x2, -30.0f) || !bgc_are_close_fp32(result.x3, 2.05f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp32(0.36f, 100.4f, 10, &vector1);
    bgc_vector3_set_values_fp32(1.09f, 0.1f, 2.5f, &vector2);

    bgc_vector3_subtract_scaled_fp32(&vector1, &vector2, 4.0f, &result);

    if (!bgc_are_close_fp32(result.x1, -4.0f) || !bgc_are_close_fp32(result.x2, 100.0f) || !bgc_are_close_fp32(result.x3, 0.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_subtract_fp64()
{
    BgcVector3FP64 vector1, vector2, result;

    print_testing_name("bgc_vector3_subtract_fp64");

    bgc_vector3_set_values_fp64(10.0, -20.0, 15.0, &vector1);
    bgc_vector3_set_values_fp64(4.0, 8.0, -5.0, &vector2);

    bgc_vector3_subtract_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, 6.0) || !bgc_are_close_fp64(result.x2, -28.0) || !bgc_are_close_fp64(result.x3, 20.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp64(-0.27, 100.3, 2.0, &vector1);
    bgc_vector3_set_values_fp64(1.29, -0.2, 0.8, &vector2);

    bgc_vector3_subtract_fp64(&vector1, &vector2, &result);

    if (!bgc_are_close_fp64(result.x1, -1.56) || !bgc_are_close_fp64(result.x2, 100.5) || !bgc_are_close_fp64(result.x3, 1.2)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_subtract_scaled_fp64()
{
    BgcVector3FP64 vector1, vector2, result;

    print_testing_name("bgc_vector3_subtract_scaled_fp64");

    bgc_vector3_set_values_fp64(10.0, 20.0, 0.1, &vector1);
    bgc_vector3_set_values_fp64(4.0, 5.0, -4.0, &vector2);

    bgc_vector3_subtract_scaled_fp64(&vector1, &vector2, 2.5, &result);

    if (!bgc_are_close_fp64(result.x1, 0.0) || !bgc_are_close_fp64(result.x2, 7.5) || !bgc_are_close_fp64(result.x3, 10.1)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp64(-0.27, 100.3, -0.01, &vector1);
    bgc_vector3_set_values_fp64(-1.29, -0.1, 0.33, &vector2);

    bgc_vector3_subtract_scaled_fp64(&vector1, &vector2, 3.0, &result);

    if (!bgc_are_close_fp64(result.x1, 3.6) || !bgc_are_close_fp64(result.x2, 100.6) || !bgc_are_close_fp64(result.x3, -1.0)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_subtract()
{
    test_vector3_subtract_fp32();
    test_vector3_subtract_fp64();

    test_vector3_subtract_scaled_fp32();
    test_vector3_subtract_scaled_fp64();
}

// ================== Multiply ================== //

void test_vector3_multiply_fp32()
{
    BgcVector3FP32 vector, result;

    print_testing_name("bgc_vector3_multiply_fp32");

    bgc_vector3_set_values_fp32(10.0f, -20.0f, 3.0f, &vector);

    bgc_vector3_multiply_fp32(&vector, 0.5f, &result);

    if (!bgc_are_close_fp32(result.x1, 5.0f) || !bgc_are_close_fp32(result.x2, -10.0f) || !bgc_are_close_fp32(result.x3, 1.5f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp32(1.78f, -0.1f, 3.6f, &vector);

    bgc_vector3_multiply_fp32(&vector, 2.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 3.56f) || !bgc_are_close_fp32(result.x2, -0.2f) || !bgc_are_close_fp32(result.x3, 7.2f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_multiply_fp64()
{
    BgcVector3FP64 vector, result;

    print_testing_name("bgc_vector3_multiply_fp64");

    bgc_vector3_set_values_fp64(30.0, -10.0, 4.0, &vector);

    bgc_vector3_multiply_fp64(&vector, 0.3, &result);

    if (!bgc_are_close_fp64(result.x1, 9.0) || !bgc_are_close_fp64(result.x2, -3.0) || !bgc_are_close_fp64(result.x3, 1.2)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp64(1.18, -0.25, 0.02, &vector);

    bgc_vector3_multiply_fp64(&vector, 4.0, &result);

    if (!bgc_are_close_fp64(result.x1, 4.72) || !bgc_are_close_fp64(result.x2, -1.0) || !bgc_are_close_fp64(result.x3, 0.08)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_multiply()
{
    test_vector3_multiply_fp32();
    test_vector3_multiply_fp64();
}

// =================== Divide =================== //

void test_vector3_divide_fp32()
{
    BgcVector3FP32 vector, result;

    print_testing_name("bgc_vector3_divide_fp32");

    bgc_vector3_set_values_fp32(10.0f, -20.0f, 40.0f, &vector);

    bgc_vector3_divide_fp32(&vector, 10.0f, &result);

    if (!bgc_are_close_fp32(result.x1, 1.0f) || !bgc_are_close_fp32(result.x2, -2.0f) || !bgc_are_close_fp32(result.x3, 4.0f)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp32(1.78f, -0.1f, 0.4f, &vector);

    bgc_vector3_divide_fp32(&vector, 0.2f, &result);

    if (!bgc_are_close_fp32(result.x1, 8.9f) || !bgc_are_close_fp32(result.x2, -0.5f) || !bgc_are_close_fp32(result.x3, 2.0f)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_divide_fp64()
{
    BgcVector3FP64 vector, result;

    print_testing_name("bgc_vector3_divide_fp64");

    bgc_vector3_set_values_fp64(30.0, -10.0, 20.0, &vector);

    bgc_vector3_divide_fp64(&vector, 5.0, &result);

    if (!bgc_are_close_fp64(result.x1, 6.0) || !bgc_are_close_fp64(result.x2, -2.0) || !bgc_are_close_fp64(result.x3, 4.0)) {
        print_testing_error("first test failed");
        return;
    }

    bgc_vector3_set_values_fp64(4.5, -0.25, 1.5, &vector);

    bgc_vector3_divide_fp64(&vector, -0.5, &result);

    if (!bgc_are_close_fp64(result.x1, -9.0) || !bgc_are_close_fp64(result.x2, 0.5) || !bgc_are_close_fp64(result.x3, -3.0)) {
        print_testing_error("second test failed");
        return;
    }

    print_testing_success();
}

void test_vector3_divide()
{
    test_vector3_divide_fp32();
    test_vector3_divide_fp64();
}
