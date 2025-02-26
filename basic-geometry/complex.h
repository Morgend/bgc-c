#ifndef _BGC_COMPLEX_H_
#define _BGC_COMPLEX_H_

#include "utilities.h"
#include "angle.h"

#include <math.h>

typedef struct
{
    float real, imaginary;
} BgcComplexFP32;

typedef struct
{
    double real, imaginary;
} BgcComplexFP64;

// =================== Reset ==================== //

inline void bgc_complex_reset_fp32(BgcComplexFP32* complex)
{
    complex->real = 0.0f;
    complex->imaginary = 0.0f;
}

inline void bgc_complex_reset_fp64(BgcComplexFP64* complex)
{
    complex->real = 0.0;
    complex->imaginary = 0.0;
}

// ==================== Set ===================== //

inline void bgc_complex_set_values_fp32(const float real, const float imaginary, BgcComplexFP32* destination)
{
    destination->real = real;
    destination->imaginary = imaginary;
}

inline void bgc_complex_set_values_fp64(const double real, const double imaginary, BgcComplexFP64* destination)
{
    destination->real = real;
    destination->imaginary = imaginary;
}

// ================== Modulus =================== //

inline float bgc_complex_get_square_modulus_fp32(const BgcComplexFP32* number)
{
    return number->real * number->real + number->imaginary * number->imaginary;
}

inline double bgc_complex_get_square_modulus_fp64(const BgcComplexFP64* number)
{
    return number->real * number->real + number->imaginary * number->imaginary;
}

inline float bgc_complex_get_modulus_fp32(const BgcComplexFP32* number)
{
    return sqrtf(bgc_complex_get_square_modulus_fp32(number));
}

inline double bgc_complex_get_modulus_fp64(const BgcComplexFP64* number)
{
    return sqrt(bgc_complex_get_square_modulus_fp64(number));
}

// ================= Comparison ================= //

inline int bgc_complex_is_zero_fp32(const BgcComplexFP32* number)
{
    return bgc_complex_get_square_modulus_fp32(number) <= BGC_SQUARE_EPSYLON_FP32;
}

inline int bgc_complex_is_zero_fp64(const BgcComplexFP64* number)
{
    return bgc_complex_get_square_modulus_fp64(number) <= BGC_SQUARE_EPSYLON_FP64;
}

inline int bgc_complex_is_unit_fp32(const BgcComplexFP32* number)
{
    return bgc_is_sqare_unit_fp32(bgc_complex_get_square_modulus_fp32(number));
}

inline int bgc_complex_is_unit_fp64(const BgcComplexFP64* number)
{
    return bgc_is_sqare_unit_fp64(bgc_complex_get_square_modulus_fp64(number));
}

// ==================== Copy ==================== //

inline void bgc_complex_copy_fp32(const BgcComplexFP32* source, BgcComplexFP32* destination)
{
    destination->real = source->real;
    destination->imaginary = source->imaginary;
}

inline void bgc_complex_copy_fp64(const BgcComplexFP64* source, BgcComplexFP64* destination)
{
    destination->real = source->real;
    destination->imaginary = source->imaginary;
}

// ==================== Swap ==================== //

inline void bgc_complex_swap_fp32(BgcComplexFP32* number1, BgcComplexFP32* number2)
{
    const float real = number2->real;
    const float imaginary = number2->imaginary;

    number2->real = number1->real;
    number2->imaginary = number1->imaginary;

    number1->real = real;
    number1->imaginary = imaginary;
}

inline void bgc_complex_swap_fp64(BgcComplexFP64* number1, BgcComplexFP64* number2)
{
    const double real = number2->real;
    const double imaginary = number2->imaginary;

    number2->real = number1->real;
    number2->imaginary = number1->imaginary;

    number1->real = real;
    number1->imaginary = imaginary;
}

// ================== Convert =================== //

inline void bgc_complex_convert_fp64_to_fp32(const BgcComplexFP64* source, BgcComplexFP32* destination)
{
    destination->real = (float)source->real;
    destination->imaginary = (float)source->imaginary;
}

inline void bgc_complex_convert_fp32_to_fp64(const BgcComplexFP32* source, BgcComplexFP64* destination)
{
    destination->real = source->real;
    destination->imaginary = source->imaginary;
}

// ================== Reverse =================== //

inline void bgc_complex_reverse_fp32(const BgcComplexFP32* number, BgcComplexFP32* reverse)
{
    reverse->real = -number->real;
    reverse->imaginary = -number->imaginary;
}

