#ifndef COMMAND_H
#define COMMAND_H

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char cmd_type[20];  ///命令的类型
    char cmd_str[100];  ///命令的长度
    char name[30];      ///名称
    char date[12];      ///日期
    char uid[4];        ///用户ID
    char sex;           ///用户性别
    char pwd[20];        ///用户的密码
    short age;          ///用户的年龄
    char others[5][50]; ///其它参数
} CMD,*pCMD;


pCMD get_cmd();


#endif // COMMAND_H
