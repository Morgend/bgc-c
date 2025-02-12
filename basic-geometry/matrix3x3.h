#ifndef _BGC_MATRIX3X3_H_
#define _BGC_MATRIX3X3_H_

#include "vector3.h"
#include "matrixes.h"

// =================== Reset ==================== //

inline void bgc_matrix3x3_reset_fp32(BgcMatrix3x3FP32* matrix)
{
    matrix->r1c1 = 0.0f;
    matrix->r1c2 = 0.0f;
    matrix->r1c3 = 0.0f;

    matrix->r2c1 = 0.0f;
    matrix->r2c2 = 0.0f;
    matrix->r2c3 = 0.0f;

    matrix->r3c1 = 0.0f;
    matrix->r3c2 = 0.0f;
    matrix->r3c3 = 0.0f;
}

inline void bgc_matrix3x3_reset_fp64(BgcMatrix3x3FP64* matrix)
{
    matrix->r1c1 = 0.0;
    matrix->r1c2 = 0.0;
    matrix->r1c3 = 0.0;

    matrix->r2c1 = 0.0;
    matrix->r2c2 = 0.0;
    matrix->r2c3 = 0.0;

    matrix->r3c1 = 0.0;
    matrix->r3c2 = 0.0;
    matrix->r3c3 = 0.0;
}

// ================== Identity ================== //

inline void bgc_matrix3x3_set_to_identity_fp32(BgcMatrix3x3FP32* matrix)
{
    matrix->r1c1 = 1.0f;
    matrix->r1c2 = 0.0f;
    matrix->r1c3 = 0.0f;

    matrix->r2c1 = 0.0f;
    matrix->r2c2 = 1.0f;
    matrix->r2c3 = 0.0f;

    matrix->r3c1 = 0.0f;
    matrix->r3c2 = 0.0f;
    matrix->r3c3 = 1.0f;
}

inline void bgc_matrix3x3_set_to_identity_fp64(BgcMatrix3x3FP64* matrix)
{
    matrix->r1c1 = 1.0;
    matrix->r1c2 = 0.0;
    matrix->r1c3 = 0.0;

    matrix->r2c1 = 0.0;
    matrix->r2c2 = 1.0;
    matrix->r2c3 = 0.0;

    matrix->r3c1 = 0.0;
    matrix->r3c2 = 0.0;
    matrix->r3c3 = 1.0;
}

// ================ Make Diagonal =============== //

inline void bgc_matrix3x3_set_to_diagonal_fp32(const float d1, const float d2, const float d3, BgcMatrix3x3FP32* matrix)
{
    matrix->r1c1 = d1;
    matrix->r1c2 = 0.0f;
    matrix->r1c3 = 0.0f;

    matrix->r2c1 = 0.0f;
    matrix->r2c2 = d2;
    matrix->r2c3 = 0.0f;

    matrix->r3c1 = 0.0f;
    matrix->r3c2 = 0.0f;
    matrix->r3c3 = d2;
}

inline void bgc_matrix3x3_set_to_diagonal_fp64(const double d1, const double d2, const double d3, BgcMatrix3x3FP64* matrix)
{
    matrix->r1c1 = d1;
    matrix->r1c2 = 0.0;
    matrix->r1c3 = 0.0;

    matrix->r2c1 = 0.0;
    matrix->r2c2 = d2;
    matrix->r2c3 = 0.0;

    matrix->r3c1 = 0.0;
    matrix->r3c2 = 0.0;
    matrix->r3c3 = d2;
}

// ==================== Copy ==================== //

inline void bgc_matrix3x3_copy_fp32(const BgcMatrix3x3FP32* from, BgcMatrix3x3FP32* to)
{
    to->r1c1 = from->r1c1;
    to->r1c2 = from->r1c2;
    to->r1c3 = from->r1c3;

    to->r2c1 = from->r2c1;
    to->r2c2 = from->r2c2;
    to->r2c3 = from->r2c3;

    to->r3c1 = from->r3c1;
    to->r3c2 = from->r3c2;
    to->r3c3 = from->r3c3;
}