inline void bgc_complex_reverse_fp64(const BgcComplexFP64* number, BgcComplexFP64* reverse)
{
    reverse->real = -number->real;
    reverse->imaginary = -number->imaginary;
}

// ================= Normalize ================== //

inline int bgc_complex_normalize_fp32(const BgcComplexFP32* number, BgcComplexFP32* normalized)
{
    const float square_modulus = bgc_complex_get_square_modulus_fp32(number);

    if (bgc_is_sqare_unit_fp32(square_modulus)) {
        normalized->real = number->real;
        normalized->imaginary = number->imaginary;
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus) {
        return 0;
    }

    const float multiplicand = sqrtf(1.0f / square_modulus);

    normalized->real = number->real * multiplicand;
    normalized->imaginary = number->imaginary * multiplicand;

    return 1;
}

inline int bgc_complex_normalize_fp64(const BgcComplexFP64* number, BgcComplexFP64* normalized)
{
    const double square_modulus = bgc_complex_get_square_modulus_fp64(number);

    if (bgc_is_sqare_unit_fp64(square_modulus)) {
        normalized->real = number->real;
        normalized->imaginary = number->imaginary;
        return 1;
    }

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus) {
        return 0;
    }

    const double multiplicand = sqrt(1.0 / square_modulus);

    normalized->real = number->real * multiplicand;
    normalized->imaginary = number->imaginary * multiplicand;

    return 1;
}

// ================= Conjugate ================== //

inline void bgc_complex_conjugate_fp32(const BgcComplexFP32* number, BgcComplexFP32* conjugate)
{
    conjugate->real = number->real;
    conjugate->imaginary = -number->imaginary;
}

inline void bgc_complex_conjugate_fp64(const BgcComplexFP64* number, BgcComplexFP64* conjugate)
{
    conjugate->real = number->real;
    conjugate->imaginary = -number->imaginary;
}

// =================== Invert =================== //

inline int bgc_complex_invert_fp32(const BgcComplexFP32* number, BgcComplexFP32* inverted)
{
    const float square_modulus = bgc_complex_get_square_modulus_fp32(number);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32 || square_modulus != square_modulus) {
        return 0;
    }

    const float multiplicand = 1.0f / square_modulus;

    inverted->real = number->real * multiplicand;
    inverted->imaginary = -number->imaginary * multiplicand;

    return 1;
}

inline int bgc_complex_invert_fp64(const BgcComplexFP64* number, BgcComplexFP64* inverted)
{
    const double square_modulus = bgc_complex_get_square_modulus_fp64(number);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64 || square_modulus != square_modulus) {
        return 0;
    }

    const double multiplicand = 1.0 / square_modulus;

    inverted->real = number->real * multiplicand;
    inverted->imaginary = -number->imaginary * multiplicand;

    return 1;
}

// ================ Get Product ================= //

inline void bgc_complex_get_product_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, BgcComplexFP32* result)
{
    const float real = number1->real * number2->real - number1->imaginary * number2->imaginary;
    const float imaginary = number1->real * number2->imaginary + number1->imaginary * number2->real;

    result->real = real;
    result->imaginary = imaginary;
}

inline void bgc_complex_get_product_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, BgcComplexFP64* result)
{
    const double real = number1->real * number2->real - number1->imaginary * number2->imaginary;
    const double imaginary = number1->real * number2->imaginary + number1->imaginary * number2->real;

    result->real = real;
    result->imaginary = imaginary;
}

// ================= Get Ratio ================== //

inline int bgc_complex_get_ratio_fp32(const BgcComplexFP32* divident, const BgcComplexFP32* divisor, BgcComplexFP32* quotient)
{
    const float square_modulus = bgc_complex_get_square_modulus_fp32(divisor);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP32) {
        return 0;
    }

    const float real = divident->real * divisor->real + divident->imaginary * divisor->imaginary;
    const float imaginary = divident->imaginary * divisor->real - divident->real * divisor->imaginary;

    const float multiplier = 1.0f / square_modulus;

    quotient->real = real * multiplier;
    quotient->imaginary = imaginary * multiplier;

    return 1;
}

