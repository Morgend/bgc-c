#include "vector2.h"

extern inline void bgc_vector2_reset_fp32(BgcVector2FP32* vector);
extern inline void bgc_vector2_reset_fp64(BgcVector2FP64* vector);

extern inline void bgc_vector2_set_values_fp32(const float x1, const float x2, BgcVector2FP32* destination);
extern inline void bgc_vector2_set_values_fp64(const double x1, const double x2, BgcVector2FP64* destination);

extern inline float bgc_vector2_get_square_modulus_fp32(const BgcVector2FP32* vector);
extern inline double bgc_vector2_get_square_modulus_fp64(const BgcVector2FP64* vector);

extern inline float bgc_vector2_get_modulus_fp32(const BgcVector2FP32* vector);
extern inline double bgc_vector2_get_modulus_fp64(const BgcVector2FP64* vector);

extern inline int bgc_vector2_is_zero_fp32(const BgcVector2FP32* vector);
extern inline int bgc_vector2_is_zero_fp64(const BgcVector2FP64* vector);

extern inline int bgc_vector2_is_unit_fp32(const BgcVector2FP32* vector);
extern inline int bgc_vector2_is_unit_fp64(const BgcVector2FP64* vector);

extern inline void bgc_vector2_copy_fp32(const BgcVector2FP32* source, BgcVector2FP32* destination);
extern inline void bgc_vector2_copy_fp64(const BgcVector2FP64* source, BgcVector2FP64* destination);

extern inline void bgc_vector2_swap_fp32(BgcVector2FP32* vector1, BgcVector2FP32* vector2);
extern inline void bgc_vector2_swap_fp64(BgcVector2FP64* vector1, BgcVector2FP64* vector2);

extern inline void bgc_vector2_convert_fp64_to_fp32(const BgcVector2FP64* source, BgcVector2FP32* destination);
extern inline void bgc_vector2_convert_fp32_to_fp64(const BgcVector2FP32* source, BgcVector2FP64* destination);

extern inline void bgc_vector2_reverse_fp32(const BgcVector2FP32* vector, BgcVector2FP32* reverse);
extern inline void bgc_vector2_reverse_fp64(const BgcVector2FP64* vector, BgcVector2FP64* reverse);

extern inline int bgc_vector2_normalize_fp32(const BgcVector2FP32* vector, BgcVector2FP32* normalized);
extern inline int bgc_vector2_normalize_fp64(const BgcVector2FP64* vector, BgcVector2FP64* normalized);

extern inline void bgc_vector2_add_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, BgcVector2FP32* sum);
extern inline void bgc_vector2_add_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, BgcVector2FP64* sum);

extern inline void bgc_vector2_add_scaled_fp32(const BgcVector2FP32* basic_vector, const BgcVector2FP32* scalable_vector, const float scale, BgcVector2FP32* sum);
extern inline void bgc_vector2_add_scaled_fp64(const BgcVector2FP64* basic_vector, const BgcVector2FP64* scalable_vector, const double scale, BgcVector2FP64* sum);

extern inline void bgc_vector2_subtract_fp32(const BgcVector2FP32* minuend, const BgcVector2FP32* subtrahend, BgcVector2FP32* difference);
extern inline void bgc_vector2_subtract_fp64(const BgcVector2FP64* minuend, const BgcVector2FP64* subtrahend, BgcVector2FP64* difference);

extern inline void bgc_vector2_subtract_scaled_fp32(const BgcVector2FP32* basic_vector, const BgcVector2FP32* scalable_vector, const float scale, BgcVector2FP32* difference);
extern inline void bgc_vector2_subtract_scaled_fp64(const BgcVector2FP64* basic_vector, const BgcVector2FP64* scalable_vector, const double scale, BgcVector2FP64* difference);

extern inline void bgc_vector2_multiply_fp32(const BgcVector2FP32* multiplicand, const float multiplier, BgcVector2FP32* product);
extern inline void bgc_vector2_multiply_fp64(const BgcVector2FP64* multiplicand, const double multiplier, BgcVector2FP64* product);

extern inline void bgc_vector2_divide_fp32(const BgcVector2FP32* dividend, const float divisor, BgcVector2FP32* quotient);
extern inline void bgc_vector2_divide_fp64(const BgcVector2FP64* dividend, const double divisor, BgcVector2FP64* quotient);

