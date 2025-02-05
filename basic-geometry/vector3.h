#ifndef _BGC_VECTOR3_H_
#define _BGC_VECTOR3_H_

#include "utilities.h"
#include "angle.h"

#include <math.h>

// ================== Vector3 =================== //

typedef struct
{
    float x1, x2, x3;
} BgcVector3FP32;

typedef struct
{
    double x1, x2, x3;
} BgcVector3FP64;

// =================== Reset ==================== //

inline void bgc_vector3_reset_fp32(BgcVector3FP32* vector)
{
    vector->x1 = 0.0f;
    vector->x2 = 0.0f;
    vector->x3 = 0.0f;
}

inline void bgc_vector3_reset_fp64(BgcVector3FP64* vector)
{
    vector->x1 = 0.0;
    vector->x2 = 0.0;
    vector->x3 = 0.0;
}

// ==================== Set ===================== //

inline void bgc_vector3_set_values_fp32(const float x1, const float x2, const float x3, BgcVector3FP32* to)
{
    to->x1 = x1;
    to->x2 = x2;
    to->x3 = x3;
}

inline void bgc_vector3_set_values_fp64(const double x1, const double x2, const double x3, BgcVector3FP64* to)
{
    to->x1 = x1;
    to->x2 = x2;
    to->x3 = x3;
}

// ==================== Copy ==================== //

inline void bgc_vector3_copy_fp32(const BgcVector3FP32* from, BgcVector3FP32* to)
{
    to->x1 = from->x1;
    to->x2 = from->x2;
    to->x3 = from->x3;
}

inline void bgc_vector3_copy_fp64(const BgcVector3FP64* from, BgcVector3FP64* to)
{
    to->x1 = from->x1;
    to->x2 = from->x2;
    to->x3 = from->x3;
}

// ================== Convert =================== //

inline void bgc_vector3_convert_fp64_to_fp32(const BgcVector3FP64* from, BgcVector3FP32* to)
{
    to->x1 = (float) from->x1;
    to->x2 = (float) from->x2;
    to->x3 = (float) from->x3;
}

inline void bgc_vector3_convert_fp32_to_fp64(const BgcVector3FP32* from, BgcVector3FP64* to)
{
    to->x1 = from->x1;
    to->x2 = from->x2;
    to->x3 = from->x3;
}

// ==================== Swap ==================== //

inline void bgc_vector3_swap_fp32(BgcVector3FP32* vector1, BgcVector3FP32* vector2)
{
    const float x1 = vector2->x1;
    const float x2 = vector2->x2;
    const float x3 = vector2->x3;

    vector2->x1 = vector1->x1;
    vector2->x2 = vector1->x2;
    vector2->x3 = vector1->x3;

    vector1->x1 = x1;
    vector1->x2 = x2;
    vector1->x3 = x3;
}

inline void bgc_vector3_swap_fp64(BgcVector3FP64* vector1, BgcVector3FP64* vector2)
{
    const double x1 = vector2->x1;
    const double x2 = vector2->x2;
    const double x3 = vector2->x3;

    vector2->x1 = vector1->x1;
    vector2->x2 = vector1->x2;
    vector2->x3 = vector1->x3;

    vector1->x1 = x1;
    vector1->x2 = x2;
    vector1->x3 = x3;
}

// ==================== Invert ================== //

inline void bgc_vector3_invert_fp32(BgcVector3FP32* vector)
{
    vector->x1 = -vector->x1;
    vector->x2 = -vector->x2;
    vector->x3 = -vector->x3;
}

inline void bgc_vector3_invert_fp64(BgcVector3FP64* vector)
{
    vector->x1 = -vector->x1;
    vector->x2 = -vector->x2;
    vector->x3 = -vector->x3;
}

// ================ Make Inverted =============== //

inline void bgc_vector3_set_inverted_fp32(const BgcVector3FP32* vector, BgcVector3FP32* result)
{
    result->x1 = -vector->x1;
    result->x2 = -vector->x2;
    result->x3 = -vector->x3;
}

inline void bgc_vector3_set_inverted_fp64(const BgcVector3FP64* vector, BgcVector3FP64* result)
{
    result->x1 = -vector->x1;
    result->x2 = -vector->x2;
    result->x3 = -vector->x3;
}

// ============== Make Inverted Twin ============ //

inline void bgc_vector3_set_inverted_fp32_to_fp64(const BgcVector3FP32* vector, BgcVector3FP64* result)
{
    result->x1 = -vector->x1;
    result->x2 = -vector->x2;
    result->x3 = -vector->x3;
}

