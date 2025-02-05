#ifndef _BGC_ANGLE_H_
#define _BGC_ANGLE_H_

#include <math.h>
#include "utilities.h"

#define BGC_PI_FP32           3.1415926536f
#define BGC_TWO_PI_FP32       6.2831853072f
#define BGC_HALF_OF_PI_FP32   1.5707963268f
#define BGC_THIRD_OF_PI_FP32  1.0471975512f
#define BGC_FOURTH_OF_PI_FP32 0.7853981634f
#define BGC_SIXTH_OF_PI_FP32  0.5235987756f

#define BGC_DEGREES_IN_RADIAN_FP32 57.295779513f
#define BGC_TURNS_IN_RADIAN_FP32   0.1591549431f
#define BGC_RADIANS_IN_DEGREE_FP32 1.745329252E-2f
#define BGC_TURNS_IN_DEGREE_FP32   2.7777777778E-3f

#define BGC_PI_FP64           3.14159265358979324
#define BGC_TWO_PI_FP64       6.28318530717958648
#define BGC_HALF_OF_PI_FP64   1.57079632679489662
#define BGC_THIRD_OF_PI_FP64  1.04719755119659775
#define BGC_FOURTH_OF_PI_FP64 0.78539816339744831
#define BGC_SIXTH_OF_PI_FP64  0.523598775598298873

#define BGC_DEGREES_IN_RADIAN_FP64 57.2957795130823209
#define BGC_TURNS_IN_RADIAN_FP64   0.159154943091895336
#define BGC_RADIANS_IN_DEGREE_FP64 1.74532925199432958E-2
#define BGC_TURNS_IN_DEGREE_FP64   2.77777777777777778E-3

typedef enum {
    BGC_ANGLE_UNIT_RADIANS = 1,
    BGC_ANGLE_UNIT_DEGREES = 2,
    BGC_ANGLE_UNIT_TURNS   = 3
} BgcAngleUnitEnum;

typedef enum {
    /**
     * The measure of an angle with a range of:
     * [0, 360) degrees, [0, 2xPI) radians, [0, 1) turns, [0, 400) gradians
     */
    BGC_ANGLE_RANGE_UNSIGNED = 1,

    /**
     * The measure of an angle with a range of:
     * (-180, 180] degrees, (-PI, PI] radians, (-0.5, 0.5] turns, (-200, 200] gradians
     */
    BGC_ANGLE_RANGE_SIGNED = 2
} BgcAngleRangeEnum;

// !================= Radians ==================! //

// ========= Convert radians to degrees ========= //

inline float bgc_radians_to_degrees_fp32(const float radians)
{
    return radians * BGC_DEGREES_IN_RADIAN_FP32;
}

inline double bgc_radians_to_degrees_fp64(const double radians)
{
    return radians * BGC_DEGREES_IN_RADIAN_FP64;
}

// ========== Convert radians to turns ========== //

inline float bgc_radians_to_turns_fp32(const float radians)
{
    return radians * BGC_TURNS_IN_RADIAN_FP32;
}

inline double bgc_radians_to_turns_fp64(const double radians)
{
    return radians * BGC_TURNS_IN_RADIAN_FP64;
}

// ========= Convert radians to any unit ======== //

inline float bgc_radians_to_units_fp32(const float radians, const BgcAngleUnitEnum to_unit)
{
    if (to_unit == BGC_ANGLE_UNIT_DEGREES) {
        return radians * BGC_DEGREES_IN_RADIAN_FP32;
    }

    if (to_unit == BGC_ANGLE_UNIT_TURNS) {
        return radians * BGC_TURNS_IN_RADIAN_FP32;
    }

    return radians;
}

inline double bgc_radians_to_units_fp64(const double radians, const BgcAngleUnitEnum to_unit)
{
    if (to_unit == BGC_ANGLE_UNIT_DEGREES) {
        return radians * BGC_DEGREES_IN_RADIAN_FP64;
    }

    if (to_unit == BGC_ANGLE_UNIT_TURNS) {
        return radians * BGC_TURNS_IN_RADIAN_FP64;
    }

    return radians;
}

// ============ Normalize radians ============= //

inline float bgc_radians_normalize_fp32(const float radians, const BgcAngleRangeEnum range)
{
    if (range == BGC_ANGLE_RANGE_UNSIGNED) {
        if (0.0f <= radians && radians < BGC_TWO_PI_FP32) {
            return radians;
        }
    }
    else {
        if (-BGC_PI_FP32 < radians && radians <= BGC_PI_FP32) {
            return radians;
        }
    }

    float turns = radians * BGC_TURNS_IN_RADIAN_FP32;

    turns -= floorf(turns);

    if (range == BGC_ANGLE_RANGE_SIGNED && turns > 0.5f) {
        turns -= 1.0f;
    }

    return turns * BGC_TWO_PI_FP32;
}

