#include <math.h>

#include "angle.h"
#include "versor.h"

const BgcVersorFP32 BGC_IDLE_VERSOR_FP32 = { 1.0f, 0.0f, 0.0f, 0.0f };

const BgcVersorFP64 BGC_IDLE_VERSOR_FP64 = { 1.0, 0.0, 0.0, 0.0 };

extern inline void bgc_versor_reset_fp32(BgcVersorFP32* versor);
extern inline void bgc_versor_reset_fp64(BgcVersorFP64* versor);

extern inline void bgc_versor_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcVersorFP32* versor);
extern inline void bgc_versor_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcVersorFP64* versor);

extern inline void bgc_versor_set_rotation_fp32(const BgcRotation3FP32* rotation, BgcVersorFP32* result);
extern inline void bgc_versor_set_rotation_fp64(const BgcRotation3FP64* rotation, BgcVersorFP64* result);

extern inline void bgc_versor_copy_fp32(const BgcVersorFP32* source, BgcVersorFP32* destination);
extern inline void bgc_versor_copy_fp64(const BgcVersorFP64* source, BgcVersorFP64* destination);

extern inline void bgc_versor_swap_fp32(BgcVersorFP32* versor1, BgcVersorFP32* versor2);
extern inline void bgc_versor_swap_fp64(BgcVersorFP64* versor1, BgcVersorFP64* versor2);

extern inline int bgc_versor_is_identity_fp32(const BgcVersorFP32* versor);
extern inline int bgc_versor_is_identity_fp64(const BgcVersorFP64* versor);

extern inline void bgc_versor_convert_fp64_to_fp32(const BgcVersorFP64* source, BgcVersorFP32* destination);
extern inline void bgc_versor_convert_fp32_to_fp64(const BgcVersorFP32* source, BgcVersorFP64* destination);

extern inline void bgc_versor_shorten_fp32(const BgcVersorFP32* versor, BgcVersorFP32* shortened);
extern inline void bgc_versor_shorten_fp64(const BgcVersorFP64* versor, BgcVersorFP64* shortened);

extern inline void bgc_versor_invert_fp32(const BgcVersorFP32* versor, BgcVersorFP32* inverted);
extern inline void bgc_versor_invert_fp64(const BgcVersorFP64* versor, BgcVersorFP64* inverted);

extern inline void bgc_versor_combine_fp32(const BgcVersorFP32* second, const BgcVersorFP32* first, BgcVersorFP32* result);
extern inline void bgc_versor_combine_fp64(const BgcVersorFP64* second, const BgcVersorFP64* first, BgcVersorFP64* result);

extern inline void bgc_versor_combine3_fp32(const BgcVersorFP32* third, const BgcVersorFP32* second, const BgcVersorFP32* first, BgcVersorFP32* result);
extern inline void bgc_versor_combine3_fp64(const BgcVersorFP64* third, const BgcVersorFP64* second, const BgcVersorFP64* first, BgcVersorFP64* result);

extern inline void bgc_versor_exclude_fp32(const BgcVersorFP32* base, const BgcVersorFP32* excludant, BgcVersorFP32* difference);
extern inline void bgc_versor_exclude_fp64(const BgcVersorFP64* base, const BgcVersorFP64* excludant, BgcVersorFP64* difference);

extern inline void bgc_versor_get_rotation_matrix_fp32(const BgcVersorFP32* versor, BgcMatrix3x3FP32* matrix);
extern inline void bgc_versor_get_rotation_matrix_fp64(const BgcVersorFP64* versor, BgcMatrix3x3FP64* matrix);

extern inline void bgc_versor_get_reverse_matrix_fp32(const BgcVersorFP32* versor, BgcMatrix3x3FP32* matrix);
extern inline void bgc_versor_get_reverse_matrix_fp64(const BgcVersorFP64* versor, BgcMatrix3x3FP64* matrix);

extern inline void bgc_versor_get_both_matrixes_fp32(const BgcVersorFP32* versor, BgcMatrix3x3FP32* rotation, BgcMatrix3x3FP32* reverse);
extern inline void bgc_versor_get_both_matrixes_fp64(const BgcVersorFP64* versor, BgcMatrix3x3FP64* rotation, BgcMatrix3x3FP64* reverse);

extern inline void bgc_versor_turn_vector_fp32(const BgcVersorFP32* versor, const BgcVector3FP32* vector, BgcVector3FP32* result);
extern inline void bgc_versor_turn_vector_fp64(const BgcVersorFP64* versor, const BgcVector3FP64* vector, BgcVector3FP64* result);

extern inline void bgc_versor_turn_vector_back_fp32(const BgcVersorFP32* versor, const BgcVector3FP32* vector, BgcVector3FP32* result);
extern inline void bgc_versor_turn_vector_back_fp64(const BgcVersorFP64* versor, const BgcVector3FP64* vector, BgcVector3FP64* result);

extern inline int bgc_versor_are_close_fp32(const BgcVersorFP32* versor1, const BgcVersorFP32* versor2);
extern inline int bgc_versor_are_close_fp64(const BgcVersorFP64* versor1, const BgcVersorFP64* versor2);

// ================= Normalize ================== //

