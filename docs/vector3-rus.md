# Трёхмерные векторы векторы

В библиотеке есть два типа двумерных векторов:
- **BgcVector3FP32** - вектор с использованием чисел с плавающей запятой одинарной точности
- **BgcVector3FP64** - вектор с использованием чисел с плавающей запятой двойной точности

Определения структур:

```c
    typedef struct
    {
        float x1, x2, x3;
    } BgcVector3FP32;

    typedef struct
    {
        double x1, x2, x3;
    } BgcVector3FP64;
```

## Функции

| Функции для BgcVector3FP32                                    | Функции для BgcVector3FP64                                    |
|:-------------------------------------------------------------:|:-------------------------------------------------------------:|
| [bgc_vector3_reset_fp32](vector3/reset-rus.md)                | [bgc_vector3_reset_fp64](vector3/reset-rus.md)                |
| [bgc_vector3_set_values_fp32](vector3/set-values-rus.md)      | [bgc_vector3_set_values_fp64](vector3/set-values-rus.md)      |
| [bgc_vector3_copy_fp32](vector3/copy-rus.md)                  | [bgc_vector3_copy_fp64](vector3/copy-rus.md)                  |
| [bgc_vector3_swap_fp32](vector3/swap-rus.md)                  | [bgc_vector3_swap_fp64](vector3/swap-rus.md)                  |

[Документация](intro-rus.md)