inline double bgc_radians_normalize_fp64(const double radians, const BgcAngleRangeEnum range)
{
    if (range == BGC_ANGLE_RANGE_UNSIGNED) {
        if (0.0 <= radians && radians < BGC_TWO_PI_FP64) {
            return radians;
        }
    }
    else {
        if (-BGC_PI_FP64 < radians && radians <= BGC_PI_FP64) {
            return radians;
        }
    }

    double turns = radians * BGC_TURNS_IN_RADIAN_FP64;

    turns -= floor(turns);

    if (range == BGC_ANGLE_RANGE_SIGNED && turns > 0.5) {
        turns -= 1.0;
    }

    return turns * BGC_TWO_PI_FP64;
}

// !================= Degrees ==================! //

// ========= Convert degrees to radians ========= //

inline float bgc_degrees_to_radians_fp32(const float degrees)
{
    return degrees * BGC_RADIANS_IN_DEGREE_FP32;
}

inline double bgc_degrees_to_radians_fp64(const double degrees)
{
    return degrees * BGC_RADIANS_IN_DEGREE_FP64;
}

// ========== Convert degrees to turns ========== //

inline float bgc_degrees_to_turns_fp32(const float radians)
{
    return radians * BGC_TURNS_IN_DEGREE_FP32;
}

inline double bgc_degrees_to_turns_fp64(const double radians)
{
    return radians * BGC_TURNS_IN_DEGREE_FP64;
}

// ========= Convert degreess to any unit ======== //

inline float bgc_degrees_to_units_fp32(const float degrees, const BgcAngleUnitEnum to_unit)
{
    if (to_unit == BGC_ANGLE_UNIT_RADIANS) {
        return degrees * BGC_RADIANS_IN_DEGREE_FP32;
    }

    if (to_unit == BGC_ANGLE_UNIT_TURNS) {
        return degrees * BGC_TURNS_IN_DEGREE_FP32;
    }

    return degrees;
}

inline double bgc_degrees_to_units_fp64(const double degrees, const BgcAngleUnitEnum to_unit)
{
    if (to_unit == BGC_ANGLE_UNIT_RADIANS) {
        return degrees * BGC_RADIANS_IN_DEGREE_FP64;
    }

    if (to_unit == BGC_ANGLE_UNIT_TURNS) {
        return degrees * BGC_TURNS_IN_DEGREE_FP64;
    }

    return degrees;
}

// ============ Normalize degrees ============= //

inline float bgc_degrees_normalize_fp32(const float degrees, const BgcAngleRangeEnum range)
{
    if (range == BGC_ANGLE_RANGE_UNSIGNED) {
        if (0.0f <= degrees && degrees < 360.0f) {
            return degrees;
        }
    }
    else {
        if (-180.0f < degrees && degrees <= 180.0f) {
            return degrees;
        }
    }

    float turns = degrees * BGC_TURNS_IN_DEGREE_FP32;

    turns -= floorf(turns);

    if (range == BGC_ANGLE_RANGE_SIGNED && turns > 0.5f) {
        turns -= 1.0f;
    }

    return turns * 360.0f;
}

inline double bgc_degrees_normalize_fp64(const double degrees, const BgcAngleRangeEnum range)
{
    if (range == BGC_ANGLE_RANGE_UNSIGNED) {
        if (0.0 <= degrees && degrees < 360.0) {
            return degrees;
        }
    }
    else {
        if (-180.0 < degrees && degrees <= 180.0) {
            return degrees;
        }
    }

    double turns = degrees * BGC_TURNS_IN_DEGREE_FP64;

    turns -= floor(turns);

    if (range == BGC_ANGLE_RANGE_SIGNED && turns > 0.5) {
        turns -= 1.0;
    }

    return turns * 360.0;
}

// !================== Turns ===================! //

// ========== Convert turns to radians ========== //

inline float bgc_turns_to_radians_fp32(const float turns)
{
    return turns * BGC_TWO_PI_FP32;
}

inline double bgc_turns_to_radians_fp64(const double turns)
{
    return turns * BGC_TWO_PI_FP64;
}

// ========== Convert turns to degrees ========== //

inline float bgc_turns_to_degrees_fp32(const float turns)
{
    return turns * 360.0f;
}

inline double bgc_turns_to_degrees_fp64(const double turns)
{
    return turns * 360.0;
}

// ========= Convert turns to any unit ======== //

inline float bgc_turns_to_units_fp32(const float turns, const BgcAngleUnitEnum to_unit)
{
    if (to_unit == BGC_ANGLE_UNIT_RADIANS) {
        return turns * BGC_TWO_PI_FP32;
    }

    if (to_unit == BGC_ANGLE_UNIT_DEGREES) {
        return turns * 360.0f;
    }

    return turns;
}

