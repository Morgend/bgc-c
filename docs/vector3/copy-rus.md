# �����������

������� ����������� ��������� ����������� �������� ��������� ������ ������� � ������ ������.

������� ��� **BgcVector3FP32**:

```c
inline void bgc_vector3_copy_fp32(const BgcVector3FP32* from, BgcVector3FP32* to);
```

������� ��� **BgcVector3FP64**:

```c
inline void bgc_vector3_copy_fp64(const BgcVector3FP64* from, BgcVector3FP64* to);
```

������ �� ������ ������� ������������ ��������� ������� ����:

```c
to->x1 = from->x1;
to->x2 = from->x2;
to->x3 = from->x3;
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
    BgcVector3FP32 my_vector1, my_vector3;

    bgc_vector3_set_values_fp32(-2, 7, 1, &my_vector1);

    bgc_vector3_copy_fp32(&my_vector1, &my_vector3);

    printf("x1 = %f, x2 = %f, x3 = %f\n", my_vector3.x1, my_vector3.x2, my_vector3.x3);

    return 0;
}
```

[������������](../intro-rus.md) / [3D �������](../vector3-rus.md)
