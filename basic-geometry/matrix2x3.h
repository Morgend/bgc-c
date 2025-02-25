#ifndef _BGC_MATRIX2X3_H_
#define _BGC_MATRIX2X3_H_

#include "vector2.h"
#include "vector3.h"
#include "matrixes.h"

// =================== Reset ==================== //

inline void bgc_matrix2x3_reset_fp32(BgcMatrix2x3FP32* matrix)
{
    matrix->r1c1 = 0.0f;
    matrix->r1c2 = 0.0f;

    matrix->r2c1 = 0.0f;
    matrix->r2c2 = 0.0f;

    matrix->r3c1 = 0.0f;
    matrix->r3c2 = 0.0f;
}

inline void bgc_matrix2x3_reset_fp64(BgcMatrix2x3FP64* matrix)
{
    matrix->r1c1 = 0.0;
    matrix->r1c2 = 0.0;

    matrix->r2c1 = 0.0;
    matrix->r2c2 = 0.0;

    matrix->r3c1 = 0.0;
    matrix->r3c2 = 0.0;
}

// ==================== Copy ==================== //

inline void bgc_matrix2x3_copy_fp32(const BgcMatrix2x3FP32* from, BgcMatrix2x3FP32* to)
{
    to->r1c1 = from->r1c1;
    to->r1c2 = from->r1c2;

    to->r2c1 = from->r2c1;
    to->r2c2 = from->r2c2;

    to->r3c1 = from->r3c1;
    to->r3c2 = from->r3c2;
}

inline void bgc_matrix2x3_copy_fp64(const BgcMatrix2x3FP64* from, BgcMatrix2x3FP64* to)
{
    to->r1c1 = from->r1c1;
    to->r1c2 = from->r1c2;

    to->r2c1 = from->r2c1;
    to->r2c2 = from->r2c2;

    to->r3c1 = from->r3c1;
    to->r3c2 = from->r3c2;
}

// ==================== Swap ==================== //

inline void bgc_matrix2x3_swap_fp32(BgcMatrix2x3FP32* matrix1, BgcMatrix2x3FP32* matrix2)
{
    const float r1c1 = matrix2->r1c1;
    const float r1c2 = matrix2->r1c2;

    const float r2c1 = matrix2->r2c1;
    const float r2c2 = matrix2->r2c2;

    const float r3c1 = matrix2->r3c1;
    const float r3c2 = matrix2->r3c2;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;

    matrix2->r3c1 = matrix1->r3c1;
    matrix2->r3c2 = matrix1->r3c2;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;

    matrix1->r3c1 = r3c1;
    matrix1->r3c2 = r3c2;
}

inline void bgc_matrix2x3_swap_fp64(BgcMatrix2x3FP64* matrix1, BgcMatrix2x3FP64* matrix2)
{
    const double r1c1 = matrix2->r1c1;
    const double r1c2 = matrix2->r1c2;

    const double r2c1 = matrix2->r2c1;
    const double r2c2 = matrix2->r2c2;

    const double r3c1 = matrix2->r3c1;
    const double r3c2 = matrix2->r3c2;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;

    matrix2->r3c1 = matrix1->r3c1;
    matrix2->r3c2 = matrix1->r3c2;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;

    matrix1->r3c1 = r3c1;
    matrix1->r3c2 = r3c2;
}

// ================== Convert =================== //

inline void bgc_matrix2x3_convert_fp64_to_fp32(const BgcMatrix2x3FP64* from, BgcMatrix2x3FP32* to)
{
    to->r1c1 = (float) from->r1c1;
    to->r1c2 = (float) from->r1c2;

    to->r2c1 = (float) from->r2c1;
    to->r2c2 = (float) from->r2c2;

    to->r3c1 = (float) from->r3c1;
    to->r3c2 = (float) from->r3c2;
}

inline void bgc_matrix2x3_convert_fp32_to_fp64(const BgcMatrix2x3FP32* from, BgcMatrix2x3FP64* to)
{
    to->r1c1 = from->r1c1;
    to->r1c2 = from->r1c2;

    to->r2c1 = from->r2c1;
    to->r2c2 = from->r2c2;

    to->r3c1 = from->r3c1;
    to->r3c2 = from->r3c2;
}

// ================= Set Row 1 ================== //

