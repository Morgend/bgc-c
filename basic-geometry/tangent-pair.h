#ifndef _bgc_tangent_pair_H_
#define _bgc_tangent_pair_H_

#include <math.h>

#include "utilities.h"
#include "angle.h"
#include "vector2.h"
#include "matrix2x2.h"

// =================== Types ==================== //

typedef struct
{
    const float cos, sin;
} BgcTangentPairFP32;

typedef struct
{
    const double cos, sin;
} BgcTangentPairFP64;

// ================= Dark Twins ================= //

typedef struct {
    float cos, sin;
} _BgcTwinTangentPairFP32;

typedef struct {
    double cos, sin;
} _BgcTwinTangentPairFP64;

// ================= Constants ================== //

extern const BgcTangentPairFP32 BGC_IDLE_TANGENT_PAIR_FP32;
extern const BgcTangentPairFP64 BGC_IDLE_TANGENT_PAIR_FP64;

// =================== Reset ==================== //

inline void bgc_tangent_pair_reset_fp32(BgcTangentPairFP32* tangent)
{
    _BgcTwinTangentPairFP32* twin = (_BgcTwinTangentPairFP32*)tangent;

    twin->cos = 1.0f;
    twin->sin = 0.0f;
}

inline void bgc_tangent_pair_reset_fp64(BgcTangentPairFP64* tangent)
{
    _BgcTwinTangentPairFP64* twin = (_BgcTwinTangentPairFP64*)tangent;

    twin->cos = 1.0;
    twin->sin = 0.0;
}

// ==================== Set ===================== //

void _bgc_tangent_pair_normalize_fp32(const float square_modulus, _BgcTwinTangentPairFP32* twin);

void _bgc_tangent_pair_normalize_fp64(const double square_modulus, _BgcTwinTangentPairFP64* twin);

inline void bgc_tangent_pair_set_values_fp32(const float x1, const float x2, BgcTangentPairFP32* tangent)
{
    const float square_modulus = x1 * x1 + x2 * x2;

    _BgcTwinTangentPairFP32* twin = (_BgcTwinTangentPairFP32*)tangent;

    twin->cos = x1;
    twin->sin = x2;

    if (!bgc_is_sqare_unit_fp32(square_modulus)) {
        _bgc_tangent_pair_normalize_fp32(square_modulus, twin);
    }
}

inline void bgc_tangent_pair_set_values_fp64(const double x1, const double x2, BgcTangentPairFP64* tangent)
{
    const double square_modulus = x1 * x1 + x2 * x2;

    _BgcTwinTangentPairFP64* twin = (_BgcTwinTangentPairFP64*)tangent;

    twin->cos = x1;
    twin->sin = x2;

    if (!bgc_is_sqare_unit_fp64(square_modulus)) {
        _bgc_tangent_pair_normalize_fp64(square_modulus, twin);
    }
}

// ================== Set Turn ================== //

inline void bgc_tangent_pair_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcTangentPairFP32* tangent)
{
    const float radians = bgc_angle_to_radians_fp32(angle, unit);

    _BgcTwinTangentPairFP32* twin = (_BgcTwinTangentPairFP32*)tangent;

    twin->cos = cosf(radians);
    twin->sin = sinf(radians);
}

inline void bgc_tangent_pair_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcTangentPairFP64* tangent)
{
    const double radians = bgc_angle_to_radians_fp64(angle, unit);

    _BgcTwinTangentPairFP64* twin = (_BgcTwinTangentPairFP64*)tangent;

    twin->cos = cos(radians);
    twin->sin = sin(radians);
}

// =================== Angle =================== //

inline float bgc_tangent_pair_get_angle_fp32(const BgcTangentPairFP32* tangent, const BgcAngleUnitEnum unit)
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

    return bgc_radians_to_units_fp32(atan2f(tangent->sin, tangent->cos), unit);
}

