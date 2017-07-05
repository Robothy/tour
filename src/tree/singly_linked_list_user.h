/** 存储用户信息的单链表 */
/** 用户的唯一标识信息为ID, 即ID不同，其它信息相同的用户视为不同的用户 */

#ifndef SINGLY_LINKED_LIST_USER_H
#define SINGLY_LINKED_LIST_USER_H

#include <stdio.h>
#include <string.h>

typedef struct Usr{
    char id[4];
    char name[30];
    char sex;
    short age;
    char pwd[20];
    struct Usr *next;
} User, *pUser;

/** 插入用户 */
int InsertUser(pUser*, pUser);

/** 删除用户 */
int DeleteUser(pUser*, char*);

/** 查找用户 */
pUser SearchUser(pUser, char*);

/** 打印单个用户信息 */
void DisplayUser(pUser);

/** 打印所有用户信息 */
void DisplayAllUser(pUser);


#endif // SINGLY_LINKED_LIST_USER_H