inline int bgc_complex_get_ratio_fp64(const BgcComplexFP64* divident, const BgcComplexFP64* divisor, BgcComplexFP64* quotient)
{
    const double square_modulus = bgc_complex_get_square_modulus_fp64(divisor);

    if (square_modulus <= BGC_SQUARE_EPSYLON_FP64) {
        return 0;
    }

    const double real = divident->real * divisor->real + divident->imaginary * divisor->imaginary;
    const double imaginary = divident->imaginary * divisor->real - divident->real * divisor->imaginary;

    const double multiplier = 1.0 / square_modulus;

    quotient->real = real * multiplier;
    quotient->imaginary = imaginary * multiplier;

    return 1;
}

// =============== Get Exponation =============== //

void bgc_complex_get_exponation_fp32(const BgcComplexFP32* base, const float real_exponent, const float imaginary_exponent, BgcComplexFP32* power);

void bgc_complex_get_exponation_fp64(const BgcComplexFP64* base, const double real_exponent, const double imaginary_exponent, BgcComplexFP64* power);

// ==================== Add ===================== //

inline void bgc_complex_add_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, BgcComplexFP32* sum)
{
    sum->real = number1->real + number2->real;
    sum->imaginary = number1->imaginary + number2->imaginary;
}

inline void bgc_complex_add_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, BgcComplexFP64* sum)
{
    sum->real = number1->real + number2->real;
    sum->imaginary = number1->imaginary + number2->imaginary;
}

// ================= Add scaled ================= //

inline void bgc_complex_add_scaled_fp32(const BgcComplexFP32* basic_number, const BgcComplexFP32* scalable_number, const float scale, BgcComplexFP32* sum)
{
    sum->real = basic_number->real + scalable_number->real * scale;
    sum->imaginary = basic_number->imaginary + scalable_number->imaginary * scale;
}

inline void bgc_complex_add_scaled_fp64(const BgcComplexFP64* basic_number, const BgcComplexFP64* scalable_number, const double scale, BgcComplexFP64* sum)
{
    sum->real = basic_number->real + scalable_number->real * scale;
    sum->imaginary = basic_number->imaginary + scalable_number->imaginary * scale;
}

// ================== Subtract ================== //

inline void bgc_complex_subtract_fp32(const BgcComplexFP32* minuend, const BgcComplexFP32* subtrahend, BgcComplexFP32* difference)
{
    difference->real = minuend->real - subtrahend->real;
    difference->imaginary = minuend->imaginary - subtrahend->imaginary;
}

inline void bgc_complex_subtract_fp64(const BgcComplexFP64* minuend, const BgcComplexFP64* subtrahend, BgcComplexFP64* difference)
{
    difference->real = minuend->real - subtrahend->real;
    difference->imaginary = minuend->imaginary - subtrahend->imaginary;
}

// ============== Subtract scaled =============== //

inline void bgc_complex_subtract_scaled_fp32(const BgcComplexFP32* basic_number, const BgcComplexFP32* scalable_number, const float scale, BgcComplexFP32* difference)
{
    difference->real = basic_number->real - scalable_number->real * scale;
    difference->imaginary = basic_number->imaginary - scalable_number->imaginary * scale;
}

inline void bgc_complex_subtract_scaled_fp64(const BgcComplexFP64* basic_number, const BgcComplexFP64* scalable_number, const double scale, BgcComplexFP64* difference)
{
    difference->real = basic_number->real - scalable_number->real * scale;
    difference->imaginary = basic_number->imaginary - scalable_number->imaginary * scale;
}

// ================== Multiply ================== //

inline void bgc_complex_multiply_fp32(const BgcComplexFP32* multiplicand, const float multiplier, BgcComplexFP32* product)
{
    product->real = multiplicand->real * multiplier;
    product->imaginary = multiplicand->imaginary * multiplier;
}

inline void bgc_complex_multiply_fp64(const BgcComplexFP64* multiplicand, const double multiplier, BgcComplexFP64* product)
{
    product->real = multiplicand->real * multiplier;
    product->imaginary = multiplicand->imaginary * multiplier;
}

// =================== Divide =================== //

inline void bgc_complex_divide_fp32(const BgcComplexFP32* dividend, const float divisor, BgcComplexFP32* quotient)
{
    bgc_complex_multiply_fp32(dividend, 1.0f / divisor, quotient);
}

inline void bgc_complex_divide_fp64(const BgcComplexFP64* dividend, const double divisor, BgcComplexFP64* quotient)
{
    bgc_complex_multiply_fp64(dividend, 1.0 / divisor, quotient);
}

// ================== Average2 ================== //

