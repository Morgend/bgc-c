# Кватернионы

Кватернионы — это гиперкомплексные числа, которые расширяют понятие комплексных чисел. Они состоят из одной действительной компоненты и трёх мнимых компонент:

q = w + ix + jy + kz

где:

- w, x, y, z &isin; R - действительные числа
- i, j, k - мнимые единицы, удовлетворяющие следующим условиям:
   - i<sup>2</sup> = j<sup>2</sup> = k<sup>2</sup> = ijk = -1

Кватернионы были открыты математиком Уильямом Гамильтоном и представлены публике в 1843 году. Они нашли широкое применение в компьютерной графике, робототехнике и физике для описания поворотов в трёхмерном пространстве.

## Реализация кватернионов в библиотеке

Библиотека предоставляет две реализации кватернионов:
1. **Кватернионы общего назначения**
   - Поддерживают все основные операции (сложение, вычитание, умножение на скаляр и т.д.).

2. **Версоры**:
   - Специализированные кватернионы, модуль которых всегда равен единице.
   - Подходят для описания поворотов в трёхмерном пространстве.
   - Не поддерживают операции сложения, вычитания и умножения на скаляр.

Кватернионы общего назначения также можно использовать для представления поворотов в трёхмерном пространстве. Но разработчик, использующий кватернионы для описания поворотов, сам должен следить за тем, чтобы модули кватернионов не становились меньше величины погрешности и не принимали значение NaN (не число).

### Структуры для кватернионов

#### Кватернионы общего назначения

```c
    typedef struct {
        float s0, x1, x2, x3;
    } BgcQuaternionFP32;

    typedef struct {
        double s0, x1, x2, x3;
    } BgcQuaternionFP64;
```

#### Версоры

```c
    typedef struct {
        const float s0, x1, x2, x3;
    } BgcVersorFP32;

    typedef struct {
        const double s0, x1, x2, x3;
    } BgcVersorFP64;
```

Поля:
- s0 - это вещественная часть кватерниона.
- x1, x2, x3 - Мнимые компоненты кватерниона.

Поля версоров объявлены как const, чтобы разработчик использовал функции библиотеки для работы с версорами, а не изменял их напрямую.

Поля кватернионов разработчик, использующий библиотеку, может менять свободно.

[Документация](intro-rus.md)
