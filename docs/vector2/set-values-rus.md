# Задание координат двумерного вектора

Задавать координаты векторов можно как напрямую, так и спомощью функций. Функции задания значений координат позволяют сделать это одной строкой.

Функция для **BgcVector2FP32**:

```c
    inline void bgc_vector2_set_values_fp32(const float x1, const float x2, BgcVector2FP32* to);
```

Функция для **BgcVector2FP32**:

```c
    inline void bgc_vector2_set_values_fp64(const double x1, const double x2, BgcVector2FP64* to);
```

Каждая из данных функции эквивалентна следующим строкам кода:

```c
    vector->x1 = x1;
    vector->x2 = x2;
```

В данные функции не следует передавать некорректные указатели. Значение NULL (0) также считается некорректным.

Пример применения:

```c
    #include <stdio.h>
    #include <basic-geometry.h>

    int main()
    {
        BgcVector2FP32 my_vector;

        bgc_vector2_set_values_fp32(-2, 7, &my_vector);

        printf("x1 = %f, x2 = %f\n", my_vector.x1, my_vector.x2);

        return 0;
    }
```

[Документация](../intro-rus.md) / [2D векторы](../vector2-rus.md)
