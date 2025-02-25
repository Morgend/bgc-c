#ifndef _BGC_ROTATION3_H_
#define _BGC_ROTATION3_H_

#include "utilities.h"
#include "angle.h"
#include "vector3.h"

typedef struct {
    BgcVector3FP32 axis;
    float radians;
} BgcRotation3FP32;

typedef struct {
    BgcVector3FP64 axis;
    double radians;
} BgcRotation3FP64;

extern const BgcRotation3FP32 BGC_IDLE_ROTATION3_FP32;

extern const BgcRotation3FP64 BGC_IDLE_ROTATION3_FP64;

// =================== Reset ==================== //

inline void bgc_rotation3_reset_fp32(BgcRotation3FP32* rotation)
{
    rotation->axis.x1 = 0.0f;
    rotation->axis.x2 = 0.0f;
    rotation->axis.x3 = 0.0f;

    rotation->radians = 0.0f;
}

inline void bgc_rotation3_reset_fp64(BgcRotation3FP64* rotation)
{
    rotation->axis.x1 = 0.0;
    rotation->axis.x2 = 0.0;
    rotation->axis.x3 = 0.0;

    rotation->radians = 0.0;
}

// ================= Set Values ================= //

inline void bgc_rotation3_set_values_fp32(const float x1, const float x2, const float x3, const float angle, const BgcAngleUnitEnum unit, BgcRotation3FP32* rotation)
{
    rotation->axis.x1 = x1;
    rotation->axis.x2 = x2;
    rotation->axis.x3 = x3;

    if (bgc_vector3_normalize_fp32(&rotation->axis, &rotation->axis)) {
        rotation->radians = bgc_angle_to_radians_fp32(angle, unit);
    }
    else {
        rotation->radians = 0.0f;
    }
}


inline void bgc_rotation3_set_values_fp64(const double x1, const double x2, const double x3, const double angle, const BgcAngleUnitEnum unit, BgcRotation3FP64* rotation)
{
    rotation->axis.x1 = x1;
    rotation->axis.x2 = x2;
    rotation->axis.x3 = x3;

    if (bgc_vector3_normalize_fp64(&rotation->axis, &rotation->axis)) {
        rotation->radians = bgc_angle_to_radians_fp64(angle, unit);
    }
    else {
        rotation->radians = 0.0;
    }
}

inline void bgc_rotation3_set_with_axis_fp32(const BgcVector3FP32* axis, const float angle, const BgcAngleUnitEnum unit, BgcRotation3FP32* rotation)
{
    rotation->axis.x1 = axis->x1;
    rotation->axis.x2 = axis->x2;
    rotation->axis.x3 = axis->x3;

    if (bgc_vector3_normalize_fp32(&rotation->axis, &rotation->axis)) {
        rotation->radians = bgc_angle_to_radians_fp32(angle, unit);
    }
    else {
        rotation->radians = 0.0f;
    }
}

inline void bgc_rotation3_set_with_axis_fp64(const BgcVector3FP64* axis, const double angle, const BgcAngleUnitEnum unit, BgcRotation3FP64* rotation)
{
    rotation->axis.x1 = axis->x1;
    rotation->axis.x2 = axis->x2;
    rotation->axis.x3 = axis->x3;

    if (bgc_vector3_normalize_fp64(&rotation->axis, &rotation->axis)) {
        rotation->radians = bgc_angle_to_radians_fp64(angle, unit);
    }
    else {
        rotation->radians = 0.0;
    }
}

#endif
