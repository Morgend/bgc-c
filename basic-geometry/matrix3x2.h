#ifndef _BGC_MATRIX3X2_H_
#define _BGC_MATRIX3X2_H_

#include "vector2.h"
#include "vector3.h"
#include "matrixes.h"

// =================== Reset ==================== //

inline void bgc_matrix3x2_reset_fp32(BgcMatrix3x2FP32* matrix)
{
    matrix->r1c1 = 0.0f;
    matrix->r1c2 = 0.0f;
    matrix->r1c3 = 0.0f;

    matrix->r2c1 = 0.0f;
    matrix->r2c2 = 0.0f;
    matrix->r2c3 = 0.0f;
}

inline void bgc_matrix3x2_reset_fp64(BgcMatrix3x2FP64* matrix)
{
    matrix->r1c1 = 0.0;
    matrix->r1c2 = 0.0;
    matrix->r1c3 = 0.0;

    matrix->r2c1 = 0.0;
    matrix->r2c2 = 0.0;
    matrix->r2c3 = 0.0;
}

// ==================== Copy ==================== //

inline void bgc_matrix3x2_copy_fp32(const BgcMatrix3x2FP32* source, BgcMatrix3x2FP32* destination)
{
    destination->r1c1 = source->r1c1;
    destination->r1c2 = source->r1c2;
    destination->r1c3 = source->r1c3;

    destination->r2c1 = source->r2c1;
    destination->r2c2 = source->r2c2;
    destination->r2c3 = source->r2c3;
}

inline void bgc_matrix3x2_copy_fp64(const BgcMatrix3x2FP64* source, BgcMatrix3x2FP64* destination)
{
    destination->r1c1 = source->r1c1;
    destination->r1c2 = source->r1c2;
    destination->r1c3 = source->r1c3;

    destination->r2c1 = source->r2c1;
    destination->r2c2 = source->r2c2;
    destination->r2c3 = source->r2c3;
}

// ==================== Swap ==================== //

inline void bgc_matrix3x2_swap_fp32(BgcMatrix3x2FP32* matrix1, BgcMatrix3x2FP32* matrix2)
{
    const float r1c1 = matrix2->r1c1;
    const float r1c2 = matrix2->r1c2;
    const float r1c3 = matrix2->r1c3;

    const float r2c1 = matrix2->r2c1;
    const float r2c2 = matrix2->r2c2;
    const float r2c3 = matrix2->r2c3;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;
    matrix2->r1c3 = matrix1->r1c3;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;
    matrix2->r2c3 = matrix1->r2c3;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;
    matrix1->r1c3 = r1c3;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;
    matrix1->r2c3 = r2c3;
}

inline void bgc_matrix3x2_swap_fp64(BgcMatrix3x2FP64* matrix1, BgcMatrix3x2FP64* matrix2)
{
    const double r1c1 = matrix2->r1c1;
    const double r1c2 = matrix2->r1c2;
    const double r1c3 = matrix2->r1c3;

    const double r2c1 = matrix2->r2c1;
    const double r2c2 = matrix2->r2c2;
    const double r2c3 = matrix2->r2c3;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;
    matrix2->r1c3 = matrix1->r1c3;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;
    matrix2->r2c3 = matrix1->r2c3;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;
    matrix1->r1c3 = r1c3;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;
    matrix1->r2c3 = r2c3;
}

// ================== Convert =================== //

inline void bgc_matrix3x2_convert_fp64_to_fp32(const BgcMatrix3x2FP64* source, BgcMatrix3x2FP32* destination)
{
    destination->r1c1 = (float)source->r1c1;
    destination->r1c2 = (float)source->r1c2;
    destination->r1c3 = (float)source->r1c3;

    destination->r2c1 = (float)source->r2c1;
    destination->r2c2 = (float)source->r2c2;
    destination->r2c3 = (float)source->r2c3;
}

inline void bgc_matrix3x2_convert_fp32_to_fp64(const BgcMatrix3x2FP32* source, BgcMatrix3x2FP64* destination)
{
    destination->r1c1 = source->r1c1;
    destination->r1c2 = source->r1c2;
    destination->r1c3 = source->r1c3;

    destination->r2c1 = source->r2c1;
    destination->r2c2 = source->r2c2;
    destination->r2c3 = source->r2c3;
}

// ================= Transpose ================== //

