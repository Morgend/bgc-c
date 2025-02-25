#ifndef _BGC_MATRIX2X2_H_
#define _BGC_MATRIX2X2_H_

#include "angle.h"
#include "vector2.h"
#include "matrixes.h"

// =================== Reset ==================== //

inline void bgc_matrix2x2_reset_fp32(BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = 0.0f;
    matrix->r1c2 = 0.0f;
    matrix->r2c1 = 0.0f;
    matrix->r2c2 = 0.0f;
}

inline void bgc_matrix2x2_reset_fp64(BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = 0.0;
    matrix->r1c2 = 0.0;
    matrix->r2c1 = 0.0;
    matrix->r2c2 = 0.0;
}

// ================== Identity ================== //

inline void bgc_matrix2x2_set_to_identity_fp32(BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = 1.0f;
    matrix->r1c2 = 0.0f;
    matrix->r2c1 = 0.0f;
    matrix->r2c2 = 1.0f;
}

inline void bgc_matrix2x2_set_to_identity_fp64(BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = 1.0;
    matrix->r1c2 = 0.0;
    matrix->r2c1 = 0.0;
    matrix->r2c2 = 1.0;
}

// ================ Set Diagonal ================ //

inline void bgc_matrix2x2_set_to_diagonal_fp32(const float d1, const float d2, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = d1;
    matrix->r1c2 = 0.0f;
    matrix->r2c1 = 0.0f;
    matrix->r2c2 = d2;
}

inline void bgc_matrix2x2_set_to_diagonal_fp64(const double d1, const double d2, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = d1;
    matrix->r1c2 = 0.0;
    matrix->r2c1 = 0.0;
    matrix->r2c2 = d2;
}

// ============== Rotation Matrix =============== //

inline void bgc_matrix2x2_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcMatrix2x2FP32* matrix)
{
    const float radians = bgc_angle_to_radians_fp32(angle, unit);
    const float cosine = cosf(radians);
    const float sine = sinf(radians);

    matrix->r1c1 = cosine;
    matrix->r1c2 = -sine;
    matrix->r2c1 = sine;
    matrix->r2c2 = cosine;
}

inline void bgc_matrix2x2_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcMatrix2x2FP64* matrix)
{
    const double radians = bgc_angle_to_radians_fp64(angle, unit);
    const double cosine = cos(radians);
    const double sine = sin(radians);

    matrix->r1c1 = cosine;
    matrix->r1c2 = -sine;
    matrix->r2c1 = sine;
    matrix->r2c2 = cosine;
}

// ================ Determinant ================= //

inline float bgc_matrix2x2_get_determinant_fp32(const BgcMatrix2x2FP32* matrix)
{
    return matrix->r1c1 * matrix->r2c2 - matrix->r1c2 * matrix->r2c1;
}

inline double bgc_matrix2x2_get_determinant_fp64(const BgcMatrix2x2FP64* matrix)
{
    return matrix->r1c1 * matrix->r2c2 - matrix->r1c2 * matrix->r2c1;
}

// ================== Singular ================== //

inline int bgc_matrix2x2_is_singular_fp32(const BgcMatrix2x2FP32* matrix)
{
    return bgc_is_zero_fp32(bgc_matrix2x2_get_determinant_fp32(matrix));
}

inline int bgc_matrix2x2_is_singular_fp64(const BgcMatrix2x2FP64* matrix)
{
    return bgc_is_zero_fp64(bgc_matrix2x2_get_determinant_fp64(matrix));
}

// ==================== Copy ==================== //

inline void bgc_matrix2x2_copy_fp32(const BgcMatrix2x2FP32* source, BgcMatrix2x2FP32* destination)
{
    destination->r1c1 = source->r1c1;
    destination->r1c2 = source->r1c2;

    destination->r2c1 = source->r2c1;
    destination->r2c2 = source->r2c2;
}

inline void bgc_matrix2x2_copy_fp64(const BgcMatrix2x2FP64* source, BgcMatrix2x2FP64* destination)
{
    destination->r1c1 = source->r1c1;
    destination->r1c2 = source->r1c2;

    destination->r2c1 = source->r2c1;
    destination->r2c2 = source->r2c2;
}

// ==================== Swap ==================== //