inline double bgc_turns_to_units_fp64(const double turns, const BgcAngleUnitEnum to_unit)
{
    if (to_unit == BGC_ANGLE_UNIT_RADIANS) {
        return turns * BGC_TWO_PI_FP64;
    }

    if (to_unit == BGC_ANGLE_UNIT_DEGREES) {
        return turns * 360.0;
    }

    return turns;
}

// ============= Normalize turns ============== //

inline float bgc_turns_normalize_fp32(const float turns, const BgcAngleRangeEnum range)
{
    if (range == BGC_ANGLE_RANGE_UNSIGNED) {
        if (0.0f <= turns && turns < 1.0f) {
            return turns;
        }
    }
    else {
        if (-0.5f < turns && turns <= 0.5f) {
            return turns;
        }
    }

    float rest = turns - floorf(turns);

    if (range == BGC_ANGLE_RANGE_SIGNED && rest > 0.5f) {
        return rest - 1.0f;
    }

    return rest;
}

inline double bgc_turns_normalize_fp64(const double turns, const BgcAngleRangeEnum range)
{
    if (range == BGC_ANGLE_RANGE_UNSIGNED) {
        if (0.0 <= turns && turns < 1.0) {
            return turns;
        }
    }
    else {
        if (-0.5 < turns && turns <= 0.5) {
            return turns;
        }
    }

    double rest = turns - floor(turns);

    if (range == BGC_ANGLE_RANGE_SIGNED && rest > 0.5) {
        return rest - 1.0;
    }

    return rest;
}

// !================== Angle ===================! //

// ========= Convert any unit to radians ======== //

inline float bgc_angle_to_radians_fp32(const float angle, const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return angle * BGC_RADIANS_IN_DEGREE_FP32;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return angle * BGC_TWO_PI_FP32;
    }

    return angle;
}

inline double bgc_angle_to_radians_fp64(const double angle, const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return angle * BGC_RADIANS_IN_DEGREE_FP64;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return angle * BGC_TWO_PI_FP64;
    }

    return angle;
}

// ========= Convert any unit to degreess ======== //

inline float bgc_angle_to_degrees_fp32(const float angle, const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_RADIANS) {
        return angle * BGC_DEGREES_IN_RADIAN_FP32;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return angle * 360.0f;
    }

    return angle;
}

inline double bgc_angle_to_degrees_fp64(const double angle, const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_RADIANS) {
        return angle * BGC_DEGREES_IN_RADIAN_FP64;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return angle * 360.0;
    }

    return angle;
}

// ========= Convert any unit to turns ======== //

inline float bgc_angle_to_turns_fp32(const float angle, const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_RADIANS) {
        return angle * BGC_TURNS_IN_RADIAN_FP32;
    }

    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return angle * BGC_TURNS_IN_DEGREE_FP32;
    }

    return angle;
}

inline double bgc_angle_to_turns_fp64(const double angle, const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_RADIANS) {
        return angle * BGC_TURNS_IN_RADIAN_FP64;
    }

    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return angle * BGC_TURNS_IN_DEGREE_FP64;
    }

    return angle;
}

// ============= Get Full Circle ============== //

inline float bgc_angle_get_full_circle_fp32(const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return 360.0f;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return 1.0f;
    }

    return BGC_TWO_PI_FP32;
}

inline double bgc_angle_get_full_circle_fp64(const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return 360.0;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return 1.0;
    }

    return BGC_TWO_PI_FP64;
}

// ============= Get Half Circle ============== //

inline float bgc_angle_get_half_circle_fp32(const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return 180.0f;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return 0.5f;
    }

    return BGC_PI_FP32;
}

inline double bgc_angle_get_half_circle_fp64(const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return 180.0;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return 0.5;
    }

    return BGC_PI_FP64;
}

// ============= Get Half Circle ============== //

inline float bgc_angle_get_quater_circle_fp32(const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return 90.0f;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return 0.25f;
    }

    return BGC_HALF_OF_PI_FP32;
}

inline double bgc_angle_get_quater_circle_fp64(const BgcAngleUnitEnum unit)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return 90.0;
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return 0.25;
    }

    return BGC_HALF_OF_PI_FP64;
}

// ================ Normalize ================= //

inline float bgc_angle_normalize_fp32(const float angle, const BgcAngleUnitEnum unit, const BgcAngleRangeEnum range)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return bgc_degrees_normalize_fp32(angle, range);
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return bgc_turns_normalize_fp32(angle, range);
    }

    return bgc_radians_normalize_fp32(angle, range);
}

inline double bgc_angle_normalize_fp64(const double angle, const BgcAngleUnitEnum unit, const BgcAngleRangeEnum range)
{
    if (unit == BGC_ANGLE_UNIT_DEGREES) {
        return bgc_degrees_normalize_fp64(angle, range);
    }

    if (unit == BGC_ANGLE_UNIT_TURNS) {
        return bgc_turns_normalize_fp64(angle, range);
    }

    return bgc_radians_normalize_fp64(angle, range);
}

#endif
