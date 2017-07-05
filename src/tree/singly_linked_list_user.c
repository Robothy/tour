#include "singly_linked_list_user.h"

int InsertUser(pUser *root, pUser u){
    if((*root) == NULL){
        (*root) = u;
    }
    else{
        pUser p = (*root);
        while(p->next != NULL){
            if(strcmp(p->id , u->id)==0){
                return 0;
            }
            p = p->next;
        }
        if(strcmp(p->id, u->id) == 0){
            return 0;
        }
        p->next = u;
    }
    return 1;
}

int DeleteUser(pUser *root, char *id){
    if((*root) == NULL) {
        return 0;
    }
    pUser p = (*root);
    if(strcmp((*root)->id, id) == 0){
        (*root) = (*root)->next;
    }else{
        while(p->next != NULL){
            if(strcmp(p->next->id,id) == 0){//找到待删除节点
                free(p->next);
                p->next = p->next->next;
                return 1;
            }
            p = p->next;
        }
    }
    return 0;
}

pUser SearchUser(pUser root, char*id){
    while(root!=NULL){
        if(strcmp(root->id, id) == 0) break;
        root = root->next;
    }
    return root;
}

void DisplayUser(pUser u){
    if(u == NULL){
        printf("Can not display User, because it is NULL\n");
    }
    else{
        printf("%-5s %-20s %-3c %-5d\n",u->id, u->name, u->sex, u->age);
    }
}

void DisplayAllUser(pUser root){
    while(root){
        DisplayUser(root);
        root = root->next;
    }
}
