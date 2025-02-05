#ifndef _BGC_VECTOR2_H_
#define _BGC_VECTOR2_H_

#include "utilities.h"
#include "angle.h"

#include <math.h>

typedef struct
{
    float x1, x2;
} BgcVector2FP32;

typedef struct
{
    double x1, x2;
} BgcVector2FP64;

// =================== Reset ==================== //

inline void bgc_vector2_reset_fp32(BgcVector2FP32* vector)
{
    vector->x1 = 0.0f;
    vector->x2 = 0.0f;
}

inline void bgc_vector2_reset_fp64(BgcVector2FP64* vector)
{
    vector->x1 = 0.0;
    vector->x2 = 0.0;
}

// ==================== Set ===================== //

inline void bgc_vector2_set_values_fp32(const float x1, const float x2, BgcVector2FP32* to)
{
    to->x1 = x1;
    to->x2 = x2;
}

inline void bgc_vector2_set_values_fp64(const double x1, const double x2, BgcVector2FP64* to)
{
    to->x1 = x1;
    to->x2 = x2;
}

// ==================== Copy ==================== //

inline void bgc_vector2_copy_fp32(const BgcVector2FP32* from, BgcVector2FP32* to)
{
    to->x1 = from->x1;
    to->x2 = from->x2;
}

inline void bgc_vector2_copy_fp64(const BgcVector2FP64* from, BgcVector2FP64* to)
{
    to->x1 = from->x1;
    to->x2 = from->x2;
}

// ==================== Swap ==================== //

inline void bgc_vector2_swap_fp32(BgcVector2FP32* vector1, BgcVector2FP32* vector2)
{
    const float x1 = vector2->x1;
    const float x2 = vector2->x2;

    vector2->x1 = vector1->x1;
    vector2->x2 = vector1->x2;

    vector1->x1 = x1;
    vector1->x2 = x2;
}

inline void bgc_vector2_swap_fp64(BgcVector2FP64* vector1, BgcVector2FP64* vector2)
{
    const double x1 = vector2->x1;
    const double x2 = vector2->x2;

    vector2->x1 = vector1->x1;
    vector2->x2 = vector1->x2;

    vector1->x1 = x1;
    vector1->x2 = x2;
}

// ============= Copy to twin type ============== //

inline void bgc_vector2_convert_fp64_to_fp32(const BgcVector2FP64* from, BgcVector2FP32* to)
{
    to->x1 = (float)from->x1;
    to->x2 = (float)from->x2;
}

inline void bgc_vector2_convert_fp32_to_fp64(const BgcVector2FP32* from, BgcVector2FP64* to)
{
    to->x1 = from->x1;
    to->x2 = from->x2;
}

// =================== Reverse ================== //

inline void bgc_vector2_set_reverse_fp32(const BgcVector2FP32* from, BgcVector2FP32* to)
{
    to->x1 = -from->x1;
    to->x2 = -from->x2;
}

inline void bgc_vector2_set_reverse_fp64(const BgcVector2FP64* from, BgcVector2FP64* to)
{
    to->x1 = -from->x1;
    to->x2 = -from->x2;
}

// ============= Reverse twin type ============== //

inline void bgc_vector2_set_reverse_fp64_to_fp32(const BgcVector2FP64* from, BgcVector2FP32* to)
{
    to->x1 = (float) -from->x1;
    to->x2 = (float) -from->x2;
}

inline void bgc_vector2_set_reverse_fp32_to_fp64(const BgcVector2FP32* from, BgcVector2FP64* to)
{
    to->x1 = -from->x1;
    to->x2 = -from->x2;
}

// =================== Module =================== //

inline float bgc_vector2_get_square_modulus_fp32(const BgcVector2FP32* vector)
{
    return vector->x1 * vector->x1 + vector->x2 * vector->x2;
}

inline double bgc_vector2_get_square_modulus_fp64(const BgcVector2FP64* vector)
{
    return vector->x1 * vector->x1 + vector->x2 * vector->x2;
}

inline float bgc_vector2_get_modulus_fp32(const BgcVector2FP32* vector)
{
    return sqrtf(bgc_vector2_get_square_modulus_fp32(vector));
}

inline double bgc_vector2_get_modulus_fp64(const BgcVector2FP64* vector)
{
    return sqrt(bgc_vector2_get_square_modulus_fp64(vector));
}

// ================= Comparison ================= //

