#include "matrix2x3.h"

extern inline void bgc_matrix2x3_reset_fp32(BgcMatrix2x3FP32* matrix);
extern inline void bgc_matrix2x3_reset_fp64(BgcMatrix2x3FP64* matrix);

extern inline void bgc_matrix2x3_copy_fp32(const BgcMatrix2x3FP32* from, BgcMatrix2x3FP32* to);
extern inline void bgc_matrix2x3_copy_fp64(const BgcMatrix2x3FP64* from, BgcMatrix2x3FP64* to);

extern inline void bgc_matrix2x3_swap_fp32(BgcMatrix2x3FP32* matrix1, BgcMatrix2x3FP32* matrix2);
extern inline void bgc_matrix2x3_swap_fp64(BgcMatrix2x3FP64* matrix1, BgcMatrix2x3FP64* matrix2);

extern inline void bgc_matrix2x3_convert_fp64_to_fp32(const BgcMatrix2x3FP64* from, BgcMatrix2x3FP32* to);
extern inline void bgc_matrix2x3_convert_fp32_to_fp64(const BgcMatrix2x3FP32* from, BgcMatrix2x3FP64* to);

extern inline void bgc_matrix2x3_set_row1_fp32(const float c1, const float c2, BgcMatrix2x3FP32* matrix);
extern inline void bgc_matrix2x3_set_row1_fp64(const double c1, const double c2, BgcMatrix2x3FP64* matrix);

extern inline void bgc_matrix2x3_set_row2_fp32(const float c1, const float c2, BgcMatrix2x3FP32* matrix);
extern inline void bgc_matrix2x3_set_row2_fp64(const double c1, const double c2, BgcMatrix2x3FP64* matrix);

extern inline void bgc_matrix2x3_set_row3_fp32(const float c1, const float c2, BgcMatrix2x3FP32* matrix);
extern inline void bgc_matrix2x3_set_row3_fp64(const double c1, const double c2, BgcMatrix2x3FP64* matrix);

extern inline void bgc_matrix2x3_set_column1_fp32(const float r1, const float r2, const float r3, BgcMatrix2x3FP32* matrix);
extern inline void bgc_matrix2x3_set_column1_fp64(const double r1, const double r2, const double r3, BgcMatrix2x3FP64* matrix);

extern inline void bgc_matrix2x3_set_column2_fp32(const float r1, const float r2, const float r3, BgcMatrix2x3FP32* matrix);
extern inline void bgc_matrix2x3_set_column2_fp64(const double r1, const double r2, const double r3, BgcMatrix2x3FP64* matrix);

extern inline void bgc_matrix2x3_make_transposed_fp32(const BgcMatrix3x2FP32* from, BgcMatrix2x3FP32* to);
extern inline void bgc_matrix2x3_make_transposed_fp64(const BgcMatrix3x2FP64* from, BgcMatrix2x3FP64* to);

extern inline void bgc_matrix2x3_add_fp32(const BgcMatrix2x3FP32* matrix1, const BgcMatrix2x3FP32* matrix2, BgcMatrix2x3FP32* sum);
extern inline void bgc_matrix2x3_add_fp64(const BgcMatrix2x3FP64* matrix1, const BgcMatrix2x3FP64* matrix2, BgcMatrix2x3FP64* sum);

extern inline void bgc_matrix2x3_add_scaled_fp32(const BgcMatrix2x3FP32* basic_matrix, const BgcMatrix2x3FP32* scalable_matrix, const float scale, BgcMatrix2x3FP32* sum);
extern inline void bgc_matrix2x3_add_scaled_fp64(const BgcMatrix2x3FP64* basic_matrix, const BgcMatrix2x3FP64* scalable_matrix, const double scale, BgcMatrix2x3FP64* sum);

extern inline void bgc_matrix2x3_subtract_fp32(const BgcMatrix2x3FP32* minuend, const BgcMatrix2x3FP32* subtrahend, BgcMatrix2x3FP32* difference);
extern inline void bgc_matrix2x3_subtract_fp64(const BgcMatrix2x3FP64* minuend, const BgcMatrix2x3FP64* subtrahend, BgcMatrix2x3FP64* difference);

extern inline void bgc_matrix2x3_subtract_scaled_fp32(const BgcMatrix2x3FP32* basic_matrix, const BgcMatrix2x3FP32* scalable_matrix, const float scale, BgcMatrix2x3FP32* difference);
extern inline void bgc_matrix2x3_subtract_scaled_fp64(const BgcMatrix2x3FP64* basic_matrix, const BgcMatrix2x3FP64* scalable_matrix, const double scale, BgcMatrix2x3FP64* difference);

extern inline void bgc_matrix2x3_multiply_fp32(const BgcMatrix2x3FP32* multiplicand, const float multiplier, BgcMatrix2x3FP32* product);
extern inline void bgc_matrix2x3_multiply_fp64(const BgcMatrix2x3FP64* multiplicand, const double multiplier, BgcMatrix2x3FP64* product);

extern inline void bgc_matrix2x3_divide_fp32(const BgcMatrix2x3FP32* dividend, const float divisor, BgcMatrix2x3FP32* quotient);
extern inline void bgc_matrix2x3_divide_fp64(const BgcMatrix2x3FP64* dividend, const double divisor, BgcMatrix2x3FP64* quotient);

extern inline void bgc_matrix2x3_left_product_fp32(const BgcVector3FP32* vector, const BgcMatrix2x3FP32* matrix, BgcVector2FP32* result);
extern inline void bgc_matrix2x3_left_product_fp64(const BgcVector3FP64* vector, const BgcMatrix2x3FP64* matrix, BgcVector2FP64* result);

extern inline void bgc_matrix2x3_right_product_fp32(const BgcMatrix2x3FP32* matrix, const BgcVector2FP32* vector, BgcVector3FP32* result);
extern inline void bgc_matrix2x3_right_product_fp64(const BgcMatrix2x3FP64* matrix, const BgcVector2FP64* vector, BgcVector3FP64* result);
