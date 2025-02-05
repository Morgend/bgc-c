# Versors

Quaternions are complex numbers which have one real component and three
imaginary components.

A quaternion can be viewed as a four-dimensional vector:

1. summation and subtraction of quaternions are same as for four-dimensional
vectors in Euclidean space;

2. quaternions can be multiplied by real numbers the same way as
four-dimensional vectors;

3. the modulus of a quaternion is calculated in exactly the same way as
the modulus of a vector in four-dimensional Euclidean space;

4. the multiplication of two quaternions can be represented as the product
of a 4x4 matrix and a four-dimensional vector.

A quaternion has four degrees of freedom. But if we introduce a constraint in
the form of a requirement that the modulus of this quaternion be equal to one,
then such a set of quaternions will have only three degrees of freedom.

These quaternions represent a sphere of radius 1 in four-dimensional space.
The "surface" of this sphere has a dimension equal to three.

Quaternions of unit length describe rotations in three-dimensional space very
well. And this is logical, because rotations in three-dimensional space have
three degrees of freedom, just like a sphere in four-dimensional space.

There is a special name for a quaternion of unit length: versor.

Versors are quaternions of unit length.

## Implementation of versors in the library

The library has a separate implementation for versors in the form of special
structures and a set of functions that keep the modulus of a versorclose to one.

There are two structures for versors: **BgcVersorFP32** and **BgcVersorFP64**:

    typedef struct {
        const float s0, x1, x2, x3;
    } BgcVersorFP32;

    typedef struct {
        const double s0, x1, x2, x3;
    } BgcVersorFP64;

The fields are deliberately declared const so that a developer using these
structures is not tempted to change the values ​​of the fields directly.

With these structures, it is better to use special functions that allow you
to save new values ​​in the structure fields of **BgcVersorFP32** and
**BgcVersorFP64**.