inline void bgc_matrix2x2_swap_fp32(BgcMatrix2x2FP32* matrix1, BgcMatrix2x2FP32* matrix2)
{
    const float r1c1 = matrix2->r1c1;
    const float r1c2 = matrix2->r1c2;

    const float r2c1 = matrix2->r2c1;
    const float r2c2 = matrix2->r2c2;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;
}

inline void bgc_matrix2x2_swap_fp64(BgcMatrix2x2FP64* matrix1, BgcMatrix2x2FP64* matrix2)
{
    const double r1c1 = matrix2->r1c1;
    const double r1c2 = matrix2->r1c2;

    const double r2c1 = matrix2->r2c1;
    const double r2c2 = matrix2->r2c2;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;
}

// ================== Convert =================== //

inline void bgc_matrix2x2_convert_fp64_to_fp32(const BgcMatrix2x2FP64* source, BgcMatrix2x2FP32* destination)
{
    destination->r1c1 = (float)source->r1c1;
    destination->r1c2 = (float)source->r1c2;

    destination->r2c1 = (float)source->r2c1;
    destination->r2c2 = (float)source->r2c2;
}

inline void bgc_matrix2x2_convert_fp32_to_fp64(const BgcMatrix2x2FP32* source, BgcMatrix2x2FP64* destination)
{
    destination->r1c1 = source->r1c1;
    destination->r1c2 = source->r1c2;

    destination->r2c1 = source->r2c1;
    destination->r2c2 = source->r2c2;
}

// =================== Invert =================== //

inline int bgc_matrix2x2_invert_fp32(const BgcMatrix2x2FP32* matrix, BgcMatrix2x2FP32* inverted)
{
    const float determinant = bgc_matrix2x2_get_determinant_fp32(matrix);

    if (bgc_is_zero_fp32(determinant)) {
        return 0;
    }

    const float r1c1 = matrix->r2c2;
    const float r1c2 = -matrix->r1c2;

    const float r2c1 = -matrix->r2c1;
    const float r2c2 = matrix->r1c1;

    const float multiplier = 1.0f / determinant;

    inverted->r1c1 = r1c1 * multiplier;
    inverted->r1c2 = r1c2 * multiplier;

    inverted->r2c1 = r2c1 * multiplier;
    inverted->r2c2 = r2c2 * multiplier;

    return 1;
}

inline int bgc_matrix2x2_invert_fp64(const BgcMatrix2x2FP64* matrix, BgcMatrix2x2FP64* inverted)
{
    const double determinant = bgc_matrix2x2_get_determinant_fp64(matrix);

    if (bgc_is_zero_fp64(determinant)) {
        return 0;
    }

    const double r1c1 = matrix->r2c2;
    const double r1c2 = -matrix->r1c2;

    const double r2c1 = -matrix->r2c1;
    const double r2c2 = matrix->r1c1;

    const double multiplier = 1.0 / determinant;

    inverted->r1c1 = r1c1 * multiplier;
    inverted->r1c2 = r1c2 * multiplier;

    inverted->r2c1 = r2c1 * multiplier;
    inverted->r2c2 = r2c2 * multiplier;

    return 1;
}

// ================= Transpose ================== //

inline void bgc_matrix2x2_transpose_fp32(const BgcMatrix2x2FP32* matrix, BgcMatrix2x2FP32* transposed)
{
    const float r1c2 = matrix->r1c2;

    transposed->r1c1 = matrix->r1c1;
    transposed->r1c2 = matrix->r2c1;

    transposed->r2c1 = r1c2;
    transposed->r2c2 = matrix->r2c2;
}

inline void bgc_matrix2x2_transpose_fp64(const BgcMatrix2x2FP64* matrix, BgcMatrix2x2FP64* transposed)
{
    const double r1c2 = matrix->r1c2;

    transposed->r1c1 = matrix->r1c1;
    transposed->r1c2 = matrix->r2c1;

    transposed->r2c1 = r1c2;
    transposed->r2c2 = matrix->r2c2;
}

// ================= Set Row 1 ================== //

inline void bgc_matrix2x2_set_row1_fp32(const float c1, const float c2, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
}

inline void bgc_matrix2x2_set_row1_fp64(const double c1, const double c2, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
}

// ================= Set Row 2 ================== //

inline void bgc_matrix2x2_set_row2_fp32(const float c1, const float c2, BgcMatrix2x2FP32* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
}

inline void bgc_matrix2x2_set_row2_fp64(const double c1, const double c2, BgcMatrix2x2FP64* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
}

