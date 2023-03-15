#include "array.h"

Array *create_array(Array_t type){
    Array *array = (Array *)malloc(sizeof(Array));
    array->type = type;
    array->size = 0;
    switch(array->type){
        case INT:
            array->int_array = (int *)malloc(sizeof(int));
            break;
        case FLOAT:
            array->float_array = (float *)malloc(sizeof(float));
            break;
        case CHAR:
            array->char_array = (char *)malloc(sizeof(char));
            break;
        case STRING:
            //array->string_array = (char **)malloc(sizeof(char *));
            break;
    }
    return array;
}

void free_array(Array *array){
    switch(array->type){
        case INT:
            free(array->int_array);
            break;
        case FLOAT:
            free(array->float_array);
            break;
        case CHAR:
            free(array->char_array);
            break;
        case STRING:
            for(int i = 0; i < array->size; i++){
                free(array->string_array[i]);
            }
            break;
    }
    free(array);
}

void print_array(Array *array){
    switch(array->type){
        case INT:
            for(int i = 0; i < array->size; i++){
                printf("%d ", array->int_array[i]);
            }
            break;
        case FLOAT:
            for(int i = 0; i < array->size; i++){
                printf("%f ", array->float_array[i]);
            }
            break;
        case CHAR:
            for(int i = 0; i < array->size; i++){
                printf("%c ", array->char_array[i]);
            }
            break;
        case STRING:
            for(int i = 0; i < array->size; i++){
                printf("%s ", array->string_array[i]);
            }
            break;
    }
    printf("\n");
}

void add_int(Array *array, int value){
    array->int_array = (int *)realloc(array->int_array, (array->size + 1) * sizeof(int));
    array->int_array[array->size] = value;
    array->size++;
}

void add_float(Array *array, float value){
    array->float_array = (float *)realloc(array->float_array, (array->size + 1) * sizeof(float));
    array->float_array[array->size] = value;
    array->size++;
}

void add_char(Array *array, char value){
    array->char_array = (char *)realloc(array->char_array, (array->size + 1) * sizeof(char));
    array->char_array[array->size] = value;
    array->size++;
}

void add_string(Array *array, char *value){
    array->string_array[array->size] = (char *)malloc(strlen(value) + 1);
    strcpy(array->string_array[array->size], value);
    array->size++;
}

int get_int(Array *array, int index){
    if (index < array->size){
        return array->int_array[index];
    }
    else{
        printf("Index out of range!\n");
        return NULL;
    }
}

float get_float(Array *array, int index){
    if (index < array->size){
        return array->float_array[index];
    }
    else{
        printf("Index out of range!\n");
        return -1;
    }
}

char get_char(Array *array, int index){
    if (index < array->size){
        return array->char_array[index];
    }
    else{
        printf("Index out of range!\n");
        return NULL;
    }
}

char* get_string(Array *array, int index){
    if (index < array->size){
        return array->string_array[index];
    }
    else{
        printf("Index out of range!\n");
        return NULL;
    }
}