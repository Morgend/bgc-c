# Two dimensional vectors

There are two types of 2D vectors in the library:
- **BgcVector2FP32** - vector using single-precision floating-point numbers
- **BgcVector2FP64** - vector using double-precision floating-point numbers

Structure definitions:

```c
    typedef struct
    {
        float x1, x2;
    } BgcVector2FP32;

    typedef struct
    {
        double x1, x2;
    } BgcVector2FP64;
```

## Functions

| Funtions for BgcVector2FP32                                   | Funtions for BgcVector2FP64                                   |
|:-------------------------------------------------------------:|:-------------------------------------------------------------:|
| [bgc_vector2_reset_fp32](vector2/reset-eng.md)                | [bgc_vector2_reset_fp64](vector2/reset-eng.md)                |
| [bgc_vector2_set_values_fp32](vector2/set-values-eng.md)      | [bgc_vector2_set_values_fp64](vector2/set-values-eng.md)      |
| [bgc_vector2_copy_fp32](vector2/copy-eng.md)                  | [bgc_vector2_copy_fp64](vector2/copy-eng.md)                  |
| [bgc_vector2_swap_fp32](vector2/swap-eng.md)                  | [bgc_vector2_swap_fp64](vector2/swap-eng.md)                  |


[Documentation](intro-eng.md)