inline void bgc_vector3_set_inverted_fp64_to_fp32(const BgcVector3FP64* vector, BgcVector3FP32* result)
{
    result->x1 = (float) -vector->x1;
    result->x2 = (float) -vector->x2;
    result->x3 = (float) -vector->x3;
}

// =================== Module =================== //

inline float bgc_vector3_get_square_modulus_fp32(const BgcVector3FP32* vector)
{
    return vector->x1 * vector->x1 + vector->x2 * vector->x2 + vector->x3 * vector->x3;
}

inline double bgc_vector3_get_square_modulus_fp64(const BgcVector3FP64* vector)
{
    return vector->x1 * vector->x1 + vector->x2 * vector->x2 + vector->x3 * vector->x3;
}

inline float bgc_vector3_get_modulus_fp32(const BgcVector3FP32* vector)
{
    return sqrtf(bgc_vector3_get_square_modulus_fp32(vector));
}

inline double bgc_vector3_get_modulus_fp64(const BgcVector3FP64* vector)
{
    return sqrt(bgc_vector3_get_square_modulus_fp64(vector));
}

// ================= Comparison ================= //

inline int bgc_vector3_is_zero_fp32(const BgcVector3FP32* vector)
{
    return bgc_vector3_get_square_modulus_fp32(vector) <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_vector3_is_zero_fp64(const BgcVector3FP64* vector)
{
    return bgc_vector3_get_square_modulus_fp64(vector) <= BGC_SQUARE_EPSYLON_FP64;
}

inline int bgc_vector3_is_unit_fp32(const BgcVector3FP32* vector)
{
    return bgc_is_sqare_value_unit_fp32(bgc_vector3_get_square_modulus_fp32(vector));
}

inline int bgc_vector3_is_unit_fp64(const BgcVector3FP64* vector)
{
    return bgc_is_sqare_value_unit_fp64(bgc_vector3_get_square_modulus_fp64(vector));
}

// ==================== Add ===================== //

inline void bgc_vector3_add_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, BgcVector3FP32* sum)
{
    sum->x1 = vector1->x1 + vector2->x1;
    sum->x2 = vector1->x2 + vector2->x2;
    sum->x3 = vector1->x3 + vector2->x3;
}

inline void bgc_vector3_add_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, BgcVector3FP64* sum)
{
    sum->x1 = vector1->x1 + vector2->x1;
    sum->x2 = vector1->x2 + vector2->x2;
    sum->x3 = vector1->x3 + vector2->x3;
}

// ================= Add scaled ================= //

inline void bgc_vector3_add_scaled_fp32(const BgcVector3FP32* basic_vector, const BgcVector3FP32* scalable_vector, const float scale, BgcVector3FP32* result)
{
    result->x1 = basic_vector->x1 + scalable_vector->x1 * scale;
    result->x2 = basic_vector->x2 + scalable_vector->x2 * scale;
    result->x3 = basic_vector->x3 + scalable_vector->x3 * scale;
}

inline void bgc_vector3_add_scaled_fp64(const BgcVector3FP64* basic_vector, const BgcVector3FP64* scalable_vector, const double scale, BgcVector3FP64* result)
{
    result->x1 = basic_vector->x1 + scalable_vector->x1 * scale;
    result->x2 = basic_vector->x2 + scalable_vector->x2 * scale;
    result->x3 = basic_vector->x3 + scalable_vector->x3 * scale;
}

// ================ Subtraction ================= //

inline void bgc_vector3_subtract_fp32(const BgcVector3FP32* minuend, const BgcVector3FP32* subtrahend, BgcVector3FP32* difference)
{
    difference->x1 = minuend->x1 - subtrahend->x1;
    difference->x2 = minuend->x2 - subtrahend->x2;
    difference->x3 = minuend->x3 - subtrahend->x3;
}

inline void bgc_vector3_subtract_fp64(const BgcVector3FP64* minuend, const BgcVector3FP64* subtrahend, BgcVector3FP64* difference)
{
    difference->x1 = minuend->x1 - subtrahend->x1;
    difference->x2 = minuend->x2 - subtrahend->x2;
    difference->x3 = minuend->x3 - subtrahend->x3;
}

// =============== Multiplication =============== //

inline void bgc_vector3_multiply_fp32(const BgcVector3FP32* multiplicand, const float multiplier, BgcVector3FP32* product)
{
    product->x1 = multiplicand->x1 * multiplier;
    product->x2 = multiplicand->x2 * multiplier;
    product->x3 = multiplicand->x3 * multiplier;
}

