#ifndef _BGC_MATRIX_TYPES_H_
#define _BGC_MATRIX_TYPES_H_

// ================== Matrix2x2 ================= //

typedef struct {
    float r1c1, r1c2;
    float r2c1, r2c2;
} BgcMatrix2x2FP32;

typedef struct {
    double r1c1, r1c2;
    double r2c1, r2c2;
} BgcMatrix2x2FP64;

// ================== Matrix2x3 ================= //

typedef struct {
    float r1c1, r1c2;
    float r2c1, r2c2;
    float r3c1, r3c2;
} BgcMatrix2x3FP32;

typedef struct {
    double r1c1, r1c2;
    double r2c1, r2c2;
    double r3c1, r3c2;
} BgcMatrix2x3FP64;

// ================== Matrix3x2 ================= //

typedef struct {
    float r1c1, r1c2, r1c3;
    float r2c1, r2c2, r2c3;
} BgcMatrix3x2FP32;

typedef struct {
    double r1c1, r1c2, r1c3;
    double r2c1, r2c2, r2c3;
} BgcMatrix3x2FP64;

// ================== Matrix3x3 ================= //

typedef struct {
    float r1c1, r1c2, r1c3;
    float r2c1, r2c2, r2c3;
    float r3c1, r3c2, r3c3;
} BgcMatrix3x3FP32;

typedef struct {
    double r1c1, r1c2, r1c3;
    double r2c1, r2c2, r2c3;
    double r3c1, r3c2, r3c3;
} BgcMatrix3x3FP64;

// ========== Matrix Product 2x2 at 2x2 ========= //

inline void bgc_matrix_product_2x2_at_2x2_fp32(const BgcMatrix2x2FP32* matrix1, const BgcMatrix2x2FP32* matrix2, BgcMatrix2x2FP32* result)
{
    const float r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    const float r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;

    const float r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    const float r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
}

inline void bgc_matrix_product_2x2_at_2x2_fp64(const BgcMatrix2x2FP64* matrix1, const BgcMatrix2x2FP64* matrix2, BgcMatrix2x2FP64* result)
{
    const double r1c1 = matrix1->r1c1 * matrix2->r1c1 + matrix1->r1c2 * matrix2->r2c1;
    const double r1c2 = matrix1->r1c1 * matrix2->r1c2 + matrix1->r1c2 * matrix2->r2c2;

    const double r2c1 = matrix1->r2c1 * matrix2->r1c1 + matrix1->r2c2 * matrix2->r2c1;
    const double r2c2 = matrix1->r2c1 * matrix2->r1c2 + matrix1->r2c2 * matrix2->r2c2;

    result->r1c1 = r1c1;
    result->r1c2 = r1c2;

    result->r2c1 = r2c1;
    result->r2c2 = r2c2;
}

// ========== Matrix Product 2x2 at 3x2 ========= //

void bgc_matrix_product_2x2_at_3x2_fp32(const BgcMatrix2x2FP32* matrix1, const BgcMatrix3x2FP32* matrix2, BgcMatrix3x2FP32* result);

void bgc_matrix_product_2x2_at_3x2_fp64(const BgcMatrix2x2FP64* matrix1, const BgcMatrix3x2FP64* matrix2, BgcMatrix3x2FP64* result);

// ========== Matrix Product 2x3 at 2x2 ========= //

void bgc_matrix_product_2x3_at_2x2_fp32(const BgcMatrix2x3FP32* matrix1, const BgcMatrix2x2FP32* matrix2, BgcMatrix2x3FP32* result);

void bgc_matrix_product_2x3_at_2x2_fp64(const BgcMatrix2x3FP64* matrix1, const BgcMatrix2x2FP64* matrix2, BgcMatrix2x3FP64* result);

// ========== Matrix Product 2x3 at 3x2 ========= //

void bgc_matrix_product_2x3_at_3x2_fp32(const BgcMatrix2x3FP32* matrix1, const BgcMatrix3x2FP32* matrix2, BgcMatrix3x3FP32* result);

void bgc_matrix_product_2x3_at_3x2_fp64(const BgcMatrix2x3FP64* matrix1, const BgcMatrix3x2FP64* matrix2, BgcMatrix3x3FP64* result);

// ========== Matrix Product 3x2 at 2x3 ========= //

void bgc_matrix_product_3x2_at_2x3_fp32(const BgcMatrix3x2FP32* matrix1, const BgcMatrix2x3FP32* matrix2, BgcMatrix2x2FP32* result);

void bgc_matrix_product_3x2_at_2x3_fp64(const BgcMatrix3x2FP64* matrix1, const BgcMatrix2x3FP64* matrix2, BgcMatrix2x2FP64* result);

// ========== Matrix Product 3x2 at 3x3 ========= //

void bgc_matrix_product_3x2_at_3x3_fp32(const BgcMatrix3x2FP32* matrix1, const BgcMatrix3x3FP32* matrix2, BgcMatrix3x2FP32* result);

void bgc_matrix_product_3x2_at_3x3_fp64(const BgcMatrix3x2FP64* matrix1, const BgcMatrix3x3FP64* matrix2, BgcMatrix3x2FP64* result);

// ========== Matrix Product 3x3 at 2x3 ========= //

void bgc_matrix_product_3x3_at_2x3_fp32(const BgcMatrix3x3FP32* matrix1, const BgcMatrix2x3FP32* matrix2, BgcMatrix2x3FP32* result);

void bgc_matrix_product_3x3_at_2x3_fp64(const BgcMatrix3x3FP64* matrix1, const BgcMatrix2x3FP64* matrix2, BgcMatrix2x3FP64* result);

// ========== Matrix Product 3x3 at 3x3 ========= //

void bgc_matrix_product_3x3_at_3x3_fp32(const BgcMatrix3x3FP32* matrix1, const BgcMatrix3x3FP32* matrix2, BgcMatrix3x3FP32* result);

void bgc_matrix_product_3x3_at_3x3_fp64(const BgcMatrix3x3FP64* matrix1, const BgcMatrix3x3FP64* matrix2, BgcMatrix3x3FP64* result);

#endif // _BGC_MATRIX_TYPES_H_
