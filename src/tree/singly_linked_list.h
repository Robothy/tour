#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

typedef struct Tourist Tourlist, *pTourlist;

//int SLListInsert(pTourlist *e);


struct Tourist{
    char id[3];
    char name[30];
    char sex;
    short age;
};

#endif // SINGLY_LINKED_LIST_H

