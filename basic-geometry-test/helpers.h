#ifndef __GEOMETRY_TEST_H__
#define __GEOMETRY_TEST_H__

#include <basic-geometry.h>

#define TEST_SUCCES 0
#define TEST_FAILED 1

// =================== Number =================== //

typedef struct {
    float number1, number2;
} TestNumberPairFP32;

typedef struct {
    double number1, number2;
} TestNumberPairFP64;

// ================== Vector2 =================== //

// ================== Vector3 =================== //

// ================= Quaternion ================= //

// =================== Versor =================== //

typedef struct {
    BgcVersorFP32 first, second;
} TestVersorPairFP32;

typedef struct {
    BgcVersorFP64 first, second;
} TestVersorPairFP64;

typedef struct {
    BgcVersorFP32 first, second, result;
} TestVersorTripletFP32;

typedef struct {
    BgcVersorFP64 first, second, result;
} TestVersorTripletFP64;

// ================= Functions ================== //

void print_testing_section(const char * name);

void print_testing_name(const char * name);

void print_testing_success();

void print_testing_error(const char * message);

void print_testing_failed();

#endif
