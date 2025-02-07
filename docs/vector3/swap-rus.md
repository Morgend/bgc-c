# Обмен

Функции обмена позволяют двум векторам одного типа обменяться значениями координат.

Функция для **BgcVector3FP32**:

```c
inline void bgc_vector3_swap_fp32(BgcVector3FP32* vector1, BgcVector3FP32* vector2);
```

Функция для **BgcVector3FP32**:

```c
inline void bgc_vector3_swap_fp64(BgcVector3FP64* vector1, BgcVector3FP64* vector2);
```

Параметры **vector1** и **vector2** не должны быть некорректными указателями. Значение NULL (0) также считается некорректным.

Вектор **vector1** после вызова данной функции будет иметь значения координат, какие имел вектор **vector2** до вызова функции.

А вектор **vector2** после вызова данной функции будет иметь такие же значения координат, какие имел вектор **vector1** до вызова функции.

Пример применения:

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

Результат:

```
Vector #1: x1 = 10.000000, x2 = -1.000000, x3 = -3.000000
Vector #2: x1 = -2.000000, x2 = 7.000000, x3 = 5.000000
```

[Документация](../intro-rus.md) / [2D векторы](../vector3-rus.md)
