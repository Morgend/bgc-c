#include "./versor_reset.h"

#include "./../../helpers.h"

void test_versor_reset_fp32()
{
    BgcVersorFP32 versor;

    print_testing_name("bgc_versor_reset_fp32");

    bgc_versor_reset_fp32(&versor);

    if (versor.s0 != 1.0f || versor.x1 != 0.0f || versor.x2 != 0.0f || versor.x3 != 0.0f) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_versor_reset_fp64()
{
    BgcVersorFP64 versor;

    print_testing_name("bgc_versor_reset_fp64");

    bgc_versor_reset_fp64(&versor);

    if (versor.s0 != 1.0 || versor.x1 != 0.0 || versor.x2 != 0.0 || versor.x3 != 0.0) {
        print_testing_failed();
        return;
    }

    print_testing_success();
}

void test_versor_reset()
{
    test_versor_reset_fp32();
    test_versor_reset_fp64();
}
