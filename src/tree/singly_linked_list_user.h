/** �洢�û���Ϣ�ĵ����� */
/** �û���Ψһ��ʶ��ϢΪID, ��ID��ͬ��������Ϣ��ͬ���û���Ϊ��ͬ���û� */

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

/** �����û� */
int InsertUser(pUser*, pUser);

/** ɾ���û� */
int DeleteUser(pUser*, char*);

/** �����û� */
pUser SearchUser(pUser, char*);

/** ��ӡ�����û���Ϣ */
void DisplayUser(pUser);

/** ��ӡ�����û���Ϣ */
void DisplayAllUser(pUser);


#endif // SINGLY_LINKED_LIST_USER_H
