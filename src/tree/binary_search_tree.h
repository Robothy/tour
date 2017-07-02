#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <string.h>
#include "singly_linked_list.h"

/**
*   ���塾���ξ��㡿�ڵ㣬�����������ƣ�����ʱ�䣬����
*/
typedef struct TouristAttraction{
    char name[50];                  //tourist attraction's name
    char go_off[11];                //go-off, format: yyyy-mm-dd
    unsigned int tourists_number;   // The number of tourists

    struct TouristAttraction *lchild;//Pointer of left child
    struct TouristAttraction *rchild;//Pointre of right child
}Attraction, *pAttraction;

//typedef struct TouristAttraction  Attraction, *pAttraction;
int BSTDelete(pAttraction *root, char*,char*,pAttraction*);
pAttraction BSTSearch(pAttraction root,char *name, char *go_off);
void BSTInsert(pAttraction *root, pAttraction e);
int compare_node(pAttraction,pAttraction);

#endif // BINARY_SEARCH_TREE_H
