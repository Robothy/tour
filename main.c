#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "src/tree/binary_search_tree.h"

int main()
{
    pAttraction att = (pAttraction)malloc(sizeof(Attraction));

    strcpy(att->name,"Hello");

    printf("%s",att->name);
    return 0;
}