inline void bgc_matrix3x3_copy_fp64(const BgcMatrix3x3FP64* from, BgcMatrix3x3FP64* to)
{
    to->r1c1 = from->r1c1;
    to->r1c2 = from->r1c2;
    to->r1c3 = from->r1c3;

    to->r2c1 = from->r2c1;
    to->r2c2 = from->r2c2;
    to->r2c3 = from->r2c3;

    to->r3c1 = from->r3c1;
    to->r3c2 = from->r3c2;
    to->r3c3 = from->r3c3;
}

// ==================== Swap ==================== //

inline void bgc_matrix3x3_swap_fp32(BgcMatrix3x3FP32* matrix1, BgcMatrix3x3FP32* matrix2)
{
    const float r1c1 = matrix2->r1c1;
    const float r1c2 = matrix2->r1c2;
    const float r1c3 = matrix2->r1c3;

    const float r2c1 = matrix2->r2c1;
    const float r2c2 = matrix2->r2c2;
    const float r2c3 = matrix2->r2c3;

    const float r3c1 = matrix2->r3c1;
    const float r3c2 = matrix2->r3c2;
    const float r3c3 = matrix2->r3c3;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;
    matrix2->r1c3 = matrix1->r1c3;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;
    matrix2->r2c3 = matrix1->r2c3;

    matrix2->r3c1 = matrix1->r3c1;
    matrix2->r3c2 = matrix1->r3c2;
    matrix2->r3c3 = matrix1->r3c3;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;
    matrix1->r1c3 = r1c3;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;
    matrix1->r2c3 = r2c3;

    matrix1->r3c1 = r3c1;
    matrix1->r3c2 = r3c2;
    matrix1->r3c3 = r3c3;
}

inline void bgc_matrix3x3_swap_fp64(BgcMatrix3x3FP64* matrix1, BgcMatrix3x3FP64* matrix2)
{
    const double r1c1 = matrix2->r1c1;
    const double r1c2 = matrix2->r1c2;
    const double r1c3 = matrix2->r1c3;

    const double r2c1 = matrix2->r2c1;
    const double r2c2 = matrix2->r2c2;
    const double r2c3 = matrix2->r2c3;

    const double r3c1 = matrix2->r3c1;
    const double r3c2 = matrix2->r3c2;
    const double r3c3 = matrix2->r3c3;

    matrix2->r1c1 = matrix1->r1c1;
    matrix2->r1c2 = matrix1->r1c2;
    matrix2->r1c3 = matrix1->r1c3;

    matrix2->r2c1 = matrix1->r2c1;
    matrix2->r2c2 = matrix1->r2c2;
    matrix2->r2c3 = matrix1->r2c3;

    matrix2->r3c1 = matrix1->r3c1;
    matrix2->r3c2 = matrix1->r3c2;
    matrix2->r3c3 = matrix1->r3c3;

    matrix1->r1c1 = r1c1;
    matrix1->r1c2 = r1c2;
    matrix1->r1c3 = r1c3;

    matrix1->r2c1 = r2c1;
    matrix1->r2c2 = r2c2;
    matrix1->r2c3 = r2c3;

    matrix1->r3c1 = r3c1;
    matrix1->r3c2 = r3c2;
    matrix1->r3c3 = r3c3;
}

// ================== Convert =================== //

inline void bgc_matrix3x3_convert_fp64_to_fp32(const BgcMatrix3x3FP64* from, BgcMatrix3x3FP32* to)
{
    to->r1c1 = (float) from->r1c1;
    to->r1c2 = (float) from->r1c2;
    to->r1c3 = (float) from->r1c3;

    to->r2c1 = (float) from->r2c1;
    to->r2c2 = (float) from->r2c2;
    to->r2c3 = (float) from->r2c3;

    to->r3c1 = (float) from->r3c1;
    to->r3c2 = (float) from->r3c2;
    to->r3c3 = (float) from->r3c3;
}

