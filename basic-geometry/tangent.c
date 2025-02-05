#include "tangent.h"

const BgcTangentFP32 BGC_IDLE_TANGENT_FP32 = { 1.0f, 0.0f };

const BgcTangentFP64 BGC_IDLE_TANGENT_FP64 = { 1.0, 0.0 };

extern inline void bgc_tangent_reset_fp32(BgcTangentFP32* tangent);
extern inline void bgc_tangent_reset_fp64(BgcTangentFP64* tangent);

extern inline void bgc_tangent_set_values_fp32(const float x1, const float x2, BgcTangentFP32* tangent);
extern inline void bgc_tangent_set_values_fp64(const double x1, const double x2, BgcTangentFP64* tangent);

extern inline void bgc_tangent_copy_fp32(const BgcTangentFP32* from, BgcTangentFP32* to);
extern inline void bgc_tangent_copy_fp64(const BgcTangentFP64* from, BgcTangentFP64* to);

extern inline void bgc_tangent_swap_fp32(BgcTangentFP32* tangent1, BgcTangentFP32* tangent2);
extern inline void bgc_tangent_swap_fp64(BgcTangentFP64* tangent1, BgcTangentFP64* tangent2);

extern inline void bgc_tangent_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcTangentFP32* tangent);
extern inline void bgc_tangent_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcTangentFP64* tangent);

extern inline void bgc_tangent_convert_fp64_to_fp32(const BgcTangentFP64* from, BgcTangentFP32* to);
extern inline void bgc_tangent_convert_fp32_to_fp64(const BgcTangentFP32* from, BgcTangentFP64* to);

extern inline void bgc_tangent_invert_fp32(BgcTangentFP32* tangent);
extern inline void bgc_tangent_invert_fp64(BgcTangentFP64* tangent);

extern inline void bgc_tangent_set_inverted_fp32(const BgcTangentFP32* tangent, BgcTangentFP32* result);
extern inline void bgc_tangent_set_inverted_fp64(const BgcTangentFP64* tangent, BgcTangentFP64* result);

extern inline void bgc_tangent_make_rotation_matrix_fp32(const BgcTangentFP32* tangent, BgcMatrix2x2FP32* matrix);
extern inline void bgc_tangent_make_rotation_matrix_fp64(const BgcTangentFP64* tangent, BgcMatrix2x2FP64* matrix);

extern inline void bgc_tangent_make_reverse_matrix_fp32(const BgcTangentFP32* tangent, BgcMatrix2x2FP32* matrix);
extern inline void bgc_tangent_make_reverse_matrix_fp64(const BgcTangentFP64* tangent, BgcMatrix2x2FP64* matrix);

extern inline float bgc_tangent_get_angle_fp32(const BgcTangentFP32* tangent, const BgcAngleUnitEnum unit);
extern inline double bgc_tangent_get_angle_fp64(const BgcTangentFP64* tangent, const BgcAngleUnitEnum unit);

extern inline void bgc_tangent_combine_fp32(const BgcTangentFP32* tangent1, const BgcTangentFP32* tangent2, BgcTangentFP32* result);
extern inline void bgc_tangent_combine_fp64(const BgcTangentFP64* tangent1, const BgcTangentFP64* tangent2, BgcTangentFP64* result);

extern inline void bgc_tangent_turn_vector_fp32(const BgcTangentFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result);
extern inline void bgc_tangent_turn_vector_fp64(const BgcTangentFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result);

extern inline void bgc_tangent_turn_vector_back_fp32(const BgcTangentFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result);
extern inline void bgc_tangent_turn_vector_back_fp64(const BgcTangentFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result);

void _bgc_tangent_normalize_fp32(const float square_modulus, _BgcDarkTwinTangentFP32* twin)
{
    // (square_modulus != square_modulus) is true when square_modulus is NaN

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus) {
        twin->cos = 1.0f;
        twin->sin = 0.0f;
        return;
    }

    const float multiplier = sqrtf(1.0f / square_modulus);

    twin->cos *= multiplier;
    twin->sin *= multiplier;
}

void _bgc_tangent_normalize_fp64(const double square_modulus, _BgcDarkTwinTangentFP64* twin)
{
    // (square_modulus != square_modulus) is true when square_modulus is NaN

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus) {
        twin->cos = 1.0;
        twin->sin = 0.0;
        return;
    }

    const double multiplier = sqrt(1.0 / square_modulus);

    twin->cos *= multiplier;
    twin->sin *= multiplier;
}
