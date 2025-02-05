# Basic Geometry Computations

## Library of basic geometric computations for C

[Версия на русском языке / Russian version](./README.md)

Programming language: C (C99)

Version: 0.2.0-dev

License: Apache-2.0

The main goals of development of the library were:

1. Performance
2. Functionality
3. Versatility

Performance was the main goal of making of the library. That fact affected
the implementation of the library.

For example, the main way to return data structures as a function result
was chosen to be returning via a parameter, which avoids redundant copying
of data through the call stack.

Also the majority of functions were made as inline functions. That allows
a compiller to replace a call of some function onto the body of that
function.

The library uses two types of floating point numbers: **float** и **double**
(**binary32** and **binary64** types of the **IEEE 754** standard). That
affected the implementation of the library too.

The library is implicitly divided into two halves: one half is for data and
functions of **float** type and another one is for date of th **double** type.
And there are several bridges connect both of the halves. Those bridges are
the functions of the type conversion.

But there are just few functions which use data of different types (**float**
and **double** at the same time) for the computations.
