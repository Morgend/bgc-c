#ifndef _BGC_COTES_NUMBER_H_
#define _BGC_COTES_NUMBER_H_

#include <math.h>

#include "utilities.h"
#include "angle.h"
#include "vector2.h"
#include "matrix2x2.h"

// =================== Types ==================== //

typedef struct
{
    const float cos, sin;
} BgcCotesNumberFP32;

typedef struct
{
    const double cos, sin;
} BgcCotesNumberFP64;

// ================= Dark Twins ================= //

typedef struct {
    float cos, sin;
} _BgcTwinCotesNumberFP32;

typedef struct {
    double cos, sin;
} _BgcTwinCotesNumberFP64;

// ================= Constants ================== //

extern const BgcCotesNumberFP32 BGC_IDLE_COTES_NUMBER_FP32;
extern const BgcCotesNumberFP64 BGC_IDLE_COTES_NUMBER_FP64;

// =================== Reset ==================== //

inline void bgc_cotes_number_reset_fp32(BgcCotesNumberFP32* number)
{
    _BgcTwinCotesNumberFP32* twin = (_BgcTwinCotesNumberFP32*)number;

    twin->cos = 1.0f;
    twin->sin = 0.0f;
}

inline void bgc_cotes_number_reset_fp64(BgcCotesNumberFP64* number)
{
    _BgcTwinCotesNumberFP64* twin = (_BgcTwinCotesNumberFP64*)number;

    twin->cos = 1.0;
    twin->sin = 0.0;
}

// ==================== Set ===================== //

void _bgc_cotes_number_normalize_fp32(const float square_modulus, _BgcTwinCotesNumberFP32* twin);

void _bgc_cotes_number_normalize_fp64(const double square_modulus, _BgcTwinCotesNumberFP64* twin);

inline void bgc_cotes_number_set_values_fp32(const float x1, const float x2, BgcCotesNumberFP32* number)
{
    const float square_modulus = x1 * x1 + x2 * x2;

    _BgcTwinCotesNumberFP32* twin = (_BgcTwinCotesNumberFP32*)number;

    twin->cos = x1;
    twin->sin = x2;

    if (!bgc_is_sqare_unit_fp32(square_modulus)) {
        _bgc_cotes_number_normalize_fp32(square_modulus, twin);
    }
}

inline void bgc_cotes_number_set_values_fp64(const double x1, const double x2, BgcCotesNumberFP64* number)
{
    const double square_modulus = x1 * x1 + x2 * x2;

    _BgcTwinCotesNumberFP64* twin = (_BgcTwinCotesNumberFP64*)number;

    twin->cos = x1;
    twin->sin = x2;

    if (!bgc_is_sqare_unit_fp64(square_modulus)) {
        _bgc_cotes_number_normalize_fp64(square_modulus, twin);
    }
}

// ================== Set Turn ================== //

inline void bgc_cotes_number_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcCotesNumberFP32* number)
{
    const float radians = bgc_angle_to_radians_fp32(angle, unit);

    _BgcTwinCotesNumberFP32* twin = (_BgcTwinCotesNumberFP32*)number;

    twin->cos = cosf(radians);
    twin->sin = sinf(radians);
}

inline void bgc_cotes_number_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcCotesNumberFP64* number)
{
    const double radians = bgc_angle_to_radians_fp64(angle, unit);

    _BgcTwinCotesNumberFP64* twin = (_BgcTwinCotesNumberFP64*)number;

    twin->cos = cos(radians);
    twin->sin = sin(radians);
}

// =================== Angle =================== //

inline float bgc_cotes_number_get_angle_fp32(const BgcCotesNumberFP32* number, const BgcAngleUnitEnum unit)
{
    if (number->cos >= 1.0f - BGC_EPSYLON_FP32) {
        return 0.0f;
    }

    if (number->cos <= -1.0f + BGC_EPSYLON_FP32) {
        return bgc_angle_get_half_circle_fp32(unit);
    }

    if (number->sin >= 1.0f - BGC_EPSYLON_FP32) {
        return bgc_angle_get_quater_circle_fp32(unit);
    }

    if (number->sin <= -1.0f + BGC_EPSYLON_FP32) {
        return 0.75f * bgc_angle_get_full_circle_fp32(unit);
    }

    return bgc_radians_to_units_fp32(atan2f(number->sin, number->cos), unit);
}

