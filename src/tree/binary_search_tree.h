#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <string.h>
#include "singly_linked_list.h"

typedef struct TouristAttraction  Attraction, *pAttraction;

pAttraction BSTSearch(pAttraction root,char *name, char *go_off);
void BSTInsert(pAttraction root, pAttraction e);

#include "binary_search_tree.c"

#endif // BINARY_SEARCH_TREE_HPP
