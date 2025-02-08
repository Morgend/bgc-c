#ifndef _TEST_VERSOR_H_
#define _TEST_VERSOR_H_

#include "./versor/versor_reset.h"
#include "./versor/versor_set_values.h"
#include "./versor/versor_copy.h"
#include "./versor/versor_swap.h"
#include "./versor/versor_are_close.h"

int test_bgc_versor_reset();

int test_bgc_versor_set_values();

int test_bgc_versor_copy();

int test_bgc_versor_swap();

int test_bgc_versor_are_close();

int test_bgc_versor_combine();

int test_versor();

#endif
