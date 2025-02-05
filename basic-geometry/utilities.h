#ifndef _BGC_UTILITIES_H_
#define _BGC_UTILITIES_H_

#define BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32 10.0f

#define BGC_EPSYLON_FP32 5E-7f
#define BGC_SQUARE_EPSYLON_FP32 2.5E-13f

#define BGC_ONE_THIRD_FP32 0.333333333f
#define BGC_ONE_SIXTH_FP32 0.166666667f
#define BGC_ONE_NINETH_FP32 0.111111111f

#define BGC_GOLDEN_RATIO_HIGH_FP32 1.618034f
#define BGC_GOLDEN_RATIO_LOW_FP32 0.618034f

#define BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64 10.0

#define BGC_EPSYLON_FP64 5E-14
#define BGC_SQUARE_EPSYLON_FP64 2.5E-27

#define BGC_ONE_THIRD_FP64 0.333333333333333333
#define BGC_ONE_SIXTH_FP64 0.166666666666666667
#define BGC_ONE_NINETH_FP64 0.111111111111111111

#define BGC_GOLDEN_RATIO_HIGH_FP64 1.61803398874989485
#define BGC_GOLDEN_RATIO_LOW_FP64 0.61803398874989485

inline int bgc_is_zero_fp32(const float square_value)
{
    return (-BGC_EPSYLON_FP32 <= square_value) && (square_value <= BGC_EPSYLON_FP32);
}

inline int bgc_is_zero_fp64(const double square_value)
{
    return (-BGC_EPSYLON_FP64 <= square_value) && (square_value <= BGC_EPSYLON_FP64);
}


inline int bgc_is_unit_fp32(const float square_value)
{
    return (1.0f - BGC_EPSYLON_FP32 <= square_value) && (square_value <= 1.0f + BGC_EPSYLON_FP32);
}

inline int bgc_is_unit_fp64(const double square_value)
{
    return (1.0 - BGC_EPSYLON_FP64 <= square_value) && (square_value <= 1.0 + BGC_EPSYLON_FP64);
}


inline int bgc_is_sqare_value_unit_fp32(const float square_value)
{
    return (1.0f - 2.0f * BGC_EPSYLON_FP32 <= square_value) && (square_value <= 1.0f + 2.0f * BGC_EPSYLON_FP32);
}

inline int bgc_is_sqare_value_unit_fp64(const double square_value)
{
    return (1.0 - 2.0 * BGC_EPSYLON_FP64 <= square_value) && (square_value <= 1.0 + 2.0 * BGC_EPSYLON_FP64);
}


inline int bgc_are_equal_fp32(const float value1, const float value2)
{
    if (-BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32 < value1 && value1 < BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP32) {
        return -BGC_EPSYLON_FP32 <= (value1 - value2) && (value1 - value2) <= BGC_EPSYLON_FP32;
    }

    if (value1 < 0.0f) {
        return (1.0f + BGC_EPSYLON_FP32) * value2 <= value1 && (1.0f + BGC_EPSYLON_FP32) * value1 <= value2;
    }

    return value2 <= value1 * (1.0f + BGC_EPSYLON_FP32) && value1 <= value2 * (1.0f + BGC_EPSYLON_FP32);
}

inline int bgc_are_equal_fp64(const double value1, const double value2)
{
    if (-BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64 < value1 && value1 < BGC_EPSYLON_EFFECTIVENESS_LIMIT_FP64) {
        return -BGC_EPSYLON_FP64 <= (value1 - value2) && (value1 - value2) <= BGC_EPSYLON_FP64;
    }

    if (value1 < 0.0) {
        return (1.0 + BGC_EPSYLON_FP64) * value2 <= value1 && (1.0 + BGC_EPSYLON_FP64) * value1 <= value2;
    }

    return value2 <= value1 * (1.0 + BGC_EPSYLON_FP64) && value1 <= value2 * (1.0 + BGC_EPSYLON_FP64);
}

#endif
