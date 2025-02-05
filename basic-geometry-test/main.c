#include <stdio.h>
#include <stdlib.h>

#include "geometry_test.h"
#include "fp32_vector2_test.h"

#define PROGRAM_RESULT_SUCCESS 0
#define PROGRAM_RESULT_FAILED 1

int main()
{
    if (test_fp32_vector2() == TEST_RESULT_FAILED) {
        return PROGRAM_RESULT_FAILED;
    }

    return PROGRAM_RESULT_SUCCESS;
}
