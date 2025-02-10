# Копирование

Функции копирования позволяют скопировать значения координат одного вектора в другой вектор.

Функция для **BgcVector3FP32**:

```c
inline void bgc_vector3_copy_fp32(const BgcVector3FP32* from, BgcVector3FP32* to);
```

Функция для **BgcVector3FP64**:

```c
inline void bgc_vector3_copy_fp64(const BgcVector3FP64* from, BgcVector3FP64* to);
```

Каждая из данных функции эквивалентна следующим строкам кода:

```c
to->x1 = from->x1;
to->x2 = from->x2;
to->x3 = from->x3;
```

Параметры **from** и **to** не должны быть некорректными указателями. Значение NULL (0) также считается некорректным.

Параметр **from** должен быть указателем на трёхмерный вектор, координаты которого должны быть скопированы. Координаты вектора **from** не изменятся после вызова функции.
 
Параметр **to** должен быть указателем на трёхмерный вектор, координаты которого должны быть изменены. Координаты вектора **to** после вызова функции станут такими же, как и у вектора **from**.

Пример применения:

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

[Документация](../intro-rus.md) / [3D векторы](../vector3-rus.md)
