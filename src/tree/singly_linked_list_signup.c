#include "singly_linked_list_signup.h"

int InsertSignup(pSign*root, pSign s){
    if((*root) == NULL){
        (*root) = u;
    }
    else{
        pSign p = (*root);
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

int DeleteSignup(pSign* root, pSign s){
    if((*root) == NULL) {
        return 0;
    }
    pSign p = (*root);
    if(strcmp((*root)->id, id) == 0){
        (*root) = (*root)->next;
    }else{
        while(p->next != NULL){
            if(strcmp(p->next->id,id) == 0){//ÕÒµ½´ýÉ¾³ý½Úµã
                p->next = p->next->next;
                p = p->next;
                free(p);
                return 1;
            }
            p = p->next;
        }
    }
    return 0;

}

pSign SearchSignup(pSign root, char* id){
    while(root!=NULL){
        if(strcmp(root->id, id) == 0) break;
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

