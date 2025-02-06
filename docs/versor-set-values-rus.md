# ������� �������������� �������� ��������� �������

����� ������� ���������� �������� ��� ��������� ������� ������������� ����������� �������.

��� ���� **BgFP32Versor** ������� ����� ���:

    inline void bgc_versor_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcVersorFP32* versor);

��� ���� **BgFP64Versor** ������� ����� ���:

    inline void bgc_versor_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcVersorFP64* versor);

������ ������� ������������� ��������, ���������� � ���������� **s0**, **x1**, **x2** � **x3**, � �������������� ���������� �������, ����������� �� ��������� � ��������� **versor**. �� ���� ������������ ��������� �� �������� ��������������� ������������, �� ������� ����������� ������.

�������� **versor** ������ ���� ���������� ����������, � ����� �� ������ ���� ����� NULL.

������ ������� ����� ������ �������� ��� ������������� ��������� ���������� ����� **BgFP32Versor** � **BgFP64Versor** ��� � ������� [bgc_versor_reset_fp32 � bgc_versor_reset_fp64](./versor-reset-eng.md).

������ �������������:

    #include <stdio.h>
    #include <basic-geometry.h>
    
    int main() {
        BgcVersorFP64 versor;
        
        bgc_versor_set_values_fp64(1, 2, 3, 4, &versor);
        
        printf("Versor: (%lf, %lf, %lf, %lf)\n", versor.s0, versor.x1, versor.x2, versor.x3);
        
        return 0;
    }

���������:

    Versor: (0.182574, 0.365148, 0.547723, 0.730297)

���� � �������� �������� ��������� � ������� �������� ����, �� ������, ��������� �� ������� ������� � ��������� **versor**, ����� ���������� � ���������, ��������������� ���������� ��������:

    bgc_versor_set_values_fp64(0, 0, 0, 0, &versor);

���������:

    Versor: (1.000000, 0.000000, 0.000000, 0.000000)

[�������](./versor-rus.md)

