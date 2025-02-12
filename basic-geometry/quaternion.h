#ifndef _BGC_QUATERNION_H_
#define _BGC_QUATERNION_H_

#include <math.h>

#include "utilities.h"
#include "angle.h"
#include "matrix3x3.h"

typedef struct {
    float s0, x1, x2, x3;
} BgcQuaternionFP32;

typedef struct {
    double s0, x1, x2, x3;
} BgcQuaternionFP64;

// ==================== Reset =================== //

inline void bgc_quaternion_reset_fp32(BgcQuaternionFP32 * quaternion)
{
    quaternion->s0 = 0.0f;
    quaternion->x1 = 0.0f;
    quaternion->x2 = 0.0f;
    quaternion->x3 = 0.0f;
}

inline void bgc_quaternion_reset_fp64(BgcQuaternionFP64 * quaternion)
{
    quaternion->s0 = 0.0;
    quaternion->x1 = 0.0;
    quaternion->x2 = 0.0;
    quaternion->x3 = 0.0;
}

// ================== Set Unit ================== //

inline void bgc_quaternion_set_to_identity_fp32(BgcQuaternionFP32 * quaternion)
{
    quaternion->s0 = 1.0f;
    quaternion->x1 = 0.0f;
    quaternion->x2 = 0.0f;
    quaternion->x3 = 0.0f;
}

inline void bgc_quaternion_set_to_identity_fp64(BgcQuaternionFP64 * quaternion)
{
    quaternion->s0 = 1.0;
    quaternion->x1 = 0.0;
    quaternion->x2 = 0.0;
    quaternion->x3 = 0.0;
}

// ==================== Set ===================== //

inline void bgc_quaternion_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcQuaternionFP32 * quaternion)
{
    quaternion->s0 = s0;
    quaternion->x1 = x1;
    quaternion->x2 = x2;
    quaternion->x3 = x3;
}

inline void bgc_quaternion_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcQuaternionFP64 * quaternion)
{
    quaternion->s0 = s0;
    quaternion->x1 = x1;
    quaternion->x2 = x2;
    quaternion->x3 = x3;
}

// ============= Get Square Modulus ============= //

inline float bgc_quaternion_get_square_modulus_fp32(const BgcQuaternionFP32* quaternion)
{
    return (quaternion->s0 * quaternion->s0 + quaternion->x1 * quaternion->x1) + (quaternion->x2 * quaternion->x2 + quaternion->x3 * quaternion->x3);
}

inline double bgc_quaternion_get_square_modulus_fp64(const BgcQuaternionFP64* quaternion)
{
    return (quaternion->s0 * quaternion->s0 + quaternion->x1 * quaternion->x1) + (quaternion->x2 * quaternion->x2 + quaternion->x3 * quaternion->x3);
}

// ================ Get Modulus ================= //

inline float bgc_quaternion_get_modulus_fp32(const BgcQuaternionFP32* quaternion)
{
    return sqrtf(bgc_quaternion_get_square_modulus_fp32(quaternion));
}

inline double bgc_quaternion_get_modulus_fp64(const BgcQuaternionFP64* quaternion)
{
    return sqrt(bgc_quaternion_get_square_modulus_fp64(quaternion));
}

// ================== Is Zero =================== //

