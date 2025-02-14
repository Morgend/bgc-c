#include "vector3.h"

void test_vector3()
{
    print_testing_section("BGC Vector3");

    test_vector3_reset();
    test_vector3_set_values();
    test_vector3_copy();
    test_vector3_swap();
    test_vector3_is_zero();
    test_vector3_is_unit();
    test_vector3_modulus();
}
