#include "quaternion.h"

extern inline void bgc_quaternion_reset_fp32(BgcQuaternionFP32* quaternion);
extern inline void bgc_quaternion_reset_fp64(BgcQuaternionFP64* quaternion);

extern inline void bgc_quaternion_set_to_identity_fp32(BgcQuaternionFP32* quaternion);
extern inline void bgc_quaternion_set_to_identity_fp64(BgcQuaternionFP64* quaternion);

extern inline void bgc_quaternion_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcQuaternionFP32* quaternion);
extern inline void bgc_quaternion_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcQuaternionFP64* quaternion);

extern inline float bgc_quaternion_get_square_modulus_fp32(const BgcQuaternionFP32* quaternion);
extern inline double bgc_quaternion_get_square_modulus_fp64(const BgcQuaternionFP64* quaternion);

extern inline float bgc_quaternion_get_modulus_fp32(const BgcQuaternionFP32* quaternion);
extern inline double bgc_quaternion_get_modulus_fp64(const BgcQuaternionFP64* quaternion);

extern inline int bgc_quaternion_is_zero_fp32(const BgcQuaternionFP32* quaternion);
extern inline int bgc_quaternion_is_zero_fp64(const BgcQuaternionFP64* quaternion);

extern inline int bgc_quaternion_is_unit_fp32(const BgcQuaternionFP32* quaternion);
extern inline int bgc_quaternion_is_unit_fp64(const BgcQuaternionFP64* quaternion);

extern inline void bgc_quaternion_copy_fp32(const BgcQuaternionFP32* source, BgcQuaternionFP32* destination);
extern inline void bgc_quaternion_copy_fp64(const BgcQuaternionFP64* source, BgcQuaternionFP64* destination);

extern inline void bgc_quaternion_swap_fp32(BgcQuaternionFP32* quarternion1, BgcQuaternionFP32* quarternion2);
extern inline void bgc_quaternion_swap_fp64(BgcQuaternionFP64* quarternion1, BgcQuaternionFP64* quarternion2);

extern inline void bgc_quaternion_convert_fp64_to_fp32(const BgcQuaternionFP64* source, BgcQuaternionFP32* destination);
extern inline void bgc_quaternion_convert_fp32_to_fp64(const BgcQuaternionFP32* source, BgcQuaternionFP64* destination);

extern inline void bgc_quaternion_conjugate_fp32(const BgcQuaternionFP32* quaternion, BgcQuaternionFP32* conjugate);
extern inline void bgc_quaternion_conjugate_fp64(const BgcQuaternionFP64* quaternion, BgcQuaternionFP64* conjugate);

extern inline int bgc_quaternion_invert_fp32(const BgcQuaternionFP32* quaternion, BgcQuaternionFP32* inverted);
extern inline int bgc_quaternion_invert_fp64(const BgcQuaternionFP64* quaternion, BgcQuaternionFP64* inverted);

extern inline int bgc_quaternion_normalize_fp32(const BgcQuaternionFP32* quaternion, BgcQuaternionFP32* normalized);
extern inline int bgc_quaternion_normalize_fp64(const BgcQuaternionFP64* quaternion, BgcQuaternionFP64* normalized);

extern inline void bgc_quaternion_get_product_fp32(const BgcQuaternionFP32* left, const BgcQuaternionFP32* right, BgcQuaternionFP32* product);
extern inline void bgc_quaternion_get_product_fp64(const BgcQuaternionFP64* left, const BgcQuaternionFP64* right, BgcQuaternionFP64* product);

extern inline int bgc_quaternion_get_ratio_fp32(const BgcQuaternionFP32* divident, const BgcQuaternionFP32* divisor, BgcQuaternionFP32* quotient);
extern inline int bgc_quaternion_get_ratio_fp64(const BgcQuaternionFP64* divident, const BgcQuaternionFP64* divisor, BgcQuaternionFP64* quotient);

