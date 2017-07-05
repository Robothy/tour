
#include "singly_linked_list_signup.h"

int InsertSignup(pSign*root, pSign s){
    if((*root) == NULL){
        (*root) = s;
    }
    else{
        pSign p = (*root);
        while(p->next != NULL){
            if(p==s){
                return 0;
            }
            p = p->next;
        }
        if(p==s){
            return 0;
        }
        p->next = s;
    }
    return 1;
}

/** 根据用户ID和报名根节点删除报名信息 **/
int DeleteSignup(pSign* root, char* uid){
    if(*(root) == NULL){
        return 0;
    }

    pSign p = (*root);
    if(strcmp(p->u->id, uid) == 0){
        (*root) = (*root)->next;
        free(p);
        return 1;
    }
    while(p->next != NULL){
        if(strcmp(p->next->u->id, uid) == 0){
            p->next = p->next->next;
            return 1;
        }
        p=p->next;
    }
    return 0;
}

pSign SearchSignup(pSign root, char* id){
    while(root!=NULL){
        if(strcmp(root->u->id, id) == 0) break;
        root = root->next;
    }
    return root;
}

void DisplaySign(pSign s){
    if(s == NULL){
        printf("Can not display Signup, because it is NULL.\n");
    }else{
        printf("%-5s\n", s->u->id);
    }
}

void DisplayAllSign(pSign root){
    while(root != NULL){
        DisplaySign(root);
        root = root->next;
    }
}

int CountSignNumber(pSign root){
    int i=0;
    while(root){
        i++;
        root = root->next;
    }
    return i;
}
