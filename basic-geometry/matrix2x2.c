#include "matrix2x2.h"

extern inline void bgc_matrix2x2_reset_fp32(BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_reset_fp64(BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_set_to_identity_fp32(BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_to_identity_fp64(BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_set_to_diagonal_fp32(const float d1, const float d2, BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_to_diagonal_fp64(const double d1, const double d2, BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcMatrix2x2FP64* matrix);

extern inline float bgc_matrix2x2_get_determinant_fp32(const BgcMatrix2x2FP32* matrix);
extern inline double bgc_matrix2x2_get_determinant_fp64(const BgcMatrix2x2FP64* matrix);

extern inline int bgc_matrix2x2_is_singular_fp32(const BgcMatrix2x2FP32* matrix);
extern inline int bgc_matrix2x2_is_singular_fp64(const BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_copy_fp32(const BgcMatrix2x2FP32* source, BgcMatrix2x2FP32* destination);
extern inline void bgc_matrix2x2_copy_fp64(const BgcMatrix2x2FP64* source, BgcMatrix2x2FP64* destination);

extern inline void bgc_matrix2x2_swap_fp32(BgcMatrix2x2FP32* matrix1, BgcMatrix2x2FP32* matrix2);
extern inline void bgc_matrix2x2_swap_fp64(BgcMatrix2x2FP64* matrix1, BgcMatrix2x2FP64* matrix2);

extern inline void bgc_matrix2x2_convert_fp64_to_fp32(const BgcMatrix2x2FP64* source, BgcMatrix2x2FP32* destination);
extern inline void bgc_matrix2x2_convert_fp32_to_fp64(const BgcMatrix2x2FP32* source, BgcMatrix2x2FP64* destination);

extern inline int bgc_matrix2x2_invert_fp32(const BgcMatrix2x2FP32* matrix, BgcMatrix2x2FP32* inverted);
extern inline int bgc_matrix2x2_invert_fp64(const BgcMatrix2x2FP64* matrix, BgcMatrix2x2FP64* inverted);

extern inline void bgc_matrix2x2_transpose_fp32(const BgcMatrix2x2FP32* matrix, BgcMatrix2x2FP32* transposed);
extern inline void bgc_matrix2x2_transpose_fp64(const BgcMatrix2x2FP64* matrix, BgcMatrix2x2FP64* transposed);

extern inline void bgc_matrix2x2_set_row1_fp32(const float c1, const float c2, BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_row1_fp64(const double c1, const double c2, BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_set_row2_fp32(const float c1, const float c2, BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_row2_fp64(const double c1, const double c2, BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_set_column1_fp32(const float r1, const float r2, BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_column1_fp64(const double r1, const double r2, BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_set_column2_fp32(const float r1, const float r2, BgcMatrix2x2FP32* matrix);
extern inline void bgc_matrix2x2_set_column2_fp64(const double r1, const double r2, BgcMatrix2x2FP64* matrix);

extern inline void bgc_matrix2x2_add_fp32(const BgcMatrix2x2FP32* matrix1, const BgcMatrix2x2FP32* matrix2, BgcMatrix2x2FP32* sum);
extern inline void bgc_matrix2x2_add_fp64(const BgcMatrix2x2FP64* matrix1, const BgcMatrix2x2FP64* matrix2, BgcMatrix2x2FP64* sum);

extern inline void bgc_matrix2x2_add_scaled_fp32(const BgcMatrix2x2FP32* basic_matrix, const BgcMatrix2x2FP32* scalable_matrix, const float scale, BgcMatrix2x2FP32* sum);
extern inline void bgc_matrix2x2_add_scaled_fp64(const BgcMatrix2x2FP64* basic_matrix, const BgcMatrix2x2FP64* scalable_matrix, const double scale, BgcMatrix2x2FP64* sum);

extern inline void bgc_matrix2x2_subtract_fp32(const BgcMatrix2x2FP32* minuend, const BgcMatrix2x2FP32* subtrahend, BgcMatrix2x2FP32* difference);
extern inline void bgc_matrix2x2_subtract_fp64(const BgcMatrix2x2FP64* minuend, const BgcMatrix2x2FP64* subtrahend, BgcMatrix2x2FP64* difference);

extern inline void bgc_matrix2x2_subtract_scaled_fp32(const BgcMatrix2x2FP32* basic_matrix, const BgcMatrix2x2FP32* scalable_matrix, const float scale, BgcMatrix2x2FP32* difference);
extern inline void bgc_matrix2x2_subtract_scaled_fp64(const BgcMatrix2x2FP64* basic_matrix, const BgcMatrix2x2FP64* scalable_matrix, const double scale, BgcMatrix2x2FP64* difference);

extern inline void bgc_matrix2x2_multiply_fp32(const BgcMatrix2x2FP32* multiplicand, const float multiplier, BgcMatrix2x2FP32* product);
extern inline void bgc_matrix2x2_multiply_fp64(const BgcMatrix2x2FP64* multiplicand, const double multiplier, BgcMatrix2x2FP64* product);

extern inline void bgc_matrix2x2_divide_fp32(const BgcMatrix2x2FP32* dividend, const float divisor, BgcMatrix2x2FP32* quotient);
extern inline void bgc_matrix2x2_divide_fp64(const BgcMatrix2x2FP64* dividend, const double divisor, BgcMatrix2x2FP64* quotient);

extern inline void bgc_matrix2x2_get_left_product_fp32(const BgcVector2FP32* vector, const BgcMatrix2x2FP32* matrix, BgcVector2FP32* product);
extern inline void bgc_matrix2x2_get_left_product_fp64(const BgcVector2FP64* vector, const BgcMatrix2x2FP64* matrix, BgcVector2FP64* product);

extern inline void bgc_matrix2x2_get_right_product_fp32(const BgcMatrix2x2FP32* matrix, const BgcVector2FP32* vector, BgcVector2FP32* product);
extern inline void bgc_matrix2x2_get_right_product_fp64(const BgcMatrix2x2FP64* matrix, const BgcVector2FP64* vector, BgcVector2FP64* product);
