# Функции reset для версоров

Фунции сбрасывают состояние версора на состояние, соответствующее нулевому
повороту:

    s0 = 1, x1 = 0, x2 = 0, x3 = 0

Для типа **BgFP32Versor** функция имеет вид:

    void bgc_versor_reset_fp32(BgFP32Versor* versor);

Для типа **BgFP64Versor** функция имеет вид:

    void bgc_versor_reset_fp64(BgFP64Versor* versor);

Данные функции хорошо подходят для инициализации состояния переменной типов
**BgFP32Versor** и **BgFP64Versor**.

Пример использования:

    #include <stdio.h>
    #include <basic-geometry.h>

    int main() {
        BgFP32Versor versor;

        bgc_versor_reset_fp32(&versor);

        printf("Versor: (%f, %f, %f, %f)\n", versor.s0, versor.x1, versor.x2, versor.x3);

        return 0;
    }

Результат:

    Versor: (1.000000, 0.000000, 0.000000, 0.000000)

