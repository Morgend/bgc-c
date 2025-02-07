# Сброс состояния двумерного вектора

Функции устанавливают значение 0 всем координатам двумерных векторов.

Функция для **BgcVector2FP32**:

```c
inline void bgc_vector2_reset_fp32(BgcVector2FP32* vector);
```

Функция для **BgcVector2FP64**:

```c
inline void bgc_vector2_reset_fp64(BgcVector2FP64* vector);
```

Каждая из данных функции эквивалентна следующим строкам кода:

```c
vector->x1 = 0;
vector->x2 = 0;
```

В параметре **vector** не следует передавать некорректные указатели. Значение NULL (0) также считается некорректным.

Пример применения:

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

[Документация](../intro-rus.md) / [2D векторы](../vector2-rus.md)
