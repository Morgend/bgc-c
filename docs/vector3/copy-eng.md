# Copying

The copy functions allow you to copy the coordinate values of one vector to another vector.

Function for **BgcVector3FP32**:

```c
inline void bgc_vector3_copy_fp32(const BgcVector3FP32* from, BgcVector3FP32* to);
```

Function for **BgcVector3FP64**:

```c
inline void bgc_vector3_copy_fp64(const BgcVector3FP64* from, BgcVector3FP64* to);
```

Each of these functions is equivalent to the following lines of code:

```c
to->x1 = from->x1;
to->x2 = from->x2;
to->x3 = from->x3;
```

The **from** and **to** parameters must not be invalid pointers. The NULL (0) value is also considered invalid.

The **from** parameter must be a pointer to a three-dimensional vector whose coordinates are to be copied. The coordinates of the **from** vector will not change after the function call.

The **to** parameter must be a pointer to a three-dimensional vector whose coordinates are to be changed. The coordinates of the **to** vector will become the same as those of the **from** vector after the function call.

Example of use:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector3FP32 my_vector1, my_vector3;

    bgc_vector3_set_values_fp32(-2, 7, 1, &my_vector1);

    bgc_vector3_copy_fp32(&my_vector1, &my_vector3);

    printf("x1 = %f, x2 = %f, x3 = %f\n", my_vector3.x1, my_vector3.x2, my_vector3.x3);

    return 0;
}
```

[Documentation](../intro-eng.md) / [3D vectors](../vector3-eng.md)
