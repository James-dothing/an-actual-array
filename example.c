#include <stdio.h>
#include <stdlib.h>
#include "src/aaa.h"

int main() 
{
    an_actual_array* x = newArray();
    printf("say hello to x! it's at %p\n", x);
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

    printf("say hello to y! it's at %p\n", y);

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

    printf("i exited the program without any issue or error whatso ever");
    return 0;
}