#include "utilities.h"


extern inline int bgc_is_zero_fp32(const float square_value);
extern inline int bgc_is_zero_fp64(const double square_value);

extern inline int bgc_is_unit_fp32(const float square_value);
extern inline int bgc_is_unit_fp64(const double square_value);

extern inline int bgc_is_sqare_unit_fp32(const float square_value);
extern inline int bgc_is_sqare_unit_fp64(const double square_value);

extern inline int bgc_are_close_fp32(const float value1, const float value2);
extern inline int bgc_are_close_fp64(const double value1, const double value2);