inline int bgc_quaternion_is_zero_fp32(const BgcQuaternionFP32* quaternion)
{
    return bgc_quaternion_get_square_modulus_fp32(quaternion) <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_quaternion_is_zero_fp64(const BgcQuaternionFP64* quaternion)
{
    return bgc_quaternion_get_square_modulus_fp64(quaternion) <= BGC_SQUARE_EPSYLON_FP64;
}

// ================== Is Unit =================== //

inline int bgc_quaternion_is_unit_fp32(const BgcQuaternionFP32* quaternion)
{
    return bgc_is_sqare_unit_fp32(bgc_quaternion_get_square_modulus_fp32(quaternion));
}

inline int bgc_quaternion_is_unit_fp64(const BgcQuaternionFP64* quaternion)
{
    return bgc_is_sqare_unit_fp64(bgc_quaternion_get_square_modulus_fp64(quaternion));
}

// ==================== Copy ==================== //

inline void bgc_quaternion_copy_fp32(const BgcQuaternionFP32* from, BgcQuaternionFP32* to)
{
    to->s0 = from->s0;
    to->x1 = from->x1;
    to->x2 = from->x2;
    to->x3 = from->x3;
}

inline void bgc_quaternion_copy_fp64(const BgcQuaternionFP64* from, BgcQuaternionFP64* to)
{
    to->s0 = from->s0;
    to->x1 = from->x1;
    to->x2 = from->x2;
    to->x3 = from->x3;
}

// ==================== Swap ==================== //

inline void bgc_quaternion_swap_fp32(BgcQuaternionFP32* quarternion1, BgcQuaternionFP32* quarternion2)
{
    const float s0 = quarternion2->s0;
    const float x1 = quarternion2->x1;
    const float x2 = quarternion2->x2;
    const float x3 = quarternion2->x3;

    quarternion2->s0 = quarternion1->s0;
    quarternion2->x1 = quarternion1->x1;
    quarternion2->x2 = quarternion1->x2;
    quarternion2->x3 = quarternion1->x3;

    quarternion1->s0 = s0;
    quarternion1->x1 = x1;
    quarternion1->x2 = x2;
    quarternion1->x3 = x3;
}

inline void bgc_quaternion_swap_fp64(BgcQuaternionFP64* quarternion1, BgcQuaternionFP64* quarternion2)
{
    const double s0 = quarternion2->s0;
    const double x1 = quarternion2->x1;
    const double x2 = quarternion2->x2;
    const double x3 = quarternion2->x3;

    quarternion2->s0 = quarternion1->s0;
    quarternion2->x1 = quarternion1->x1;
    quarternion2->x2 = quarternion1->x2;
    quarternion2->x3 = quarternion1->x3;

    quarternion1->s0 = s0;
    quarternion1->x1 = x1;
    quarternion1->x2 = x2;
    quarternion1->x3 = x3;
}

// ================== Convert =================== //

inline void bgc_quaternion_convert_fp64_to_fp32(const BgcQuaternionFP64* quaternion, BgcQuaternionFP32* result)
{
    result->s0 = (float) quaternion->s0;
    result->x1 = (float) quaternion->x1;
    result->x2 = (float) quaternion->x2;
    result->x3 = (float) quaternion->x3;
}

inline void bgc_quaternion_convert_fp32_to_fp64(const BgcQuaternionFP32* quaternion, BgcQuaternionFP64* result)
{
    result->s0 = quaternion->s0;
    result->x1 = quaternion->x1;
    result->x2 = quaternion->x2;
    result->x3 = quaternion->x3;
}

// ================= Conjugate ================== //

inline void bgc_quaternion_conjugate_fp32(BgcQuaternionFP32* quaternion)
{
    quaternion->x1 = -quaternion->x1;
    quaternion->x2 = -quaternion->x2;
    quaternion->x3 = -quaternion->x3;
}

inline void bgc_quaternion_conjugate_fp64(BgcQuaternionFP64* quaternion)
{
    quaternion->x1 = -quaternion->x1;
    quaternion->x2 = -quaternion->x2;
    quaternion->x3 = -quaternion->x3;
}

// ================= Normalize ================== //

inline int bgc_quaternion_normalize_fp32(BgcQuaternionFP32* quaternion)
{
    const float square_modulus = bgc_quaternion_get_square_modulus_fp32(quaternion);

    if (bgc_is_sqare_unit_fp32(square_modulus)) {
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus) {
        bgc_quaternion_reset_fp32(quaternion);
        return 0;
    }

    const float multiplier = sqrtf(1.0f / square_modulus);

    quaternion->s0 *= multiplier;
    quaternion->x1 *= multiplier;
    quaternion->x2 *= multiplier;
    quaternion->x3 *= multiplier;

    return 1;
}

inline int bgc_quaternion_normalize_fp64(BgcQuaternionFP64* quaternion)
{
    const double square_modulus = bgc_quaternion_get_square_modulus_fp64(quaternion);

    if (bgc_is_sqare_unit_fp64(square_modulus)) {
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus) {
        bgc_quaternion_reset_fp64(quaternion);
        return 0;
    }

    const double multiplier = sqrt(1.0 / square_modulus);

    quaternion->s0 *= multiplier;
    quaternion->x1 *= multiplier;
    quaternion->x2 *= multiplier;
    quaternion->x3 *= multiplier;

    return 1;
}

// =============== Make Conjugate =============== //

inline void bgc_quaternion_make_conjugate_fp32(const BgcQuaternionFP32* quaternion, BgcQuaternionFP32* conjugate)
{
    conjugate->s0 = quaternion->s0;
    conjugate->x1 = -quaternion->x1;
    conjugate->x2 = -quaternion->x2;
    conjugate->x3 = -quaternion->x3;
}

inline void bgc_quaternion_make_conjugate_fp64(const BgcQuaternionFP64* quaternion, BgcQuaternionFP64* conjugate)
{
    conjugate->s0 = quaternion->s0;
    conjugate->x1 = -quaternion->x1;
    conjugate->x2 = -quaternion->x2;
    conjugate->x3 = -quaternion->x3;
}

// ============== Make Normalized =============== //

inline int bgc_quaternion_make_normalized_fp32(const BgcQuaternionFP32* quaternion, BgcQuaternionFP32* normalized)
{
    bgc_quaternion_copy_fp32(quaternion, normalized);
    return bgc_quaternion_normalize_fp32(normalized);
}

inline int bgc_quaternion_make_normalized_fp64(const BgcQuaternionFP64* quaternion, BgcQuaternionFP64* normalized)
{
    bgc_quaternion_copy_fp64(quaternion, normalized);
    return bgc_quaternion_normalize_fp64(normalized);
}

// ================== Product =================== //

inline void bgc_quaternion_make_product_fp32(const BgcQuaternionFP32* left, const BgcQuaternionFP32* right, BgcQuaternionFP32* product)
{
    const float s0 = (left->s0 * right->s0 - left->x1 * right->x1) - (left->x2 * right->x2 + left->x3 * right->x3);
    const float x1 = (left->x1 * right->s0 + left->s0 * right->x1) - (left->x3 * right->x2 - left->x2 * right->x3);
    const float x2 = (left->x2 * right->s0 + left->s0 * right->x2) - (left->x1 * right->x3 - left->x3 * right->x1);
    const float x3 = (left->x3 * right->s0 + left->s0 * right->x3) - (left->x2 * right->x1 - left->x1 * right->x2);

    product->s0 = s0;
    product->x1 = x1;
    product->x2 = x2;
    product->x3 = x3;
}

inline void bgc_quaternion_make_product_fp64(const BgcQuaternionFP64* left, const BgcQuaternionFP64* right, BgcQuaternionFP64* product)
{
    const double s0 = (left->s0 * right->s0 - left->x1 * right->x1) - (left->x2 * right->x2 + left->x3 * right->x3);
    const double x1 = (left->x1 * right->s0 + left->s0 * right->x1) - (left->x3 * right->x2 - left->x2 * right->x3);
    const double x2 = (left->x2 * right->s0 + left->s0 * right->x2) - (left->x1 * right->x3 - left->x3 * right->x1);
    const double x3 = (left->x3 * right->s0 + left->s0 * right->x3) - (left->x2 * right->x1 - left->x1 * right->x2);

    product->s0 = s0;
    product->x1 = x1;
    product->x2 = x2;
    product->x3 = x3;
}

// ============ Make Rotation Matrix ============ //

inline void bgc_quaternion_make_rotation_matrix_fp32(const BgcQuaternionFP32* quaternion, BgcMatrix3x3FP32* rotation)
{
    const float s0s0 = quaternion->s0 * quaternion->s0;
    const float x1x1 = quaternion->x1 * quaternion->x1;
    const float x2x2 = quaternion->x2 * quaternion->x2;
    const float x3x3 = quaternion->x3 * quaternion->x3;

    const float square_modulus = (s0s0 + x1x1) + (x2x2 + x3x3);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus)
    {
        bgc_matrix3x3_set_to_identity_fp32(rotation);
        return;
    }

    const float corrector1 = 1.0f / square_modulus;

    const float s0x1 = quaternion->s0 * quaternion->x1;
    const float s0x2 = quaternion->s0 * quaternion->x2;
    const float s0x3 = quaternion->s0 * quaternion->x3;
    const float x1x2 = quaternion->x1 * quaternion->x2;
    const float x1x3 = quaternion->x1 * quaternion->x3;
    const float x2x3 = quaternion->x2 * quaternion->x3;

    const float corrector2 = 2.0f * corrector1;

    rotation->r1c1 = corrector1 * ((s0s0 + x1x1) - (x2x2 + x3x3));
    rotation->r2c2 = corrector1 * ((s0s0 + x2x2) - (x1x1 + x3x3));
    rotation->r3c3 = corrector1 * ((s0s0 + x3x3) - (x1x1 + x2x2));

    rotation->r1c2 = corrector2 * (x1x2 - s0x3);
    rotation->r2c3 = corrector2 * (x2x3 - s0x1);
    rotation->r3c1 = corrector2 * (x1x3 - s0x2);

    rotation->r2c1 = corrector2 * (x1x2 + s0x3);
    rotation->r3c2 = corrector2 * (x2x3 + s0x1);
    rotation->r1c3 = corrector2 * (x1x3 + s0x2);
}

