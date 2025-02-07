# Копирование

Функции копирования позволяют скопировать значения координат одного вектора в другой вектор.

Функция для **BgcVector2FP32**:

```c
inline void bgc_vector2_copy_fp32(const BgcVector2FP32* from, BgcVector2FP32* to);
```

Функция для **BgcVector2FP64**:

```c
inline void bgc_vector2_copy_fp64(const BgcVector2FP64* from, BgcVector2FP64* to);
```

Каждая из данных функции эквивалентна следующим строкам кода:

```c
to->x1 = from->x1;
to->x2 = from->x2;
```

Параметры **from** и **to** не должны быть некорректными указателями. Значение NULL (0) также считается некорректным.

Параметр **from** должен быть указателем на двумерный вектор, координаты которого должны быть скопированы. Координаты вектора **from** не изменятся после вызова функции.
 
Параметр **to** должен быть указателем на двумерный вектор, координаты которого должны быть изменены. Координаты вектора **to** после вызова функции станут такими же, как и у вектора **from**.

Пример применения:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector2FP32 my_vector1, my_vector2;

    bgc_vector2_set_values_fp32(-2, 7, &my_vector1);

    bgc_vector2_copy_fp32(&my_vector1, &my_vector2);

    printf("x1 = %f, x2 = %f\n", my_vector2.x1, my_vector2.x2);

    return 0;
}
```

[Документация](../intro-rus.md) / [2D векторы](../vector2-rus.md)