inline void bgc_matrix3x2_transpose_fp32(const BgcMatrix2x3FP32* matrix, BgcMatrix3x2FP32* transposed)
{
    transposed->r1c1 = matrix->r1c1;
    transposed->r1c2 = matrix->r2c1;
    transposed->r1c3 = matrix->r3c1;

    transposed->r2c1 = matrix->r1c2;
    transposed->r2c2 = matrix->r2c2;
    transposed->r2c3 = matrix->r3c2;
}

inline void bgc_matrix3x2_transpose_fp64(const BgcMatrix2x3FP64* matrix, BgcMatrix3x2FP64* transposed)
{
    transposed->r1c1 = matrix->r1c1;
    transposed->r1c2 = matrix->r2c1;
    transposed->r1c3 = matrix->r3c1;

    transposed->r2c1 = matrix->r1c2;
    transposed->r2c2 = matrix->r2c2;
    transposed->r2c3 = matrix->r3c2;
}

// ================= Set Row 1 ================== //

inline void bgc_matrix3x2_set_row1_fp32(const float c1, const float c2, const float c3, BgcMatrix3x2FP32* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
    matrix->r1c3 = c3;
}

inline void bgc_matrix3x2_set_row1_fp64(const double c1, const double c2, const double c3, BgcMatrix3x2FP64* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
    matrix->r1c3 = c3;
}

// ================= Set Row 2 ================== //

inline void bgc_matrix3x2_set_row2_fp32(const float c1, const float c2, const float c3, BgcMatrix3x2FP32* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
    matrix->r2c3 = c3;
}

inline void bgc_matrix3x2_set_row2_fp64(const double c1, const double c2, const double c3, BgcMatrix3x2FP64* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
    matrix->r2c3 = c3;
}

// ================ Set Column 1 ================ //

inline void bgc_matrix3x2_set_column1_fp32(const float r1, const float r2, BgcMatrix3x2FP32* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
}

inline void bgc_matrix3x2_set_column1_fp64(const double r1, const double r2, BgcMatrix3x2FP64* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
}

// ================ Set Column 2 ================ //

inline void bgc_matrix3x2_set_column2_fp32(const float r1, const float r2, BgcMatrix3x2FP32* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
}

inline void bgc_matrix3x2_set_column2_fp64(const double r1, const double r2, BgcMatrix3x2FP64* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
}

// ================ Set Column 3 ================ //

inline void bgc_matrix3x2_set_column3_fp32(const float r1, const float r2, BgcMatrix3x2FP32* matrix)
{
    matrix->r1c3 = r1;
    matrix->r2c3 = r2;
}

inline void bgc_matrix3x2_set_column3_fp64(const double r1, const double r2, BgcMatrix3x2FP64* matrix)
{
    matrix->r1c3 = r1;
    matrix->r2c3 = r2;
}

// ==================== Add ===================== //

inline void bgc_matrix3x2_add_fp32(const BgcMatrix3x2FP32* matrix1, const BgcMatrix3x2FP32* matrix2, BgcMatrix3x2FP32* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;
    sum->r1c3 = matrix1->r1c3 + matrix2->r1c3;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;
    sum->r2c3 = matrix1->r2c3 + matrix2->r2c3;
}

inline void bgc_matrix3x2_add_fp64(const BgcMatrix3x2FP64* matrix1, const BgcMatrix3x2FP64* matrix2, BgcMatrix3x2FP64* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;
    sum->r1c3 = matrix1->r1c3 + matrix2->r1c3;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;
    sum->r2c3 = matrix1->r2c3 + matrix2->r2c3;
}

// ================= Add scaled ================= //

inline void bgc_matrix3x2_add_scaled_fp32(const BgcMatrix3x2FP32* basic_matrix, const BgcMatrix3x2FP32* scalable_matrix, const float scale, BgcMatrix3x2FP32* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;
    sum->r1c3 = basic_matrix->r1c3 + scalable_matrix->r1c3 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;
    sum->r2c3 = basic_matrix->r2c3 + scalable_matrix->r2c3 * scale;
}

inline void bgc_matrix3x2_add_scaled_fp64(const BgcMatrix3x2FP64* basic_matrix, const BgcMatrix3x2FP64* scalable_matrix, const double scale, BgcMatrix3x2FP64* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;
    sum->r1c3 = basic_matrix->r1c3 + scalable_matrix->r1c3 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;
    sum->r2c3 = basic_matrix->r2c3 + scalable_matrix->r2c3 * scale;
}

