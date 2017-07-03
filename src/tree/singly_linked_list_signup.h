#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdio.h>
#include <string.h>

#include "singly_linked_list_user.h"

typedef struct Signup{
    pUser u;
    struct Signup *next;
}Sign, *pSign;

int InsertSignup(pSign*, pSign);

int DeleteSignup(pSign*, pSign);

pSign SearchSignup(pSign, char*);

void DisplaySign(pSign s);

void DisplayAllSign(pSign s);

#endif // SINGLY_LINKED_LIST_H

