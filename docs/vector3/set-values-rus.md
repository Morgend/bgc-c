# ������� ��������� ���������� �������

�������� ���������� �������� ����� ��� ��������, ��� � �������� �������. ������� ������� �������� ��������� ��������� ������� ��� ����� �������.

������� ��� **BgcVector3FP32**:

```c
inline void bgc_vector3_set_values_fp32(const float x1, const float x2, const float x3, BgcVector3FP32* to);
```

������� ��� **BgcVector3FP32**:

```c
inline void bgc_vector3_set_values_fp64(const double x1, const double x2, const double x3, BgcVector3FP64* to);
```

������ �� ������ ������� ������������ ��������� ������� ����:

```c
to->x1 = x1;
to->x2 = x2;
to->x3 = x3;
```

� ��������� **to** �� ������� ���������� ������������ ���������. �������� NULL (0) ����� ��������� ������������.

������ ����������:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector3FP32 my_vector;

    bgc_vector3_set_values_fp32(-2, 7, 10, &my_vector);

    printf("x1 = %f, x2 = %f, x3 = %f\n", my_vector.x1, my_vector.x2, my_vector.x3);

    return 0;
}
```

[������������](../intro-rus.md) / [3D �������](../vector3-rus.md)