inline void bgc_matrix3x3_convert_fp32_to_fp64(const BgcMatrix3x3FP32* from, BgcMatrix3x3FP64* to)
{
    to->r1c1 = from->r1c1;
    to->r1c2 = from->r1c2;
    to->r1c3 = from->r1c3;

    to->r2c1 = from->r2c1;
    to->r2c2 = from->r2c2;
    to->r2c3 = from->r2c3;

    to->r3c1 = from->r3c1;
    to->r3c2 = from->r3c2;
    to->r3c3 = from->r3c3;
}

// ================ Determinant ================= //

inline float bgc_matrix3x3_get_determinant_fp32(const BgcMatrix3x3FP32* matrix)
{
    return matrix->r1c1 * (matrix->r2c2 * matrix->r3c3 - matrix->r2c3 * matrix->r3c2)
         + matrix->r1c2 * (matrix->r2c3 * matrix->r3c1 - matrix->r2c1 * matrix->r3c3)
         + matrix->r1c3 * (matrix->r2c1 * matrix->r3c2 - matrix->r2c2 * matrix->r3c1);
}

inline double bgc_matrix3x3_get_determinant_fp64(const BgcMatrix3x3FP64* matrix)
{
    return matrix->r1c1 * (matrix->r2c2 * matrix->r3c3 - matrix->r2c3 * matrix->r3c2)
         + matrix->r1c2 * (matrix->r2c3 * matrix->r3c1 - matrix->r2c1 * matrix->r3c3)
         + matrix->r1c3 * (matrix->r2c1 * matrix->r3c2 - matrix->r2c2 * matrix->r3c1);
}

// ================== Singular ================== //

inline int bgc_matrix3x3_is_singular_fp32(const BgcMatrix3x3FP32* matrix)
{
    return bgc_is_zero_fp32(bgc_matrix3x3_get_determinant_fp32(matrix));
}

inline int bgc_matrix3x3_is_singular_fp64(const BgcMatrix3x3FP64* matrix)
{
    return bgc_is_zero_fp64(bgc_matrix3x3_get_determinant_fp64(matrix));
}

// =================== Invert =================== //

int bgc_matrix3x3_invert_fp32(BgcMatrix3x3FP32* matrix);

int bgc_matrix3x3_invert_fp64(BgcMatrix3x3FP64* matrix);

// ================= Transpose ================== //

inline void bgc_matrix3x3_transpose_fp32(BgcMatrix3x3FP32* matrix)
{
    float tmp = matrix->r1c2;
    matrix->r1c2 = matrix->r2c1;
    matrix->r2c1 = tmp;

    tmp = matrix->r1c3;
    matrix->r1c3 = matrix->r3c1;
    matrix->r3c1 = tmp;

    tmp = matrix->r2c3;
    matrix->r2c3 = matrix->r3c2;
    matrix->r3c2 = tmp;
}

inline void bgc_matrix3x3_transpose_fp64(BgcMatrix3x3FP64* matrix)
{
    double tmp = matrix->r1c2;
    matrix->r1c2 = matrix->r2c1;
    matrix->r2c1 = tmp;

    tmp = matrix->r1c3;
    matrix->r1c3 = matrix->r3c1;
    matrix->r3c1 = tmp;

    tmp = matrix->r2c3;
    matrix->r2c3 = matrix->r3c2;
    matrix->r3c2 = tmp;
}

// ================= Set Row 1 ================== //

inline void bgc_matrix3x3_set_row1_fp32(const float c1, const float c2, const float c3, BgcMatrix3x3FP32* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
    matrix->r1c3 = c3;
}

