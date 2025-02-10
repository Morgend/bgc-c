# Resetting the state of a 3D vector

These functions set all coordinates of 3D vectors to 0.

Function for **BgcVector3FP32**:

```c
inline void bgc_vector3_reset_fp32(BgcVector3FP32* vector);
```

Function for **BgcVector3FP64**:

```c
inline void bgc_vector3_reset_fp64(BgcVector3FP64* vector);
```

Each of these functions is equivalent to the following lines of code:

```c
vector->x1 = 0;
vector->x2 = 0;
vector->x3 = 0;
```

You should not pass invalid pointers to these functions. The NULL (0) value is also considered invalid.

Example of use:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector3FP32 my_vector;

    bgc_vector3_reset_fp32(&my_vector);

    printf("x1 = %f, x2 = %f, x3 = %f\n", my_vector.x1, my_vector.x2, my_vector.x3);

    return 0;
}
```

[Documentation](../intro-eng.md) / [3D vectors](../vector3-eng.md)
