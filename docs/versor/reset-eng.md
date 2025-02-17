# State reset functions for versors

[A versor](../versor-eng.md) that corresponds to no rotation has the following component values:

```
    s0 = 1;
    x1 = 0;
    x2 = 0;
    x3 = 0;
```

To set such a state for the versor components, the library has the corresponding functions.

For the **BgFP32Versor** type, the function is:

```c
    inline void bgc_versor_reset_fp32(BgFP32Versor* versor);
```

For the **BgFP64Versor** type, the function is:

```c
    inline void bgc_versor_reset_fp64(BgFP64Versor* versor);
```

The **versor** parameter must be a valid pointer and must not be NULL.

These functions are well suited for initializing the state of variables of the **BgFP32Versor** and **BgFP64Versor** types.

Usage example:

```c
    #include <stdio.h>
    #include <basic-geometry.h>

    int main() {
        BgFP32Versor versor;

        bgc_versor_reset_fp32(&versor);

        printf("Versor: (%f, %f, %f, %f)\n", versor.s0, versor.x1, versor.x2, versor.x3);

        return 0;
    }
```

Result:

```
    Versor: (1.000000, 0.000000, 0.000000, 0.000000)
```

[Documentation](../intro-eng.md) / [Versors](../versor-eng.md)
