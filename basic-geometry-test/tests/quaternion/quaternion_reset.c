#include "./quaternion_reset.h"

#include "./../../helpers.h"

void test_quaternion_reset_fp32()
{
    BgcQuaternionFP32 vector;

    print_testing_name("bgc_quaternion_reset_fp32");

    bgc_quaternion_reset_fp32(&vector);

    if (vector.s0 != 0.0f || vector.x1 != 0.0f || vector.x2 != 0.0f || vector.x3 != 0.0f) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_quaternion_reset_fp64()
{
    BgcQuaternionFP64 vector;

    print_testing_name("bgc_quaternion_reset_fp64");

    bgc_quaternion_reset_fp64(&vector);

    if (vector.s0 != 0.0 || vector.x1 != 0.0 || vector.x2 != 0.0 || vector.x3 != 0.0) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_quaternion_reset()
{
    test_quaternion_reset_fp32();
    test_quaternion_reset_fp64();
}
