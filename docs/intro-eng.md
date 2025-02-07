# Naming

## Prefixes

The library uses prefixes in names of types, constants and functions.

The main prefix is **BGC** which means **B**asic **G**eometric **C**omputations.

The structure types have prefix in the form **Bgc**. For example: BgcVector3FP64,
BgcVersorFP32, BgcMatrix2x2FP32.

The constants have prefix in the form **BGC_**. For example: BGC_EPSYLON_FP32,
BGC_TWO_PI_FP64.

The functions have prefix in the form **bgc_**. For example:
bgc_versor_combine_fp32, bgc_matrix3x3_subtract_fp32.

## Suffixes

Suffixs of type ends the names of constats, types and functions of the library.
The library uses two types of floating point numbers: **float** and  **double**
(**binary32** and **binary64** types of the **IEEE 754** standard).

Thus there are two suffixes of types:

* **FP32** - means **F**loating **P**oint, **32** bit, which corresponds to the
**float** type of the C language.

* **FP64** - means **F**loating **P**oint, **64** bit, which corresponds to the
**double** type of the C language.

The types of structures which are based in the **float** type have **FP32** as
the type prefix: BgcVector3FP32, BgcMatrix3x2FP32, BgcQuaternionFP32.

The types of structures which are based in the **double** type have **FP64** as
the type prefix: BgcVector2FP64, BgcMatrix2x3FP64, BgcVersorFP64.

The constants of the **float** type have **_FP32** as the type suffix:
BGC_PI_FP32, BGC_EPSYLON_FP32.

The constants of the **double** type have **_FP64** as the type suffix:
BGC_HALF_PI_FP64, BGC_ONE_THIRD_FP64.

The functions which works with data of the **float** type have **_fp32** as
the type suffix: bgc_vector2_get_modulus_fp64, bgc_radians_to_degrees_fp32.

The functions which works with data of the **double** type have **_fp64** as
the type suffix: bgc_vector3_reset_fp64, bgc_radians_normalize_fp64.

## Entities

- Vectors 2D and 3D
- [Versors](./versor-eng.md)

