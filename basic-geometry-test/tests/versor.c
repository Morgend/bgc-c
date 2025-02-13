#include "./versor.h"

#include "./../helpers.h"

void test_versor()
{
    print_testing_section("BGC Versor");

    test_versor_reset();
    test_versor_set_values();
    test_versor_copy();
    test_versor_swap();
    test_versor_are_close();
    test_versor_is_identity();
    test_versor_combine();
}
