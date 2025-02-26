#include <stdio.h>
#include <stdlib.h>

#include "helpers.h"

#include "tests/utilities.h"
#include "tests/vector2.h"
#include "tests/vector3.h"
#include "tests/complex.h"
#include "tests/quaternion.h"
#include "tests/versor.h"

int main()
{
    test_utilities();

    test_vector2();

    test_vector3();

    test_complex();

    test_quaternion();

    test_versor();

    return 0;
}
