#include "matrixes.h"

extern inline void bgc_matrix_product_2x2_at_2x2_fp32(const BgcMatrix2x2FP32* matrix1, const BgcMatrix2x2FP32* matrix2, BgcMatrix2x2FP32* result);
extern inline void bgc_matrix_product_2x2_at_2x2_fp64(const BgcMatrix2x2FP64* matrix1, const BgcMatrix2x2FP64* matrix2, BgcMatrix2x2FP64* result);

// ========== Matrix Product 2x2 at 3x2 ========= //

void bgc_matrix_product_2x2_at_3x2_fp32(const BgcMatrix2x2FP32* matrix1, const BgcMatrix3x2FP32* matrix2, BgcMatrix3x2FP32* result)
{
    const float r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    const float r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;
    const float r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3;

    const float r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    const float r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;
    const float r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;
    result->r1c3 = r1c3;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
    result->r2c3 = r2c3;
}

void bgc_matrix_product_2x2_at_3x2_fp64(const BgcMatrix2x2FP64* matrix1, const BgcMatrix3x2FP64* matrix2, BgcMatrix3x2FP64* result)
{
    const double r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    const double r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;
    const double r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3;

    const double r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    const double r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;
    const double r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;
    result->r1c3 = r1c3;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
    result->r2c3 = r2c3;
}

// ========== Matrix Product 2x3 at 2x2 ========= //

void bgc_matrix_product_2x3_at_2x2_fp32(const BgcMatrix2x3FP32* matrix1, const BgcMatrix2x2FP32* matrix2, BgcMatrix2x3FP32* result)
{
    const float r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    const float r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;

    const float r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    const float r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;

    const float r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1;
    const float r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;

    result->r3c1 = r3c1;
    result->r3c2 = r3c2;
}

void bgc_matrix_product_2x3_at_2x2_fp64(const BgcMatrix2x3FP64* matrix1, const BgcMatrix2x2FP64* matrix2, BgcMatrix2x3FP64* result)
{
    const double r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    const double r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;

    const double r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    const double r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;

    const double r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1;
    const double r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;

    result->r3c1 = r3c1;
    result->r3c2 = r3c2;
}

// ========== Matrix Product 2x3 at 3x2 ========= //

void bgc_matrix_product_2x3_at_3x2_fp32(const BgcMatrix2x3FP32* matrix1, const BgcMatrix3x2FP32* matrix2, BgcMatrix3x3FP32* result)
{
    result->r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    result->r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;
    result->r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3;

    result->r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    result->r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;
    result->r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3;

    result->r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1;
    result->r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2;
    result->r3c3 = matrix1->r3c1 * matrix2->r1c3 + matrix1->r3c2 * matrix2->r2c3;
}

void bgc_matrix_product_2x3_at_3x2_fp64(const BgcMatrix2x3FP64* matrix1, const BgcMatrix3x2FP64* matrix2, BgcMatrix3x3FP64* result)
{
    result->r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    result->r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;
    result->r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3;

    result->r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    result->r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;
    result->r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3;

    result->r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1;
    result->r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2;
    result->r3c3 = matrix1->r3c1 * matrix2->r1c3 + matrix1->r3c2 * matrix2->r2c3;
}

// ========== Matrix Product 3x2 at 2x3 ========= //

void bgc_matrix_product_3x2_at_2x3_fp32(const BgcMatrix3x2FP32* matrix1, const BgcMatrix2x3FP32* matrix2, BgcMatrix2x2FP32* result)
{
    result->r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    result->r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;

    result->r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    result->r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;
}

void bgc_matrix_product_3x2_at_2x3_fp64(const BgcMatrix3x2FP64* matrix1, const BgcMatrix2x3FP64* matrix2, BgcMatrix2x2FP64* result)
{
    result->r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    result->r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;

    result->r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    result->r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;
}

// ========== Matrix Product 3x2 at 3x3 ========= //

void bgc_matrix_product_3x2_at_3x3_fp32(const BgcMatrix3x2FP32* matrix1, const BgcMatrix3x3FP32* matrix2, BgcMatrix3x2FP32* result)
{
    const float r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    const float r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;
    const float r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3 + matrix1->r1c3 * matrix2->r3c3;

    const float r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    const float r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;
    const float r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3 + matrix1->r2c3 * matrix2->r3c3;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;
    result->r1c3 = r1c3;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
    result->r2c3 = r2c3;
}

