# Задание координат трёхмерного вектора

Задавать координаты векторов можно как напрямую, так и спомощью функций. Функции задания значений координат позволяют сделать это одной строкой.

Функция для **BgcVector3FP32**:

```c
inline void bgc_vector3_set_values_fp32(const float x1, const float x2, const float x3, BgcVector3FP32* to);
```

Функция для **BgcVector3FP32**:

```c
inline void bgc_vector3_set_values_fp64(const double x1, const double x2, const double x3, BgcVector3FP64* to);
```

Каждая из данных функции эквивалентна следующим строкам кода:

```c
to->x1 = x1;
to->x2 = x2;
to->x3 = x3;
```

В параметре **to** не следует передавать некорректные указатели. Значение NULL (0) также считается некорректным.

Пример применения:

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

[Документация](../intro-rus.md) / [3D векторы](../vector3-rus.md)
