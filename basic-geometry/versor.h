#ifndef _BGC_VERSOR_H_
#define _BGC_VERSOR_H_

#include <stdint.h>

#include "utilities.h"
#include "angle.h"
#include "vector3.h"
#include "rotation3.h"
#include "matrix3x3.h"

// =================== Types ==================== //

typedef struct {
    const float s0, x1, x2, x3;
} BgcVersorFP32;

typedef struct {
    const double s0, x1, x2, x3;
} BgcVersorFP64;

// ================= Dark Twins ================= //

typedef struct {
    float s0, x1, x2, x3;
} _BgcDarkTwinVersorFP32;

typedef struct {
    double s0, x1, x2, x3;
} _BgcDarkTwinVersorFP64;

// ================= Constants ================== //

extern const BgcVersorFP32 BGC_IDLE_VERSOR_FP32;
extern const BgcVersorFP64 BGC_IDLE_VERSOR_FP64;

// =================== Reset ==================== //

inline void bgc_versor_reset_fp32(BgcVersorFP32* versor)
{
    _BgcDarkTwinVersorFP32* twin = (_BgcDarkTwinVersorFP32*)versor;

    twin->s0 = 1.0f;
    twin->x1 = 0.0f;
    twin->x2 = 0.0f;
    twin->x3 = 0.0f;
}

inline void bgc_versor_reset_fp64(BgcVersorFP64* versor)
{
    _BgcDarkTwinVersorFP64* twin = (_BgcDarkTwinVersorFP64*)versor;

    twin->s0 = 1.0;
    twin->x1 = 0.0;
    twin->x2 = 0.0;
    twin->x3 = 0.0;
}

// ==================== Set ===================== //

void _bgc_versor_normalize_fp32(const float square_modulus, _BgcDarkTwinVersorFP32* twin);

void _bgc_versor_normalize_fp64(const double square_modulus, _BgcDarkTwinVersorFP64* twin);

inline void bgc_versor_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcVersorFP32* versor)
{
    _BgcDarkTwinVersorFP32* twin = (_BgcDarkTwinVersorFP32*)versor;

    twin->s0 = s0;
    twin->x1 = x1;
    twin->x2 = x2;
    twin->x3 = x3;

    const float square_modulus = (s0 * s0 + x1 * x1) + (x2 * x2 + x3 * x3);

    if (!bgc_is_sqare_unit_fp32(square_modulus)) {
        _bgc_versor_normalize_fp32(square_modulus, twin);
    }
}

inline void bgc_versor_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcVersorFP64* versor)
{
    _BgcDarkTwinVersorFP64* twin = (_BgcDarkTwinVersorFP64*)versor;

    twin->s0 = s0;
    twin->x1 = x1;
    twin->x2 = x2;
    twin->x3 = x3;

    const double square_modulus = (s0 * s0 + x1 * x1) + (x2 * x2 + x3 * x3);

    if (!bgc_is_sqare_unit_fp64(square_modulus)) {
        _bgc_versor_normalize_fp64(square_modulus, twin);
    }
}

// ================== Set Turn ================== //

void bgc_versor_set_turn_fp32(const float x1, const float x2, const float x3, const float angle, const BgcAngleUnitEnum unit, BgcVersorFP32* result);

void bgc_versor_set_turn_fp64(const double x1, const double x2, const double x3, const double angle, const BgcAngleUnitEnum unit, BgcVersorFP64* result);

// ================ Set Rotation ================ //

inline void bgc_versor_set_rotation_fp32(const BgcRotation3FP32* rotation, BgcVersorFP32* result)
{
    bgc_versor_set_turn_fp32(rotation->axis.x1, rotation->axis.x2, rotation->axis.x3, rotation->radians, BGC_ANGLE_UNIT_RADIANS, result);
}

inline void bgc_versor_set_rotation_fp64(const BgcRotation3FP64* rotation, BgcVersorFP64* result)
{
    bgc_versor_set_turn_fp64(rotation->axis.x1, rotation->axis.x2, rotation->axis.x3, rotation->radians, BGC_ANGLE_UNIT_RADIANS, result);
}

// ==================== Copy ==================== //