inline double bgc_tangent_pair_get_angle_fp64(const BgcTangentPairFP64* tangent, const BgcAngleUnitEnum unit)
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

    return bgc_radians_to_units_fp64(atan2(tangent->sin, tangent->cos), unit);
}

// ==================== Copy ==================== //

inline void bgc_tangent_pair_copy_fp32(const BgcTangentPairFP32* from, BgcTangentPairFP32* to)
{
    _BgcTwinTangentPairFP32* twin = (_BgcTwinTangentPairFP32*)to;

    twin->cos = from->cos;
    twin->sin = from->sin;
}

inline void bgc_tangent_pair_copy_fp64(const BgcTangentPairFP64* from, BgcTangentPairFP64* to)
{
    _BgcTwinTangentPairFP64* twin = (_BgcTwinTangentPairFP64*)to;

    twin->cos = from->cos;
    twin->sin = from->sin;
}

// ==================== Swap ==================== //

inline void bgc_tangent_pair_swap_fp32(BgcTangentPairFP32* tangent1, BgcTangentPairFP32* tangent2)
{
    const float cos = tangent1->cos;
    const float sin = tangent1->sin;

    _BgcTwinTangentPairFP32* twin1 = (_BgcTwinTangentPairFP32*)tangent1;

    twin1->cos = tangent2->cos;
    twin1->sin = tangent2->sin;

    _BgcTwinTangentPairFP32* twin2 = (_BgcTwinTangentPairFP32*)tangent2;

    twin2->cos = cos;
    twin2->sin = sin;
}

inline void bgc_tangent_pair_swap_fp64(BgcTangentPairFP64* tangent1, BgcTangentPairFP64* tangent2)
{
    const double cos = tangent1->cos;
    const double sin = tangent1->sin;

    _BgcTwinTangentPairFP64* twin1 = (_BgcTwinTangentPairFP64*)tangent1;

    twin1->cos = tangent2->cos;
    twin1->sin = tangent2->sin;

    _BgcTwinTangentPairFP64* twin2 = (_BgcTwinTangentPairFP64*)tangent2;

    twin2->cos = cos;
    twin2->sin = sin;
}

// ================== Convert =================== //

inline void bgc_tangent_pair_convert_fp64_to_fp32(const BgcTangentPairFP64* from, BgcTangentPairFP32* to)
{
    bgc_tangent_pair_set_values_fp32((float)from->cos, (float)from->sin, to);
}

inline void bgc_tangent_pair_convert_fp32_to_fp64(const BgcTangentPairFP32* from, BgcTangentPairFP64* to)
{
    bgc_tangent_pair_set_values_fp64((double)from->cos, (double)from->sin, to);
}

// =================== Invert =================== //

inline void bgc_tangent_pair_invert_fp32(BgcTangentPairFP32* tangent)
{
    ((_BgcTwinTangentPairFP32*)tangent)->sin = -tangent->sin;
}

inline void bgc_tangent_pair_invert_fp64(BgcTangentPairFP64* tangent)
{
    ((_BgcTwinTangentPairFP64*)tangent)->sin = -tangent->sin;
}

// ================ Combination ================= //

inline void bgc_tangent_pair_combine_fp32(const BgcTangentPairFP32* tangent1, const BgcTangentPairFP32* tangent2, BgcTangentPairFP32* result)
{
    bgc_tangent_pair_set_values_fp32(
        tangent1->cos * tangent2->cos - tangent1->sin * tangent2->sin,
        tangent1->cos * tangent2->sin + tangent1->sin * tangent2->cos,
        result
    );
}

inline void bgc_tangent_pair_combine_fp64(const BgcTangentPairFP64* tangent1, const BgcTangentPairFP64* tangent2, BgcTangentPairFP64* result)
{
    bgc_tangent_pair_set_values_fp64(
        tangent1->cos * tangent2->cos - tangent1->sin * tangent2->sin,
        tangent1->cos * tangent2->sin + tangent1->sin * tangent2->cos,
        result
    );
}

// ================ Set Inverted ================ //