// ================ Set Column 1 ================ //

inline void bgc_matrix2x2_set_column1_fp32(const float r1, const float r2, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
}

inline void bgc_matrix2x2_set_column1_fp64(const double r1, const double r2, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
}

// ================ Set Column 2 ================ //

inline void bgc_matrix2x2_set_column2_fp32(const float r1, const float r2, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
}

inline void bgc_matrix2x2_set_column2_fp64(const double r1, const double r2, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
}

// ==================== Add ===================== //

inline void bgc_matrix2x2_add_fp32(const BgcMatrix2x2FP32* matrix1, const BgcMatrix2x2FP32* matrix2, BgcMatrix2x2FP32* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;
}

inline void bgc_matrix2x2_add_fp64(const BgcMatrix2x2FP64* matrix1, const BgcMatrix2x2FP64* matrix2, BgcMatrix2x2FP64* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;
}

// ================= Add scaled ================= //

inline void bgc_matrix2x2_add_scaled_fp32(const BgcMatrix2x2FP32* basic_matrix, const BgcMatrix2x2FP32* scalable_matrix, const float scale, BgcMatrix2x2FP32* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;
}

inline void bgc_matrix2x2_add_scaled_fp64(const BgcMatrix2x2FP64* basic_matrix, const BgcMatrix2x2FP64* scalable_matrix, const double scale, BgcMatrix2x2FP64* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;
}

// ================== Subtract ================== //

inline void bgc_matrix2x2_subtract_fp32(const BgcMatrix2x2FP32* minuend, const BgcMatrix2x2FP32* subtrahend, BgcMatrix2x2FP32* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;
}

inline void bgc_matrix2x2_subtract_fp64(const BgcMatrix2x2FP64* minuend, const BgcMatrix2x2FP64* subtrahend, BgcMatrix2x2FP64* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;
}

// ============== Subtract scaled =============== //

inline void bgc_matrix2x2_subtract_scaled_fp32(const BgcMatrix2x2FP32* basic_matrix, const BgcMatrix2x2FP32* scalable_matrix, const float scale, BgcMatrix2x2FP32* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;
}

inline void bgc_matrix2x2_subtract_scaled_fp64(const BgcMatrix2x2FP64* basic_matrix, const BgcMatrix2x2FP64* scalable_matrix, const double scale, BgcMatrix2x2FP64* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;
}

// ================== Multiply ================== //

inline void bgc_matrix2x2_multiply_fp32(const BgcMatrix2x2FP32* multiplicand, const float multiplier, BgcMatrix2x2FP32* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;
}

inline void bgc_matrix2x2_multiply_fp64(const BgcMatrix2x2FP64* multiplicand, const double multiplier, BgcMatrix2x2FP64* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;
}

// =================== Divide =================== //

inline void bgc_matrix2x2_divide_fp32(const BgcMatrix2x2FP32* dividend, const float divisor, BgcMatrix2x2FP32* quotient)
{
    bgc_matrix2x2_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_matrix2x2_divide_fp64(const BgcMatrix2x2FP64* dividend, const double divisor, BgcMatrix2x2FP64* quotient)
{
    bgc_matrix2x2_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ============ Left Vector Product ============= //

inline void bgc_matrix2x2_get_left_product_fp32(const BgcVector2FP32* vector, const BgcMatrix2x2FP32* matrix, BgcVector2FP32* product)
{
    const float x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1;
    const float x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2;

    product->x1 = x1;
    product->x2 = x2;
}

inline void bgc_matrix2x2_get_left_product_fp64(const BgcVector2FP64* vector, const BgcMatrix2x2FP64* matrix, BgcVector2FP64* product)
{
    const double x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1;
    const double x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2;

    product->x1 = x1;
    product->x2 = x2;
}

// ============ Right Vector Product ============ //

inline void bgc_matrix2x2_get_right_product_fp32(const BgcMatrix2x2FP32* matrix, const BgcVector2FP32* vector, BgcVector2FP32* product)
{
    const float x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2;
    const float x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2;

    product->x1 = x1;
    product->x2 = x2;
}

inline void bgc_matrix2x2_get_right_product_fp64(const BgcMatrix2x2FP64* matrix, const BgcVector2FP64* vector, BgcVector2FP64* product)
{
    const double x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2;
    const double x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2;

    product->x1 = x1;
    product->x2 = x2;
}

#endif
