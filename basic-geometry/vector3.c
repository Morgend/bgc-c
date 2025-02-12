#include "vector3.h"

extern inline void bgc_vector3_reset_fp32(BgcVector3FP32* vector);
extern inline void bgc_vector3_reset_fp64(BgcVector3FP64* vector);

extern inline void bgc_vector3_set_values_fp32(const float x1, const float x2, const float x3, BgcVector3FP32* to);
extern inline void bgc_vector3_set_values_fp64(const double x1, const double x2, const double x3, BgcVector3FP64* to);

extern inline float bgc_vector3_get_square_modulus_fp32(const BgcVector3FP32* vector);
extern inline double bgc_vector3_get_square_modulus_fp64(const BgcVector3FP64* vector);

extern inline float bgc_vector3_get_modulus_fp32(const BgcVector3FP32* vector);
extern inline double bgc_vector3_get_modulus_fp64(const BgcVector3FP64* vector);

extern inline int bgc_vector3_is_zero_fp32(const BgcVector3FP32* vector);
extern inline int bgc_vector3_is_zero_fp64(const BgcVector3FP64* vector);

extern inline int bgc_vector3_is_unit_fp32(const BgcVector3FP32* vector);
extern inline int bgc_vector3_is_unit_fp64(const BgcVector3FP64* vector);

extern inline void bgc_vector3_copy_fp32(const BgcVector3FP32* from, BgcVector3FP32* to);
extern inline void bgc_vector3_copy_fp64(const BgcVector3FP64* from, BgcVector3FP64* to);

extern inline void bgc_vector3_convert_fp64_to_fp32(const BgcVector3FP64* from, BgcVector3FP32* to);
extern inline void bgc_vector3_convert_fp32_to_fp64(const BgcVector3FP32* from, BgcVector3FP64* to);

extern inline void bgc_vector3_swap_fp32(BgcVector3FP32* vector1, BgcVector3FP32* vector2);
extern inline void bgc_vector3_swap_fp64(BgcVector3FP64* vector1, BgcVector3FP64* vector2);

extern inline void bgc_vector3_reverse_fp32(BgcVector3FP32* vector);
extern inline void bgc_vector3_reverse_fp64(BgcVector3FP64* vector);

extern inline int bgc_vector3_normalize_fp32(BgcVector3FP32* vector);
extern inline int bgc_vector3_normalize_fp64(BgcVector3FP64* vector);

extern inline void bgc_vector3_make_reverse_fp32(const BgcVector3FP32* vector, BgcVector3FP32* reverse);
extern inline void bgc_vector3_make_reverse_fp64(const BgcVector3FP64* vector, BgcVector3FP64* reverse);

extern inline int bgc_vector3_make_normalized_fp32(const BgcVector3FP32* vector, BgcVector3FP32* normalized);
extern inline int bgc_vector3_make_normalized_fp64(const BgcVector3FP64* vector, BgcVector3FP64* normalized);

extern inline void bgc_vector3_add_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, BgcVector3FP32* sum);
extern inline void bgc_vector3_add_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, BgcVector3FP64* sum);

extern inline void bgc_vector3_add_scaled_fp32(const BgcVector3FP32* basic_vector, const BgcVector3FP32* scalable_vector, const float scale, BgcVector3FP32* sum);
extern inline void bgc_vector3_add_scaled_fp64(const BgcVector3FP64* basic_vector, const BgcVector3FP64* scalable_vector, const double scale, BgcVector3FP64* sum);

extern inline void bgc_vector3_subtract_fp32(const BgcVector3FP32* minuend, const BgcVector3FP32* subtrahend, BgcVector3FP32* difference);
extern inline void bgc_vector3_subtract_fp64(const BgcVector3FP64* minuend, const BgcVector3FP64* subtrahend, BgcVector3FP64* difference);

extern inline void bgc_vector3_subtract_scaled_fp32(const BgcVector3FP32* basic_vector, const BgcVector3FP32* scalable_vector, const float scale, BgcVector3FP32* difference);
extern inline void bgc_vector3_subtract_scaled_fp64(const BgcVector3FP64* basic_vector, const BgcVector3FP64* scalable_vector, const double scale, BgcVector3FP64* difference);

