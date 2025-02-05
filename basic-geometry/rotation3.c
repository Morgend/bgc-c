#include "rotation3.h"

const BgcRotation3FP32 BGC_IDLE_ROTATION3_FP32 = { {0.0f, 0.0f, 0.0f}, 0.0f};

const BgcRotation3FP64 BGC_IDLE_ROTATION3_FP64 = { {0.0, 0.0, 0.0}, 0.0};

extern inline void bgc_rotation3_reset_fp32(BgcRotation3FP32* rotation);
extern inline void bgc_rotation3_reset_fp64(BgcRotation3FP64* rotation);

extern inline void bgc_rotation3_set_values_fp32(const float x1, const float x2, const float x3, const float angle, const BgcAngleUnitEnum unit, BgcRotation3FP32* rotation);
extern inline void bgc_rotation3_set_values_fp64(const double x1, const double x2, const double x3, const double angle, const BgcAngleUnitEnum unit, BgcRotation3FP64* rotation);

extern inline void bgc_rotation3_set_with_axis_fp32(const BgcVector3FP32* axis, const float angle, const BgcAngleUnitEnum unit, BgcRotation3FP32* rotation);
extern inline void bgc_rotation3_set_with_axis_fp64(const BgcVector3FP64* axis, const double angle, const BgcAngleUnitEnum unit, BgcRotation3FP64* rotation);
