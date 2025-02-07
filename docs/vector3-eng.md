# Three-dimensional vectors

There are two types of 3D vectors in the library:
- **BgcVector3FP32** - vector using single-precision floating-point numbers
- **BgcVector3FP64** - vector using double-precision floating-point numbers

Structure definitions:

```c
    typedef struct
    {
        float x1, x2, x3;
    } BgcVector3FP32;

    typedef struct
    {
        double x1, x2, x3;
    } BgcVector3FP64;
```

## Functions

| Funtions for BgcVector3FP32                                   | Funtions for BgcVector3FP64                                   |
|:-------------------------------------------------------------:|:-------------------------------------------------------------:|
| [bgc_vector3_reset_fp32](vector3/reset-eng.md)                | [bgc_vector3_reset_fp64](vector3/reset-eng.md)                |
| [bgc_vector3_set_values_fp32](vector3/set-values-eng.md)      | [bgc_vector3_set_values_fp64](vector3/set-values-eng.md)      |
| [bgc_vector3_copy_fp32](vector3/copy-eng.md)                  | [bgc_vector3_copy_fp64](vector3/copy-eng.md)                  |
| [bgc_vector3_swap_fp32](vector3/swap-eng.md)                  | [bgc_vector3_swap_fp64](vector3/swap-eng.md)                  |


[Documentation](intro-eng.md)
