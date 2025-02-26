#include "./complex.h"

extern inline void bgc_complex_reset_fp32(BgcComplexFP32* complex);
extern inline void bgc_complex_reset_fp64(BgcComplexFP64* complex);

extern inline void bgc_complex_set_values_fp32(const float real, const float imaginary, BgcComplexFP32* destination);
extern inline void bgc_complex_set_values_fp64(const double real, const double imaginary, BgcComplexFP64* destination);

extern inline float bgc_complex_get_square_modulus_fp32(const BgcComplexFP32* number);
extern inline double bgc_complex_get_square_modulus_fp64(const BgcComplexFP64* number);

extern inline float bgc_complex_get_modulus_fp32(const BgcComplexFP32* number);
extern inline double bgc_complex_get_modulus_fp64(const BgcComplexFP64* number);

extern inline int bgc_complex_is_zero_fp32(const BgcComplexFP32* number);
extern inline int bgc_complex_is_zero_fp64(const BgcComplexFP64* number);

extern inline int bgc_complex_is_unit_fp32(const BgcComplexFP32* number);
extern inline int bgc_complex_is_unit_fp64(const BgcComplexFP64* number);

extern inline void bgc_complex_copy_fp32(const BgcComplexFP32* source, BgcComplexFP32* destination);
extern inline void bgc_complex_copy_fp64(const BgcComplexFP64* source, BgcComplexFP64* destination);

extern inline void bgc_complex_swap_fp32(BgcComplexFP32* number1, BgcComplexFP32* number2);
extern inline void bgc_complex_swap_fp64(BgcComplexFP64* number1, BgcComplexFP64* number2);

extern inline void bgc_complex_convert_fp64_to_fp32(const BgcComplexFP64* source, BgcComplexFP32* destination);
extern inline void bgc_complex_convert_fp32_to_fp64(const BgcComplexFP32* source, BgcComplexFP64* destination);

extern inline void bgc_complex_reverse_fp32(const BgcComplexFP32* number, BgcComplexFP32* reverse);
extern inline void bgc_complex_reverse_fp64(const BgcComplexFP64* number, BgcComplexFP64* reverse);

extern inline int bgc_complex_normalize_fp32(const BgcComplexFP32* number, BgcComplexFP32* normalized);
extern inline int bgc_complex_normalize_fp64(const BgcComplexFP64* number, BgcComplexFP64* normalized);

extern inline void bgc_complex_conjugate_fp32(const BgcComplexFP32* number, BgcComplexFP32* conjugate);
extern inline void bgc_complex_conjugate_fp64(const BgcComplexFP64* number, BgcComplexFP64* conjugate);

extern inline int bgc_complex_invert_fp32(const BgcComplexFP32* number, BgcComplexFP32* inverted);
extern inline int bgc_complex_invert_fp64(const BgcComplexFP64* number, BgcComplexFP64* inverted);

extern inline void bgc_complex_get_product_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, BgcComplexFP32* result);
extern inline void bgc_complex_get_product_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, BgcComplexFP64* result);

extern inline int bgc_complex_get_ratio_fp32(const BgcComplexFP32* divident, const BgcComplexFP32* divisor, BgcComplexFP32* quotient);
extern inline int bgc_complex_get_ratio_fp64(const BgcComplexFP64* divident, const BgcComplexFP64* divisor, BgcComplexFP64* quotient);

extern inline void bgc_complex_add_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, BgcComplexFP32* sum);
extern inline void bgc_complex_add_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, BgcComplexFP64* sum);

extern inline void bgc_complex_add_scaled_fp32(const BgcComplexFP32* basic_number, const BgcComplexFP32* scalable_number, const float scale, BgcComplexFP32* sum);
extern inline void bgc_complex_add_scaled_fp64(const BgcComplexFP64* basic_number, const BgcComplexFP64* scalable_number, const double scale, BgcComplexFP64* sum);

