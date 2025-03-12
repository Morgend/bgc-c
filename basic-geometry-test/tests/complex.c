#include "./complex.h"

void test_complex()
{
    print_testing_section("BGC Complex");

    test_complex_reset();
    test_complex_set_values();
    test_complex_copy();
    test_complex_swap();
    test_complex_is_zero();
    test_complex_is_unit();
    test_complex_modulus();

    test_complex_add();
    test_complex_subtract();
    test_complex_multiply();
    test_complex_divide();
}