inline void bgc_quaternion_make_rotation_matrix_fp64(const BgcQuaternionFP64* quaternion, BgcMatrix3x3FP64* rotation)
{
    const double s0s0 = quaternion->s0 * quaternion->s0;
    const double x1x1 = quaternion->x1 * quaternion->x1;
    const double x2x2 = quaternion->x2 * quaternion->x2;
    const double x3x3 = quaternion->x3 * quaternion->x3;

    const double square_modulus = (s0s0 + x1x1) + (x2x2 + x3x3);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus)
    {
        bgc_matrix3x3_set_to_identity_fp64(rotation);
        return;
    }

    const double corrector1 = 1.0f / square_modulus;

    const double s0x1 = quaternion->s0 * quaternion->x1;
    const double s0x2 = quaternion->s0 * quaternion->x2;
    const double s0x3 = quaternion->s0 * quaternion->x3;
    const double x1x2 = quaternion->x1 * quaternion->x2;
    const double x1x3 = quaternion->x1 * quaternion->x3;
    const double x2x3 = quaternion->x2 * quaternion->x3;

    const double corrector2 = 2.0f * corrector1;

    rotation->r1c1 = corrector1 * ((s0s0 + x1x1) - (x2x2 + x3x3));
    rotation->r2c2 = corrector1 * ((s0s0 + x2x2) - (x1x1 + x3x3));
    rotation->r3c3 = corrector1 * ((s0s0 + x3x3) - (x1x1 + x2x2));

    rotation->r1c2 = corrector2 * (x1x2 - s0x3);
    rotation->r2c3 = corrector2 * (x2x3 - s0x1);
    rotation->r3c1 = corrector2 * (x1x3 - s0x2);

    rotation->r2c1 = corrector2 * (x1x2 + s0x3);
    rotation->r3c2 = corrector2 * (x2x3 + s0x1);
    rotation->r1c3 = corrector2 * (x1x3 + s0x2);
}