void _bgc_versor_normalize_fp32(const float square_modulus, _BgcDarkTwinVersorFP32* twin)
{
    // (square_modulus != square_modulus) is true when square_modulus is NaN

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus) {
        twin->s0 = 1.0f;
        twin->x1 = 0.0f;
        twin->x2 = 0.0f;
        twin->x3 = 0.0f;
        return;
    }

    const float multiplier = sqrtf(1.0f / square_modulus);

    twin->s0 *= multiplier;
    twin->x1 *= multiplier;
    twin->x2 *= multiplier;
    twin->x3 *= multiplier;

}

void _bgc_versor_normalize_fp64(const double square_modulus, _BgcDarkTwinVersorFP64* twin)
{
    // (square_modulus != square_modulus) is true when square_modulus is NaN

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus) {
        twin->s0 = 1.0;
        twin->x1 = 0.0;
        twin->x2 = 0.0;
        twin->x3 = 0.0;
        return;
    }

    const double multiplier = sqrt(1.0 / square_modulus);

    twin->s0 *= multiplier;
    twin->x1 *= multiplier;
    twin->x2 *= multiplier;
    twin->x3 *= multiplier;
}

// ================== Set Turn ================== //

void bgc_versor_set_turn_fp32(const float x1, const float x2, const float x3, const float angle, const BgcAngleUnitEnum unit, BgcVersorFP32* result)
{
    const float square_vector = x1 * x1 + x2 * x2 + x3 * x3;

    if (square_vector <= BGC_SQUARE_EPSYLON_FP32) {
        bgc_versor_reset_fp32(result);
        return;
    }

    const float half_angle = bgc_angle_to_radians_fp32(0.5f * angle, unit);

    const float sine = sinf(half_angle);

    if (bgc_is_zero_fp32(sine)) {
        bgc_versor_reset_fp32(result);
        return;
    }

    const float multiplier = sine / sqrtf(square_vector);

    bgc_versor_set_values_fp32(cosf(half_angle), x1 * multiplier, x2 * multiplier, x3 * multiplier, result);
}

void bgc_versor_set_turn_fp64(const double x1, const double x2, const double x3, const double angle, const BgcAngleUnitEnum unit, BgcVersorFP64* result)
{
    const double square_vector = x1 * x1 + x2 * x2 + x3 * x3;

    if (square_vector <= BGC_SQUARE_EPSYLON_FP64) {
        bgc_versor_reset_fp64(result);
        return;
    }

    const double half_angle = bgc_angle_to_radians_fp64(0.5 * angle, unit);

    const double sine = sin(half_angle);

    if (bgc_is_zero_fp64(sine)) {
        bgc_versor_reset_fp64(result);
        return;
    }

    const double multiplier = sine / sqrt(square_vector);

    bgc_versor_set_values_fp64(cos(half_angle), x1 * multiplier, x2 * multiplier, x3 * multiplier, result);
}

// ================ Get Rotation ================ //

void bgc_versor_get_rotation_fp32(const BgcVersorFP32* versor, BgcRotation3FP32* result)
{
    if (versor->s0 <= -(1.0f - BGC_EPSYLON_FP32) || 1.0f - BGC_EPSYLON_FP32 <= versor->s0) {
        bgc_rotation3_reset_fp32(result);
        return;
    }

    const float multiplier = sqrtf(1.0f / (versor->x1 * versor->x1 + versor->x2 * versor->x2 + versor->x3 * versor->x3));

    result->radians = 2.0f * acosf(versor->s0);

    result->axis.x1 = versor->x1 * multiplier;
    result->axis.x2 = versor->x2 * multiplier;
    result->axis.x3 = versor->x3 * multiplier;
}

void bgc_versor_get_rotation_fp64(const BgcVersorFP64* versor, BgcRotation3FP64* result)
{
    if (versor->s0 <= -(1.0 - BGC_EPSYLON_FP64) || 1.0 - BGC_EPSYLON_FP64 <= versor->s0) {
        bgc_rotation3_reset_fp64(result);
        return;
    }

    const double multiplier = sqrt(1.0 / (versor->x1 * versor->x1 + versor->x2 * versor->x2 + versor->x3 * versor->x3));

    result->radians = 2.0 * acos(versor->s0);

    result->axis.x1 = versor->x1 * multiplier;
    result->axis.x2 = versor->x2 * multiplier;
    result->axis.x3 = versor->x3 * multiplier;
}

// =============== Get Exponation =============== //

void bgc_versor_get_exponation_fp32(const BgcVersorFP32* base, const float exponent, BgcVersorFP32* power)
{
    const float square_vector = base->x1 * base->x1 + base->x2 * base->x2 + base->x3 * base->x3;

    if (square_vector <= BGC_SQUARE_EPSYLON_FP32) {
        bgc_versor_reset_fp32(power);
        return;
    }

    const float angle = acosf(base->s0) * exponent;

    const float multiplier = sinf(angle) / sqrtf(square_vector);

    bgc_versor_set_values_fp32(cosf(angle), base->x1 * multiplier, base->x2 * multiplier, base->x3 * multiplier, power);
}

void bgc_versor_get_exponation_fp64(const BgcVersorFP64* base, const double exponent, BgcVersorFP64* power)
{
    const double square_vector = base->x1 * base->x1 + base->x2 * base->x2 + base->x3 * base->x3;

    if (square_vector <= BGC_SQUARE_EPSYLON_FP64) {
        bgc_versor_reset_fp64(power);
        return;
    }

    const double angle = acos(base->s0) * exponent;

    const double multiplier = sin(angle) / sqrt(square_vector);

    bgc_versor_set_values_fp64(cos(angle), base->x1 * multiplier, base->x2 * multiplier, base->x3 * multiplier, power);
}
