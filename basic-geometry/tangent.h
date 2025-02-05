#ifndef _BGC_TANGENT_H_
#define _BGC_TANGENT_H_

#include <math.h>

#include "utilities.h"
#include "angle.h"
#include "vector2.h"
#include "matrix2x2.h"

// =================== Types ==================== //

typedef struct
{
    const float cos, sin;
} BgcTangentFP32;

typedef struct
{
    const double cos, sin;
} BgcTangentFP64;

// ================= Dark Twins ================= //

typedef struct {
    float cos, sin;
} _BgcDarkTwinTangentFP32;

typedef struct {
    double cos, sin;
} _BgcDarkTwinTangentFP64;

// ================= Constants ================== //

extern const BgcTangentFP32 BGC_IDLE_TANGENT_FP32;
extern const BgcTangentFP64 BGC_IDLE_TANGENT_FP64;

// =================== Reset ==================== //

inline void bgc_tangent_reset_fp32(BgcTangentFP32* tangent)
{
    _BgcDarkTwinTangentFP32* twin = (_BgcDarkTwinTangentFP32*)tangent;

    twin->cos = 1.0f;
    twin->sin = 0.0f;
}

inline void bgc_tangent_reset_fp64(BgcTangentFP64* tangent)
{
    _BgcDarkTwinTangentFP64* twin = (_BgcDarkTwinTangentFP64*)tangent;

    twin->cos = 1.0;
    twin->sin = 0.0;
}

// ==================== Set ===================== //

void _bgc_tangent_normalize_fp32(const float square_modulus, _BgcDarkTwinTangentFP32* twin);

void _bgc_tangent_normalize_fp64(const double square_modulus, _BgcDarkTwinTangentFP64* twin);

inline void bgc_tangent_set_values_fp32(const float x1, const float x2, BgcTangentFP32* tangent)
{
    const float square_modulus = x1 * x1 + x2 * x2;

    _BgcDarkTwinTangentFP32* twin = (_BgcDarkTwinTangentFP32*)tangent;

    twin->cos = x1;
    twin->sin = x2;

    if (!bgc_is_sqare_value_unit_fp32(square_modulus)) {
        _bgc_tangent_normalize_fp32(square_modulus, twin);
    }
}

inline void bgc_tangent_set_values_fp64(const double x1, const double x2, BgcTangentFP64* tangent)
{
    const double square_modulus = x1 * x1 + x2 * x2;

    _BgcDarkTwinTangentFP64* twin = (_BgcDarkTwinTangentFP64*)tangent;

    twin->cos = x1;
    twin->sin = x2;

    if (!bgc_is_sqare_value_unit_fp64(square_modulus)) {
        _bgc_tangent_normalize_fp64(square_modulus, twin);
    }
}

// ==================== Copy ==================== //

inline void bgc_tangent_copy_fp32(const BgcTangentFP32* from, BgcTangentFP32* to)
{
    _BgcDarkTwinTangentFP32* twin = (_BgcDarkTwinTangentFP32*)to;

    twin->cos = from->cos;
    twin->sin = from->sin;
}

inline void bgc_tangent_copy_fp64(const BgcTangentFP64* from, BgcTangentFP64* to)
{
    _BgcDarkTwinTangentFP64* twin = (_BgcDarkTwinTangentFP64*)to;

    twin->cos = from->cos;
    twin->sin = from->sin;
}

// ==================== Swap ==================== //

inline void bgc_tangent_swap_fp32(BgcTangentFP32* tangent1, BgcTangentFP32* tangent2)
{
    const float cos = tangent1->cos;
    const float sin = tangent1->sin;

    _BgcDarkTwinTangentFP32* twin1 = (_BgcDarkTwinTangentFP32*)tangent1;

    twin1->cos = tangent2->cos;
    twin1->sin = tangent2->sin;

    _BgcDarkTwinTangentFP32* twin2 = (_BgcDarkTwinTangentFP32*)tangent2;

    twin2->cos = cos;
    twin2->sin = sin;
}

