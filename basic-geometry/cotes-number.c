#include "./cotes-number.h"

const BgcCotesNumberFP32 BGC_IDLE_COTES_NUMBER_FP32 = { 1.0f, 0.0f };

const BgcCotesNumberFP64 BGC_IDLE_COTES_NUMBER_FP64 = { 1.0, 0.0 };

extern inline void bgc_cotes_number_reset_fp32(BgcCotesNumberFP32* number);
extern inline void bgc_cotes_number_reset_fp64(BgcCotesNumberFP64* number);

extern inline void bgc_cotes_number_set_values_fp32(const float x1, const float x2, BgcCotesNumberFP32* number);
extern inline void bgc_cotes_number_set_values_fp64(const double x1, const double x2, BgcCotesNumberFP64* number);

extern inline void bgc_cotes_number_set_turn_fp32(const float angle, const BgcAngleUnitEnum unit, BgcCotesNumberFP32* number);
extern inline void bgc_cotes_number_set_turn_fp64(const double angle, const BgcAngleUnitEnum unit, BgcCotesNumberFP64* number);

extern inline float bgc_cotes_number_get_angle_fp32(const BgcCotesNumberFP32* number, const BgcAngleUnitEnum unit);
extern inline double bgc_cotes_number_get_angle_fp64(const BgcCotesNumberFP64* number, const BgcAngleUnitEnum unit);

extern inline void bgc_cotes_number_copy_fp32(const BgcCotesNumberFP32* source, BgcCotesNumberFP32* destination);
extern inline void bgc_cotes_number_copy_fp64(const BgcCotesNumberFP64* source, BgcCotesNumberFP64* destination);

extern inline void bgc_cotes_number_swap_fp32(BgcCotesNumberFP32* number1, BgcCotesNumberFP32* number2);
extern inline void bgc_cotes_number_swap_fp64(BgcCotesNumberFP64* number1, BgcCotesNumberFP64* number2);

extern inline void bgc_cotes_number_convert_fp64_to_fp32(const BgcCotesNumberFP64* source, BgcCotesNumberFP32* destination);
extern inline void bgc_cotes_number_convert_fp32_to_fp64(const BgcCotesNumberFP32* source, BgcCotesNumberFP64* destination);

extern inline void bgc_cotes_number_invert_fp32(const BgcCotesNumberFP32* number, BgcCotesNumberFP32* inverted);
extern inline void bgc_cotes_number_invert_fp64(const BgcCotesNumberFP64* number, BgcCotesNumberFP64* inverted);

extern inline void bgc_cotes_number_get_exponation_fp32(const BgcCotesNumberFP32* base, const float exponent, BgcCotesNumberFP32* power);
extern inline void bgc_cotes_number_get_exponation_fp64(const BgcCotesNumberFP64* base, const double exponent, BgcCotesNumberFP64* power);

extern inline void bgc_cotes_number_combine_fp32(const BgcCotesNumberFP32* number1, const BgcCotesNumberFP32* number2, BgcCotesNumberFP32* result);
extern inline void bgc_cotes_number_combine_fp64(const BgcCotesNumberFP64* number1, const BgcCotesNumberFP64* number2, BgcCotesNumberFP64* result);

extern inline void bgc_cotes_number_exclude_fp32(const BgcCotesNumberFP32* base, const BgcCotesNumberFP32* excludant, BgcCotesNumberFP32* difference);
extern inline void bgc_cotes_number_exclude_fp64(const BgcCotesNumberFP64* base, const BgcCotesNumberFP64* excludant, BgcCotesNumberFP64* difference);

extern inline void bgc_cotes_number_get_rotation_matrix_fp32(const BgcCotesNumberFP32* number, BgcMatrix2x2FP32* matrix);
extern inline void bgc_cotes_number_get_rotation_matrix_fp64(const BgcCotesNumberFP64* number, BgcMatrix2x2FP64* matrix);

extern inline void bgc_cotes_number_get_reverse_matrix_fp32(const BgcCotesNumberFP32* number, BgcMatrix2x2FP32* matrix);
extern inline void bgc_cotes_number_get_reverse_matrix_fp64(const BgcCotesNumberFP64* number, BgcMatrix2x2FP64* matrix);

extern inline void bgc_cotes_number_turn_vector_fp32(const BgcCotesNumberFP32* number, const BgcVector2FP32* vector, BgcVector2FP32* result);
extern inline void bgc_cotes_number_turn_vector_fp64(const BgcCotesNumberFP64* number, const BgcVector2FP64* vector, BgcVector2FP64* result);

extern inline void bgc_cotes_number_turn_vector_back_fp32(const BgcCotesNumberFP32* number, const BgcVector2FP32* vector, BgcVector2FP32* result);
extern inline void bgc_cotes_number_turn_vector_back_fp64(const BgcCotesNumberFP64* number, const BgcVector2FP64* vector, BgcVector2FP64* result);

extern inline int bgc_cotes_number_are_close_fp32(const BgcCotesNumberFP32* number1, const BgcCotesNumberFP32* number2);
extern inline int bgc_cotes_number_are_close_fp64(const BgcCotesNumberFP64* number1, const BgcCotesNumberFP64* number2);

void _bgc_cotes_number_normalize_fp32(const float square_modulus, _BgcTwinCotesNumberFP32* twin)
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

void _bgc_cotes_number_normalize_fp64(const double square_modulus, _BgcTwinCotesNumberFP64* twin)
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