void bgc_matrix_product_3x2_at_3x3_fp64(const BgcMatrix3x2FP64* matrix1, const BgcMatrix3x3FP64* matrix2, BgcMatrix3x2FP64* result)
{
    const double r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    const double r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;
    const double r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3 + matrix1->r1c3 * matrix2->r3c3;

    const double r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    const double r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;
    const double r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3 + matrix1->r2c3 * matrix2->r3c3;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;
    result->r1c3 = r1c3;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
    result->r2c3 = r2c3;
}

// ========== Matrix Product 3x3 at 2x3 ========= //

void bgc_matrix_product_3x3_at_2x3_fp32(const BgcMatrix3x3FP32* matrix1, const BgcMatrix2x3FP32* matrix2, BgcMatrix2x3FP32* result)
{
    const float r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    const float r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;

    const float r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    const float r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;

    const float r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1 + matrix1->r3c3 * matrix2->r3c1;
    const float r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2 + matrix1->r3c3 * matrix2->r3c2;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;

    result->r3c1 = r3c1;
    result->r3c2 = r3c2;
}

void bgc_matrix_product_3x3_at_2x3_fp64(const BgcMatrix3x3FP64* matrix1, const BgcMatrix2x3FP64* matrix2, BgcMatrix2x3FP64* result)
{
    const double r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    const double r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;

    const double r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    const double r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;

    const double r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1 + matrix1->r3c3 * matrix2->r3c1;
    const double r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2 + matrix1->r3c3 * matrix2->r3c2;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;

    result->r3c1 = r3c1;
    result->r3c2 = r3c2;
}

// ========== Matrix Product 3x3 at 3x3 ========= //

void bgc_matrix_product_3x3_at_3x3_fp32(const BgcMatrix3x3FP32* matrix1, const BgcMatrix3x3FP32* matrix2, BgcMatrix3x3FP32* result)
{
    const float r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    const float r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;
    const float r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3 + matrix1->r1c3 * matrix2->r3c3;

    const float r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    const float r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;
    const float r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3 + matrix1->r2c3 * matrix2->r3c3;

    const float r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1 + matrix1->r3c3 * matrix2->r3c1;
    const float r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2 + matrix1->r3c3 * matrix2->r3c2;
    const float r3c3 = matrix1->r3c1 * matrix2->r1c3 + matrix1->r3c2 * matrix2->r2c3 + matrix1->r3c3 * matrix2->r3c3;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;
    result->r1c3 = r1c3;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
    result->r2c3 = r2c3;

    result->r3c1 = r3c1;
    result->r3c2 = r3c2;
    result->r3c3 = r3c3;
}

void bgc_matrix_product_3x3_at_3x3_fp64(const BgcMatrix3x3FP64* matrix1, const BgcMatrix3x3FP64* matrix2, BgcMatrix3x3FP64* result)
{
    const double r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1 + matrix1->r1c3 * matrix2->r3c1;
    const double r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2 + matrix1->r1c3 * matrix2->r3c2;
    const double r1c3 = matrix1->r1c1 * matrix2->r1c3 + matrix1->r1c2 * matrix2->r2c3 + matrix1->r1c3 * matrix2->r3c3;

    const double r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1 + matrix1->r2c3 * matrix2->r3c1;
    const double r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2 + matrix1->r2c3 * matrix2->r3c2;
    const double r2c3 = matrix1->r2c1 * matrix2->r1c3 + matrix1->r2c2 * matrix2->r2c3 + matrix1->r2c3 * matrix2->r3c3;

    const double r3c1 = matrix1->r3c1 * matrix2->r1c1 + matrix1->r3c2 * matrix2->r2c1 + matrix1->r3c3 * matrix2->r3c1;
    const double r3c2 = matrix1->r3c1 * matrix2->r1c2 + matrix1->r3c2 * matrix2->r2c2 + matrix1->r3c3 * matrix2->r3c2;
    const double r3c3 = matrix1->r3c1 * matrix2->r1c3 + matrix1->r3c2 * matrix2->r2c3 + matrix1->r3c3 * matrix2->r3c3;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;
    result->r1c3 = r1c3;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
    result->r2c3 = r2c3;

    result->r3c1 = r3c1;
    result->r3c2 = r3c2;
    result->r3c3 = r3c3;
}