// ============ Make Reverse Matrix ============= //

inline void bgc_quaternion_make_reverse_matrix_fp32(const BgcQuaternionFP32* quaternion, BgcMatrix3x3FP32* reverse)
{
    const float s0s0 = quaternion->s0 * quaternion->s0;
    const float x1x1 = quaternion->x1 * quaternion->x1;
    const float x2x2 = quaternion->x2 * quaternion->x2;
    const float x3x3 = quaternion->x3 * quaternion->x3;

    const float square_modulus = (s0s0 + x1x1) + (x2x2 + x3x3);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus)
    {
        bgc_matrix3x3_set_to_identity_fp32(reverse);
        return;
    }

    const float corrector1 = 1.0f / square_modulus;

    const float s0x1 = quaternion->s0 * quaternion->x1;
    const float s0x2 = quaternion->s0 * quaternion->x2;
    const float s0x3 = quaternion->s0 * quaternion->x3;
    const float x1x2 = quaternion->x1 * quaternion->x2;
    const float x1x3 = quaternion->x1 * quaternion->x3;
    const float x2x3 = quaternion->x2 * quaternion->x3;

    const float corrector2 = 2.0f * corrector1;

    reverse->r1c1 = corrector1 * ((s0s0 + x1x1) - (x2x2 + x3x3));
    reverse->r2c2 = corrector1 * ((s0s0 + x2x2) - (x1x1 + x3x3));
    reverse->r3c3 = corrector1 * ((s0s0 + x3x3) - (x1x1 + x2x2));

    reverse->r1c2 = corrector2 * (x1x2 + s0x3);
    reverse->r2c3 = corrector2 * (x2x3 + s0x1);
    reverse->r3c1 = corrector2 * (x1x3 + s0x2);

    reverse->r2c1 = corrector2 * (x1x2 - s0x3);
    reverse->r3c2 = corrector2 * (x2x3 - s0x1);
    reverse->r1c3 = corrector2 * (x1x3 - s0x2);
}

