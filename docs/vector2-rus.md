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

