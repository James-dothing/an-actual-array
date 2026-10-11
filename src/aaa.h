#include <stdlib.h>
#ifndef AAA_H
#define AAA_H

typedef struct
{
    size_t size;
    size_t malloc_size;
    int* array;
}an_actual_array;

typedef struct
{
    size_t size;
    size_t malloc_size;
    an_actual_array** array;  //double pointer is useful for the first time lol?
}array_array;

void enableDebugMode();
void disableDebugMode();
void freeEveryArray();
an_actual_array* newArray();
void appendInt(an_actual_array *array, int item);
int getItem(an_actual_array *array, int index);
int getLength(an_actual_array* array);
void replaceInt(an_actual_array *array, int item, int index);
void insertItem(an_actual_array *array, int item, int index);
void debugArray(an_actual_array* array);

#endif