inline int bgc_vector2_is_zero_fp32(const BgcVector2FP32* vector)
{
    return bgc_vector2_get_square_modulus_fp32(vector) <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_vector2_is_zero_fp64(const BgcVector2FP64* vector)
{
    return bgc_vector2_get_square_modulus_fp64(vector) <= BGC_SQUARE_EPSYLON_FP64;
}

inline int bgc_vector2_is_unit_fp32(const BgcVector2FP32* vector)
{
    return bgc_is_sqare_value_unit_fp32(bgc_vector2_get_square_modulus_fp32(vector));
}

inline int bgc_vector2_is_unit_fp64(const BgcVector2FP64* vector)
{
    return bgc_is_sqare_value_unit_fp64(bgc_vector2_get_square_modulus_fp64(vector));
}

// ==================== Add ===================== //

inline void bgc_vector2_add_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, BgcVector2FP32* sum)
{
    sum->x1 = vector1->x1 + vector2->x1;
    sum->x2 = vector1->x2 + vector2->x2;
}

inline void bgc_vector2_add_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, BgcVector2FP64* sum)
{
    sum->x1 = vector1->x1 + vector2->x1;
    sum->x2 = vector1->x2 + vector2->x2;
}

// ================ Append scaled =============== //

inline void bgc_vector2_add_scaled_fp32(const BgcVector2FP32* basic_vector, const BgcVector2FP32* scalable_vector, const float scale, BgcVector2FP32* sum)
{
    sum->x1 = basic_vector->x1 + scalable_vector->x1 * scale;
    sum->x2 = basic_vector->x2 + scalable_vector->x2 * scale;
}

inline void bgc_vector2_add_scaled_fp64(const BgcVector2FP64* basic_vector, const BgcVector2FP64* scalable_vector, const double scale, BgcVector2FP64* sum)
{
    sum->x1 = basic_vector->x1 + scalable_vector->x1 * scale;
    sum->x2 = basic_vector->x2 + scalable_vector->x2 * scale;
}

// ================ Subtraction ================= //

inline void bgc_vector2_subtract_fp32(const BgcVector2FP32* minuend, const BgcVector2FP32* subtrahend, BgcVector2FP32* difference)
{
    difference->x1 = minuend->x1 - subtrahend->x1;
    difference->x2 = minuend->x2 - subtrahend->x2;
}

inline void bgc_vector2_subtract_fp64(const BgcVector2FP64* minuend, const BgcVector2FP64* subtrahend, BgcVector2FP64* difference)
{
    difference->x1 = minuend->x1 - subtrahend->x1;
    difference->x2 = minuend->x2 - subtrahend->x2;
}

// =============== Multiplication =============== //

inline void bgc_vector2_multiply_fp32(const BgcVector2FP32* multiplicand, const float multiplier, BgcVector2FP32* product)
{
    product->x1 = multiplicand->x1 * multiplier;
    product->x2 = multiplicand->x2 * multiplier;
}

inline void bgc_vector2_multiply_fp64(const BgcVector2FP64* multiplicand, const double multiplier, BgcVector2FP64* product)
{
    product->x1 = multiplicand->x1 * multiplier;
    product->x2 = multiplicand->x2 * multiplier;
}

// ================== Division ================== //

inline void bgc_vector2_divide_fp32(const BgcVector2FP32* dividend, const float divisor, BgcVector2FP32* quotient)
{
    bgc_vector2_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_vector2_divide_fp64(const BgcVector2FP64* dividend, const double divisor, BgcVector2FP64* quotient)
{
    bgc_vector2_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ================== Average2 ================== //

inline void bgc_vector2_mean_of_two_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, BgcVector2FP32* result)
{
    result->x1 = (vector1->x1 + vector2->x1) * 0.5f;
    result->x2 = (vector1->x2 + vector2->x2) * 0.5f;
}

inline void bgc_vector2_mean_of_two_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, BgcVector2FP64* result)
{
    result->x1 = (vector1->x1 + vector2->x1) * 0.5;
    result->x2 = (vector1->x2 + vector2->x2) * 0.5;
}

// ================== Average3 ================== //

inline void bgc_vector2_mean_of_three_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const BgcVector2FP32* vector3, BgcVector2FP32* result)
{
    result->x1 = (vector1->x1 + vector2->x1 + vector3->x1) * BGC_ONE_THIRD_FP32;
    result->x2 = (vector1->x2 + vector2->x2 + vector3->x2) * BGC_ONE_THIRD_FP32;
}

inline void bgc_vector2_mean_of_three_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const BgcVector2FP64* vector3, BgcVector2FP64* result)
{
    result->x1 = (vector1->x1 + vector2->x1 + vector3->x1) * BGC_ONE_THIRD_FP64;
    result->x2 = (vector1->x2 + vector2->x2 + vector3->x2) * BGC_ONE_THIRD_FP64;
}

// =============== Scalar Product =============== //

