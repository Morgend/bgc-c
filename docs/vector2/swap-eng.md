# Swapping

The exchange functions allow two vectors of the same type to exchange coordinate values.

Function for **BgcVector2FP32**:

```c
inline void bgc_vector2_swap_fp32(BgcVector2FP32* vector1, BgcVector2FP32* vector2);
```

Function for **BgcVector2FP32**:

```c
inline void bgc_vector2_swap_fp64(BgcVector2FP64* vector1, BgcVector2FP64* vector2);
```

The **vector1** and **vector2** parameters must not be invalid pointers. The NULL (0) value is also considered invalid.

Vector **vector1** after calling this function will have the coordinate values that vector **vector2** had before calling the function.

And vector **vector2** after calling this function will have the same coordinate values that vector **vector1** had before calling the function.

Example of use:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector2FP32 my_vector1, my_vector2;

    bgc_vector2_set_values_fp32(-2, 7, &my_vector1);
    bgc_vector2_set_values_fp32(10, -1, &my_vector2);

    bgc_vector2_swap_fp32(&my_vector1, &my_vector2);

    printf("Vector #1: x1 = %f, x2 = %f\n", my_vector1.x1, my_vector1.x2);
    printf("Vector #2: x1 = %f, x2 = %f\n", my_vector2.x1, my_vector2.x2);

    return 0;
}
```

[Documentation](../intro-eng.md) / [2D vectors](../vector2-eng.md)