inline void bgc_matrix3x3_set_row1_fp64(const double c1, const double c2, const double c3, BgcMatrix3x3FP64* matrix)
{
    matrix->r1c1 = c1;
    matrix->r1c2 = c2;
    matrix->r1c3 = c3;
}

// ================= Set Row 2 ================== //

inline void bgc_matrix3x3_set_row2_fp32(const float c1, const float c2, const float c3, BgcMatrix3x3FP32* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
    matrix->r2c3 = c3;
}

inline void bgc_matrix3x3_set_row2_fp64(const double c1, const double c2, const double c3, BgcMatrix3x3FP64* matrix)
{
    matrix->r2c1 = c1;
    matrix->r2c2 = c2;
    matrix->r2c3 = c3;
}

// ================= Set Row 3 ================== //

inline void bgc_matrix3x3_set_row3_fp32(const float c1, const float c2, const float c3, BgcMatrix3x3FP32* matrix)
{
    matrix->r3c1 = c1;
    matrix->r3c2 = c2;
    matrix->r3c3 = c3;
}

inline void bgc_matrix3x3_set_row3_fp64(const double c1, const double c2, const double c3, BgcMatrix3x3FP64* matrix)
{
    matrix->r3c1 = c1;
    matrix->r3c2 = c2;
    matrix->r3c3 = c3;
}

// ================ Set Column 1 ================ //

inline void bgc_matrix3x3_set_column1_fp32(const float r1, const float r2, const float r3, BgcMatrix3x3FP32* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
    matrix->r3c1 = r3;
}

inline void bgc_matrix3x3_set_column1_fp64(const double r1, const double r2, const double r3, BgcMatrix3x3FP64* matrix)
{
    matrix->r1c1 = r1;
    matrix->r2c1 = r2;
    matrix->r3c1 = r3;
}

// ================ Set Column 2 ================ //

inline void bgc_matrix3x3_set_column2_fp32(const float r1, const float r2, const float r3, BgcMatrix3x3FP32* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
    matrix->r3c2 = r3;
}

inline void bgc_matrix3x3_set_column2_fp64(const double r1, const double r2, const double r3, BgcMatrix3x3FP64* matrix)
{
    matrix->r1c2 = r1;
    matrix->r2c2 = r2;
    matrix->r3c2 = r3;
}

// ================ Set Column 3 ================ //

inline void bgc_matrix3x3_set_column3_fp32(const float r1, const float r2, const float r3, BgcMatrix3x3FP32* matrix)
{
    matrix->r1c3 = r1;
    matrix->r2c3 = r2;
    matrix->r3c3 = r3;
}

inline void bgc_matrix3x3_set_column3_fp64(const double r1, const double r2, const double r3, BgcMatrix3x3FP64* matrix)
{
    matrix->r1c3 = r1;
    matrix->r2c3 = r2;
    matrix->r3c3 = r3;
}

// ================ Make Inverted =============== //

int bgc_matrix3x3_make_inverted_fp32(const BgcMatrix3x3FP32* matrix, BgcMatrix3x3FP32* result);

int bgc_matrix3x3_make_inverted_fp64(const BgcMatrix3x3FP64* matrix, BgcMatrix3x3FP64* result);

// =============== Make Transposed ============== //

inline void bgc_matrix3x3_make_transposed_fp32(const BgcMatrix3x3FP32* matrix, BgcMatrix3x3FP32* result)
{
    if (matrix == result) {
        bgc_matrix3x3_transpose_fp32(result);
        return;
    }

    result->r1c1 = matrix->r1c1;
    result->r1c2 = matrix->r2c1;
    result->r1c3 = matrix->r3c1;

    result->r2c1 = matrix->r1c2;
    result->r2c2 = matrix->r2c2;
    result->r2c3 = matrix->r3c2;

    result->r3c1 = matrix->r1c3;
    result->r3c2 = matrix->r2c3;
    result->r3c3 = matrix->r3c3;
}

