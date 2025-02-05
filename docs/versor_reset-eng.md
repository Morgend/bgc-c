# Reset functions for versors

The functions reset the state of versors to the state of no turn:

    s0 = 1, x1 = 0, x2 = 0, x3 = 0

For the **BgFP32Versor** type the function is:

    void bgc_versor_reset_fp32(BgFP32Versor* versor);

For the **BgFP64Versor** type the function is:

    void bgc_versor_reset_fp64(BgFP64Versor* versor);

These functions are good for setting the initial state of variables and fields
of **BgFP32Versor** and **BgFP64Versor** types.

Example of usage:

    #include <stdio.h>
    #include <basic-geometry.h>

    int main() {
        BgFP32Versor versor;

        bgc_versor_reset_fp32(&versor);

        printf("Versor: (%f, %f, %f, %f)\n", versor.s0, versor.x1, versor.x2, versor.x3);

        return 0;
    }

Result:

    Versor: (1.000000, 0.000000, 0.000000, 0.000000)

