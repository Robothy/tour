//#define TEST_SINGLY_LINKED_LIST_SIGNUP

#ifdef TEST_SINGLY_LINKED_LIST_SIGNUP

#include "../tree/singly_linked_list_signup.h"

#include "../tree/singly_linked_list_user.h"

void CreateLinkedListSignup(pSign *root){
    char* users[][4]={
        {"001","Shelly",'F',20},{"002","Bob",'M',31},
        {"002","Alice",'F',23},{"003","Alice",'F',23},
        {"003","John",'M',24},{"004","John",'M',24},
        {"006","Mike",'M',28},{"008","Wolf",'M',30},
        {"010","Angle",'M',32},{"111","Robothy",'M',22}
    };
    int i = 0;
    for(; i<10; i++){
        pUser u = (pUser)malloc(sizeof(User));
        strcpy(u->id, users[i][0]);
        strcpy(u->name, users[i][1]);
        u->sex = users[i][2];
        u->age = users[i][3];
        u->next = NULL;
        pSign s = (pSign)malloc(sizeof(Sign));
        s->u = u;
        s->next = NULL;
        InsertSignup(root, s);
    }
}

void main(){

    pSign root = NULL;
    CreateLinkedListSignup(&root);

    DisplayAllSign(root);

    printf("Search 111, result:\n%-5s\n",SearchSignup(root, "111")->u->id);

    DeleteSignup(&root, "001");
    printf("Delete 001. \n");
    DisplayAllSign(root);

    system("pause");
}

#endif //TEST_SINGLY_LINKED_LIST_SIGNUP