inline void bgc_tangent_pair_get_inverted_fp32(const BgcTangentPairFP32* tangent, BgcTangentPairFP32* result)
{
    _BgcTwinTangentPairFP32* twin = (_BgcTwinTangentPairFP32*)result;

    twin->cos = tangent->cos;
    twin->sin = -tangent->sin;
}

inline void bgc_tangent_pair_get_inverted_fp64(const BgcTangentPairFP64* tangent, BgcTangentPairFP64* result)
{
    _BgcTwinTangentPairFP64* twin = (_BgcTwinTangentPairFP64*)result;

    twin->cos = tangent->cos;
    twin->sin = -tangent->sin;
}

// ============== Rotation Matrix =============== //

inline void bgc_tangent_pair_get_rotation_matrix_fp32(const BgcTangentPairFP32* tangent, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = -tangent->sin;
    matrix->r2c1 = tangent->sin;
    matrix->r2c2 = tangent->cos;
}

inline void bgc_tangent_pair_get_rotation_matrix_fp64(const BgcTangentPairFP64* tangent, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = -tangent->sin;
    matrix->r2c1 = tangent->sin;
    matrix->r2c2 = tangent->cos;
}

// ============== Reverse Matrix ================ //

inline void bgc_tangent_pair_get_reverse_matrix_fp32(const BgcTangentPairFP32* tangent, BgcMatrix2x2FP32* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = tangent->sin;
    matrix->r2c1 = -tangent->sin;
    matrix->r2c2 = tangent->cos;
}

inline void bgc_tangent_pair_get_reverse_matrix_fp64(const BgcTangentPairFP64* tangent, BgcMatrix2x2FP64* matrix)
{
    matrix->r1c1 = tangent->cos;
    matrix->r1c2 = tangent->sin;
    matrix->r2c1 = -tangent->sin;
    matrix->r2c2 = tangent->cos;
}

// ================ Turn Vector ================= //

inline void bgc_tangent_pair_turn_vector_fp32(const BgcTangentPairFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    const float x1 = tangent->cos * vector->x1 - tangent->sin * vector->x2;
    const float x2 = tangent->sin * vector->x1 + tangent->cos * vector->x2;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_tangent_pair_turn_vector_fp64(const BgcTangentPairFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    const double x1 = tangent->cos * vector->x1 - tangent->sin * vector->x2;
    const double x2 = tangent->sin * vector->x1 + tangent->cos * vector->x2;

    result->x1 = x1;
    result->x2 = x2;
}

// ============ Turn Vector Backward ============ //

inline void bgc_tangent_pair_turn_vector_back_fp32(const BgcTangentPairFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result)
{
    const float x1 = tangent->sin * vector->x2 + tangent->cos * vector->x1;
    const float x2 = tangent->cos * vector->x2 - tangent->sin * vector->x1;

    result->x1 = x1;
    result->x2 = x2;
}

inline void bgc_tangent_pair_turn_vector_back_fp64(const BgcTangentPairFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result)
{
    const double x1 = tangent->sin * vector->x2 + tangent->cos * vector->x1;
    const double x2 = tangent->cos * vector->x2 - tangent->sin * vector->x1;

    result->x1 = x1;
    result->x2 = x2;
}

// ================== Are Close ================= //

inline int bgc_tangent_pair_are_close_fp32(const BgcTangentPairFP32* tangent1, const BgcTangentPairFP32* tangent2)
{
    const float d_cos = tangent1->cos - tangent2->cos;
    const float d_sin = tangent1->sin - tangent2->sin;

    return d_cos * d_cos + d_sin * d_sin <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_tangent_pair_are_close_fp64(const BgcTangentPairFP64* tangent1, const BgcTangentPairFP64* tangent2)
{
    const double d_cos = tangent1->cos - tangent2->cos;
    const double d_sin = tangent1->sin - tangent2->sin;

    return d_cos * d_cos + d_sin * d_sin <= BGC_SQUARE_EPSYLON_FP64;
}

#endif