extern inline void bgc_vector3_multiply_fp32(const BgcVector3FP32* multiplicand, const float multiplier, BgcVector3FP32* product);
extern inline void bgc_vector3_multiply_fp64(const BgcVector3FP64* multiplicand, const double multiplier, BgcVector3FP64* product);

extern inline void bgc_vector3_divide_fp32(const BgcVector3FP32* dividend, const float divisor, BgcVector3FP32* quotient);
extern inline void bgc_vector3_divide_fp64(const BgcVector3FP64* dividend, const double divisor, BgcVector3FP64* quotient);

extern inline void bgc_vector3_mean_of_two_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, BgcVector3FP32* result);
extern inline void bgc_vector3_mean_of_two_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, BgcVector3FP64* result);

extern inline void bgc_vector3_mean_of_three_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcVector3FP32* vector3, BgcVector3FP32* result);
extern inline void bgc_vector3_mean_of_three_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcVector3FP64* vector3, BgcVector3FP64* result);

extern inline float bgc_vector3_scalar_product_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2);
extern inline double bgc_vector3_scalar_product_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2);

extern inline float bgc_vector3_triple_product_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcVector3FP32* vector3);
extern inline double bgc_vector3_triple_product_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcVector3FP64* vector3);

extern inline void bgc_vector3_cross_product_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, BgcVector3FP32* result);
extern inline void bgc_vector3_cross_product_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, BgcVector3FP64* result);

extern inline void bgc_vector3_double_cross_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcVector3FP32* vector3, BgcVector3FP32* result);
extern inline void bgc_vector3_double_cross_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcVector3FP64* vector3, BgcVector3FP64* result);

extern inline float bgc_vector3_get_square_distance_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2);
extern inline double bgc_vector3_get_square_distance_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2);

extern inline float bgc_vector3_get_distance_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2);
extern inline double bgc_vector3_get_distance_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2);

extern inline int bgc_vector3_are_close_enough_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const float distance);
extern inline int bgc_vector3_are_close_enough_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const double distance);

extern inline int bgc_vector3_are_close_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2);
extern inline int bgc_vector3_are_close_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2);

// =================== Angle ==================== //

float bgc_vector3_get_angle_fp32(const BgcVector3FP32* vector1, const BgcVector3FP32* vector2, const BgcAngleUnitEnum unit)
{
    const float square_modulus1 = bgc_vector3_get_square_modulus_fp32(vector1);

    if (square_modulus1 <= BGC_SQUARE_EPSYLON_FP32) {
        return 0.0f;
    }

    const float square_modulus2 = bgc_vector3_get_square_modulus_fp32(vector2);

    if (square_modulus2 <= BGC_SQUARE_EPSYLON_FP32) {
        return 0.0f;
    }

    const float cosine = bgc_vector3_scalar_product_fp32(vector1, vector2) / sqrtf(square_modulus1 * square_modulus2);

    if (cosine >= 1.0f - BGC_EPSYLON_FP32) {
        return 0.0f;
    }

    if (cosine <= -1.0f + BGC_EPSYLON_FP32) {
        return bgc_angle_get_half_circle_fp32(unit);
    }

    return bgc_radians_to_units_fp32(acosf(cosine), unit);
}

double bgc_vector3_get_angle_fp64(const BgcVector3FP64* vector1, const BgcVector3FP64* vector2, const BgcAngleUnitEnum unit)
{
    const double square_modulus1 = bgc_vector3_get_square_modulus_fp64(vector1);

    if (square_modulus1 <= BGC_SQUARE_EPSYLON_FP64) {
        return 0.0;
    }

    const double square_modulus2 = bgc_vector3_get_square_modulus_fp64(vector2);

    if (square_modulus2 <= BGC_SQUARE_EPSYLON_FP64) {
        return 0.0;
    }

    const double cosine = bgc_vector3_scalar_product_fp64(vector1, vector2) / sqrt(square_modulus1 * square_modulus2);

    if (cosine >= 1.0 - BGC_EPSYLON_FP64) {
        return 0.0;
    }

    if (cosine <= -1.0 + BGC_EPSYLON_FP64) {
        return bgc_angle_get_half_circle_fp64(unit);
    }

    return bgc_radians_to_units_fp64(acos(cosine), unit);
}
