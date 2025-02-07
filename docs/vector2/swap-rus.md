# Обмен

Функции обмена позволяют двум векторам одного типа обменяться значениями координат.

Функция для **BgcVector2FP32**:

```c
    inline void bgc_vector2_swap_fp32(BgcVector2FP32* vector1, BgcVector2FP32* vector2);
```

Функция для **BgcVector2FP32**:

```c
    inline void bgc_vector2_swap_fp64(BgcVector2FP64* vector1, BgcVector2FP64* vector2);
```

В данные функции не следует передавать некорректные указатели. Значение NULL (0) также считается некорректным.

Вектор **vector1** после вызова данной функции будет иметь значения координат, какие имел вектор **vector2** до вызова функции.
А вектор **vector2** после вызова данной функции будет иметь такие же значения координат, какие имел вектор **vector1** до вызова функции.

Пример применения:

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

[Документация](../intro-rus.md) / [2D векторы](../vector2-rus.md)
