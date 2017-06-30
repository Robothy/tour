#include <iostream>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

#include "D:/JiangXiaodong/tour/src/tree/binary_search_tree.hpp"

using namespace std;



int main()
{
    Attraction att = (Attraction)malloc(sizeof(Tourist));

    strcpy(att->name,"Hello");

    printf("%s",att->name);
    return 0;
}