inline void bgc_tangent_swap_fp64(BgcTangentFP64* tangent1, BgcTangentFP64* tangent2)
{
    const double cos = tangent1->cos;
    const double sin = tangent1->sin;

    _BgcDarkTwinTangentFP64* twin1 = (_BgcDarkTwinTangentFP64*)tangent1;

    twin1->cos = tangent2->cos;
    twin1->sin = tangent2->sin;

    _BgcDarkTwinTangentFP64* twin2 = (_BgcDarkTwinTangentFP64*)tangent2;

    twin2->cos = cos;
    twin2->sin = sin;
}

// ================== Set Turn ================== //

inline void bgc_tangent_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcTangentFP32* tangent)
{
    const float radians = bgc_angle_to_radians_fp32(angle, unit);

    _BgcDarkTwinTangentFP32* twin = (_BgcDarkTwinTangentFP32*)tangent;

    twin->cos = cosf(radians);
    twin->sin = sinf(radians);
}

inline void bgc_tangent_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcTangentFP64* tangent)
{
    const double radians = bgc_angle_to_radians_fp64(angle, unit);

    _BgcDarkTwinTangentFP64* twin = (_BgcDarkTwinTangentFP64*)tangent;

    twin->cos = cos(radians);
    twin->sin = sin(radians);
}

// ============= Copy to twin type ============== //

inline void bgc_tangent_convert_fp64_to_fp32(const BgcTangentFP64* from, BgcTangentFP32* to)
{
    bgc_tangent_set_values_fp32((float)from->cos, (float)from->sin, to);
}

inline void bgc_tangent_convert_fp32_to_fp64(const BgcTangentFP32* from, BgcTangentFP64* to)
{
    bgc_tangent_set_values_fp64((double)from->cos, (double)from->sin, to);
}

// ================= Inversion ================== //

inline void bgc_tangent_invert_fp32(BgcTangentFP32* tangent)
{
    ((_BgcDarkTwinTangentFP32*)tangent)->sin = -tangent->sin;
}

inline void bgc_tangent_invert_fp64(BgcTangentFP64* tangent)
{
    ((_BgcDarkTwinTangentFP64*)tangent)->sin = -tangent->sin;
}

// ================ Set Inverted ================ //

inline void bgc_tangent_set_inverted_fp32(const BgcTangentFP32* tangent, BgcTangentFP32* result)
{
    _BgcDarkTwinTangentFP32* twin = (_BgcDarkTwinTangentFP32*)result;

    twin->cos = tangent->cos;
    twin->sin = -tangent->sin;
}

inline void bgc_tangent_set_inverted_fp64(const BgcTangentFP64* tangent, BgcTangentFP64* result)
{
    _BgcDarkTwinTangentFP64* twin = (_BgcDarkTwinTangentFP64*)result;

    twin->cos = tangent->cos;
    twin->sin = -tangent->sin;
}

// ============== Rotation Matrix =============== //

inline void bgc_tangent_make_rotation_matrix_fp32(const BgcTangentFP32* tangent, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = -tangent->sin;
    matrix->r2c1 = tangent->sin;
    matrix->r2c2 = tangent->cos;
}

inline void bgc_tangent_make_rotation_matrix_fp64(const BgcTangentFP64* tangent, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = -tangent->sin;
    matrix->r2c1 = tangent->sin;
    matrix->r2c2 = tangent->cos;
}

// ============== Reverse Matrix ================ //

inline void bgc_tangent_make_reverse_matrix_fp32(const BgcTangentFP32* tangent, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = tangent->sin;
    matrix->r2c1 = -tangent->sin;
    matrix->r2c2 = tangent->cos;
}

inline void bgc_tangent_make_reverse_matrix_fp64(const BgcTangentFP64* tangent, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = tangent->sin;
    matrix->r2c1 = -tangent->sin;
    matrix->r2c2 = tangent->cos;
}

// =================== Angle =================== //

