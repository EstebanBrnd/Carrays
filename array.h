#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef enum {
    INT,
    FLOAT,
    CHAR,
    STRING
} Array_t;

typedef struct {
    Array_t type;
    int *int_array;
    float *float_array;
    char *char_array;
    char *string_array[MAX_SIZE];
    int size;
} Array;

Array *create_array(Array_t type);

void add_int(Array *array, int value);

void add_float(Array *array, float value);

void add_char(Array *array, char value);

void add_string(Array *array, char *value);

void print_array(Array *array);

void free_array(Array *array);

int get_int(Array *array, int index);

float get_float(Array *array, int index);

char get_char(Array *array, int index);

char* get_string(Array *array, int index);