// ================== Subtract ================== //

inline void bgc_matrix3x2_subtract_fp32(const BgcMatrix3x2FP32* minuend, const BgcMatrix3x2FP32* subtrahend, BgcMatrix3x2FP32* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;
    difference->r1c3 = minuend->r1c3 - subtrahend->r1c3;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;
    difference->r2c3 = minuend->r2c3 - subtrahend->r2c3;
}

inline void bgc_matrix3x2_subtract_fp64(const BgcMatrix3x2FP64* minuend, const BgcMatrix3x2FP64* subtrahend, BgcMatrix3x2FP64* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;
    difference->r1c3 = minuend->r1c3 - subtrahend->r1c3;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;
    difference->r2c3 = minuend->r2c3 - subtrahend->r2c3;
}

// ============== Subtract scaled =============== //

inline void bgc_matrix3x2_subtract_scaled_fp32(const BgcMatrix3x2FP32* basic_matrix, const BgcMatrix3x2FP32* scalable_matrix, const float scale, BgcMatrix3x2FP32* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;
    difference->r1c3 = basic_matrix->r1c3 - scalable_matrix->r1c3 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;
    difference->r2c3 = basic_matrix->r2c3 - scalable_matrix->r2c3 * scale;
}

inline void bgc_matrix3x2_subtract_scaled_fp64(const BgcMatrix3x2FP64* basic_matrix, const BgcMatrix3x2FP64* scalable_matrix, const double scale, BgcMatrix3x2FP64* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;
    difference->r1c3 = basic_matrix->r1c3 - scalable_matrix->r1c3 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;
    difference->r2c3 = basic_matrix->r2c3 - scalable_matrix->r2c3 * scale;
}

// ================== Multiply ================== //

inline void bgc_matrix3x2_multiply_fp32(const BgcMatrix3x2FP32* multiplicand, const float multiplier, BgcMatrix3x2FP32* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;
    product->r1c3 = multiplicand->r1c3 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;
    product->r2c3 = multiplicand->r2c3 * multiplier;
}

inline void bgc_matrix3x2_multiply_fp64(const BgcMatrix3x2FP64* multiplicand, const double multiplier, BgcMatrix3x2FP64* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;
    product->r1c3 = multiplicand->r1c3 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;
    product->r2c3 = multiplicand->r2c3 * multiplier;
}

// =================== Divide =================== //

inline void bgc_matrix3x2_divide_fp32(const BgcMatrix3x2FP32* dividend, const float divisor, BgcMatrix3x2FP32* quotient)
{
    bgc_matrix3x2_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_matrix3x2_divide_fp64(const BgcMatrix3x2FP64* dividend, const double divisor, BgcMatrix3x2FP64* quotient)
{
    bgc_matrix3x2_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ============ Left Vector Product ============= //

inline void bgc_matrix3x2_get_left_product_fp32(const BgcVector2FP32* vector, const BgcMatrix3x2FP32* matrix, BgcVector3FP32* result)
{
    result->x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1;
    result->x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2;
    result->x3 = vector->x1 * matrix->r1c3 + vector->x2 * matrix->r2c3;
}

inline void bgc_matrix3x2_get_left_product_fp64(const BgcVector2FP64* vector, const BgcMatrix3x2FP64* matrix, BgcVector3FP64* result)
{
    result->x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1;
    result->x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2;
    result->x3 = vector->x1 * matrix->r1c3 + vector->x2 * matrix->r2c3;
}

// ============ Right Vector Product ============ //

inline void bgc_matrix3x2_get_right_product_fp32(const BgcMatrix3x2FP32* matrix, const BgcVector3FP32* vector, BgcVector2FP32* result)
{
    result->x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2 + matrix->r1c3 * vector->x3;
    result->x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2 + matrix->r2c3 * vector->x3;
}

inline void bgc_matrix3x2_get_right_product_fp64(const BgcMatrix3x2FP64* matrix, const BgcVector3FP64* vector, BgcVector2FP64* result)
{
    result->x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2 + matrix->r1c3 * vector->x3;
    result->x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2 + matrix->r2c3 * vector->x3;
}

#endif
