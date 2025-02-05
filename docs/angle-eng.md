# Angles

There are no structures for angles in the library. The library represents
angles as floating point numbers of types **float** and **double**.

There are three units of measurement for angles in the library:
* radians (the full round is equal to 2π radians)
* degrees (the full round is equal to 360 degrees)
* turns (the full round is equal to 1 turn)

The units of measurement of angles are defined with an enumerated type:

    typedef enum {
        BGC_ANGLE_UNIT_RADIANS = 1,
        BGC_ANGLE_UNIT_DEGREES = 2,
        BGC_ANGLE_UNIT_TURNS   = 3
    } BgcAngleUnitEnum;

* BGC_ANGLE_UNIT_RADIANS is for measurement of angles in radians
* BGC_ANGLE_UNIT_DEGREES is for measurement of angles in degrees
* BGC_ANGLE_UNIT_TURNS is for measurement of angles in turns

The functions of the library do not require angle values to be limited by any
range. But there are functions which can normalize angles to specific ranges.

There are two ranges of normalized angles: a signed range and an unsigned
range.

The unsigned range has no negative values. The unsigned range corresponds:
* [0, 2π) radians
* [0, 360) degrees
* [0, 1) turns

The signed range has both positive and negative values. The signed range
corresponds:
* (-π, π] radians
* (-180, 180] degrees
* (-0.5, 0.5] turns

The ranges of angles are defined with an enumerated type:

    typedef enum {
        BGC_ANGLE_RANGE_UNSIGNED = 1,
        BGC_ANGLE_RANGE_SIGNED = 2
    } BgcAngleRangeEnum;

* BGC_ANGLE_RANGE_UNSIGNED is for the unsigned range of values;
* BGC_ANGLE_RANGE_SIGNED is for the signed range of values.
