#include "matrix3x2.h"

extern inline void bgc_matrix3x2_reset_fp32(BgcMatrix3x2FP32* matrix);
extern inline void bgc_matrix3x2_reset_fp64(BgcMatrix3x2FP64* matrix);

extern inline void bgc_matrix3x2_copy_fp32(const BgcMatrix3x2FP32* from, BgcMatrix3x2FP32* to);
extern inline void bgc_matrix3x2_copy_fp64(const BgcMatrix3x2FP64* from, BgcMatrix3x2FP64* to);

extern inline void bgc_matrix3x2_swap_fp32(BgcMatrix3x2FP32* matrix1, BgcMatrix3x2FP32* matrix2);
extern inline void bgc_matrix3x2_swap_fp64(BgcMatrix3x2FP64* matrix1, BgcMatrix3x2FP64* matrix2);

extern inline void bgc_matrix3x2_convert_fp64_to_fp32(const BgcMatrix3x2FP64* from, BgcMatrix3x2FP32* to);
extern inline void bgc_matrix3x2_convert_fp32_to_fp64(const BgcMatrix3x2FP32* from, BgcMatrix3x2FP64* to);

extern inline void bgc_matrix3x2_set_row1_fp32(const float c1, const float c2, const float c3, BgcMatrix3x2FP32* matrix);
extern inline void bgc_matrix3x2_set_row1_fp64(const double c1, const double c2, const double c3, BgcMatrix3x2FP64* matrix);

extern inline void bgc_matrix3x2_set_row2_fp32(const float c1, const float c2, const float c3, BgcMatrix3x2FP32* matrix);
extern inline void bgc_matrix3x2_set_row2_fp64(const double c1, const double c2, const double c3, BgcMatrix3x2FP64* matrix);

extern inline void bgc_matrix3x2_set_column1_fp32(const float r1, const float r2, BgcMatrix3x2FP32* matrix);
extern inline void bgc_matrix3x2_set_column1_fp64(const double r1, const double r2, BgcMatrix3x2FP64* matrix);

extern inline void bgc_matrix3x2_set_column2_fp32(const float r1, const float r2, BgcMatrix3x2FP32* matrix);
extern inline void bgc_matrix3x2_set_column2_fp64(const double r1, const double r2, BgcMatrix3x2FP64* matrix);

extern inline void bgc_matrix3x2_set_column3_fp32(const float r1, const float r2, BgcMatrix3x2FP32* matrix);
extern inline void bgc_matrix3x2_set_column3_fp64(const double r1, const double r2, BgcMatrix3x2FP64* matrix);

extern inline void bgc_matrix3x2_get_transposed_fp32(const BgcMatrix2x3FP32* from, BgcMatrix3x2FP32* to);
extern inline void bgc_matrix3x2_get_transposed_fp64(const BgcMatrix2x3FP64* from, BgcMatrix3x2FP64* to);

extern inline void bgc_matrix3x2_add_fp32(const BgcMatrix3x2FP32* matrix1, const BgcMatrix3x2FP32* matrix2, BgcMatrix3x2FP32* sum);
extern inline void bgc_matrix3x2_add_fp64(const BgcMatrix3x2FP64* matrix1, const BgcMatrix3x2FP64* matrix2, BgcMatrix3x2FP64* sum);

extern inline void bgc_matrix3x2_add_scaled_fp32(const BgcMatrix3x2FP32* basic_matrix, const BgcMatrix3x2FP32* scalable_matrix, const float scale, BgcMatrix3x2FP32* sum);
extern inline void bgc_matrix3x2_add_scaled_fp64(const BgcMatrix3x2FP64* basic_matrix, const BgcMatrix3x2FP64* scalable_matrix, const double scale, BgcMatrix3x2FP64* sum);

extern inline void bgc_matrix3x2_subtract_fp32(const BgcMatrix3x2FP32* minuend, const BgcMatrix3x2FP32* subtrahend, BgcMatrix3x2FP32* difference);
extern inline void bgc_matrix3x2_subtract_fp64(const BgcMatrix3x2FP64* minuend, const BgcMatrix3x2FP64* subtrahend, BgcMatrix3x2FP64* difference);

extern inline void bgc_matrix3x2_subtract_scaled_fp32(const BgcMatrix3x2FP32* basic_matrix, const BgcMatrix3x2FP32* scalable_matrix, const float scale, BgcMatrix3x2FP32* difference);
extern inline void bgc_matrix3x2_subtract_scaled_fp64(const BgcMatrix3x2FP64* basic_matrix, const BgcMatrix3x2FP64* scalable_matrix, const double scale, BgcMatrix3x2FP64* difference);

extern inline void bgc_matrix3x2_multiply_fp32(const BgcMatrix3x2FP32* multiplicand, const float multiplier, BgcMatrix3x2FP32* product);
extern inline void bgc_matrix3x2_multiply_fp64(const BgcMatrix3x2FP64* multiplicand, const double multiplier, BgcMatrix3x2FP64* product);

extern inline void bgc_matrix3x2_divide_fp32(const BgcMatrix3x2FP32* dividend, const float divisor, BgcMatrix3x2FP32* quotient);
extern inline void bgc_matrix3x2_divide_fp64(const BgcMatrix3x2FP64* dividend, const double divisor, BgcMatrix3x2FP64* quotient);

extern inline void bgc_matrix3x2_get_left_product_fp32(const BgcVector2FP32* vector, const BgcMatrix3x2FP32* matrix, BgcVector3FP32* result);
extern inline void bgc_matrix3x2_get_left_product_fp64(const BgcVector2FP64* vector, const BgcMatrix3x2FP64* matrix, BgcVector3FP64* result);

extern inline void bgc_matrix3x2_get_right_product_fp32(const BgcMatrix3x2FP32* matrix, const BgcVector3FP32* vector, BgcVector2FP32* result);
extern inline void bgc_matrix3x2_get_right_product_fp64(const BgcMatrix3x2FP64* matrix, const BgcVector3FP64* vector, BgcVector2FP64* result);