inline void bgc_complex_get_mean_of_two_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, BgcComplexFP32* mean)
{
    mean->real = (number1->real + number2->real) * 0.5f;
    mean->imaginary = (number1->imaginary + number2->imaginary) * 0.5f;
}

inline void bgc_complex_get_mean_of_two_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, BgcComplexFP64* mean)
{
    mean->real = (number1->real + number2->real) * 0.5;
    mean->imaginary = (number1->imaginary + number2->imaginary) * 0.5;
}

// ================== Average3 ================== //

inline void bgc_complex_get_mean_of_three_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, const BgcComplexFP32* number3, BgcComplexFP32* mean)
{
    mean->real = (number1->real + number2->real + number3->real) * BGC_ONE_THIRD_FP32;
    mean->imaginary = (number1->imaginary + number2->imaginary + number3->imaginary) * BGC_ONE_THIRD_FP32;
}

inline void bgc_complex_get_mean_of_three_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, const BgcComplexFP64* number3, BgcComplexFP64* mean)
{
    mean->real = (number1->real + number2->real + number3->real) * BGC_ONE_THIRD_FP64;
    mean->imaginary = (number1->imaginary + number2->imaginary + number3->imaginary) * BGC_ONE_THIRD_FP64;
}

// =================== Linear =================== //

inline void bgc_complex_get_linear_interpolation_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2, const float phase, BgcComplexFP32* interpolation)
{
    const float counterphase = 1.0f - phase;

    interpolation->real = number1->real * counterphase + number2->real * phase;
    interpolation->imaginary = number1->imaginary * counterphase + number2->imaginary * phase;
}

inline void bgc_complex_get_linear_interpolation_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2, const double phase, BgcComplexFP64* interpolation)
{
    const double counterphase = 1.0 - phase;

    interpolation->real = number1->real * counterphase + number2->real * phase;
    interpolation->imaginary = number1->imaginary * counterphase + number2->imaginary * phase;
}

// ================== Minimal =================== //

inline void bgc_complex_minimize_fp32(const BgcComplexFP32* number, BgcComplexFP32* minimal)
{
    if (number->real < minimal->real) {
        minimal->real = number->real;
    }

    if (number->imaginary < minimal->imaginary) {
        minimal->imaginary = number->imaginary;
    }
}

inline void bgc_complex_minimize_fp64(const BgcComplexFP64* number, BgcComplexFP64* minimal)
{
    if (number->real < minimal->real) {
        minimal->real = number->real;
    }

    if (number->imaginary < minimal->imaginary) {
        minimal->imaginary = number->imaginary;
    }
}

// ================== Maximal =================== //

inline void bgc_complex_maximize_fp32(const BgcComplexFP32* number, BgcComplexFP32* maximal)
{
    if (number->real > maximal->real) {
        maximal->real = number->real;
    }

    if (number->imaginary > maximal->imaginary) {
        maximal->imaginary = number->imaginary;
    }
}

inline void bgc_complex_maximize_fp64(const BgcComplexFP64* number, BgcComplexFP64* maximal)
{
    if (number->real > maximal->real) {
        maximal->real = number->real;
    }

    if (number->imaginary > maximal->imaginary) {
        maximal->imaginary = number->imaginary;
    }
}

// ================== Are Close ================= //

inline int bgc_complex_are_close_fp32(const BgcComplexFP32* number1, const BgcComplexFP32* number2)
{
    const float square_modulus1 = bgc_complex_get_square_modulus_fp32(number1);
    const float square_modulus2 = bgc_complex_get_square_modulus_fp32(number2);

    const float d_real = number1->real - number2->real;
    const float d_imaginary = number1->imaginary - number2->imaginary;

    const float square_distance = d_real * d_real + d_imaginary * d_imaginary;

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP32;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

inline int bgc_complex_are_close_fp64(const BgcComplexFP64* number1, const BgcComplexFP64* number2)
{
    const double square_modulus1 = bgc_complex_get_square_modulus_fp64(number1);
    const double square_modulus2 = bgc_complex_get_square_modulus_fp64(number2);

    const double d_real = number1->real - number2->real;
    const double d_imaginary = number1->imaginary - number2->imaginary;

    const double square_distance = d_real * d_real + d_imaginary * d_imaginary;

    if (square_modulus1 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64 || square_modulus2 <= BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64) {
        return square_distance <= BGC_SQUARE_EPSYLON_FP64;
    }

    return square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus1 && square_distance <= BGC_SQUARE_EPSYLON_FP32 * square_modulus2;
}

#endif
