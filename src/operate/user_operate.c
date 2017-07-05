#include "user_operate.h"

int SignUp(pUser users,char *uid,pAttraction root, char *aname, char *adate){
    pUser u = SearchUser(users, uid);
    pAttraction a = BSTSearch(root, aname, adate);
    if(a == NULL){
        return 2;   ///该团不存在
    }
    pSign s = (pSign)malloc(sizeof(Sign));
    s->u = u;
    s->next = NULL;
    if(InsertSignup(&(a->s), s)){
        ;
    }else{
        ;
    }
}


void tourist_register(pCMD cmd, pUser users){
    pUser u = SearchUser(users, cmd->uid);
    if(u != NULL){
        printf("Sorry, this user already exists.\n");
    }
    else{
        pUser new_usr = (pUser)malloc(sizeof(User));
        while(1){
            printf("Name : ");
            scanf("%s", new_usr->name);
            if(strlen(new_usr->name) <1 || strlen(new_usr->name)>30){
                printf("The name is constituted by 1-19 characters. \n");
            }else{
                break;
            }
        }

        while(1){
            printf("Sex (M or F) : ");
            new_usr->sex = getchar();
            if(new_usr->sex!='F' && new_usr != 'M'){
                printf("Please input F or M.\n");
            }else break;
        }

        while(1){
            printf("Age : ");
            scanf("%d",new_usr->age);
            if(new_usr->age<1 || new_usr>120){
                printf("Please input correct age. \n");
            }else break;
        }

        while(1){
            printf("Setting password : ");
            scanf("%s",new_usr->pwd);
            if(strlen(new_usr->pwd)>19 || strlen(new_usr->pwd)<1){
                printf("The password is constituted by 1~19 characters.\n");
            }else break;
        }

        u->next = NULL;
        InsertUser(&users, u);
        printf( "Congratulations! You have registered an account.\n");
    }
}

pUser login(pCMD cmd, pUser users){
    pUser u = SearchUser(users, cmd->uid);
    if(u!=NULL && 0==strcmp(u->pwd, cmd->pwd)){
        printf("Welcome! %s\n.",u->name);
        return u;
    }else{
        printf("Login failed. \n");
        return NULL;
    }
}

void user_signup(pCMD cmd, pUser users, pAttraction *attrs, pUser u){
    pAttraction a = BSTSearch(*attrs, cmd->name, cmd->date);
    if(a == NULL){
        printf("This attraction does not exists.\n");
        printf("You can use \" query unsignedup \" to query the available attraction.\n ");
        return;
    }

    if(SearchSignup(a->s, u->id)){
        printf("You already sign this attraction up.\n");
        return;
    }

    if(CountSignNumber(a->s)>=6){
        printf("This attraction's tourists overflowed, please choose other attractions.\n");
        return;
    }

    pSign s = (pSign)malloc(sizeof(Sign));
    s->next = NULL;
    s->u = u;

    int signedNum = CountSignNumber((*attrs)->s);
    if(signedNum > 5){
        printf("There are too much people signed up this attraction. \n");
        printf("You can type \" query unsigned \" query available attraction.\n");
        return;
    }

    if(InsertSignup(&(a->s), s)){
        printf("Sign up succeed! %s\t%s \n", cmd->name, cmd->date);
    }else{
        printf("Sorry, sign up failed.\n");
    }
}

void user_cancel(pCMD cmd, pAttraction *attrs, pUser u){
    pAttraction a = BSTSearch(*attrs, cmd->name, cmd->date);
    if(a == NULL){
        printf("The attraction does not exists.\n");
        return;
    }

    if(a->s == NULL || NULL == SearchSignup(a->s, u->id)){
        printf("You have not sign up this attraction.\n");
        return;
    }

    if(DeleteSignup(&(a->s), u->id)){
        printf("Cancel succeed!\n");
    }else{
        printf("Sorry! Operate failed.\n");
    }
}

void user_query(pCMD cmd, pAttraction *attrs, pUser u){
    if(0==strcmp("signedup", cmd->others[0])){
        printf("You have sigened up : \n");
        query_signedup(cmd, attrs, u);
    }else if(0==strcmp("unsignedup", cmd->others[0])){
        printf("You can sign up : \n");
        query_unsignedup(cmd, attrs, u);
    }
}

void query_signedup(pCMD cmd, pAttraction *attrs, pUser u){
    if(*attrs == NULL) return;
    if((*attrs)->s != NULL
       && SearchSignup((*attrs)->s, u->id)!=NULL){
        printf("%-30s%-15s\n", (*attrs)->name, (*attrs)->go_off);
    }
    query_signedup(cmd, &((*attrs)->lchild), u);
    query_signedup(cmd, &((*attrs)->rchild), u);
}

void query_unsignedup(pCMD cmd, pAttraction *attrs, pUser u){
    if(*attrs == NULL) return;
    int signedNum = 0;
    if((*attrs)->s != NULL){
        signedNum = CountSignNumber((*attrs)->s);
    }
    if(SearchSignup((*attrs)->s, u->id)==NULL){
        printf("%-30s%-15s %d signed, left %d .\n", (*attrs)->name, (*attrs)->go_off , signedNum, 6-signedNum);
    }
    query_unsignedup(cmd, &((*attrs)->lchild), u);
    query_unsignedup(cmd, &((*attrs)->rchild), u);
}

void admin_add_attr(pCMD cmd, pAttraction *attrs){
    if(BSTSearch((*attrs), cmd->name, cmd->date)!=NULL){
        printf("This attraction already exists.\n");
        return;
    }else{
        pAttraction a = (pAttraction)malloc(sizeof(Attraction));
        strcpy(a->name, cmd->name);
        strcpy(a->go_off, cmd->date);
        a->lchild = NULL;
        a->rchild = NULL;
        a->s = NULL;
        BSTInsert(attrs, a);
        printf("Operate succeed.\n");
    }
}

void admin_del_attr(pCMD cmd, pAttraction*attrs){
    if(BSTSearch((*attrs), cmd->name, cmd->date)!=NULL){
        printf("This attraction does not exists.\n");
        return;
    }else{
        if(BSTDelete(attrs, cmd->name, cmd->date, NULL)){
            printf("Operate succeed.\n");
        }else{
            printf("Operate failed.\n");
        }
    }
}

void count_info(pCMD cmd, pUser users, pAttraction attrs){
    if(0==strcmp(cmd->others[0],"tourists")){
        count_tourists(cmd, users, attrs);
    }else if(0==strcmp(cmd->others[0], "groups")){
        printf("All attractions below : \n");
        count_groups(cmd, users, attrs);
        printf("Total: %d groups.\n", count_BSTnode_num(attrs));
    }else{
        printf("Incorrect command format. Please type \" count tourists \" or \" count groups \" .\n");
    }
}

void count_tourists(pCMD cmd, pUser users, pAttraction attrs){
    if(attrs == NULL) return;
    count_tourists(cmd, users, attrs->lchild);
    pSign s = attrs->s;
    while(s){
        printf("%-20s%-4c%-30s%-15s\n", s->u->name, s->u->sex, attrs->name, attrs->go_off);
        s=s->next;
    }
    count_tourists(cmd, users, attrs->rchild);
}

void count_groups(pCMD cmd, pUser users, pAttraction attrs){
    if(attrs == NULL) return;
    count_groups(cmd, users, attrs->lchild);
    int num = CountSignNumber(attrs->s);
    printf("%-30s%-15s %d people signed. Left %d .\n", attrs->name, attrs->go_off, num, 6-num);
    count_groups(cmd, users, attrs->rchild);
}



