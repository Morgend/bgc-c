# Quaternions

Quaternions are hypercomplex numbers that extend the concept of complex numbers. They consist of one real component and three imaginary components:

q = w + ix + jy + kz

where:

- w, x, y, z &isin; R are real numbers
- i, j, k are imaginary units that satisfy the following conditions:
   - i<sup>2</sup> = j<sup>2</sup> = k<sup>2</sup> = ijk = -1

Quaternions were discovered by mathematician William Hamilton and introduced to the public in 1843. They have found wide application in computer graphics, robotics, and physics to describe rotations in three-dimensional space.

## Quaternion implementation in the library

The library provides two implementations of quaternions:

1. **General-purpose quaternions**
   - Support all basic operations (addition, subtraction, multiplication by a scalar, etc.).

2. **Versors**:
   - Specialized quaternions whose absolute value is always equal to one.
   - Suitable for describing rotations in three-dimensional space.
   - Do not support addition, subtraction, and multiplication by a scalar.

General-purpose quaternions can also be used to represent rotations in three-dimensional space. But the developer using quaternions to describe rotations must ensure that the absolute values of the quaternions do not become less than the error value and do not take the NaN (not a number) value.

### Quaternion structures

#### General purpose quaternions

```c
    typedef struct {
        float s0, x1, x2, x3;
    } BgcQuaternionFP32;

    typedef struct {
        double s0, x1, x2, x3;
    } BgcQuaternionFP64;
```

#### Versors

```c
    typedef struct {
        const float s0, x1, x2, x3;
    } BgcVersorFP32;

    typedef struct {
        const double s0, x1, x2, x3;
    } BgcVersorFP64;
```

Fields:
- s0 is the real part of the quaternion.
- x1, x2, x3 - Imaginary components of the quaternion.

The versor fields are declared as const so that the developer uses the library functions to work with versors, and does not change them directly.

The quaternion fields are free to be changed by the developer using the library.