inline double bgc_cotes_number_get_angle_fp64(const BgcCotesNumberFP64* number, const BgcAngleUnitEnum unit)
{
    if (number->cos >= 1.0 - BGC_EPSYLON_FP64) {
        return 0.0;
    }

    if (number->cos <= -1.0 + BGC_EPSYLON_FP64) {
        return bgc_angle_get_half_circle_fp64(unit);
    }

    if (number->sin >= 1.0 - BGC_EPSYLON_FP64) {
        return bgc_angle_get_quater_circle_fp64(unit);
    }

    if (number->sin <= -1.0 + BGC_EPSYLON_FP64) {
        return 0.75 * bgc_angle_get_full_circle_fp64(unit);
    }

    return bgc_radians_to_units_fp64(atan2(number->sin, number->cos), unit);
}

// ==================== Copy ==================== //

inline void bgc_cotes_number_copy_fp32(const BgcCotesNumberFP32* source, BgcCotesNumberFP32* destination)
{
    _BgcTwinCotesNumberFP32* twin = (_BgcTwinCotesNumberFP32*)destination;

    twin->cos = source->cos;
    twin->sin = source->sin;
}

inline void bgc_cotes_number_copy_fp64(const BgcCotesNumberFP64* source, BgcCotesNumberFP64* destination)
{
    _BgcTwinCotesNumberFP64* twin = (_BgcTwinCotesNumberFP64*)destination;

    twin->cos = source->cos;
    twin->sin = source->sin;
}

// ==================== Swap ==================== //

inline void bgc_cotes_number_swap_fp32(BgcCotesNumberFP32* number1, BgcCotesNumberFP32* number2)
{
    const float cos = number1->cos;
    const float sin = number1->sin;

    _BgcTwinCotesNumberFP32* twin1 = (_BgcTwinCotesNumberFP32*)number1;

    twin1->cos = number2->cos;
    twin1->sin = number2->sin;

    _BgcTwinCotesNumberFP32* twin2 = (_BgcTwinCotesNumberFP32*)number2;

    twin2->cos = cos;
    twin2->sin = sin;
}

inline void bgc_cotes_number_swap_fp64(BgcCotesNumberFP64* number1, BgcCotesNumberFP64* number2)
{
    const double cos = number1->cos;
    const double sin = number1->sin;

    _BgcTwinCotesNumberFP64* twin1 = (_BgcTwinCotesNumberFP64*)number1;

    twin1->cos = number2->cos;
    twin1->sin = number2->sin;

    _BgcTwinCotesNumberFP64* twin2 = (_BgcTwinCotesNumberFP64*)number2;

    twin2->cos = cos;
    twin2->sin = sin;
}

// ================== Convert =================== //

inline void bgc_cotes_number_convert_fp64_to_fp32(const BgcCotesNumberFP64* source, BgcCotesNumberFP32* destination)
{
    bgc_cotes_number_set_values_fp32((float)source->cos, (float)source->sin, destination);
}

inline void bgc_cotes_number_convert_fp32_to_fp64(const BgcCotesNumberFP32* source, BgcCotesNumberFP64* destination)
{
    bgc_cotes_number_set_values_fp64((double)source->cos, (double)source->sin, destination);
}

// =================== Invert =================== //

inline void bgc_cotes_number_invert_fp32(const BgcCotesNumberFP32* number, BgcCotesNumberFP32* inverted)
{
    _BgcTwinCotesNumberFP32* twin = (_BgcTwinCotesNumberFP32*)inverted;

    twin->cos = number->cos;
    twin->sin = -number->sin;
}

inline void bgc_cotes_number_invert_fp64(const BgcCotesNumberFP64* number, BgcCotesNumberFP64* inverted)
{
    _BgcTwinCotesNumberFP64* twin = (_BgcTwinCotesNumberFP64*)inverted;

    twin->cos = number->cos;
    twin->sin = -number->sin;
}

// ================= Exponation ================= //

inline void bgc_cotes_number_get_exponation_fp32(const BgcCotesNumberFP32* base, const float exponent, BgcCotesNumberFP32* power)
{
    const float power_angle = exponent * atan2f(base->sin, base->cos);

    _BgcTwinCotesNumberFP32* twin = (_BgcTwinCotesNumberFP32*)power;

    twin->cos = cosf(power_angle);
    twin->sin = sinf(power_angle);
}

