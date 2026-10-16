#include <stdio.h>
#include <stdlib.h>
#include "src/aaa.h"

int main() 
{
    enableDebugMode();
    an_actual_array* x = newArray();
    printf("say hello to x!");
    appendInt(x, 70);
    appendInt(x, 70);
    appendInt(x, 70);
    appendInt(x, 80);
    appendInt(x, 70);
    appendInt(x, 70);
    appendInt(x, 70);
    appendInt(x, 90);
    appendInt(x, 70);

    debugArray(x);

    an_actual_array* y = newArray();

    printf("say hello to y!");

    for (int i=0; i < 70; i++)
    {
        appendInt(y, i*i);
    }

    debugArray(y);

    for (int i=0; i<10;i++)
    {
        an_actual_array* v = newArray();
        for (int i=0; i<10;i++)
        {
            appendInt(v, 1);
        }
    }

    freeEveryArray();

    freeEveryArray();

    an_actual_array* a = newArray();
    enableDebugMode();
    an_actual_array* b = newArray();
    an_actual_array* c = newArray();
    printf("array: %p\n", x->array);
    freeArray(b);
    freeEveryArray();

    an_actual_array* d = newArray();
    appendInt(d, 10); // index = 0
    appendInt(d, 20); // index = 1
    appendInt(d, 30); // index = 2
    appendInt(d, 40); // index = 3
    appendInt(d, 50); // index = 4
    appendInt(d, 60); // index = 5
    removeInt(d, 3);
    debugArray(d);
    insertInt(d, 100, 3);
    debugArray(d);
    freeArray(d);

    printf("i exited the program without any issue or error whatso ever");
    return 0;
}