inline void bgc_matrix3x3_make_transposed_fp64(const BgcMatrix3x3FP64* matrix, BgcMatrix3x3FP64* result)
{
    if (matrix == result) {
        bgc_matrix3x3_transpose_fp64(result);
        return;
    }

    result->r1c1 = matrix->r1c1;
    result->r1c2 = matrix->r2c1;
    result->r1c3 = matrix->r3c1;

    result->r2c1 = matrix->r1c2;
    result->r2c2 = matrix->r2c2;
    result->r2c3 = matrix->r3c2;

    result->r3c1 = matrix->r1c3;
    result->r3c2 = matrix->r2c3;
    result->r3c3 = matrix->r3c3;
}

// ==================== Add ===================== //

inline void bgc_matrix3x3_add_fp32(const BgcMatrix3x3FP32* matrix1, const BgcMatrix3x3FP32* matrix2, BgcMatrix3x3FP32* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;
    sum->r1c3 = matrix1->r1c3 + matrix2->r1c3;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;
    sum->r2c3 = matrix1->r2c3 + matrix2->r2c3;

    sum->r3c1 = matrix1->r3c1 + matrix2->r3c1;
    sum->r3c2 = matrix1->r3c2 + matrix2->r3c2;
    sum->r3c3 = matrix1->r3c3 + matrix2->r3c3;
}

inline void bgc_matrix3x3_add_fp64(const BgcMatrix3x3FP64* matrix1, const BgcMatrix3x3FP64* matrix2, BgcMatrix3x3FP64* sum)
{
    sum->r1c1 = matrix1->r1c1 + matrix2->r1c1;
    sum->r1c2 = matrix1->r1c2 + matrix2->r1c2;
    sum->r1c3 = matrix1->r1c3 + matrix2->r1c3;

    sum->r2c1 = matrix1->r2c1 + matrix2->r2c1;
    sum->r2c2 = matrix1->r2c2 + matrix2->r2c2;
    sum->r2c3 = matrix1->r2c3 + matrix2->r2c3;

    sum->r3c1 = matrix1->r3c1 + matrix2->r3c1;
    sum->r3c2 = matrix1->r3c2 + matrix2->r3c2;
    sum->r3c3 = matrix1->r3c3 + matrix2->r3c3;
}

// ================= Add scaled ================= //

inline void bgc_matrix3x3_add_scaled_fp32(const BgcMatrix3x3FP32* basic_matrix, const BgcMatrix3x3FP32* scalable_matrix, const float scale, BgcMatrix3x3FP32* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;
    sum->r1c3 = basic_matrix->r1c3 + scalable_matrix->r1c3 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;
    sum->r2c3 = basic_matrix->r2c3 + scalable_matrix->r2c3 * scale;

    sum->r3c1 = basic_matrix->r3c1 + scalable_matrix->r3c1 * scale;
    sum->r3c2 = basic_matrix->r3c2 + scalable_matrix->r3c2 * scale;
    sum->r3c3 = basic_matrix->r3c3 + scalable_matrix->r3c3 * scale;
}

inline void bgc_matrix3x3_add_scaled_fp64(const BgcMatrix3x3FP64* basic_matrix, const BgcMatrix3x3FP64* scalable_matrix, const double scale, BgcMatrix3x3FP64* sum)
{
    sum->r1c1 = basic_matrix->r1c1 + scalable_matrix->r1c1 * scale;
    sum->r1c2 = basic_matrix->r1c2 + scalable_matrix->r1c2 * scale;
    sum->r1c3 = basic_matrix->r1c3 + scalable_matrix->r1c3 * scale;

    sum->r2c1 = basic_matrix->r2c1 + scalable_matrix->r2c1 * scale;
    sum->r2c2 = basic_matrix->r2c2 + scalable_matrix->r2c2 * scale;
    sum->r2c3 = basic_matrix->r2c3 + scalable_matrix->r2c3 * scale;

    sum->r3c1 = basic_matrix->r3c1 + scalable_matrix->r3c1 * scale;
    sum->r3c2 = basic_matrix->r3c2 + scalable_matrix->r3c2 * scale;
    sum->r3c3 = basic_matrix->r3c3 + scalable_matrix->r3c3 * scale;
}

