# Setting the coordinates of a three-dimensional vector

You can set the coordinates of vectors either directly or using functions. The functions for setting coordinate values allow you to do this in one line.

Function for **BgcVector3FP32**:

```c
inline void bgc_vector3_set_values_fp32(const float x1, const float x2, const float x3, BgcVector3FP32* to);
```

Function for **BgcVector3FP32**:

```c
inline void bgc_vector3_set_values_fp64(const double x1, const double x2, const double x3, BgcVector3FP64* to);
```

Each of these functions is equivalent to the following lines of code:

```c
to->x1 = x1;
to->x2 = x2;
to->x3 = x3;
```

Invalid pointers should not be passed in the **to** parameter. The NULL (0) value is also considered invalid.

Example of use:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector3FP32 my_vector;

    bgc_vector3_set_values_fp32(-2, 7, 10, &my_vector);

    printf("x1 = %f, x2 = %f, x3 = %f\n", my_vector.x1, my_vector.x2, my_vector.x3);

    return 0;
}
```

[Documentation](../intro-eng.md) / [3D vectors](../vector3-eng.md)