inline void bgc_quaternion_make_reverse_matrix_fp64(const BgcQuaternionFP64* quaternion, BgcMatrix3x3FP64* reverse)
{
    const double s0s0 = quaternion->s0 * quaternion->s0;
    const double x1x1 = quaternion->x1 * quaternion->x1;
    const double x2x2 = quaternion->x2 * quaternion->x2;
    const double x3x3 = quaternion->x3 * quaternion->x3;

    const double square_modulus = (s0s0 + x1x1) + (x2x2 + x3x3);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus)
    {
        bgc_matrix3x3_set_to_identity_fp64(reverse);
        return;
    }

    const double corrector1 = 1.0f / square_modulus;

    const double s0x1 = quaternion->s0 * quaternion->x1;
    const double s0x2 = quaternion->s0 * quaternion->x2;
    const double s0x3 = quaternion->s0 * quaternion->x3;
    const double x1x2 = quaternion->x1 * quaternion->x2;
    const double x1x3 = quaternion->x1 * quaternion->x3;
    const double x2x3 = quaternion->x2 * quaternion->x3;

    const double corrector2 = 2.0f * corrector1;

    reverse->r1c1 = corrector1 * ((s0s0 + x1x1) - (x2x2 + x3x3));
    reverse->r2c2 = corrector1 * ((s0s0 + x2x2) - (x1x1 + x3x3));
    reverse->r3c3 = corrector1 * ((s0s0 + x3x3) - (x1x1 + x2x2));

    reverse->r1c2 = corrector2 * (x1x2 + s0x3);
    reverse->r2c3 = corrector2 * (x2x3 + s0x1);
    reverse->r3c1 = corrector2 * (x1x3 + s0x2);

    reverse->r2c1 = corrector2 * (x1x2 - s0x3);
    reverse->r3c2 = corrector2 * (x2x3 - s0x1);
    reverse->r1c3 = corrector2 * (x1x3 - s0x2);
}

// ==================== Add ===================== //

inline void bgc_quaternion_add_fp32(const BgcQuaternionFP32 * quaternion1, const BgcQuaternionFP32 * quaternion2, BgcQuaternionFP32 * sum)
{
    sum->s0 = quaternion1->s0 + quaternion2->s0;
    sum->x1 = quaternion1->x1 + quaternion2->x1;
    sum->x2 = quaternion1->x2 + quaternion2->x2;
    sum->x3 = quaternion1->x3 + quaternion2->x3;
}

inline void bgc_quaternion_add_fp64(const BgcQuaternionFP64 * quaternion1, const BgcQuaternionFP64 * quaternion2, BgcQuaternionFP64 * sum)
{
    sum->s0 = quaternion1->s0 + quaternion2->s0;
    sum->x1 = quaternion1->x1 + quaternion2->x1;
    sum->x2 = quaternion1->x2 + quaternion2->x2;
    sum->x3 = quaternion1->x3 + quaternion2->x3;
}

// ================= Add Scaled ================= //

inline void bgc_quaternion_add_scaled_fp32(const BgcQuaternionFP32 * basic_quaternion, const BgcQuaternionFP32 * scalable_quaternion, const float scale, BgcQuaternionFP32 * sum)
{
    sum->s0 = basic_quaternion->s0 + scalable_quaternion->s0 * scale;
    sum->x1 = basic_quaternion->x1 + scalable_quaternion->x1 * scale;
    sum->x2 = basic_quaternion->x2 + scalable_quaternion->x2 * scale;
    sum->x3 = basic_quaternion->x3 + scalable_quaternion->x3 * scale;
}

inline void bgc_quaternion_add_scaled_fp64(const BgcQuaternionFP64 * basic_quaternion, const BgcQuaternionFP64 * scalable_quaternion, const double scale, BgcQuaternionFP64 * sum)
{
    sum->s0 = basic_quaternion->s0 + scalable_quaternion->s0 * scale;
    sum->x1 = basic_quaternion->x1 + scalable_quaternion->x1 * scale;
    sum->x2 = basic_quaternion->x2 + scalable_quaternion->x2 * scale;
    sum->x3 = basic_quaternion->x3 + scalable_quaternion->x3 * scale;
}

// ================== Subtract ================== //

inline void bgc_quaternion_subtract_fp32(const BgcQuaternionFP32 * minuend, const BgcQuaternionFP32 * subtrahend, BgcQuaternionFP32 * difference)
{
    difference->s0 = minuend->s0 - subtrahend->s0;
    difference->x1 = minuend->x1 - subtrahend->x1;
    difference->x2 = minuend->x2 - subtrahend->x2;
    difference->x3 = minuend->x3 - subtrahend->x3;
}

