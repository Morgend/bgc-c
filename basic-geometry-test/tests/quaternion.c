#include "quaternion.h"

void test_quaternion()
{
    print_testing_section("BGC Quaternion");

    test_quaternion_reset();
    test_quaternion_set_to_identity();
    test_quaternion_set_values();
    test_quaternion_copy();
    test_quaternion_swap();
    test_quaternion_is_zero();
    test_quaternion_is_unit();
}
