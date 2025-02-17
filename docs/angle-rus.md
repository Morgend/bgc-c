# Углы

В библиотеке нет специальных структур для представления уголов. Функции
библиотеки работают с углами как с обычными числами с плавающей запятой
типов **float** и **double**.

В библиотеке есть три единицы измерения уголов:
* радианы (полный оборот равен 2π радиан)
* градусы (полный оборот равен 360 градусов)
* обороты (полный оборот равен 1)

Единицы измерения углов определены в перечилении:

```c
    typedef enum {
        BGC_ANGLE_UNIT_RADIANS = 1,
        BGC_ANGLE_UNIT_DEGREES = 2,
        BGC_ANGLE_UNIT_TURNS   = 3
    } BgcAngleUnitEnum;
```

* BGC_ANGLE_UNIT_RADIANS для уголов, измеряемых в радианах
* BGC_ANGLE_UNIT_DEGREES для уголов, измеряемых в градусах
* BGC_ANGLE_UNIT_TURNS для уголов, измеряемых в оборотах

Функции, которые принимают угол в качестве параметра, не требуют, чтобы
угол принадлежал какому-либо промежутку значений. Но в библиотеке есть
функции, которые могут нормализовать угол так, чтобы он находился в
нужном промежутке значений.

Есть два промежутка нормализованных уголов: знаковый (singed) и беззнаковый
(unsigned).

Беззнаковый диапазон не содержит отрицательных значений и соответствует:
* \[0, 2π) радиан
* \[0, 360) градусов
* \[0, 1) оборотов

Знаковый диапазон содержит как отрицательные, так и положительные значения.
Знаковый диапазон соответствует:
* (-π, π] радиан
* (-180, 180] градусов
* (-0,5, 0,5] оборотов

Диапазоны значений определены перечиляемым типом:

```c
    typedef enum {
        BGC_ANGLE_RANGE_UNSIGNED = 1,
        BGC_ANGLE_RANGE_SIGNED = 2
    } BgcAngleRangeEnum;
```

* BGC_ANGLE_RANGE_UNSIGNED для беззнакового диапазона значений;
* BGC_ANGLE_RANGE_SIGNED для знакового диапазона значений.

[Документация](intro-rus.md)
