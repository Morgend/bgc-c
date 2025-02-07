# Resetting the state of a 2D vector

These functions set all coordinates of 2D vectors to 0.

Function for **BgcVector2FP32**:

```c
    inline void bgc_vector2_reset_fp32(BgcVector2FP32* vector);
```

Function for **BgcVector2FP64**:

```c
    inline void bgc_vector2_reset_fp64(BgcVector2FP64* vector);
```

Each of these functions is equivalent to the following lines of code:

```c
    vector->x1 = 0;
    vector->x2 = 0;
```

You should not pass invalid pointers to these functions. The NULL (0) value is also considered invalid.

Example of use:

```c
    #include <stdio.h>
    #include <basic-geometry.h>

    int main()
    {
        BgcVector2FP32 my_vector;

        bgc_vector2_reset_fp32(&my_vector);

        printf("x1 = %f, x2 = %f\n", my_vector.x1, my_vector.x2);

        return 0;
    }
```

[Documentation](../intro-eng.md) / [2D vectors](../vector2-eng.md)