// ================== Subtract ================== //

inline void bgc_matrix3x3_subtract_fp32(const BgcMatrix3x3FP32* minuend, const BgcMatrix3x3FP32* subtrahend, BgcMatrix3x3FP32* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;
    difference->r1c3 = minuend->r1c3 - subtrahend->r1c3;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;
    difference->r2c3 = minuend->r2c3 - subtrahend->r2c3;

    difference->r3c1 = minuend->r3c1 - subtrahend->r3c1;
    difference->r3c2 = minuend->r3c2 - subtrahend->r3c2;
    difference->r3c3 = minuend->r3c3 - subtrahend->r3c3;
}

inline void bgc_matrix3x3_subtract_fp64(const BgcMatrix3x3FP64* minuend, const BgcMatrix3x3FP64* subtrahend, BgcMatrix3x3FP64* difference)
{
    difference->r1c1 = minuend->r1c1 - subtrahend->r1c1;
    difference->r1c2 = minuend->r1c2 - subtrahend->r1c2;
    difference->r1c3 = minuend->r1c3 - subtrahend->r1c3;

    difference->r2c1 = minuend->r2c1 - subtrahend->r2c1;
    difference->r2c2 = minuend->r2c2 - subtrahend->r2c2;
    difference->r2c3 = minuend->r2c3 - subtrahend->r2c3;

    difference->r3c1 = minuend->r3c1 - subtrahend->r3c1;
    difference->r3c2 = minuend->r3c2 - subtrahend->r3c2;
    difference->r3c3 = minuend->r3c3 - subtrahend->r3c3;
}

// ================= Add scaled ================= //

inline void bgc_matrix3x3_subtract_scaled_fp32(const BgcMatrix3x3FP32* basic_matrix, const BgcMatrix3x3FP32* scalable_matrix, const float scale, BgcMatrix3x3FP32* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;
    difference->r1c3 = basic_matrix->r1c3 - scalable_matrix->r1c3 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;
    difference->r2c3 = basic_matrix->r2c3 - scalable_matrix->r2c3 * scale;

    difference->r3c1 = basic_matrix->r3c1 - scalable_matrix->r3c1 * scale;
    difference->r3c2 = basic_matrix->r3c2 - scalable_matrix->r3c2 * scale;
    difference->r3c3 = basic_matrix->r3c3 - scalable_matrix->r3c3 * scale;
}

inline void bgc_matrix3x3_subtract_scaled_fp64(const BgcMatrix3x3FP64* basic_matrix, const BgcMatrix3x3FP64* scalable_matrix, const double scale, BgcMatrix3x3FP64* difference)
{
    difference->r1c1 = basic_matrix->r1c1 - scalable_matrix->r1c1 * scale;
    difference->r1c2 = basic_matrix->r1c2 - scalable_matrix->r1c2 * scale;
    difference->r1c3 = basic_matrix->r1c3 - scalable_matrix->r1c3 * scale;

    difference->r2c1 = basic_matrix->r2c1 - scalable_matrix->r2c1 * scale;
    difference->r2c2 = basic_matrix->r2c2 - scalable_matrix->r2c2 * scale;
    difference->r2c3 = basic_matrix->r2c3 - scalable_matrix->r2c3 * scale;

    difference->r3c1 = basic_matrix->r3c1 - scalable_matrix->r3c1 * scale;
    difference->r3c2 = basic_matrix->r3c2 - scalable_matrix->r3c2 * scale;
    difference->r3c3 = basic_matrix->r3c3 - scalable_matrix->r3c3 * scale;
}

// ================== Multiply ================== //