inline void bgc_matrix2x3_set_row1_fp32(const float c1, const float c2, BgcMatrix2x3FP32* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
}

inline void bgc_matrix2x3_set_row1_fp64(const double c1, const double c2, BgcMatrix2x3FP64* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
}

// ================= Set Row 2 ================== //

inline void bgc_matrix2x3_set_row2_fp32(const float c1, const float c2, BgcMatrix2x3FP32* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
}

inline void bgc_matrix2x3_set_row2_fp64(const double c1, const double c2, BgcMatrix2x3FP64* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
}

// ================= Set Row 3 ================== //

inline void bgc_matrix2x3_set_row3_fp32(const float c1, const float c2, BgcMatrix2x3FP32* matrix)
{
    matrix->r3c1 = c1;
    matrix->r3c2 = c2;
}

inline void bgc_matrix2x3_set_row3_fp64(const double c1, const double c2, BgcMatrix2x3FP64* matrix)
{
    matrix->r3c1 = c1;
    matrix->r3c2 = c2;
}

// ================ Set Column 1 ================ //

inline void bgc_matrix2x3_set_column1_fp32(const float r1, const float r2, const float r3, BgcMatrix2x3FP32* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
    matrix->r3c1 = r3;
}

inline void bgc_matrix2x3_set_column1_fp64(const double r1, const double r2, const double r3, BgcMatrix2x3FP64* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
    matrix->r3c1 = r3;
}

// ================ Set Column 2 ================ //

inline void bgc_matrix2x3_set_column2_fp32(const float r1, const float r2, const float r3, BgcMatrix2x3FP32* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
    matrix->r3c2 = r3;
}

inline void bgc_matrix2x3_set_column2_fp64(const double r1, const double r2, const double r3, BgcMatrix2x3FP64* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
    matrix->r3c2 = r3;
}

// =============== Get transposed =============== //

inline void bgc_matrix2x3_get_transposed_fp32(const BgcMatrix3x2FP32* matrix, BgcMatrix2x3FP32* transposed)
{
    transposed->r1c1 = matrix->r1c1;
    transposed->r1c2 = matrix->r2c1;

    transposed->r2c1 = matrix->r1c2;
    transposed->r2c2 = matrix->r2c2;

    transposed->r3c1 = matrix->r1c3;
    transposed->r3c2 = matrix->r2c3;
}

inline void bgc_matrix2x3_get_transposed_fp64(const BgcMatrix3x2FP64* matrix, BgcMatrix2x3FP64* transposed)
{
    transposed->r1c1 = matrix->r1c1;
    transposed->r1c2 = matrix->r2c1;

    transposed->r2c1 = matrix->r1c2;
    transposed->r2c2 = matrix->r2c2;

    transposed->r3c1 = matrix->r1c3;
    transposed->r3c2 = matrix->r2c3;
}


// ==================== Add ===================== //

inline void bgc_matrix2x3_add_fp32(const BgcMatrix2x3FP32* matrix1, const BgcMatrix2x3FP32* matrix2, BgcMatrix2x3FP32* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;

    sum->r3c1 = matrix1->r3c1 + matrix2->r3c1;
    sum->r3c2 = matrix1->r3c2 + matrix2->r3c2;
}

inline void bgc_matrix2x3_add_fp64(const BgcMatrix2x3FP64* matrix1, const BgcMatrix2x3FP64* matrix2, BgcMatrix2x3FP64* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;

    sum->r3c1 = matrix1->r3c1 + matrix2->r3c1;
    sum->r3c2 = matrix1->r3c2 + matrix2->r3c2;
}

// ================= Add scaled ================= //

inline void bgc_matrix2x3_add_scaled_fp32(const BgcMatrix2x3FP32* basic_matrix, const BgcMatrix2x3FP32* scalable_matrix, const float scale, BgcMatrix2x3FP32* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;

    sum->r3c1 = basic_matrix->r3c1 + scalable_matrix->r3c1 * scale;
    sum->r3c2 = basic_matrix->r3c2 + scalable_matrix->r3c2 * scale;
}

inline void bgc_matrix2x3_add_scaled_fp64(const BgcMatrix2x3FP64* basic_matrix, const BgcMatrix2x3FP64* scalable_matrix, const double scale, BgcMatrix2x3FP64* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;

    sum->r3c1 = basic_matrix->r3c1 + scalable_matrix->r3c1 * scale;
    sum->r3c2 = basic_matrix->r3c2 + scalable_matrix->r3c2 * scale;
}

