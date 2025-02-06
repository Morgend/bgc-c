# Функции устанавливащие значения компоенен версора

Чтобы указать конкретные значения для компонент версора предусмотрены специальные функции.

Для типа **BgFP32Versor** функция имеет вид:

    inline void bgc_versor_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcVersorFP32* versor);

Для типа **BgFP64Versor** функция имеет вид:

    inline void bgc_versor_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcVersorFP64* versor);

Данные функции устанавливают значения, переданные в параметрах **s0**, **x1**, **x2** и **x3**, в соответствующе компоненты версора, переданного по указателю в параметре **versor**. Но если получившееся состояние не является нормализованным кватернионом, то функции нормализуют версор.

Параметр **versor** должен быть корректным указателем, а также не должен быть равен NULL.

Данные функции также хорошо подходят для инициализации состояния переменных типов **BgFP32Versor** и **BgFP64Versor** как и функции [bgc_versor_reset_fp32 и bgc_versor_reset_fp64](./versor-reset-eng.md).

Пример использования:

    #include <stdio.h>
    #include <basic-geometry.h>
    
    int main() {
        BgcVersorFP64 versor;
        
        bgc_versor_set_values_fp64(1, 2, 3, 4, &versor);
        
        printf("Versor: (%lf, %lf, %lf, %lf)\n", versor.s0, versor.x1, versor.x2, versor.x3);
        
        return 0;
    }

Результат:

    Versor: (0.182574, 0.365148, 0.547723, 0.730297)

Если в качестве значений компонент в функцию передать нули, то версор, указатель на который передан в параметре **versor**, будет установлен в состояние, соответствующее отсутствию поворота:

    bgc_versor_set_values_fp64(0, 0, 0, 0, &versor);

Результат:

    Versor: (1.000000, 0.000000, 0.000000, 0.000000)

[Версоры](./versor-rus.md)