inline void bgc_matrix3x3_multiply_fp32(const BgcMatrix3x3FP32* multiplicand, const float multiplier, BgcMatrix3x3FP32* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;
    product->r1c3 = multiplicand->r1c3 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;
    product->r2c3 = multiplicand->r2c3 * multiplier;

    product->r3c1 = multiplicand->r3c1 * multiplier;
    product->r3c2 = multiplicand->r3c2 * multiplier;
    product->r3c3 = multiplicand->r3c3 * multiplier;
}

inline void bgc_matrix3x3_multiply_fp64(const BgcMatrix3x3FP64* multiplicand, const double multiplier, BgcMatrix3x3FP64* product)
{
    product->r1c1 = multiplicand->r1c1 * multiplier;
    product->r1c2 = multiplicand->r1c2 * multiplier;
    product->r1c3 = multiplicand->r1c3 * multiplier;

    product->r2c1 = multiplicand->r2c1 * multiplier;
    product->r2c2 = multiplicand->r2c2 * multiplier;
    product->r2c3 = multiplicand->r2c3 * multiplier;

    product->r3c1 = multiplicand->r3c1 * multiplier;
    product->r3c2 = multiplicand->r3c2 * multiplier;
    product->r3c3 = multiplicand->r3c3 * multiplier;
}

// =================== Divide =================== //

inline void bgc_matrix3x3_divide_fp32(const BgcMatrix3x3FP32* dividend, const float divisor, BgcMatrix3x3FP32* quotient)
{
    bgc_matrix3x3_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_matrix3x3_divide_fp64(const BgcMatrix3x3FP64* dividend, const double divisor, BgcMatrix3x3FP64* quotient)
{
    bgc_matrix3x3_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ============ Left Vector Product ============= //

inline void bgc_matrix3x3_left_product_fp32(const BgcVector3FP32* vector, const BgcMatrix3x3FP32* matrix, BgcVector3FP32* result)
{
    const float x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1 + vector->x3 * matrix->r3c1;
    const float x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2 + vector->x3 * matrix->r3c2;
    const float x3 = vector->x1 * matrix->r1c3 + vector->x2 * matrix->r2c3 + vector->x3 * matrix->r3c3;

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

inline void bgc_matrix3x3_left_product_fp64(const BgcVector3FP64* vector, const BgcMatrix3x3FP64* matrix, BgcVector3FP64* result)
{
    const double x1 = vector->x1 * matrix->r1c1 + vector->x2 * matrix->r2c1 + vector->x3 * matrix->r3c1;
    const double x2 = vector->x1 * matrix->r1c2 + vector->x2 * matrix->r2c2 + vector->x3 * matrix->r3c2;
    const double x3 = vector->x1 * matrix->r1c3 + vector->x2 * matrix->r2c3 + vector->x3 * matrix->r3c3;

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

// ============ Right Vector Product ============ //

inline void bgc_matrix3x3_right_product_fp32(const BgcMatrix3x3FP32* matrix, const BgcVector3FP32* vector, BgcVector3FP32* result)
{
    const float x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2 + matrix->r1c3 * vector->x3;
    const float x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2 + matrix->r2c3 * vector->x3;
    const float x3 = matrix->r3c1 * vector->x1 + matrix->r3c2 * vector->x2 + matrix->r3c3 * vector->x3;

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

inline void bgc_matrix3x3_right_product_fp64(const BgcMatrix3x3FP64* matrix, const BgcVector3FP64* vector, BgcVector3FP64* result)
{
    const double x1 = matrix->r1c1 * vector->x1 + matrix->r1c2 * vector->x2 + matrix->r1c3 * vector->x3;
    const double x2 = matrix->r2c1 * vector->x1 + matrix->r2c2 * vector->x2 + matrix->r2c3 * vector->x3;
    const double x3 = matrix->r3c1 * vector->x1 + matrix->r3c2 * vector->x2 + matrix->r3c3 * vector->x3;

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

#endif
