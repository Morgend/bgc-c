#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

#include "tests/utilities.h"
#include "tests/vector2.h"
#include "tests/vector3.h"
#include "tests/versor.h"

#define PROGRAM_SUCCESS 0
#define PROGRAM_FAILED 1

int main()
{
    if (test_utilities() == TEST_FAILED) {
        return PROGRAM_FAILED;
    }

    if (test_vector2() == TEST_FAILED) {
        return PROGRAM_FAILED;
    }

    if (test_vector3() == TEST_FAILED) {
        return PROGRAM_FAILED;
    }

    if (test_versor() == TEST_FAILED) {
        return PROGRAM_FAILED;
    }

    return PROGRAM_SUCCESS;
}
