# Функции сброса состояния для версоров

[Версор](../versor-rus.md), который соответствует отсутствию поворота, имеет следующие значеия компонент:

```
    s0 = 1;
    x1 = 0;
    x2 = 0;
    x3 = 0;
```

Чтобы установить данное состояние для компонент версора, в библиотеке есть соответствующие функции.

Для типа **BgFP32Versor** функция имеет вид:

```c
    inline void bgc_versor_reset_fp32(BgFP32Versor* versor);
```

Для типа **BgFP64Versor** функция имеет вид:

```c
    inline void bgc_versor_reset_fp64(BgFP64Versor* versor);
```

Параметр **versor** должен быть корректным указателем, а также не должен быть равен NULL.

Эти функции хорошо подходят для инициализации состояния переменных типов **BgFP32Versor** и **BgFP64Versor**.

Пример использования:

```c
    #include <stdio.h>
    #include <basic-geometry.h>

    int main() {
        BgFP32Versor versor;

        bgc_versor_reset_fp32(&versor);

        printf("Versor: (%f, %f, %f, %f)\n", versor.s0, versor.x1, versor.x2, versor.x3);

        return 0;
    }
```

Результат:

```
    Versor: (1.000000, 0.000000, 0.000000, 0.000000)
```

[Документация](../intro-rus.md) / [Версоры](../versor-rus.md)
