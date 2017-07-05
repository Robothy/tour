#include "init.h"

int LoadData(pAttraction *root, pUser *users){

    /** 创建景点信息 */
    pAttraction e = NULL;
    char* attrs[10][2]={
        {"ShangHai","2017-07-28"},{"NanChang","2017-08-02"},
        {"ShangHai","2017-07-20"},{"BeiJing","2017-12-20"},
        {"ShangHai","2017-07-20"},{"JiuZaiGou","2017-08-02"},
        {"JingGanShan","2017-07-09"},{"LuShan","2017-12-11"},
        {"TaoBao","2017-11-11"},{"GoHome","2017-12-31"}
    };

    int i = 0;
    for(; i<10; i++){
        e = (pAttraction)malloc(sizeof(Attraction));
        strcpy(e->name, attrs[i][0]);
        strcpy(e->go_off, attrs[i][1]);
        e->tourists_number = 10+i;
        e->lchild = NULL;
        e->rchild = NULL;
        e->s = NULL;
        BSTInsert(root, e);
    }

    /** 创建用户信息 **/
    char* uinfo[][4]={
        {"001","Shelly",'F',20},{"002","Bob",'M',31},
        {"002","Alice",'F',23},{"003","Alice",'F',23},
        {"003","John",'M',24},{"004","John",'M',24},
        {"006","Mike",'M',28},{"008","Wolf",'M',30},
        {"010","Angle",'M',32},{"111","Robothy",'M',22}
    };

    for(i=0; i<10; i++){
        pUser u = (pUser)malloc(sizeof(User));
        strcpy(u->id, uinfo[i][0]);
        strcpy(u->name, uinfo[i][1]);
        u->sex = uinfo[i][2];
        u->age = uinfo[i][3];
        strcpy(u->pwd,uinfo[i][1]);
        u->next = NULL;
        InsertUser(users, u);
    }

    /** 生成报名信息 */
    SignUp(*users, "001", *root, "JingGanShan","2017-07-09");
    SignUp(*users, "002", *root, "JingGanShan","2017-07-09");
    SignUp(*users, "001", *root, "NanChang", "2017-08-02");
    SignUp(*users, "001", *root, "JiuZaiGou","2017-08-02");
    SignUp(*users, "111", *root, "GoHome","2017-12-31");
    SignUp(*users, "010", *root, "GoHome","2017-12-31");
    SignUp(*users, "008", *root, "GoHome","2017-12-31");
    SignUp(*users, "004", *root, "GoHome","2017-12-31");
    SignUp(*users, "111", *root, "GoHome","2017-12-31");///重复
    SignUp(*users, "111", *root, "BeiJing","2017-12-20");

    return 1;
}

