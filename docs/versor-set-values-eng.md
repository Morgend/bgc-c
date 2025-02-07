# Functions that set the values of the versor components

Special functions are provided to specify specific values ??for the versor components.

For the **BgFP32Versor** type, the function has the form:

    inline void bgc_versor_set_values_fp32(const float s0, const float x1, const float x2, const float x3, BgcVersorFP32* versor);

For the **BgFP64Versor** type, the function has the form:

    inline void bgc_versor_set_values_fp64(const double s0, const double x1, const double x2, const double x3, BgcVersorFP64* versor);

These functions set the values ??passed in the **s0**, **x1**, **x2**, and **x3** parameters to the corresponding components of the versor passed by pointer in the **versor** parameter. But if the resulting state is not a normalized quaternion, then the functions normalize the versor.

The **versor** parameter must be a valid pointer and must not be NULL.

These functions are also well suited for initializing the state of variables of types **BgFP32Versor** and **BgFP64Versor**, as are the functions [bgc_versor_reset_fp32 and bgc_versor_reset_fp64](./versor-reset-eng.md).


    #include <stdio.h>
    #include <basic-geometry.h>
    
    int main() {
        BgcVersorFP64 versor;
        
        bgc_versor_set_values_fp64(1, 2, 3, 4, &versor);
        
        printf("Versor: (%lf, %lf, %lf, %lf)\n", versor.s0, versor.x1, versor.x2, versor.x3);
        
        return 0;
    }

Result:

    Versor: (0.182574, 0.365148, 0.547723, 0.730297)

If zeros are passed to the function as component values, then the versor, the pointer to which is passed in the **versor** parameter, will be set to the state corresponding to the absence of rotation:

    bgc_versor_set_values_fp64(0, 0, 0, 0, &versor);

Result:

    Versor: (1.000000, 0.000000, 0.000000, 0.000000)

[Versors](./versor-eng.md)
