#include "tangent-pair.h"

const BgcTangentPairFP32 BGC_IDLE_TANGENT_PAIR_FP32 = { 1.0f, 0.0f };

const BgcTangentPairFP64 BGC_IDLE_TANGENT_PAIR_FP64 = { 1.0, 0.0 };

extern inline void bgc_tangent_pair_reset_fp32(BgcTangentPairFP32* tangent);
extern inline void bgc_tangent_pair_reset_fp64(BgcTangentPairFP64* tangent);

extern inline void bgc_tangent_pair_set_values_fp32(const float x1, const float x2, BgcTangentPairFP32* tangent);
extern inline void bgc_tangent_pair_set_values_fp64(const double x1, const double x2, BgcTangentPairFP64* tangent);

extern inline void bgc_tangent_pair_copy_fp32(const BgcTangentPairFP32* from, BgcTangentPairFP32* to);
extern inline void bgc_tangent_pair_copy_fp64(const BgcTangentPairFP64* from, BgcTangentPairFP64* to);

extern inline void bgc_tangent_pair_swap_fp32(BgcTangentPairFP32* tangent1, BgcTangentPairFP32* tangent2);
extern inline void bgc_tangent_pair_swap_fp64(BgcTangentPairFP64* tangent1, BgcTangentPairFP64* tangent2);

extern inline void bgc_tangent_pair_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcTangentPairFP32* tangent);
extern inline void bgc_tangent_pair_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcTangentPairFP64* tangent);

extern inline void bgc_tangent_pair_convert_fp64_to_fp32(const BgcTangentPairFP64* from, BgcTangentPairFP32* to);
extern inline void bgc_tangent_pair_convert_fp32_to_fp64(const BgcTangentPairFP32* from, BgcTangentPairFP64* to);

extern inline void bgc_tangent_pair_invert_fp32(BgcTangentPairFP32* tangent);
extern inline void bgc_tangent_pair_invert_fp64(BgcTangentPairFP64* tangent);

extern inline void bgc_tangent_pair_set_inverted_fp32(const BgcTangentPairFP32* tangent, BgcTangentPairFP32* result);
extern inline void bgc_tangent_pair_set_inverted_fp64(const BgcTangentPairFP64* tangent, BgcTangentPairFP64* result);

extern inline void bgc_tangent_pair_make_rotation_matrix_fp32(const BgcTangentPairFP32* tangent, BgcMatrix2x2FP32* matrix);
extern inline void bgc_tangent_pair_make_rotation_matrix_fp64(const BgcTangentPairFP64* tangent, BgcMatrix2x2FP64* matrix);

extern inline void bgc_tangent_pair_make_reverse_matrix_fp32(const BgcTangentPairFP32* tangent, BgcMatrix2x2FP32* matrix);
extern inline void bgc_tangent_pair_make_reverse_matrix_fp64(const BgcTangentPairFP64* tangent, BgcMatrix2x2FP64* matrix);

extern inline float bgc_tangent_pair_get_angle_fp32(const BgcTangentPairFP32* tangent, const BgcAngleUnitEnum unit);
extern inline double bgc_tangent_pair_get_angle_fp64(const BgcTangentPairFP64* tangent, const BgcAngleUnitEnum unit);

extern inline void bgc_tangent_pair_combine_fp32(const BgcTangentPairFP32* tangent1, const BgcTangentPairFP32* tangent2, BgcTangentPairFP32* result);
extern inline void bgc_tangent_pair_combine_fp64(const BgcTangentPairFP64* tangent1, const BgcTangentPairFP64* tangent2, BgcTangentPairFP64* result);

extern inline void bgc_tangent_pair_turn_vector_fp32(const BgcTangentPairFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result);
extern inline void bgc_tangent_pair_turn_vector_fp64(const BgcTangentPairFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result);

extern inline void bgc_tangent_pair_turn_vector_back_fp32(const BgcTangentPairFP32* tangent, const BgcVector2FP32* vector, BgcVector2FP32* result);
extern inline void bgc_tangent_pair_turn_vector_back_fp64(const BgcTangentPairFP64* tangent, const BgcVector2FP64* vector, BgcVector2FP64* result);

extern inline int bgc_tangent_pair_are_close_fp32(const BgcTangentPairFP32* tangent1, const BgcTangentPairFP32* tangent2);
extern inline int bgc_tangent_pair_are_close_fp64(const BgcTangentPairFP64* tangent1, const BgcTangentPairFP64* tangent2);

void _bgc_tangent_pair_normalize_fp32(const float square_modulus, _BgcTwinTangentPairFP32* twin)
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

void _bgc_tangent_pair_normalize_fp64(const double square_modulus, _BgcTwinTangentPairFP64* twin)
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