inline float bgc_vector2_scalar_product_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2)
{
    return vector1->x1 * vector2->x1 + vector1->x2 * vector2->x2;
}

inline double bgc_vector2_scalar_product_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2)
{
    return vector1->x1 * vector2->x1 + vector1->x2 * vector2->x2;
}

// =============== Cross Product ================ //

inline float bgc_vector2_cross_product_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2)
{
    return vector1->x1 * vector2->x2 - vector1->x2 * vector2->x1;
}

inline double bgc_vector2_cross_product_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2)
{
    return vector1->x1 * vector2->x2 - vector1->x2 * vector2->x1;
}

// ============== Complex Product =============== //

inline void bgc_vector2_complex_product_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, BgcVector2FP32* result)
{
    const float x1 = vector1->x1 * vector2->x1 - vector1->x2 * vector2->x2;
    const float x2 = vector1->x1 * vector2->x2 + vector1->x2 * vector2->x1;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_vector2_complex_product_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, BgcVector2FP64* result)
{
    const double x1 = vector1->x1 * vector2->x1 - vector1->x2 * vector2->x2;
    const double x2 = vector1->x1 * vector2->x2 + vector1->x2 * vector2->x1;

    result->x1 = x1;
    result->x2 = x2;
}

// =============== Normalization ================ //

inline int bgc_vector2_normalize_fp32(BgcVector2FP32* vector)
{
    const float square_modulus = bgc_vector2_get_square_modulus_fp32(vector);

    if (bgc_is_sqare_value_unit_fp32(square_modulus)) {
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32) {
        bgc_vector2_reset_fp32(vector);
        return 0;
    }

    bgc_vector2_multiply_fp32(vector, sqrtf(1.0f / square_modulus), vector);
    return 1;
}

inline int bgc_vector2_normalize_fp64(BgcVector2FP64* vector)
{
    const double square_modulus = bgc_vector2_get_square_modulus_fp64(vector);

    if (bgc_is_sqare_value_unit_fp64(square_modulus)) {
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64) {
        bgc_vector2_reset_fp64(vector);
        return 0;
    }

    bgc_vector2_multiply_fp64(vector, sqrt(1.0 / square_modulus), vector);
    return 1;
}

// =============== Get Normalized =============== //

inline int bgc_vector2_set_normalized_fp32(const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    bgc_vector2_copy_fp32(vector, result);
    return bgc_vector2_normalize_fp32(result);
}

inline int bgc_vector2_set_normalized_fp64(const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    bgc_vector2_copy_fp64(vector, result);
    return bgc_vector2_normalize_fp64(result);
}

// =================== Angle ==================== //

float bgc_vector2_get_angle_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const BgcAngleUnitEnum unit);

double bgc_vector2_get_angle_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const BgcAngleUnitEnum unit);

// =============== Square Distance ============== //

inline float bgc_vector2_get_square_distance_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2)
{
    const float dx1 = (vector1->x1 - vector2->x1);
    const float dx2 = (vector1->x2 - vector2->x2);

    return dx1 * dx1 + dx2 * dx2;
}

inline double bgc_vector2_get_square_distance_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2)
{
    const double dx1 = (vector1->x1 - vector2->x1);
    const double dx2 = (vector1->x2 - vector2->x2);

    return dx1 * dx1 + dx2 * dx2;
}

// ================== Distance ================== //

inline float bgc_vector2_get_distance_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2)
{
    return sqrtf(bgc_vector2_get_square_distance_fp32(vector1, vector2));
}

inline double bgc_vector2_get_distance_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2)
{
    return sqrt(bgc_vector2_get_square_distance_fp64(vector1, vector2));
}

// ============== Are Close Enough ============== //

inline int bgc_vector2_are_close_enough_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const float distance)
{
    return bgc_vector2_get_square_distance_fp32(vector1, vector2) <= distance * distance;
}

inline int bgc_vector2_are_close_enough_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const double distance)
{
    return bgc_vector2_get_square_distance_fp64(vector1, vector2) <= distance * distance;
}

// ================== Are Close ================= //

inline int bgc_vector2_are_close_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2)
{
    const float square_modulus1 = bgc_vector2_get_square_modulus_fp32(vector1);
    const float square_modulus2 = bgc_vector2_get_square_modulus_fp32(vector2);
    const float square_distance = bgc_vector2_get_square_distance_fp32(vector1, vector2);

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP32;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

inline int bgc_vector2_are_close_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2)
{
    const double square_modulus1 = bgc_vector2_get_square_modulus_fp64(vector1);
    const double square_modulus2 = bgc_vector2_get_square_modulus_fp64(vector2);
    const double square_distance = bgc_vector2_get_square_distance_fp64(vector1, vector2);

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP64;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

#endif
