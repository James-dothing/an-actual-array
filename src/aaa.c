// AAA stands for An Actual Array btw lol
// https://github.com/James-dothing/an-actual-array
//TO DO LIST:
//add more function

#include <stdio.h>
#include <stdlib.h>
#include "aaa.h"

static array_array every_array = {0,8, NULL};
static short debug_mode = 0;

static void addArray(an_actual_array* item)
{
    if (!every_array.array)
    {
        every_array.array = malloc(8 * sizeof(an_actual_array*));
        if (!every_array.array)
        {
            printf("failed to alocate memory");
            exit(1);
        }
    }

    if (every_array.size == every_array.malloc_size)
    {
        every_array.malloc_size <<= 1;
        an_actual_array** temp = realloc(every_array.array, every_array.malloc_size * sizeof(an_actual_array*));
        if (!temp)
        {
            printf("failed to alocate memory");
            exit(1);
        }
        every_array.array = temp;
    }
    every_array.array[every_array.size] = item;
    every_array.size++;
}

void enableDebugMode(){debug_mode = 1;} void disableDebugMode(){debug_mode = 0;}

void freeEveryArray()
{
    if (every_array.array)
    {
        if (debug_mode == 1)
        {
            printf("i'm going to free exactly %zu pointers\n", every_array.size * 2);
            printf("or %zu arrays total\n", every_array.size);
        }
        for (size_t i=0;i < every_array.size;i++)
        {
            if (debug_mode == 1)
            {
                printf("RAHHH I FREED %p\n", every_array.array[i]->array);
                printf("RAHHH I FREED %p\n", every_array.array[i]);
            }
            free(every_array.array[i]->array);
            free(every_array.array[i]);
            every_array.array[i] = NULL;
        }
        every_array.size = 0;
    }
}

an_actual_array* newArray()
{
    int* pseudo_array = malloc(8 * sizeof(int));
    if (!pseudo_array)
    {
        printf("failed to alocate memory");
        exit(1);
    }

    an_actual_array* new = malloc(sizeof(an_actual_array)); //incease life time :mindblowing_face:
    if (!new)
    {
        free(pseudo_array);
        exit(1);
    }

    *new = (an_actual_array){0, 8, pseudo_array};
    if(debug_mode==1){printf("say hello to %p!\n",new);}
    addArray(new);
    return new;
}

void appendInt(an_actual_array *array, int item)
{
    if (array->size == array->malloc_size)
    {
        array->malloc_size <<= 1;
        int* temp = realloc(array->array, array->malloc_size * sizeof(int));
        if (!temp)
        {
            printf("failed to alocate memory");
            exit(1);
        }
        array->array = temp;
    }
    array->array[array->size] = item;
    array->size++;
}

int getItem(an_actual_array *array, int index)
{
    if (index < 0)
    {
        printf("index is out of range (index is negative)");
        exit(1);
    }
    if (index < array->size)
    {
        return array->array[index];
    }
    printf("index out of range");
    exit(1);
}

int getLength(an_actual_array* array)
{
    return (int)array->size;
}

void replaceInt(an_actual_array *array, int item, int index)
{
    if (index < 0 || index >= array->size)
    {
        printf("index out of range");
        exit(1);
    }
    array->array[index] = item;
}

void insertItem(an_actual_array *array, int item, int index)
{
    if (index < 0)
    {
        printf("index is out of range (index is negative)");
        exit(1);
    }
    if (index < array->size)
    {
        appendInt(array, array->array[array->size-1]); //not using getLength() cuz performace :troll face:

        for (int i=(int)array->size-2;i>index;i--)
        {
            array->array[i] = array->array[i-1];
        }
        array->array[index] = item;
        // [1] [2] [3] [4] [5] [6] [7] [8] ;; wanted to insert v to index 5
        // [1] [2] [3] [4] [5] [6] [7] [8] [8] ;; dupe last item in an array
        // [1] [2] [3] [4] [5] [6] [7] [7] [8] ;; you get the idea
        // [1] [2] [3] [4] [5] [6] [6] [7] [8] ;; you get the idea
        // [1] [2] [3] [4] [5] [v] [6] [7] [8] ;; finally put v at index 5
    } else if (index == array->size)
    {
        appendInt(array, item);
    } else // index > array->size
    {

    }
}

void debugArray(an_actual_array* array)
{
    printf("\nsize: %zu\n", array->size );
    printf("malloc size: %zu\n", array->malloc_size);
    for (size_t i = 0;i<array->size;i++)
    {
        printf("%zu: ", i);
        printf("%d", array->array[i]);
        printf(" ,");
    }
    printf("\n");
}
