# �����

������� ������ ��������� ���� �������� ������ ���� ���������� ���������� ���������.

������� ��� **BgcVector2FP32**:

```c
    inline void bgc_vector2_swap_fp32(BgcVector2FP32* vector1, BgcVector2FP32* vector2);
```

������� ��� **BgcVector2FP32**:

```c
    inline void bgc_vector2_swap_fp64(BgcVector2FP64* vector1, BgcVector2FP64* vector2);
```

� ������ ������� �� ������� ���������� ������������ ���������. �������� NULL (0) ����� ��������� ������������.

������ **vector1** ����� ������ ������ ������� ����� ����� �������� ���������, ����� ���� ������ **vector2** �� ������ �������.
� ������ **vector2** ����� ������ ������ ������� ����� ����� ����� �� �������� ���������, ����� ���� ������ **vector1** �� ������ �������.

������ ����������:

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

[������������](../intro-rus.md) / [2D �������](../vector2-rus.md)