inline void bgc_versor_copy_fp32(const BgcVersorFP32* source, BgcVersorFP32* destination)
{
    _BgcDarkTwinVersorFP32* twin = (_BgcDarkTwinVersorFP32*)destination;

    twin->s0 = source->s0;
    twin->x1 = source->x1;
    twin->x2 = source->x2;
    twin->x3 = source->x3;
}

inline void bgc_versor_copy_fp64(const BgcVersorFP64* source, BgcVersorFP64* destination)
{
    _BgcDarkTwinVersorFP64* twin = (_BgcDarkTwinVersorFP64*)destination;

    twin->s0 = source->s0;
    twin->x1 = source->x1;
    twin->x2 = source->x2;
    twin->x3 = source->x3;
}

// ==================== Swap ==================== //

inline void bgc_versor_swap_fp32(BgcVersorFP32* versor1, BgcVersorFP32* versor2)
{
    const float s0 = versor1->s0;
    const float x1 = versor1->x1;
    const float x2 = versor1->x2;
    const float x3 = versor1->x3;

    _BgcDarkTwinVersorFP32* twin1 = (_BgcDarkTwinVersorFP32*)versor1;

    twin1->s0 = versor2->s0;
    twin1->x1 = versor2->x1;
    twin1->x2 = versor2->x2;
    twin1->x3 = versor2->x3;

    _BgcDarkTwinVersorFP32* twin2 = (_BgcDarkTwinVersorFP32*)versor2;

    twin2->s0 = s0;
    twin2->x1 = x1;
    twin2->x2 = x2;
    twin2->x3 = x3;
}

inline void bgc_versor_swap_fp64(BgcVersorFP64* versor1, BgcVersorFP64* versor2)
{
    const double s0 = versor1->s0;
    const double x1 = versor1->x1;
    const double x2 = versor1->x2;
    const double x3 = versor1->x3;

    _BgcDarkTwinVersorFP64* twin1 = (_BgcDarkTwinVersorFP64*)versor1;

    twin1->s0 = versor2->s0;
    twin1->x1 = versor2->x1;
    twin1->x2 = versor2->x2;
    twin1->x3 = versor2->x3;

    _BgcDarkTwinVersorFP64* twin2 = (_BgcDarkTwinVersorFP64*)versor2;

    twin2->s0 = s0;
    twin2->x1 = x1;
    twin2->x2 = x2;
    twin2->x3 = x3;
}

// ================= Comparison ================= //