inline float bgc_tangent_get_angle_fp32(const BgcTangentFP32* tangent, const BgcAngleUnitEnum unit)
{
    if (tangent->cos >= 1.0f - BGC_EPSYLON_FP32) {
        return 0.0f;
    }

    if (tangent->cos <= -1.0f + BGC_EPSYLON_FP32) {
        return bgc_angle_get_half_circle_fp32(unit);
    }

    if (tangent->sin >= 1.0f - BGC_EPSYLON_FP32) {
        return bgc_angle_get_quater_circle_fp32(unit);
    }

    if (tangent->sin <= -1.0f + BGC_EPSYLON_FP32) {
        return 0.75f * bgc_angle_get_full_circle_fp32(unit);
    }

    return bgc_radians_to_units_fp32(atan2f(tangent->cos, tangent->sin), unit);
}

inline double bgc_tangent_get_angle_fp64(const BgcTangentFP64* tangent, const BgcAngleUnitEnum unit)
{
    if (tangent->cos >= 1.0 - BGC_EPSYLON_FP64) {
        return 0.0;
    }

    if (tangent->cos <= -1.0 + BGC_EPSYLON_FP64) {
        return bgc_angle_get_half_circle_fp64(unit);
    }

    if (tangent->sin >= 1.0 - BGC_EPSYLON_FP64) {
        return bgc_angle_get_quater_circle_fp64(unit);
    }

    if (tangent->sin <= -1.0 + BGC_EPSYLON_FP64) {
        return 0.75 * bgc_angle_get_full_circle_fp64(unit);
    }

    return bgc_radians_to_units_fp64(atan2(tangent->cos, tangent->sin), unit);
}

// ================ Combination ================= //

inline void bgc_tangent_combine_fp32(const BgcTangentFP32* tangent1, const BgcTangentFP32* tangent2, BgcTangentFP32* result)
{
    bgc_tangent_set_values_fp32(
        tangent1->cos * tangent2->cos - tangent1->sin * tangent2->sin,
        tangent1->cos * tangent2->sin + tangent1->sin * tangent2->cos,
        result
    );
}

inline void bgc_tangent_combine_fp64(const BgcTangentFP64* tangent1, const BgcTangentFP64* tangent2, BgcTangentFP64* result)
{
    bgc_tangent_set_values_fp64(
        tangent1->cos * tangent2->cos - tangent1->sin * tangent2->sin,
        tangent1->cos * tangent2->sin + tangent1->sin * tangent2->cos,
        result
    );
}

// ================ Turn Vector ================= //

inline void bgc_tangent_turn_vector_fp32(const BgcTangentFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    const float x1 = tangent->cos * vector->x1 - tangent->sin * vector->x2;
    const float x2 = tangent->sin * vector->x1 + tangent->cos * vector->x2;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_tangent_turn_vector_fp64(const BgcTangentFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    const double x1 = tangent->cos * vector->x1 - tangent->sin * vector->x2;
    const double x2 = tangent->sin * vector->x1 + tangent->cos * vector->x2;

    result->x1 = x1;
    result->x2 = x2;
}

// ============ Turn Vector Backward ============ //

inline void bgc_tangent_turn_vector_back_fp32(const BgcTangentFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    const float x1 = tangent->sin * vector->x2 + tangent->cos * vector->x1;
    const float x2 = tangent->cos * vector->x2 - tangent->sin * vector->x1;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_tangent_turn_vector_back_fp64(const BgcTangentFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    const double x1 = tangent->sin * vector->x2 + tangent->cos * vector->x1;
    const double x2 = tangent->cos * vector->x2 - tangent->sin * vector->x1;

    result->x1 = x1;
    result->x2 = x2;
}

// ================== Are Close ================= //

inline int bgc_tangent_are_close_fp32(const BgcTangentFP32* tangent1, const BgcTangentFP32* tangent2)
{
    const float d_cos = tangent1->cos - tangent2->cos;
    const float d_sin = tangent1->sin - tangent2->sin;

    return d_cos * d_cos + d_sin * d_sin <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_tangent_are_close_fp64(const BgcTangentFP64* tangent1, const BgcTangentFP64* tangent2)
{
    const double d_cos = tangent1->cos - tangent2->cos;
    const double d_sin = tangent1->sin - tangent2->sin;

    return d_cos * d_cos + d_sin * d_sin <= BGC_SQUARE_EPSYLON_FP64;
}

#endif