inline void bgc_cotes_number_get_exponation_fp64(const BgcCotesNumberFP64* base, const double exponent, BgcCotesNumberFP64* power)
{
    const double power_angle = exponent * atan2(base->sin, base->cos);

    _BgcTwinCotesNumberFP64* twin = (_BgcTwinCotesNumberFP64*)power;

    twin->cos = cos(power_angle);
    twin->sin = sin(power_angle);
}

// ================ Combination ================= //

inline void bgc_cotes_number_combine_fp32(const BgcCotesNumberFP32* number1, const BgcCotesNumberFP32* number2, BgcCotesNumberFP32* result)
{
    bgc_cotes_number_set_values_fp32(
        number1->cos * number2->cos - number1->sin * number2->sin,
        number1->cos * number2->sin + number1->sin * number2->cos,
        result
    );
}

inline void bgc_cotes_number_combine_fp64(const BgcCotesNumberFP64* number1, const BgcCotesNumberFP64* number2, BgcCotesNumberFP64* result)
{
    bgc_cotes_number_set_values_fp64(
        number1->cos * number2->cos - number1->sin * number2->sin,
        number1->cos * number2->sin + number1->sin * number2->cos,
        result
    );
}

// ============== Rotation Matrix =============== //

inline void bgc_cotes_number_get_rotation_matrix_fp32(const BgcCotesNumberFP32* number, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = number->cos;
    matrix->r1c2 = -number->sin;
    matrix->r2c1 = number->sin;
    matrix->r2c2 = number->cos;
}

inline void bgc_cotes_number_get_rotation_matrix_fp64(const BgcCotesNumberFP64* number, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = number->cos;
    matrix->r1c2 = -number->sin;
    matrix->r2c1 = number->sin;
    matrix->r2c2 = number->cos;
}

// ============== Reverse Matrix ================ //

inline void bgc_cotes_number_get_reverse_matrix_fp32(const BgcCotesNumberFP32* number, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = number->cos;
    matrix->r1c2 = number->sin;
    matrix->r2c1 = -number->sin;
    matrix->r2c2 = number->cos;
}

inline void bgc_cotes_number_get_reverse_matrix_fp64(const BgcCotesNumberFP64* number, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = number->cos;
    matrix->r1c2 = number->sin;
    matrix->r2c1 = -number->sin;
    matrix->r2c2 = number->cos;
}

// ================ Turn Vector ================= //

inline void bgc_cotes_number_turn_vector_fp32(const BgcCotesNumberFP32* number, const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    const float x1 = number->cos * vector->x1 - number->sin * vector->x2;
    const float x2 = number->sin * vector->x1 + number->cos * vector->x2;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_cotes_number_turn_vector_fp64(const BgcCotesNumberFP64* number, const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    const double x1 = number->cos * vector->x1 - number->sin * vector->x2;
    const double x2 = number->sin * vector->x1 + number->cos * vector->x2;

    result->x1 = x1;
    result->x2 = x2;
}

// ============ Turn Vector Backward ============ //

inline void bgc_cotes_number_turn_vector_back_fp32(const BgcCotesNumberFP32* number, const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    const float x1 = number->sin * vector->x2 + number->cos * vector->x1;
    const float x2 = number->cos * vector->x2 - number->sin * vector->x1;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_cotes_number_turn_vector_back_fp64(const BgcCotesNumberFP64* number, const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    const double x1 = number->sin * vector->x2 + number->cos * vector->x1;
    const double x2 = number->cos * vector->x2 - number->sin * vector->x1;

    result->x1 = x1;
    result->x2 = x2;
}

// ================== Are Close ================= //

inline int bgc_cotes_number_are_close_fp32(const BgcCotesNumberFP32* number1, const BgcCotesNumberFP32* number2)
{
    const float d_cos = number1->cos - number2->cos;
    const float d_sin = number1->sin - number2->sin;

    return d_cos * d_cos + d_sin * d_sin <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_cotes_number_are_close_fp64(const BgcCotesNumberFP64* number1, const BgcCotesNumberFP64* number2)
{
    const double d_cos = number1->cos - number2->cos;
    const double d_sin = number1->sin - number2->sin;

    return d_cos * d_cos + d_sin * d_sin <= BGC_SQUARE_EPSYLON_FP64;
}

#endif