inline void bgc_vector3_multiply_fp64(const BgcVector3FP64* multiplicand, const double multiplier, BgcVector3FP64* product)
{
    product->x1 = multiplicand->x1 * multiplier;
    product->x2 = multiplicand->x2 * multiplier;
    product->x3 = multiplicand->x3 * multiplier;
}

// ================== Division ================== //

inline void bgc_vector3_divide_fp32(const BgcVector3FP32* dividend, const float divisor, BgcVector3FP32* quotient)
{
    bgc_vector3_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_vector3_divide_fp64(const BgcVector3FP64* dividend, const double divisor, BgcVector3FP64* quotient)
{
    bgc_vector3_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ================== Average2 ================== //

inline void bgc_vector3_mean_of_two_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, BgcVector3FP32* result)
{
    result->x1 = (vector1->x1 + vector2->x1) * 0.5f;
    result->x2 = (vector1->x2 + vector2->x2) * 0.5f;
    result->x3 = (vector1->x3 + vector2->x3) * 0.5f;
}

inline void bgc_vector3_mean_of_two_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, BgcVector3FP64* result)
{
    result->x1 = (vector1->x1 + vector2->x1) * 0.5;
    result->x2 = (vector1->x2 + vector2->x2) * 0.5;
    result->x3 = (vector1->x3 + vector2->x3) * 0.5;
}

// ================== Average3 ================== //

inline void bgc_vector3_mean_of_three_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcVector3FP32* vector3, BgcVector3FP32* result)
{
    result->x1 = (vector1->x1 + vector2->x1 + vector3->x1) * BGC_ONE_THIRD_FP32;
    result->x2 = (vector1->x2 + vector2->x2 + vector3->x2) * BGC_ONE_THIRD_FP32;
    result->x3 = (vector1->x3 + vector2->x3 + vector3->x3) * BGC_ONE_THIRD_FP32;
}

inline void bgc_vector3_mean_of_three_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcVector3FP64* vector3, BgcVector3FP64* result)
{
    result->x1 = (vector1->x1 + vector2->x1 + vector3->x1) * BGC_ONE_THIRD_FP64;
    result->x2 = (vector1->x2 + vector2->x2 + vector3->x2) * BGC_ONE_THIRD_FP64;
    result->x3 = (vector1->x3 + vector2->x3 + vector3->x3) * BGC_ONE_THIRD_FP64;
}

// =============== Scalar Product =============== //

inline float bgc_vector3_scalar_product_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2)
{
    return vector1->x1 * vector2->x1 + vector1->x2 * vector2->x2 + vector1->x3 * vector2->x3;
}

inline double bgc_vector3_scalar_product_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2)
{
    return vector1->x1 * vector2->x1 + vector1->x2 * vector2->x2 + vector1->x3 * vector2->x3;
}

// =============== Triple Product =============== //

inline float bgc_vector3_triple_product_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcVector3FP32* vector3)
{
    return vector1->x1 * (vector2->x2 * vector3->x3 - vector2->x3 * vector3->x2)
         + vector1->x2 * (vector2->x3 * vector3->x1 - vector2->x1 * vector3->x3)
         + vector1->x3 * (vector2->x1 * vector3->x2 - vector2->x2 * vector3->x1);
}

inline double bgc_vector3_triple_product_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcVector3FP64* vector3)
{
    return vector1->x1 * (vector2->x2 * vector3->x3 - vector2->x3 * vector3->x2)
         + vector1->x2 * (vector2->x3 * vector3->x1 - vector2->x1 * vector3->x3)
         + vector1->x3 * (vector2->x1 * vector3->x2 - vector2->x2 * vector3->x1);
}

// =============== Cross Product ================ //

inline void bgc_vector3_cross_product_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, BgcVector3FP32* result)
{
    const float x1 = vector1->x2 * vector2->x3 - vector1->x3 * vector2->x2;
    const float x2 = vector1->x3 * vector2->x1 - vector1->x1 * vector2->x3;
    const float x3 = vector1->x1 * vector2->x2 - vector1->x2 * vector2->x1;

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

inline void bgc_vector3_cross_product_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, BgcVector3FP64* result)
{
    const double x1 = vector1->x2 * vector2->x3 - vector1->x3 * vector2->x2;
    const double x2 = vector1->x3 * vector2->x1 - vector1->x1 * vector2->x3;
    const double x3 = vector1->x1 * vector2->x2 - vector1->x2 * vector2->x1;

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

// ============ Double Cross Product ============ //

inline void bgc_vector3_double_cross_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcVector3FP32* vector3, BgcVector3FP32* result)
{
    const float ac = bgc_vector3_scalar_product_fp32(vector1, vector3);
    const float ab = bgc_vector3_scalar_product_fp32(vector1, vector2);

    result->x1 = vector2->x1 * ac - vector3->x1 * ab;
    result->x2 = vector2->x2 * ac - vector3->x2 * ab;
    result->x3 = vector2->x3 * ac - vector3->x3 * ab;
}

