#include "./versor_reset.h"

#include "./../../helpers.h"

int test_versor_reset_fp32()
{
    BgcVersorFP32 versor;
    
    print_testing_name("bgc_versor_reset_fp32");

    bgc_versor_reset_fp32(&versor);

    if (versor.s0 != 1.0f || versor.x1 != 0.0f || versor.x2 != 0.0f || versor.x3 != 0.0f) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_versor_reset_fp64()
{
    BgcVersorFP64 versor;

    print_testing_name("bgc_versor_reset_fp64");

    bgc_versor_reset_fp64(&versor);

    if (versor.s0 != 1.0 || versor.x1 != 0.0 || versor.x2 != 0.0 || versor.x3 != 0.0) {
        print_testing_failed();
        return TEST_FAILED;
    }

    print_testing_success();

    return TEST_SUCCES;
}

int test_versor_reset()
{
    if (test_versor_reset_fp32() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    if (test_versor_reset_fp64() != TEST_SUCCES) {
        return TEST_FAILED;
    }

    return TEST_SUCCES;
}