extern inline void bgc_quaternion_add_fp32(const BgcQuaternionFP32* quaternion1, const BgcQuaternionFP32* quaternion2, BgcQuaternionFP32* sum);
extern inline void bgc_quaternion_add_fp64(const BgcQuaternionFP64* quaternion1, const BgcQuaternionFP64* quaternion2, BgcQuaternionFP64* sum);

extern inline void bgc_quaternion_add_scaled_fp32(const BgcQuaternionFP32* basic_quaternion, const BgcQuaternionFP32* scalable_quaternion, const float scale, BgcQuaternionFP32* sum);
extern inline void bgc_quaternion_add_scaled_fp64(const BgcQuaternionFP64* basic_quaternion, const BgcQuaternionFP64* scalable_quaternion, const double scale, BgcQuaternionFP64* sum);

extern inline void bgc_quaternion_subtract_fp32(const BgcQuaternionFP32* minuend, const BgcQuaternionFP32* subtrahend, BgcQuaternionFP32* difference);
extern inline void bgc_quaternion_subtract_fp64(const BgcQuaternionFP64* minuend, const BgcQuaternionFP64* subtrahend, BgcQuaternionFP64* difference);

extern inline void bgc_quaternion_subtract_scaled_fp32(const BgcQuaternionFP32* basic_quaternion, const BgcQuaternionFP32* scalable_quaternion, const float scale, BgcQuaternionFP32* difference);
extern inline void bgc_quaternion_subtract_scaled_fp64(const BgcQuaternionFP64* basic_quaternion, const BgcQuaternionFP64* scalable_quaternion, const double scale, BgcQuaternionFP64* difference);

extern inline void bgc_quaternion_multiply_fp32(const BgcQuaternionFP32* multiplicand, const float multipier, BgcQuaternionFP32* product);
extern inline void bgc_quaternion_multiply_fp64(const BgcQuaternionFP64* multiplicand, const double multipier, BgcQuaternionFP64* product);

extern inline void bgc_quaternion_divide_fp32(const BgcQuaternionFP32* dividend, const float divisor, BgcQuaternionFP32* quotient);
extern inline void bgc_quaternion_divide_fp64(const BgcQuaternionFP64* dividend, const double divisor, BgcQuaternionFP64* quotient);

extern inline void bgc_quaternion_get_linear_interpolation_fp32(const BgcQuaternionFP32* vector1, const BgcQuaternionFP32* vector2, const float phase, BgcQuaternionFP32* interpolation);
extern inline void bgc_quaternion_get_linear_interpolation_fp64(const BgcQuaternionFP64* vector1, const BgcQuaternionFP64* vector2, const double phase, BgcQuaternionFP64* interpolation);

extern inline int bgc_quaternion_get_rotation_matrix_fp32(const BgcQuaternionFP32* quaternion, BgcMatrix3x3FP32* rotation);
extern inline int bgc_quaternion_get_rotation_matrix_fp64(const BgcQuaternionFP64* quaternion, BgcMatrix3x3FP64* rotation);

extern inline int bgc_quaternion_get_reverse_matrix_fp32(const BgcQuaternionFP32* quaternion, BgcMatrix3x3FP32* reverse);
extern inline int bgc_quaternion_get_reverse_matrix_fp64(const BgcQuaternionFP64* quaternion, BgcMatrix3x3FP64* reverse);

extern inline int bgc_quaternion_get_both_matrixes_fp32(const BgcQuaternionFP32* quaternion, BgcMatrix3x3FP32* rotation, BgcMatrix3x3FP32* reverse);
extern inline int bgc_quaternion_get_both_matrixes_fp64(const BgcQuaternionFP64* quaternion, BgcMatrix3x3FP64* rotation, BgcMatrix3x3FP64* reverse);


extern inline int bgc_quaternion_are_close_fp32(const BgcQuaternionFP32* quaternion1, const BgcQuaternionFP32* quaternion2);
extern inline int bgc_quaternion_are_close_fp32(const BgcQuaternionFP32* quaternion1, const BgcQuaternionFP32* quaternion2);
