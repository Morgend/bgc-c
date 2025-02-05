# Two dimensional vectors

There are two types for two dimensional vectors:
- BgcVector2FP32 for single precision vectors
- BgcVector2FP64 for double precision vectors

Vectors of BgFP32Vecto2 type use **float** (binary32 of IEEE 754) type to store
coordinate values.

Vectors of BgFP64Vecto2 type use **double** (binary64 of IEEE 754) type to store
coordinate values.

The both types are structures with two fields: **x1** and **x2**

The definition of the types:

    typedef struct
    {
        float x1, x2;
    } BgcVector2FP32;

    typedef struct
    {
        double x1, x2;
    } BgcVector2FP64;

