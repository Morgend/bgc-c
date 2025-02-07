# ����� ��������� ���������� �������

������� ������������� �������� 0 ���� ����������� ��������� ��������.

������� ��� **BgcVector2FP32**:

```c
inline void bgc_vector2_reset_fp32(BgcVector2FP32* vector);
```

������� ��� **BgcVector2FP64**:

```c
inline void bgc_vector2_reset_fp64(BgcVector2FP64* vector);
```

������ �� ������ ������� ������������ ��������� ������� ����:

```c
vector->x1 = 0;
vector->x2 = 0;
```

� ��������� **vector** �� ������� ���������� ������������ ���������. �������� NULL (0) ����� ��������� ������������.

������ ����������:

```c
#include <stdio.h>
#include <basic-geometry.h>

int main()
{
    BgcVector2FP32 my_vector;

    bgc_vector2_reset_fp32(&my_vector);

    printf("x1 = %f, x2 = %f\n", my_vector.x1, my_vector.x2);

    return 0;
}
```

[������������](../intro-rus.md) / [2D �������](../vector2-rus.md)
