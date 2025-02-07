# Versors

[Quaternions](./quaternion-eng.md) are hypercomplex numbers that have one real component and three imaginary components:

q = w + ix + jy + kz

where:

- w, x, y, z &isin; R are real numbers
- i, j, k are imaginary units that satisfy the following conditions:
   - i<sup>2</sup> = j<sup>2</sup> = k<sup>2</sup> = ijk = -1

Quaternions were discovered by mathematician William Hamilton and introduced to the public in 1843. Hamilton later proposed a special class of quaternions, which he called versors.

## What is a versor?

A versor is a quaternion whose modulus is equal to one. That is, the formulas defining quaternions must be supplemented with the condition that the modulus of a quaternion is equal to one.

It is sufficient to add the equation of the modulus being equal to one to the formulas defining a quaternion:

q = w + ix + jy + kz

- w, x, y, z &isin; R are real numbers
- i, j, k are imaginary units that satisfy the following conditions:
   - i<sup>2</sup> = j<sup>2</sup> = k<sup>2</sup> = ijk = -1
- w<sup>2</sup> + x<sup>2</sup> + y<sup>2</sup> + z<sup>2</sup> = 1

The name comes from the Latin verb "versare", meaning "to turn", "to rotate", to which the Latin ending -or is added, denoting the subject performing the action. Literally, the Latin word "versor" can be translated as "rotator" or "turner".

## Using Versors

Versors have proven to be an excellent tool for describing rotations in three-dimensional space. The quaternion multiplication operation has proven useful for combining two consecutive rotations, and the conjugate quaternion operation has proven useful for obtaining the inverse rotation.

When multiplying two versors (quaternions of unit length) and taking the conjugate versor, the result will also be a versor, that is, a quaternion of unit length.

Addition and subtraction of two quaternions, as well as multiplication and division of a quaternion by a number, turned out to be unnecessary for describing rotations in three-dimensional space.

## Advantages of versors

1. **Preservation of modulus**: Versors preserve modulus equal to one, which prevents them from degenerating.
2. **Efficiency**: The BGC library automatically normalizes versors only when necessary, which avoids unnecessary computations.

## Implementation in the BGC library

The BGC library provides a separate implementation for versors in the form of structures and functions that keep the versor modulus close to one.

### Structures

```c
    typedef struct {
        const float s0, x1, x2, x3;
    } BgcVersorFP32;

    typedef struct {
        const double s0, x1, x2, x3;
    } BgcVersorFP64;
```

Fields:
- s0 is the real part of the versor.
- x1, x2, x3 are the imaginary components of the versor.

## Operation with versors

- [Reset state](./versor-reset-eng.md)
- [Specify component values](./versor-set-values-eng.md)
- Copy component values
- Swap component values
- Build based on rotation
- Check for absence of rotation
- Type conversion
- Rotation reduction
- Inversion
- Combination
- Get rotation description
- Get rotation matrix
- Get inverse rotation matrix
- Rotate vector
- Inverse vector rotation
- Compare