inline void bgc_vector3_double_cross_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcVector3FP64* vector3, BgcVector3FP64* result)
{
    const double ac = bgc_vector3_scalar_product_fp64(vector1, vector3);
    const double ab = bgc_vector3_scalar_product_fp64(vector1, vector2);

    result->x1 = vector2->x1 * ac - vector3->x1 * ab;
    result->x2 = vector2->x2 * ac - vector3->x2 * ab;
    result->x3 = vector2->x3 * ac - vector3->x3 * ab;
}

// =============== Normalization ================ //

inline int bgc_vector3_normalize_fp32(BgcVector3FP32* vector)
{
    const float square_modulus = bgc_vector3_get_square_modulus_fp32(vector);

    if (bgc_is_sqare_value_unit_fp32(square_modulus)) {
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32) {
        bgc_vector3_reset_fp32(vector);
        return 0;
    }

    bgc_vector3_multiply_fp32(vector, sqrtf(1.0f / square_modulus), vector);
    return 1;
}

inline int bgc_vector3_normalize_fp64(BgcVector3FP64* vector)
{
    const double square_modulus = bgc_vector3_get_square_modulus_fp64(vector);

    if (bgc_is_sqare_value_unit_fp64(square_modulus)) {
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64) {
        bgc_vector3_reset_fp64(vector);
        return 0;
    }

    bgc_vector3_multiply_fp64(vector, sqrt(1.0 / square_modulus), vector);
    return 1;
}

// =============== Set Normalized =============== //

inline int bgc_vector3_set_normalized_fp32(const BgcVector3FP32* vector, BgcVector3FP32* result)
{
    bgc_vector3_copy_fp32(vector, result);
    return bgc_vector3_normalize_fp32(result);
}

inline int bgc_vector3_set_normalized_fp64(const BgcVector3FP64* vector, BgcVector3FP64* result)
{
    bgc_vector3_copy_fp64(vector, result);
    return bgc_vector3_normalize_fp64(result);
}

// =================== Angle ==================== //

float bgc_vector3_get_angle_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcAngleUnitEnum unit);

double bgc_vector3_get_angle_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcAngleUnitEnum unit);

// =============== Square Distance ============== //

inline float bgc_vector3_get_square_distance_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2)
{
    const float dx1 = (vector1->x1 - vector2->x1);
    const float dx2 = (vector1->x2 - vector2->x2);
    const float dx3 = (vector1->x3 - vector2->x3);

    return dx1 * dx1 + dx2 * dx2 + dx3 * dx3;
}

inline double bgc_vector3_get_square_distance_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2)
{
    const double dx1 = (vector1->x1 - vector2->x1);
    const double dx2 = (vector1->x2 - vector2->x2);
    const double dx3 = (vector1->x3 - vector2->x3);

    return dx1 * dx1 + dx2 * dx2 + dx3 * dx3;
}

// ================== Distance ================== //

inline float bgc_vector3_get_distance_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2)
{
    return sqrtf(bgc_vector3_get_square_distance_fp32(vector1, vector2));
}

inline double bgc_vector3_get_distance_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2)
{
    return sqrt(bgc_vector3_get_square_distance_fp64(vector1, vector2));
}

// ============== Are Close Enough ============== //

inline int bgc_vector3_are_close_enough_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const float distance)
{
    return bgc_vector3_get_square_distance_fp32(vector1, vector2) <= distance * distance;
}

inline int bgc_vector3_are_close_enough_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const double distance)
{
    return bgc_vector3_get_square_distance_fp64(vector1, vector2) <= distance * distance;
}

// ================== Are Close ================= //

inline int bgc_vector3_are_close_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2)
{
    const float square_modulus1 = bgc_vector3_get_square_modulus_fp32(vector1);
    const float square_modulus2 = bgc_vector3_get_square_modulus_fp32(vector2);
    const float square_distance = bgc_vector3_get_square_distance_fp32(vector1, vector2);

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP32;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

inline int bgc_vector3_are_close_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2)
{
    const double square_modulus1 = bgc_vector3_get_square_modulus_fp64(vector1);
    const double square_modulus2 = bgc_vector3_get_square_modulus_fp64(vector2);
    const double square_distance = bgc_vector3_get_square_distance_fp64(vector1, vector2);

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP64;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

#endif
