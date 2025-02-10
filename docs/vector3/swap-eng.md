# Swapping

The exchange functions allow two vectors of the same type to exchange coordinate values.

Function for **BgcVector3FP32**:

```c
inline void bgc_vector3_swap_fp32(BgcVector3FP32* vector1, BgcVector3FP32* vector2);
```

Function for **BgcVector3FP32**:

```c
inline void bgc_vector3_swap_fp64(BgcVector3FP64* vector1, BgcVector3FP64* vector2);
```

The **vector1** and **vector2** parameters must not be invalid pointers. The NULL (0) value is also considered invalid.

Vector **vector1** after calling this function will have the coordinate values that vector **vector3** had before calling the function.

And vector **vector3** after calling this function will have the same coordinate values that vector **vector1** had before calling the function.

Example of use:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector3FP32 my_vector1, my_vector2;

    bgc_vector3_set_values_fp32(-2, 7, 5, &my_vector1);
    bgc_vector3_set_values_fp32(10, -1, -3, &my_vector2);

    bgc_vector3_swap_fp32(&my_vector1, &my_vector2);

    printf("Vector #1: x1 = %f, x2 = %f, x3 = %f\n", my_vector1.x1, my_vector1.x2, my_vector1.x3);
    printf("Vector #2: x1 = %f, x2 = %f, x3 = %f\n", my_vector2.x1, my_vector2.x2, my_vector2.x3);

    return 0;
}
```

Result:

```
Vector #1: x1 = 10.000000, x2 = -1.000000, x3 = -3.000000
Vector #2: x1 = -2.000000, x2 = 7.000000, x3 = 5.000000
```

[Documentation](../intro-eng.md) / [3D vectors](../vector3-eng.md)