// ================== Subtract ================== //

inline void bgc_matrix2x3_subtract_fp32(const BgcMatrix2x3FP32* minuend, const BgcMatrix2x3FP32* subtrahend, BgcMatrix2x3FP32* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;

    difference->r3c1 = minuend->r3c1 - subtrahend->r3c1;
    difference->r3c2 = minuend->r3c2 - subtrahend->r3c2;
}

inline void bgc_matrix2x3_subtract_fp64(const BgcMatrix2x3FP64* minuend, const BgcMatrix2x3FP64* subtrahend, BgcMatrix2x3FP64* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;

    difference->r3c1 = minuend->r3c1 - subtrahend->r3c1;
    difference->r3c2 = minuend->r3c2 - subtrahend->r3c2;
}

// ============== Subtract scaled =============== //

inline void bgc_matrix2x3_subtract_scaled_fp32(const BgcMatrix2x3FP32* basic_matrix, const BgcMatrix2x3FP32* scalable_matrix, const float scale, BgcMatrix2x3FP32* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;

    difference->r3c1 = basic_matrix->r3c1 - scalable_matrix->r3c1 * scale;
    difference->r3c2 = basic_matrix->r3c2 - scalable_matrix->r3c2 * scale;
}

inline void bgc_matrix2x3_subtract_scaled_fp64(const BgcMatrix2x3FP64* basic_matrix, const BgcMatrix2x3FP64* scalable_matrix, const double scale, BgcMatrix2x3FP64* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;

    difference->r3c1 = basic_matrix->r3c1 - scalable_matrix->r3c1 * scale;
    difference->r3c2 = basic_matrix->r3c2 - scalable_matrix->r3c2 * scale;
}

// ================== Multiply ================== //

inline void bgc_matrix2x3_multiply_fp32(const BgcMatrix2x3FP32* multiplicand, const float multiplier, BgcMatrix2x3FP32* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;

    product->r3c1 = multiplicand->r3c1 * multiplier;
    product->r3c2 = multiplicand->r3c2 * multiplier;
}

inline void bgc_matrix2x3_multiply_fp64(const BgcMatrix2x3FP64* multiplicand, const double multiplier, BgcMatrix2x3FP64* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;

    product->r3c1 = multiplicand->r3c1 * multiplier;
    product->r3c2 = multiplicand->r3c2 * multiplier;
}

// =================== Divide =================== //

inline void bgc_matrix2x3_divide_fp32(const BgcMatrix2x3FP32* dividend, const float divisor, BgcMatrix2x3FP32* quotient)
{
    bgc_matrix2x3_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_matrix2x3_divide_fp64(const BgcMatrix2x3FP64* dividend, const double divisor, BgcMatrix2x3FP64* quotient)
{
    bgc_matrix2x3_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ============ Left Vector Product ============= //

inline void bgc_matrix2x3_get_left_product_fp32(const BgcVector3FP32* vector, const BgcMatrix2x3FP32* matrix, BgcVector2FP32* result)
{
    result->x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1 + vector->x3 * matrix->r3c1;
    result->x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2 + vector->x3 * matrix->r3c2;
}

inline void bgc_matrix2x3_get_left_product_fp64(const BgcVector3FP64* vector, const BgcMatrix2x3FP64* matrix, BgcVector2FP64* result)
{
    result->x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1 + vector->x3 * matrix->r3c1;
    result->x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2 + vector->x3 * matrix->r3c2;
}

// ============ Right Vector Product ============ //

inline void bgc_matrix2x3_get_right_product_fp32(const BgcMatrix2x3FP32* matrix, const BgcVector2FP32* vector, BgcVector3FP32* result)
{
    result->x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2;
    result->x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2;
    result->x3 = matrix->r3c1 * vector->x1 + matrix->r3c2 * vector->x2;
}

inline void bgc_matrix2x3_get_right_product_fp64(const BgcMatrix2x3FP64* matrix, const BgcVector2FP64* vector, BgcVector3FP64* result)
{
    result->x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2;
    result->x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2;
    result->x3 = matrix->r3c1 * vector->x1 + matrix->r3c2 * vector->x2;
}

#endif