inline int bgc_versor_is_identity_fp32(const BgcVersorFP32* versor)
{
    return versor->x1 * versor->x1 + versor->x2 * versor->x2 + versor->x3 * versor->x3 <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_versor_is_identity_fp64(const BgcVersorFP64* versor)
{
    return versor->x1 * versor->x1 + versor->x2 * versor->x2 + versor->x3 * versor->x3 <= BGC_SQUARE_EPSYLON_FP64;
}

// ================== Convert =================== //

inline void bgc_versor_convert_fp64_to_fp32(const BgcVersorFP64* source, BgcVersorFP32* destination)
{
    bgc_versor_set_values_fp32(
        (float)source->s0,
        (float)source->x1,
        (float)source->x2,
        (float)source->x3,
        destination
    );
}

inline void bgc_versor_convert_fp32_to_fp64(const BgcVersorFP32* source, BgcVersorFP64* destination)
{
    bgc_versor_set_values_fp64(
        source->s0,
        source->x1,
        source->x2,
        source->x3,
        destination
    );
}

// ================== Shorten =================== //

inline void bgc_versor_shorten_fp32(const BgcVersorFP32* versor, BgcVersorFP32* shortened)
{
    _BgcDarkTwinVersorFP32* twin = (_BgcDarkTwinVersorFP32*)shortened;

    if (versor->s0 >= 0.0f) {
        twin->x1 = versor->s0;
        twin->x1 = versor->x1;
        twin->x2 = versor->x2;
        twin->x3 = versor->x3;
        return;
    }

    twin->x1 = -versor->s0;
    twin->x1 = -versor->x1;
    twin->x2 = -versor->x2;
    twin->x3 = -versor->x3;
}

inline void bgc_versor_shorten_fp64(const BgcVersorFP64* versor, BgcVersorFP64* shortened)
{
    _BgcDarkTwinVersorFP64* twin = (_BgcDarkTwinVersorFP64*)shortened;

    if (versor->s0 >= 0.0) {
        twin->x1 = versor->s0;
        twin->x1 = versor->x1;
        twin->x2 = versor->x2;
        twin->x3 = versor->x3;
        return;
    }

    twin->x1 = -versor->s0;
    twin->x1 = -versor->x1;
    twin->x2 = -versor->x2;
    twin->x3 = -versor->x3;
}

// =================== Invert =================== //

inline void bgc_versor_invert_fp32(const BgcVersorFP32* versor, BgcVersorFP32* inverted)
{
    _BgcDarkTwinVersorFP32* twin = (_BgcDarkTwinVersorFP32*)inverted;
    twin->s0 = versor->s0;
    twin->x1 = -versor->x1;
    twin->x2 = -versor->x2;
    twin->x3 = -versor->x3;
}

inline void bgc_versor_invert_fp64(const BgcVersorFP64* versor, BgcVersorFP64* inverted)
{
    _BgcDarkTwinVersorFP64* twin = (_BgcDarkTwinVersorFP64*)inverted;
    twin->s0 = versor->s0;
    twin->x1 = -versor->x1;
    twin->x2 = -versor->x2;
    twin->x3 = -versor->x3;
}

// =============== Get Exponation =============== //

void bgc_versor_get_exponation_fp32(const BgcVersorFP32* base, const float exponent, BgcVersorFP32* power);

void bgc_versor_get_exponation_fp64(const BgcVersorFP64* base, const double exponent, BgcVersorFP64* power);

// ================ Combination ================= //

inline void bgc_versor_combine_fp32(const BgcVersorFP32* second, const BgcVersorFP32* first, BgcVersorFP32* result)
{
    bgc_versor_set_values_fp32(
        (second->s0 * first->s0 - second->x1 * first->x1) - (second->x2 * first->x2 + second->x3 * first->x3),
        (second->x1 * first->s0 + second->s0 * first->x1) - (second->x3 * first->x2 - second->x2 * first->x3),
        (second->x2 * first->s0 + second->s0 * first->x2) - (second->x1 * first->x3 - second->x3 * first->x1),
        (second->x3 * first->s0 + second->s0 * first->x3) - (second->x2 * first->x1 - second->x1 * first->x2),
        result
    );
}

inline void bgc_versor_combine_fp64(const BgcVersorFP64* second, const BgcVersorFP64* first, BgcVersorFP64* result)
{
    bgc_versor_set_values_fp64(
        (second->s0 * first->s0 - second->x1 * first->x1) - (second->x2 * first->x2 + second->x3 * first->x3),
        (second->x1 * first->s0 + second->s0 * first->x1) - (second->x3 * first->x2 - second->x2 * first->x3),
        (second->x2 * first->s0 + second->s0 * first->x2) - (second->x1 * first->x3 - second->x3 * first->x1),
        (second->x3 * first->s0 + second->s0 * first->x3) - (second->x2 * first->x1 - second->x1 * first->x2),
        result
    );
}

// ============ Combination of three ============ //

inline void bgc_versor_combine3_fp32(const BgcVersorFP32* third, const BgcVersorFP32* second, const BgcVersorFP32* first, BgcVersorFP32* result)
{
    const float s0 = (second->s0 * first->s0 - second->x1 * first->x1) - (second->x2 * first->x2 + second->x3 * first->x3);
    const float x1 = (second->x1 * first->s0 + second->s0 * first->x1) - (second->x3 * first->x2 - second->x2 * first->x3);
    const float x2 = (second->x2 * first->s0 + second->s0 * first->x2) - (second->x1 * first->x3 - second->x3 * first->x1);
    const float x3 = (second->x3 * first->s0 + second->s0 * first->x3) - (second->x2 * first->x1 - second->x1 * first->x2);

    bgc_versor_set_values_fp32(
        (third->s0 * s0 - third->x1 * x1) - (third->x2 * x2 + third->x3 * x3),
        (third->x1 * s0 + third->s0 * x1) - (third->x3 * x2 - third->x2 * x3),
        (third->x2 * s0 + third->s0 * x2) - (third->x1 * x3 - third->x3 * x1),
        (third->x3 * s0 + third->s0 * x3) - (third->x2 * x1 - third->x1 * x2),
        result
    );
}

inline void bgc_versor_combine3_fp64(const BgcVersorFP64* third, const BgcVersorFP64* second, const BgcVersorFP64* first, BgcVersorFP64* result)
{
    const double s0 = (second->s0 * first->s0 - second->x1 * first->x1) - (second->x2 * first->x2 + second->x3 * first->x3);
    const double x1 = (second->x1 * first->s0 + second->s0 * first->x1) - (second->x3 * first->x2 - second->x2 * first->x3);
    const double x2 = (second->x2 * first->s0 + second->s0 * first->x2) - (second->x1 * first->x3 - second->x3 * first->x1);
    const double x3 = (second->x3 * first->s0 + second->s0 * first->x3) - (second->x2 * first->x1 - second->x1 * first->x2);

    bgc_versor_set_values_fp64(
        (third->s0 * s0 - third->x1 * x1) - (third->x2 * x2 + third->x3 * x3),
        (third->x1 * s0 + third->s0 * x1) - (third->x3 * x2 - third->x2 * x3),
        (third->x2 * s0 + third->s0 * x2) - (third->x1 * x3 - third->x3 * x1),
        (third->x3 * s0 + third->s0 * x3) - (third->x2 * x1 - third->x1 * x2),
        result
    );
}

// ================ Get Rotation ================ //

void bgc_versor_get_rotation_fp32(const BgcVersorFP32* versor, BgcRotation3FP32* result);

void bgc_versor_get_rotation_fp64(const BgcVersorFP64* versor, BgcRotation3FP64* result);

// ============ Get Rotation Matrix ============= //

inline void bgc_versor_get_rotation_matrix_fp32(const BgcVersorFP32* versor, BgcMatrix3x3FP32* matrix)
{
    const float s0s0 = versor->s0 * versor->s0;
    const float x1x1 = versor->x1 * versor->x1;
    const float x2x2 = versor->x2 * versor->x2;
    const float x3x3 = versor->x3 * versor->x3;

    const float s0x1 = 2.0f * versor->s0 * versor->x1;
    const float s0x2 = 2.0f * versor->s0 * versor->x2;
    const float s0x3 = 2.0f * versor->s0 * versor->x3;

    const float x1x2 = 2.0f * versor->x1 * versor->x2;
    const float x1x3 = 2.0f * versor->x1 * versor->x3;
    const float x2x3 = 2.0f * versor->x2 * versor->x3;

    matrix->r1c1 = (s0s0 + x1x1) - (x2x2 + x3x3);
    matrix->r2c2 = (s0s0 + x2x2) - (x1x1 + x3x3);
    matrix->r3c3 = (s0s0 + x3x3) - (x1x1 + x2x2);

    matrix->r1c2 = x1x2 - s0x3;
    matrix->r2c3 = x2x3 - s0x1;
    matrix->r3c1 = x1x3 - s0x2;

    matrix->r2c1 = x1x2 + s0x3;
    matrix->r3c2 = x2x3 + s0x1;
    matrix->r1c3 = x1x3 + s0x2;
}

inline void bgc_versor_get_rotation_matrix_fp64(const BgcVersorFP64* versor, BgcMatrix3x3FP64* matrix)
{
    const double s0s0 = versor->s0 * versor->s0;
    const double x1x1 = versor->x1 * versor->x1;
    const double x2x2 = versor->x2 * versor->x2;
    const double x3x3 = versor->x3 * versor->x3;

    const double s0x1 = 2.0 * versor->s0 * versor->x1;
    const double s0x2 = 2.0 * versor->s0 * versor->x2;
    const double s0x3 = 2.0 * versor->s0 * versor->x3;

    const double x1x2 = 2.0 * versor->x1 * versor->x2;
    const double x1x3 = 2.0 * versor->x1 * versor->x3;
    const double x2x3 = 2.0 * versor->x2 * versor->x3;

    matrix->r1c1 = (s0s0 + x1x1) - (x2x2 + x3x3);
    matrix->r2c2 = (s0s0 + x2x2) - (x1x1 + x3x3);
    matrix->r3c3 = (s0s0 + x3x3) - (x1x1 + x2x2);

    matrix->r1c2 = x1x2 - s0x3;
    matrix->r2c3 = x2x3 - s0x1;
    matrix->r3c1 = x1x3 - s0x2;

    matrix->r2c1 = x1x2 + s0x3;
    matrix->r3c2 = x2x3 + s0x1;
    matrix->r1c3 = x1x3 + s0x2;
}

// ============= Get Reverse Matrix ============= //

inline void bgc_versor_get_reverse_matrix_fp32(const BgcVersorFP32* versor, BgcMatrix3x3FP32* matrix)
{
    const float s0s0 = versor->s0 * versor->s0;
    const float x1x1 = versor->x1 * versor->x1;
    const float x2x2 = versor->x2 * versor->x2;
    const float x3x3 = versor->x3 * versor->x3;

    const float s0x1 = 2.0f * versor->s0 * versor->x1;
    const float s0x2 = 2.0f * versor->s0 * versor->x2;
    const float s0x3 = 2.0f * versor->s0 * versor->x3;

    const float x1x2 = 2.0f * versor->x1 * versor->x2;
    const float x1x3 = 2.0f * versor->x1 * versor->x3;
    const float x2x3 = 2.0f * versor->x2 * versor->x3;

    matrix->r1c1 = (s0s0 + x1x1) - (x2x2 + x3x3);
    matrix->r2c2 = (s0s0 + x2x2) - (x1x1 + x3x3);
    matrix->r3c3 = (s0s0 + x3x3) - (x1x1 + x2x2);

    matrix->r1c2 = x1x2 + s0x3;
    matrix->r2c3 = x2x3 + s0x1;
    matrix->r3c1 = x1x3 + s0x2;

    matrix->r2c1 = x1x2 - s0x3;
    matrix->r3c2 = x2x3 - s0x1;
    matrix->r1c3 = x1x3 - s0x2;
}

inline void bgc_versor_get_reverse_matrix_fp64(const BgcVersorFP64* versor, BgcMatrix3x3FP64* matrix)
{
    const double s0s0 = versor->s0 * versor->s0;
    const double x1x1 = versor->x1 * versor->x1;
    const double x2x2 = versor->x2 * versor->x2;
    const double x3x3 = versor->x3 * versor->x3;

    const double s0x1 = 2.0 * versor->s0 * versor->x1;
    const double s0x2 = 2.0 * versor->s0 * versor->x2;
    const double s0x3 = 2.0 * versor->s0 * versor->x3;

    const double x1x2 = 2.0 * versor->x1 * versor->x2;
    const double x1x3 = 2.0 * versor->x1 * versor->x3;
    const double x2x3 = 2.0 * versor->x2 * versor->x3;

    matrix->r1c1 = (s0s0 + x1x1) - (x2x2 + x3x3);
    matrix->r2c2 = (s0s0 + x2x2) - (x1x1 + x3x3);
    matrix->r3c3 = (s0s0 + x3x3) - (x1x1 + x2x2);

    matrix->r1c2 = x1x2 + s0x3;
    matrix->r2c3 = x2x3 + s0x1;
    matrix->r3c1 = x1x3 + s0x2;

    matrix->r2c1 = x1x2 - s0x3;
    matrix->r3c2 = x2x3 - s0x1;
    matrix->r1c3 = x1x3 - s0x2;
}

// ============= Get Both Matrixes ============== //

inline void bgc_versor_get_both_matrixes_fp32(const BgcVersorFP32* versor, BgcMatrix3x3FP32* rotation, BgcMatrix3x3FP32* reverse)
{
    bgc_versor_get_reverse_matrix_fp32(versor, reverse);
    bgc_matrix3x3_transpose_fp32(reverse, rotation);
}

inline void bgc_versor_get_both_matrixes_fp64(const BgcVersorFP64* versor, BgcMatrix3x3FP64* rotation, BgcMatrix3x3FP64* reverse)
{
    bgc_versor_get_reverse_matrix_fp64(versor, reverse);
    bgc_matrix3x3_transpose_fp64(reverse, rotation);
}

// ================ Turn Vector ================= //

inline void bgc_versor_turn_vector_fp32(const BgcVersorFP32* versor, const BgcVector3FP32* vector, BgcVector3FP32* result)
{
    const float tx1 = 2.0f * (versor->x2 * vector->x3 - versor->x3 * vector->x2);
    const float tx2 = 2.0f * (versor->x3 * vector->x1 - versor->x1 * vector->x3);
    const float tx3 = 2.0f * (versor->x1 * vector->x2 - versor->x2 * vector->x1);

    const float x1 = (vector->x1 + tx1 * versor->s0) + (versor->x2 * tx3 - versor->x3 * tx2);
    const float x2 = (vector->x2 + tx2 * versor->s0) + (versor->x3 * tx1 - versor->x1 * tx3);
    const float x3 = (vector->x3 + tx3 * versor->s0) + (versor->x1 * tx2 - versor->x2 * tx1);

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

inline void bgc_versor_turn_vector_fp64(const BgcVersorFP64* versor, const BgcVector3FP64* vector, BgcVector3FP64* result)
{
    const double tx1 = 2.0 * (versor->x2 * vector->x3 - versor->x3 * vector->x2);
    const double tx2 = 2.0 * (versor->x3 * vector->x1 - versor->x1 * vector->x3);
    const double tx3 = 2.0 * (versor->x1 * vector->x2 - versor->x2 * vector->x1);

    const double x1 = (vector->x1 + tx1 * versor->s0) + (versor->x2 * tx3 - versor->x3 * tx2);
    const double x2 = (vector->x2 + tx2 * versor->s0) + (versor->x3 * tx1 - versor->x1 * tx3);
    const double x3 = (vector->x3 + tx3 * versor->s0) + (versor->x1 * tx2 - versor->x2 * tx1);

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

// ============== Turn Vector Back ============== //

inline void bgc_versor_turn_vector_back_fp32(const BgcVersorFP32* versor, const BgcVector3FP32* vector, BgcVector3FP32* result)
{
    const float tx1 = 2.0f * (versor->x2 * vector->x3 - versor->x3 * vector->x2);
    const float tx2 = 2.0f * (versor->x3 * vector->x1 - versor->x1 * vector->x3);
    const float tx3 = 2.0f * (versor->x1 * vector->x2 - versor->x2 * vector->x1);

    const float x1 = (vector->x1 - tx1 * versor->s0) + (versor->x2 * tx3 - versor->x3 * tx2);
    const float x2 = (vector->x2 - tx2 * versor->s0) + (versor->x3 * tx1 - versor->x1 * tx3);
    const float x3 = (vector->x3 - tx3 * versor->s0) + (versor->x1 * tx2 - versor->x2 * tx1);

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

inline void bgc_versor_turn_vector_back_fp64(const BgcVersorFP64* versor, const BgcVector3FP64* vector, BgcVector3FP64* result)
{
    const double tx1 = 2.0 * (versor->x2 * vector->x3 - versor->x3 * vector->x2);
    const double tx2 = 2.0 * (versor->x3 * vector->x1 - versor->x1 * vector->x3);
    const double tx3 = 2.0 * (versor->x1 * vector->x2 - versor->x2 * vector->x1);

    const double x1 = (vector->x1 - tx1 * versor->s0) + (versor->x2 * tx3 - versor->x3 * tx2);
    const double x2 = (vector->x2 - tx2 * versor->s0) + (versor->x3 * tx1 - versor->x1 * tx3);
    const double x3 = (vector->x3 - tx3 * versor->s0) + (versor->x1 * tx2 - versor->x2 * tx1);

    result->x1 = x1;
    result->x2 = x2;
    result->x3 = x3;
}

// ================== Are Close ================= //

inline int bgc_versor_are_close_fp32(const BgcVersorFP32* versor1, const BgcVersorFP32* versor2)
{
    const float ds0 = versor1->s0 - versor2->s0;
    const float dx1 = versor1->x1 - versor2->x1;
    const float dx2 = versor1->x2 - versor2->x2;
    const float dx3 = versor1->x3 - versor2->x3;

    return (ds0 * ds0 + dx1 * dx1) + (dx2 * dx2 + dx3 * dx3) <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_versor_are_close_fp64(const BgcVersorFP64* versor1, const BgcVersorFP64* versor2)
{
    const double ds0 = versor1->s0 - versor2->s0;
    const double dx1 = versor1->x1 - versor2->x1;
    const double dx2 = versor1->x2 - versor2->x2;
    const double dx3 = versor1->x3 - versor2->x3;

    return (ds0 * ds0 + dx1 * dx1) + (dx2 * dx2 + dx3 * dx3) <= BGC_SQUARE_EPSYLON_FP64;
}

#endif
