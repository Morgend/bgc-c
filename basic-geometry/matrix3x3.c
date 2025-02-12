#include "matrix3x3.h"

extern inline void bgc_matrix3x3_reset_fp32(BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_reset_fp64(BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_to_identity_fp32(BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_to_identity_fp64(BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_to_diagonal_fp32(const float d1, const float d2, const float d3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_to_diagonal_fp64(const double d1, const double d2, const double d3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_copy_fp32(const BgcMatrix3x3FP32* from, BgcMatrix3x3FP32* to);
extern inline void bgc_matrix3x3_copy_fp64(const BgcMatrix3x3FP64* from, BgcMatrix3x3FP64* to);

extern inline void bgc_matrix3x3_swap_fp32(BgcMatrix3x3FP32* matrix1, BgcMatrix3x3FP32* matrix2);
extern inline void bgc_matrix3x3_swap_fp64(BgcMatrix3x3FP64* matrix1, BgcMatrix3x3FP64* matrix2);

extern inline void bgc_matrix3x3_convert_fp64_to_fp32(const BgcMatrix3x3FP64* from, BgcMatrix3x3FP32* to);
extern inline void bgc_matrix3x3_convert_fp32_to_fp64(const BgcMatrix3x3FP32* from, BgcMatrix3x3FP64* to);

extern inline float bgc_matrix3x3_get_determinant_fp32(const BgcMatrix3x3FP32* matrix);
extern inline double bgc_matrix3x3_get_determinant_fp64(const BgcMatrix3x3FP64* matrix);

extern inline int bgc_matrix3x3_is_singular_fp32(const BgcMatrix3x3FP32* matrix);
extern inline int bgc_matrix3x3_is_singular_fp64(const BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_transpose_fp32(BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_transpose_fp64(BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_row1_fp32(const float c1, const float c2, const float c3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_row1_fp64(const double c1, const double c2, const double c3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_row2_fp32(const float c1, const float c2, const float c3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_row2_fp64(const double c1, const double c2, const double c3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_row3_fp32(const float c1, const float c2, const float c3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_row3_fp64(const double c1, const double c2, const double c3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_column1_fp32(const float r1, const float r2, const float r3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_column1_fp64(const double r1, const double r2, const double r3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_column2_fp32(const float r1, const float r2, const float r3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_column2_fp64(const double r1, const double r2, const double r3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_set_column3_fp32(const float r1, const float r2, const float r3, BgcMatrix3x3FP32* matrix);
extern inline void bgc_matrix3x3_set_column3_fp64(const double r1, const double r2, const double r3, BgcMatrix3x3FP64* matrix);

extern inline void bgc_matrix3x3_make_transposed_fp32(const BgcMatrix3x3FP32* matrix, BgcMatrix3x3FP32* result);
extern inline void bgc_matrix3x3_make_transposed_fp64(const BgcMatrix3x3FP64* matrix, BgcMatrix3x3FP64* result);

extern inline void bgc_matrix3x3_add_fp32(const BgcMatrix3x3FP32* matrix1, const BgcMatrix3x3FP32* matrix2, BgcMatrix3x3FP32* sum);
extern inline void bgc_matrix3x3_add_fp64(const BgcMatrix3x3FP64* matrix1, const BgcMatrix3x3FP64* matrix2, BgcMatrix3x3FP64* sum);

extern inline void bgc_matrix3x3_add_scaled_fp32(const BgcMatrix3x3FP32* basic_matrix, const BgcMatrix3x3FP32* scalable_matrix, const float scale, BgcMatrix3x3FP32* sum);
extern inline void bgc_matrix3x3_add_scaled_fp64(const BgcMatrix3x3FP64* basic_matrix, const BgcMatrix3x3FP64* scalable_matrix, const double scale, BgcMatrix3x3FP64* sum);

extern inline void bgc_matrix3x3_subtract_fp32(const BgcMatrix3x3FP32* minuend, const BgcMatrix3x3FP32* subtrahend, BgcMatrix3x3FP32* difference);
extern inline void bgc_matrix3x3_subtract_fp64(const BgcMatrix3x3FP64* minuend, const BgcMatrix3x3FP64* subtrahend, BgcMatrix3x3FP64* difference);

extern inline void bgc_matrix3x3_subtract_scaled_fp32(const BgcMatrix3x3FP32* basic_matrix, const BgcMatrix3x3FP32* scalable_matrix, const float scale, BgcMatrix3x3FP32* difference);
extern inline void bgc_matrix3x3_subtract_scaled_fp64(const BgcMatrix3x3FP64* basic_matrix, const BgcMatrix3x3FP64* scalable_matrix, const double scale, BgcMatrix3x3FP64* difference);

extern inline void bgc_matrix3x3_multiply_fp32(const BgcMatrix3x3FP32* multiplicand, const float multiplier, BgcMatrix3x3FP32* product);
extern inline void bgc_matrix3x3_multiply_fp64(const BgcMatrix3x3FP64* multiplicand, const double multiplier, BgcMatrix3x3FP64* product);

extern inline void bgc_matrix3x3_divide_fp32(const BgcMatrix3x3FP32* dividend, const float divisor, BgcMatrix3x3FP32* quotient);
extern inline void bgc_matrix3x3_divide_fp64(const BgcMatrix3x3FP64* dividend, const double divisor, BgcMatrix3x3FP64* quotient);

extern inline void bgc_matrix3x3_left_product_fp32(const BgcVector3FP32* vector, const BgcMatrix3x3FP32* matrix, BgcVector3FP32* result);
extern inline void bgc_matrix3x3_left_product_fp64(const BgcVector3FP64* vector, const BgcMatrix3x3FP64* matrix, BgcVector3FP64* result);

extern inline void bgc_matrix3x3_right_product_fp32(const BgcMatrix3x3FP32* matrix, const BgcVector3FP32* vector, BgcVector3FP32* result);
extern inline void bgc_matrix3x3_right_product_fp64(const BgcMatrix3x3FP64* matrix, const BgcVector3FP64* vector, BgcVector3FP64* result);

// =================== Invert =================== //

int bgc_matrix3x3_invert_fp32(BgcMatrix3x3FP32* matrix)
{
    const float determinant = bgc_matrix3x3_get_determinant_fp32(matrix);

    if (-BGC_EPSYLON_FP32 <= determinant && determinant <= BGC_EPSYLON_FP32) {
        return 0;
    }

    const float r1c1 = matrix->r2c2 * matrix->r3c3 - matrix->r2c3 * matrix->r3c2;
    const float r1c2 = matrix->r1c3 * matrix->r3c2 - matrix->r1c2 * matrix->r3c3;
    const float r1c3 = matrix->r1c2 * matrix->r2c3 - matrix->r1c3 * matrix->r2c2;

    const float r2c1 = matrix->r2c3 * matrix->r3c1 - matrix->r2c1 * matrix->r3c3;
    const float r2c2 = matrix->r1c1 * matrix->r3c3 - matrix->r1c3 * matrix->r3c1;
    const float r2c3 = matrix->r1c3 * matrix->r2c1 - matrix->r1c1 * matrix->r2c3;

    const float r3c1 = matrix->r2c1 * matrix->r3c2 - matrix->r2c2 * matrix->r3c1;
    const float r3c2 = matrix->r1c2 * matrix->r3c1 - matrix->r1c1 * matrix->r3c2;
    const float r3c3 = matrix->r1c1 * matrix->r2c2 - matrix->r1c2 * matrix->r2c1;

    const float multiplier = 1.0f / determinant;

    matrix->r1c1 = r1c1 * multiplier;
    matrix->r1c2 = r1c2 * multiplier;
    matrix->r1c3 = r1c3 * multiplier;

    matrix->r2c1 = r2c1 * multiplier;
    matrix->r2c2 = r2c2 * multiplier;
    matrix->r2c3 = r2c3 * multiplier;

    matrix->r3c1 = r3c1 * multiplier;
    matrix->r3c2 = r3c2 * multiplier;
    matrix->r3c3 = r3c3 * multiplier;

    return 1;
}

int bgc_matrix3x3_invert_fp64(BgcMatrix3x3FP64* matrix)
{
    const double determinant = bgc_matrix3x3_get_determinant_fp64(matrix);

    if (-BGC_EPSYLON_FP64 <= determinant && determinant <= BGC_EPSYLON_FP64) {
        return 0;
    }

    const double r1c1 = matrix->r2c2 * matrix->r3c3 - matrix->r2c3 * matrix->r3c2;
    const double r1c2 = matrix->r1c3 * matrix->r3c2 - matrix->r1c2 * matrix->r3c3;
    const double r1c3 = matrix->r1c2 * matrix->r2c3 - matrix->r1c3 * matrix->r2c2;

    const double r2c1 = matrix->r2c3 * matrix->r3c1 - matrix->r2c1 * matrix->r3c3;
    const double r2c2 = matrix->r1c1 * matrix->r3c3 - matrix->r1c3 * matrix->r3c1;
    const double r2c3 = matrix->r1c3 * matrix->r2c1 - matrix->r1c1 * matrix->r2c3;

    const double r3c1 = matrix->r2c1 * matrix->r3c2 - matrix->r2c2 * matrix->r3c1;
    const double r3c2 = matrix->r1c2 * matrix->r3c1 - matrix->r1c1 * matrix->r3c2;
    const double r3c3 = matrix->r1c1 * matrix->r2c2 - matrix->r1c2 * matrix->r2c1;

    const double multiplier = 1.0 / determinant;

    matrix->r1c1 = r1c1 * multiplier;
    matrix->r1c2 = r1c2 * multiplier;
    matrix->r1c3 = r1c3 * multiplier;

    matrix->r2c1 = r2c1 * multiplier;
    matrix->r2c2 = r2c2 * multiplier;
    matrix->r2c3 = r2c3 * multiplier;

    matrix->r3c1 = r3c1 * multiplier;
    matrix->r3c2 = r3c2 * multiplier;
    matrix->r3c3 = r3c3 * multiplier;

    return 1;
}

// ================ Make Inverted =============== //

int bgc_matrix3x3_make_inverted_fp32(const BgcMatrix3x3FP32* matrix, BgcMatrix3x3FP32* result)
{
    const float determinant = bgc_matrix3x3_get_determinant_fp32(matrix);

    if (-BGC_EPSYLON_FP32 <= determinant && determinant <= BGC_EPSYLON_FP32) {
        return 0;
    }

    const float r1c1 = matrix->r2c2 * matrix->r3c3 - matrix->r2c3 * matrix->r3c2;
    const float r1c2 = matrix->r1c3 * matrix->r3c2 - matrix->r1c2 * matrix->r3c3;
    const float r1c3 = matrix->r1c2 * matrix->r2c3 - matrix->r1c3 * matrix->r2c2;

    const float r2c1 = matrix->r2c3 * matrix->r3c1 - matrix->r2c1 * matrix->r3c3;
    const float r2c2 = matrix->r1c1 * matrix->r3c3 - matrix->r1c3 * matrix->r3c1;
    const float r2c3 = matrix->r1c3 * matrix->r2c1 - matrix->r1c1 * matrix->r2c3;

    const float r3c1 = matrix->r2c1 * matrix->r3c2 - matrix->r2c2 * matrix->r3c1;
    const float r3c2 = matrix->r1c2 * matrix->r3c1 - matrix->r1c1 * matrix->r3c2;
    const float r3c3 = matrix->r1c1 * matrix->r2c2 - matrix->r1c2 * matrix->r2c1;

    const float multiplier = 1.0f / determinant;

    result->r1c1 = r1c1 * multiplier;
    result->r1c2 = r1c2 * multiplier;
    result->r1c3 = r1c3 * multiplier;

    result->r2c1 = r2c1 * multiplier;
    result->r2c2 = r2c2 * multiplier;
    result->r2c3 = r2c3 * multiplier;

    result->r3c1 = r3c1 * multiplier;
    result->r3c2 = r3c2 * multiplier;
    result->r3c3 = r3c3 * multiplier;

    return 1;
}

int bgc_matrix3x3_make_inverted_fp64(const BgcMatrix3x3FP64* matrix, BgcMatrix3x3FP64* result)
{
    const double determinant = bgc_matrix3x3_get_determinant_fp64(matrix);

    if (-BGC_EPSYLON_FP64 <= determinant && determinant <= BGC_EPSYLON_FP64) {
        return 0;
    }

    const double r1c1 = matrix->r2c2 * matrix->r3c3 - matrix->r2c3 * matrix->r3c2;
    const double r1c2 = matrix->r1c3 * matrix->r3c2 - matrix->r1c2 * matrix->r3c3;
    const double r1c3 = matrix->r1c2 * matrix->r2c3 - matrix->r1c3 * matrix->r2c2;

    const double r2c1 = matrix->r2c3 * matrix->r3c1 - matrix->r2c1 * matrix->r3c3;
    const double r2c2 = matrix->r1c1 * matrix->r3c3 - matrix->r1c3 * matrix->r3c1;
    const double r2c3 = matrix->r1c3 * matrix->r2c1 - matrix->r1c1 * matrix->r2c3;

    const double r3c1 = matrix->r2c1 * matrix->r3c2 - matrix->r2c2 * matrix->r3c1;
    const double r3c2 = matrix->r1c2 * matrix->r3c1 - matrix->r1c1 * matrix->r3c2;
    const double r3c3 = matrix->r1c1 * matrix->r2c2 - matrix->r1c2 * matrix->r2c1;

    const double multiplier = 1.0 / determinant;

    result->r1c1 = r1c1 * multiplier;
    result->r1c2 = r1c2 * multiplier;
    result->r1c3 = r1c3 * multiplier;

    result->r2c1 = r2c1 * multiplier;
    result->r2c2 = r2c2 * multiplier;
    result->r2c3 = r2c3 * multiplier;

    result->r3c1 = r3c1 * multiplier;
    result->r3c2 = r3c2 * multiplier;
    result->r3c3 = r3c3 * multiplier;

    return 1;
}
