# Двумерные векторы векторы

В библиотеке есть два типа двумерных векторов:
- **BgcVector2FP32** - вектор с использованием чисел с плавающей запятой одинарной точности
- **BgcVector2FP64** - вектор с использованием чисел с плавающей запятой двойной точности

Определения структур:

```c
    typedef struct
    {
        float x1, x2;
    } BgcVector2FP32;

    typedef struct
    {
        double x1, x2;
    } BgcVector2FP64;
```

## Функции

| Функции для BgcVector2FP32                                    | Функции для BgcVector2FP64                                    |
|:-------------------------------------------------------------:|:-------------------------------------------------------------:|
| [bgc_vector2_reset_fp32](vector2/reset-rus.md)                | [bgc_vector2_reset_fp64](vector2/reset-rus.md)                |
| [bgc_vector2_set_values_fp32](vector2/set-values-rus.md)      | [bgc_vector2_set_values_fp64](vector2/set-values-rus.md)      |
| [bgc_vector2_copy_fp32](vector2/copy-rus.md)                  | [bgc_vector2_copy_fp64](vector2/copy-rus.md)                  |
| [bgc_vector2_swap_fp32](vector2/swap-rus.md)                  | [bgc_vector2_swap_fp64](vector2/swap-rus.md)                  |

### Функции кнвертации типа

Функции конвертации типа позволяют преобразовать 

	inline void bgc_vector2_convert_fp64_to_fp32(const BgcVector2FP64* from, BgcVector2FP32* to);
	inline void bgc_vector2_convert_fp32_to_fp64(const BgcVector2FP32* from, BgcVector2FP64* to);

Функции библиотеки проектировались из предпосылки, что разработчик, использующий
данную библиотеку, выберет один из двух типов чисел с плавающей запятой
(**float** или **double**) и будет работать с геометрическими структурами и
функциями выбранного типа.

Тем не менее, в библиотеке есть функции, которые позволяют преобразовать данные
одного типа в данные другого типа.

[Документация](intro-rus.md)
