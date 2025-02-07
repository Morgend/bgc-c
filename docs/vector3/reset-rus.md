# ����� ��������� ���������� �������

������� ������������� �������� 0 ���� ����������� ��������� ��������.

������� ��� **BgcVector3FP32**:

```c
inline void bgc_vector3_reset_fp32(BgcVector3FP32* vector);
```

������� ��� **BgcVector3FP64**:

```c
inline void bgc_vector3_reset_fp64(BgcVector3FP64* vector);
```

������ �� ������ ������� ������������ ��������� ������� ����:

```c
vector->x1 = 0;
vector->x2 = 0;
vector->x3 = 0;
```

� ������ ������� �� ������� ���������� ������������ ���������. �������� NULL (0) ����� ��������� ������������.

������ ����������:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector3FP32 my_vector;

    bgc_vector3_reset_fp32(&my_vector);

    printf("x1 = %f, x2 = %f, x3 = %f\n", my_vector.x1, my_vector.x2, my_vector.x3);

    return 0;
}
```

[������������](../intro-rus.md) / [2D �������](../vector3-rus.md)
