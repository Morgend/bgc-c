#include "./vector2_reset.h"

#include "./../../helpers.h"

void test_vector2_reset_fp32()
{
    BgcVector2FP32 vector;

    print_testing_name("bgc_vector2_reset_fp32");

    bgc_vector2_reset_fp32(&vector);

    if (vector.x1 != 0.0f || vector.x2 != 0.0f) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_vector2_reset_fp64()
{
    BgcVector2FP64 vector;

    print_testing_name("bgc_vector2_reset_fp64");

    bgc_vector2_reset_fp64(&vector);

    if (vector.x1 != 0.0 || vector.x2 != 0.0) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_vector2_reset()
{
    test_vector2_reset_fp32();
    test_vector2_reset_fp64();
}
