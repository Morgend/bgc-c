#include "utilities.h"
#include "angle.h"

// !================= Radians ==================! //

extern inline float bgc_radians_to_degrees_fp32(const float radians);
extern inline double bgc_radians_to_degrees_fp64(const double radians);

extern inline float bgc_radians_to_turns_fp32(const float radians);
extern inline double bgc_radians_to_turns_fp64(const double radians);

extern inline float bgc_radians_to_units_fp32(const float radians, const BgcAngleUnitEnum to_unit);
extern inline double bgc_radians_to_units_fp64(const double radians, const BgcAngleUnitEnum to_unit);

extern inline float bgc_radians_normalize_fp32(const float radians, const BgcAngleRangeEnum range);
extern inline double bgc_radians_normalize_fp64(const double radians, const BgcAngleRangeEnum range);

// !================= Degrees ==================! //

extern inline float bgc_degrees_to_radians_fp32(const float degrees);
extern inline double bgc_degrees_to_radians_fp64(const double degrees);

extern inline float bgc_degrees_to_turns_fp32(const float radians);
extern inline double bgc_degrees_to_turns_fp64(const double radians);

extern inline float bgc_degrees_to_units_fp32(const float degrees, const BgcAngleUnitEnum to_unit);
extern inline double bgc_degrees_to_units_fp64(const double degrees, const BgcAngleUnitEnum to_unit);

extern inline float bgc_degrees_normalize_fp32(const float degrees, const BgcAngleRangeEnum range);
extern inline double bgc_degrees_normalize_fp64(const double degrees, const BgcAngleRangeEnum range);

// !================== Turns ===================! //

extern inline float bgc_turns_to_radians_fp32(const float turns);
extern inline double bgc_turns_to_radians_fp64(const double turns);

extern inline float bgc_turns_to_degrees_fp32(const float turns);
extern inline double bgc_turns_to_degrees_fp64(const double turns);

extern inline float bgc_turns_to_units_fp32(const float turns, const BgcAngleUnitEnum to_unit);
extern inline double bgc_turns_to_units_fp64(const double turns, const BgcAngleUnitEnum to_unit);

extern inline float bgc_turns_normalize_fp32(const float turns, const BgcAngleRangeEnum range);
extern inline double bgc_turns_normalize_fp64(const double turns, const BgcAngleRangeEnum range);

// !================== Angle ===================! //

extern inline float bgc_angle_to_radians_fp32(const float angle, const BgcAngleUnitEnum unit);
extern inline double bgc_angle_to_radians_fp64(const double angle, const BgcAngleUnitEnum unit);

extern inline float bgc_angle_to_degrees_fp32(const float angle, const BgcAngleUnitEnum unit);
extern inline double bgc_angle_to_degrees_fp64(const double angle, const BgcAngleUnitEnum unit);

extern inline float bgc_angle_to_turns_fp32(const float angle, const BgcAngleUnitEnum unit);
extern inline double bgc_angle_to_turns_fp64(const double angle, const BgcAngleUnitEnum unit);

extern inline float bgc_angle_get_full_circle_fp32(const BgcAngleUnitEnum unit);
extern inline double bgc_angle_get_full_circle_fp64(const BgcAngleUnitEnum unit);

extern inline float bgc_angle_get_half_circle_fp32(const BgcAngleUnitEnum unit);
extern inline double bgc_angle_get_half_circle_fp64(const BgcAngleUnitEnum unit);

extern inline float bgc_angle_get_quater_circle_fp32(const BgcAngleUnitEnum unit);
extern inline double bgc_angle_get_quater_circle_fp64(const BgcAngleUnitEnum unit);

extern inline float bgc_angle_normalize_fp32(const float angle, const BgcAngleUnitEnum unit, const BgcAngleRangeEnum range);
extern inline double bgc_angle_normalize_fp64(const double angle, const BgcAngleUnitEnum unit, const BgcAngleRangeEnum range);
