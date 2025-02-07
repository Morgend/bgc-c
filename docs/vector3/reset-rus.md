# Сброс состояния трёхмерного вектора

Функции устанавливают значение 0 всем координатам трёхмерных векторов.

Функция для **BgcVector3FP32**:

```c
inline void bgc_vector3_reset_fp32(BgcVector3FP32* vector);
```

Функция для **BgcVector3FP64**:

```c
inline void bgc_vector3_reset_fp64(BgcVector3FP64* vector);
```

Каждая из данных функции эквивалентна следующим строкам кода:

```c
vector->x1 = 0;
vector->x2 = 0;
vector->x3 = 0;
```

В данные функции не следует передавать некорректные указатели. Значение NULL (0) также считается некорректным.

Пример применения:

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

[Документация](../intro-rus.md) / [2D векторы](../vector3-rus.md)
