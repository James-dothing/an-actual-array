#include <stdlib.h>
#ifndef AAA_H
#define AAA_H

typedef struct
{
    size_t size;
    size_t current_cap;
    int* array;
}an_actual_array;

typedef struct
{
    size_t size;
    size_t current_cap;
    an_actual_array** array;  //double pointer is useful for the first time lol?
}array_array;

void freeEveryArray();
an_actual_array* newArray();
void appendInt(an_actual_array *array, int item);
int getItem(an_actual_array *array, int index);
void debugArray(an_actual_array* array);

#endif