inline void bgc_quaternion_subtract_fp64(const BgcQuaternionFP64 * minuend, const BgcQuaternionFP64 * subtrahend, BgcQuaternionFP64 * difference)
{
    difference->s0 = minuend->s0 - subtrahend->s0;
    difference->x1 = minuend->x1 - subtrahend->x1;
    difference->x2 = minuend->x2 - subtrahend->x2;
    difference->x3 = minuend->x3 - subtrahend->x3;
}

// ============== Subtract scaled =============== //

inline void bgc_quaternion_subtract_scaled_fp32(const BgcQuaternionFP32 * basic_quaternion, const BgcQuaternionFP32 * scalable_quaternion, const float scale, BgcQuaternionFP32 * difference)
{
    difference->s0 = basic_quaternion->s0 - scalable_quaternion->s0 * scale;
    difference->x1 = basic_quaternion->x1 - scalable_quaternion->x1 * scale;
    difference->x2 = basic_quaternion->x2 - scalable_quaternion->x2 * scale;
    difference->x3 = basic_quaternion->x3 - scalable_quaternion->x3 * scale;
}

inline void bgc_quaternion_subtract_scaled_fp64(const BgcQuaternionFP64 * basic_quaternion, const BgcQuaternionFP64 * scalable_quaternion, const double scale, BgcQuaternionFP64 * difference)
{
    difference->s0 = basic_quaternion->s0 - scalable_quaternion->s0 * scale;
    difference->x1 = basic_quaternion->x1 - scalable_quaternion->x1 * scale;
    difference->x2 = basic_quaternion->x2 - scalable_quaternion->x2 * scale;
    difference->x3 = basic_quaternion->x3 - scalable_quaternion->x3 * scale;
}

// ================== Multiply ================== //

inline void bgc_quaternion_multiply_fp32(const BgcQuaternionFP32* multiplicand, const float multipier, BgcQuaternionFP32* product)
{
    product->s0 = multiplicand->s0 * multipier;
    product->x1 = multiplicand->x1 * multipier;
    product->x2 = multiplicand->x2 * multipier;
    product->x3 = multiplicand->x3 * multipier;
}

inline void bgc_quaternion_multiply_fp64(const BgcQuaternionFP64* multiplicand, const double multipier, BgcQuaternionFP64* product)
{
    product->s0 = multiplicand->s0 * multipier;
    product->x1 = multiplicand->x1 * multipier;
    product->x2 = multiplicand->x2 * multipier;
    product->x3 = multiplicand->x3 * multipier;
}

// =================== Divide =================== //

inline void bgc_quaternion_divide_fp32(const BgcQuaternionFP32* dividend, const float divisor, BgcQuaternionFP32* quotient)
{
    bgc_quaternion_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_quaternion_divide_fp64(const BgcQuaternionFP64* dividend, const double divisor, BgcQuaternionFP64* quotient)
{
    bgc_quaternion_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ================== Are Close ================= //

inline int bgc_quaternion_are_close_fp32(const BgcQuaternionFP32* quaternion1, const BgcQuaternionFP32* quaternion2)
{
    const float ds0 = quaternion1->s0 - quaternion2->s0;
    const float dx1 = quaternion1->x1 - quaternion2->x1;
    const float dx2 = quaternion1->x2 - quaternion2->x2;
    const float dx3 = quaternion1->x3 - quaternion2->x3;

    const float square_modulus1 = bgc_quaternion_get_square_modulus_fp32(quaternion1);
    const float square_modulus2 = bgc_quaternion_get_square_modulus_fp32(quaternion2);
    const float square_distance = (ds0 * ds0 + dx1 * dx1) + (dx2 * dx2 + dx3 * dx3);

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP32;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

inline int bgc_quaternion_are_close_fp64(const BgcQuaternionFP64* quaternion1, const BgcQuaternionFP64* quaternion2)
{
    const double ds0 = quaternion1->s0 - quaternion2->s0;
    const double dx1 = quaternion1->x1 - quaternion2->x1;
    const double dx2 = quaternion1->x2 - quaternion2->x2;
    const double dx3 = quaternion1->x3 - quaternion2->x3;

    const double square_modulus1 = bgc_quaternion_get_square_modulus_fp64(quaternion1);
    const double square_modulus2 = bgc_quaternion_get_square_modulus_fp64(quaternion2);
    const double square_distance = (ds0 * ds0 + dx1 * dx1) + (dx2 * dx2 + dx3 * dx3);

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP64;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP64 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP64 * square_modulus2;
}

#endif // _BGC_QUATERNION_H_
