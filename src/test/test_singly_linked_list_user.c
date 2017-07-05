//#define TEST_SINGLY_LINKED_LIST_USER

#ifdef TEST_SINGLY_LINKED_LIST_USER

#include "../tree/singly_linked_list_user.h"

void CreateLinkedListUser(pUser *root){
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
        InsertUser(root, u);

    }
}

void main(){
    pUser root = NULL;
    CreateLinkedListUser(&root);
    DisplayAllUser(root);

    DeleteUser(&root, "111");
    printf("delete Id = %s\n", "111");
    DisplayAllUser(root);

    DeleteUser(&root, "001");
    printf("delete Id = %s\n", "001");
    DisplayAllUser(root);

    DeleteUser(&root, "111");
    DisplayAllUser(root);

    printf("\n\n Test Search \n");
    pUser u = SearchUser(root, "111");
    if(u!=NULL) printf("Test Search failed");
    u = SearchUser(root, "002");
    DisplayUser(u);
    system("pause");
}

#endif //TEST_SINGLY_LINKED_LIST_USER