extern inline void bgc_complex_subtract_fp32(const BgcComplexFP32* minuend, const BgcComplexFP32* subtrahend, BgcComplexFP32* difference);
extern inline void bgc_complex_subtract_fp64(const BgcComplexFP64* minuend, const BgcComplexFP64* subtrahend, BgcComplexFP64* difference);

extern inline void bgc_complex_subtract_scaled_fp32(const BgcComplexFP32* basic_number, const BgcComplexFP32* scalable_number, const float scale, BgcComplexFP32* difference);
extern inline void bgc_complex_subtract_scaled_fp64(const BgcComplexFP64* basic_number, const BgcComplexFP64* scalable_number, const double scale, BgcComplexFP64* difference);

extern inline void bgc_complex_multiply_fp32(const BgcComplexFP32* multiplicand, const float multiplier, BgcComplexFP32* product);
extern inline void bgc_complex_multiply_fp64(const BgcComplexFP64* multiplicand, const double multiplier, BgcComplexFP64* product);

extern inline void bgc_complex_divide_fp32(const BgcComplexFP32* dividend, const float divisor, BgcComplexFP32* quotient);
extern inline void bgc_complex_divide_fp64(const BgcComplexFP64* dividend, const double divisor, BgcComplexFP64* quotient);

extern inline void bgc_complex_get_mean_of_two_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, BgcComplexFP32* mean);
extern inline void bgc_complex_get_mean_of_two_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, BgcComplexFP64* mean);

extern inline void bgc_complex_get_mean_of_three_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, const BgcComplexFP32* number3, BgcComplexFP32* mean);
extern inline void bgc_complex_get_mean_of_three_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, const BgcComplexFP64* number3, BgcComplexFP64* mean);

extern inline void bgc_complex_get_linear_interpolation_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, const float phase, BgcComplexFP32* interpolation);
extern inline void bgc_complex_get_linear_interpolation_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, const double phase, BgcComplexFP64* interpolation);

extern inline void bgc_complex_minimize_fp32(const BgcComplexFP32* number, BgcComplexFP32* minimal);
extern inline void bgc_complex_minimize_fp64(const BgcComplexFP64* number, BgcComplexFP64* minimal);

extern inline void bgc_complex_maximize_fp32(const BgcComplexFP32* number, BgcComplexFP32* maximal);
extern inline void bgc_complex_maximize_fp64(const BgcComplexFP64* number, BgcComplexFP64* maximal);

extern inline int bgc_complex_are_close_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2);
extern inline int bgc_complex_are_close_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2);

// =============== Get Exponation =============== //

void bgc_complex_get_exponation_fp32(const BgcComplexFP32* base, const float real_exponent, const float imaginary_exponent, BgcComplexFP32* power)
{
    const float square_modulus = bgc_complex_get_square_modulus_fp32(base);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32) {
        power->real = 0.0f;
        power->imaginary = 0.0f;
        return;
    }

    const float log_modulus = logf(square_modulus) * 0.5f;
    const float angle = atan2f(base->imaginary, base->real);

    const float power_modulus = expf(real_exponent * log_modulus - imaginary_exponent * angle);
    const float power_angle = real_exponent * angle + imaginary_exponent * log_modulus;

    power->real = power_modulus * cosf(power_angle);
    power->imaginary = power_modulus * sinf(power_angle);
}

void bgc_complex_get_exponation_fp64(const BgcComplexFP64* base, const double real_exponent, const double imaginary_exponent, BgcComplexFP64* power)
{
    const double square_modulus = bgc_complex_get_square_modulus_fp64(base);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64) {
        power->real = 0.0;
        power->imaginary = 0.0;
        return;
    }

    const double log_modulus = log(square_modulus) * 0.5;
    const double angle = atan2(base->imaginary, base->real);

    const double power_modulus = exp(real_exponent * log_modulus - imaginary_exponent * angle);
    const double power_angle = real_exponent * angle + imaginary_exponent * log_modulus;

    power->real = power_modulus * cos(power_angle);
    power->imaginary = power_modulus * sin(power_angle);
}
