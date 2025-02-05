#ifndef __GEOMETRY_TEST_H__
#define __GEOMETRY_TEST_H__

#include <basic-geometry.h>

#define TEST_RESULT_SUCCES 0
#define TEST_RESULT_FAILED 100

#define TEST_BGC_EPSYLON_FP32 1E-6f
#define TEST_BGC_TWO_EPSYLON_FP32 2E-6f
#define TEST_BGC_SQUARE_EPSYLON_FP32 1E-12f

#define TEST_BGC_EPSYLON_FP64 1E-13f
#define TEST_BGC_TWO_EPSYLON_FP64 2E-13f
#define TEST_BGC_SQUARE_EPSYLON_FP64 1E-26f

void print_test_section(const char * name);

void print_test_name(const char * name);

void print_test_success();

void print_test_failed();

inline int test_are_equal_fp32(const float value1, const float value2, const float epsylon)
{
    if (-1.0f <= value1 && value1 <= 1.0f) {
        const float difference = value1 - value2;
        return -epsylon <= difference && difference <= epsylon;
    }

    if (value1 > 0.0f) {
        return value1 <= value2 * (1.0f + epsylon) && value2 <= value1 * (1.0f + epsylon);
    }

    return value1 * (1.0f + epsylon) <= value2 && value2 * (1.0f + epsylon) <= value1;
}

inline int test_are_equal_fp64(const double value1, const double value2, const double epsylon)
{
    if (-1.0 <= value1 && value1 <= 1.0) {
        const double difference = value1 - value2;
        return -epsylon <= difference && difference <= epsylon;
    }

    if (value1 > 0.0) {
        return value1 <= value2 * (1.0 + epsylon) && value2 <= value1 * (1.0 + epsylon);
    }

    return value1 * (1.0 + epsylon) <= value2 && value2 * (1.0 + epsylon) <= value1;
}

#endif
