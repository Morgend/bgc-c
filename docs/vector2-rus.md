# Двумерные векторы

В библиотеке есть две версии вектора:
- BgcVector2FP32 - вектор одинарной точности
- BgcVector2FP64 - вектор двойной точности

Векторы типа BgcVector2FP32 для хранения координат использует тип **float** (тип
binary32 стандарта IEEE 754).

Векторы BgcVector2FP64 используют тип **double** (тип binary64 стандарта IEEE 754).

Оба типа представляют собой структуры с двумя полями: **x1** и **x2**.

Определение типов:

    typedef struct
    {
        float x1, x2;
    } BgcVector2FP32;

    typedef struct
    {
        double x1, x2;
    } BgcVector2FP64;

Операции:
- сбос состояния
- указание координат
- копирование
- обмен
- конвертация типа
- получение обратного вектора

### Сброс состояния

Для сброса координат в нулевое значение предлагаются следующие функции:

    inline void bgc_vector2_reset_fp32(BgcVector2FP32* vector);
    inline void bgc_vector2_reset_fp64(BgcVector2FP64* vector);

Каждая из данных функции эквивалентна следующим строкам кода:

    vector->x1 = 0;
    vector->x2 = 0;

В данные функции не следует передавать некорректные указатели. Значение NULL (0)
в качестве параметра также считается некорректным.

Пример применения:

    #include <stdio.h>
    #include <basic-geometry.h>

    int main()
    {
        BgcVector2FP32 my_vector;

        bgc_vector2_reset_fp32(&my_vector);

        printf("x1 = %f, x2 = %f\n", my_vector.x1, my_vector.x2);

        return 0;
    }

### Указание координат

Для прямого указания координат предлагаются следующие две функции:

    inline void bgc_vector2_set_values_fp32(const float x1, const float x2, BgcVector2FP32* to);
    inline void bgc_vector2_set_values_fp64(const double x1, const double x2, BgcVector2FP64* to);

Каждая из данных функции эквивалентна следующим строкам кода:

    vector->x1 = x1;
    vector->x2 = x2;

В данные функции не следует передавать некорректные указатели. Значение NULL (0)
в качестве параметра также считается некорректным.

Пример применения:

    #include <stdio.h>
    #include <basic-geometry.h>

    int main()
    {
        BgcVector2FP32 my_vector;

        bgc_vector2_set_values_fp32(-2, 7, &my_vector);

        printf("x1 = %f, x2 = %f\n", my_vector.x1, my_vector.x2);

        return 0;
    }

### Копирование

Функции копирования позволяют 
Для копирования координат векторов предлагаются данные функции:

    inline void bgc_vector2_copy_fp32(const BgcVector2FP32* from, BgcVector2FP32* to);
    inline void bgc_vector2_copy_fp64(const BgcVector2FP64* from, BgcVector2FP64* to);

Каждая из данных функции эквивалентна следующим строкам кода:

    to->x1 = from->x1;
    to->x2 = from->x2;

В данные функции не следует передавать некорректные указатели. Значение NULL (0)
в качестве параметра также считается некорректным.

Пример применения:

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

### Обмен

Функции обмена позволяют двум векторам одного типа обменяться значениями
координат.

Для обмена значениями координат векторов определены следующие функции:

    inline void bgc_vector2_swap_fp32(BgcVector2FP32* vector1, BgcVector2FP32* vector2);
    inline void bgc_vector2_swap_fp64(BgcVector2FP64* vector1, BgcVector2FP64* vector2);

В данные функции не следует передавать некорректные указатели. Значение NULL (0)
также считается некорректным.

Пример применения:

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

### Конвертация типа

Функции конвертации типа позволяют преобразовать 

	inline void bgc_vector2_convert_fp64_to_fp32(const BgcVector2FP64* from, BgcVector2FP32* to);
	inline void bgc_vector2_convert_fp32_to_fp64(const BgcVector2FP32* from, BgcVector2FP64* to);

Функции библиотеки проектировались из предпосылки, что разработчик, использующий
данную библиотеку, выберет один из двух типов чисел с плавающей запятой
(**float** или **double**) и будет работать с геометрическими структурами и
функциями выбранного типа.

Тем не менее, в библиотеке есть функции, которые позволяют преобразовать данные
одного типа в данные другого типа.
