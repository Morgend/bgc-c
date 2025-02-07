# �����������

������� ����������� ��������� ����������� �������� ��������� ������ ������� � ������ ������.

������� ��� **BgcVector2FP32**:

```c
inline void bgc_vector2_copy_fp32(const BgcVector2FP32* from, BgcVector2FP32* to);
```

������� ��� **BgcVector2FP64**:

```c
inline void bgc_vector2_copy_fp64(const BgcVector2FP64* from, BgcVector2FP64* to);
```

������ �� ������ ������� ������������ ��������� ������� ����:

```c
to->x1 = from->x1;
to->x2 = from->x2;
```

��������� **from** � **to** �� ������ ���� ������������� �����������. �������� NULL (0) ����� ��������� ������������.

�������� **from** ������ ���� ���������� �� ��������� ������, ���������� �������� ������ ���� �����������. ���������� ������� **from** �� ��������� ����� ������ �������.
 
�������� **to** ������ ���� ���������� �� ��������� ������, ���������� �������� ������ ���� ��������. ���������� ������� **to** ����� ������ ������� ������ ������ ��, ��� � � ������� **from**.

������ ����������:

```c
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
```

[������������](../intro-rus.md) / [2D �������](../vector2-rus.md)