extern inline void bgc_vector2_get_mean_of_two_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, BgcVector2FP32* mean);
extern inline void bgc_vector2_get_mean_of_two_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, BgcVector2FP64* mean);

extern inline void bgc_vector2_get_mean_of_three_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const BgcVector2FP32* vector3, BgcVector2FP32* mean);
extern inline void bgc_vector2_get_mean_of_three_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const BgcVector2FP64* vector3, BgcVector2FP64* mean);

extern inline void bgc_vector2_get_linear_interpolation_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const float phase, BgcVector2FP32* interpolation);
extern inline void bgc_vector2_get_linear_interpolation_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const double phase, BgcVector2FP64* interpolation);

extern inline void bgc_vector2_minimize_fp32(const BgcVector2FP32* vector, BgcVector2FP32* minimal);
extern inline void bgc_vector2_minimize_fp64(const BgcVector2FP64* vector, BgcVector2FP64* minimal);

extern inline void bgc_vector2_maximize_fp32(const BgcVector2FP32* vector, BgcVector2FP32* maximal);
extern inline void bgc_vector2_maximize_fp64(const BgcVector2FP64* vector, BgcVector2FP64* maximal);

extern inline float bgc_vector2_get_scalar_product_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2);
extern inline double bgc_vector2_get_scalar_product_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2);

extern inline float bgc_vector2_get_cross_product_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2);
extern inline double bgc_vector2_get_cross_product_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2);

extern inline float bgc_vector2_get_square_distance_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2);
extern inline double bgc_vector2_get_square_distance_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2);

extern inline float bgc_vector2_get_distance_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2);
extern inline double bgc_vector2_get_distance_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2);

extern inline int bgc_vector2_are_close_enough_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const float distance);
extern inline int bgc_vector2_are_close_enough_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const double distance);

extern inline int bgc_vector2_are_close_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2);
extern inline int bgc_vector2_are_close_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2);

// =================== Angle ==================== //

float bgc_vector2_get_angle_fp32(const BgcVector2FP32* vector1, const BgcVector2FP32* vector2, const BgcAngleUnitEnum unit)
{
    const float square_modulus1 = bgc_vector2_get_square_modulus_fp32(vector1);

    if (square_modulus1 <= BGC_SQUARE_EPSYLON_FP32) {
        return 0.0f;
    }

    const float square_modulus2 = bgc_vector2_get_square_modulus_fp32(vector2);

    if (square_modulus2 <= BGC_SQUARE_EPSYLON_FP32) {
        return 0.0f;
    }

    const float cosine = bgc_vector2_get_scalar_product_fp32(vector1, vector2) / sqrtf(square_modulus1 * square_modulus2);

    if (cosine >= 1.0f - BGC_EPSYLON_FP32) {
        return 0.0f;
    }

    if (cosine <= -1.0f + BGC_EPSYLON_FP32) {
        return bgc_angle_get_half_circle_fp32(unit);
    }

    return bgc_radians_to_units_fp32(acosf(cosine), unit);
}

double bgc_vector2_get_angle_fp64(const BgcVector2FP64* vector1, const BgcVector2FP64* vector2, const BgcAngleUnitEnum unit)
{
    const double square_modulus1 = bgc_vector2_get_square_modulus_fp64(vector1);

    if (square_modulus1 <= BGC_SQUARE_EPSYLON_FP64) {
        return 0.0;
    }

    const double square_modulus2 = bgc_vector2_get_square_modulus_fp64(vector2);

    if (square_modulus2 <= BGC_SQUARE_EPSYLON_FP64) {
        return 0.0;
    }

    const double cosine = bgc_vector2_get_scalar_product_fp64(vector1, vector2) / sqrt(square_modulus1 * square_modulus2);

    if (cosine >= 1.0 - BGC_EPSYLON_FP64) {
        return 0.0;
    }

    if (cosine <= -1.0 + BGC_EPSYLON_FP64) {
        return bgc_angle_get_half_circle_fp64(unit);
    }

    return bgc_radians_to_units_fp64(acos(cosine), unit);
}
