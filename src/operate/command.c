#include "command.h"


pCMD get_cmd(pCMD*cmd){
    char cmd_str[100];
    gets(cmd_str);
    char ch;
    char result[5][30];
    int i=0;
    int m=0;
    int n=0;
    while('\0' != (ch=cmd_str[i++])){
        if(ch!=' '){
            result[m][n++] = ch;
        }else {
            result[m++][n] = '\0';
            n=0;
        }
    }
    result[m][n]='\0';

    strcpy((*cmd)->cmd_str, cmd_str);

    if(strcmp(result[0], "login")==0){ ///登录操作
        strcpy((*cmd)->cmd_type, "login");
        if(strcmp("-u", result[1])==0 && strcmp("-p", result[3])==0){
            strcpy((*cmd)->uid, result[2]);
            strcpy((*cmd)->pwd, result[4]);
        }
        else if(strcmp("-u", result[3])==0 && strcmp("-p", result[1])==0){
            strcpy((*cmd)->name, result[4]);
            strcpy((*cmd)->pwd, result[2]);
        }
        else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(strcmp(result[0], "register")==0){///注册操作
        strcpy((*cmd)->cmd_type, "register");
        if(0==strcmp(result[1], "-u")){
            strcpy((*cmd)->uid, result[2]);
        }
        else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(0==strcmp(result[0], "help")){
        strcpy((*cmd)->cmd_type, "help");
    }

    else if(0==strcmp(result[0], "signup")){
        strcpy((*cmd)->cmd_type, "signup");
        if(0==strcmp(result[1], "-l") && 0==strcmp(result[3], "-d")){
            strcpy((*cmd)->name, result[2]);
            strcpy((*cmd)->date, result[4]);
        }
        else if(0==strcmp(result[3], "-l") && strcmp(result[1], "-d")){
            strcpy((*cmd)->name, result[4]);
            strcpy((*cmd)->date, result[2]);
        }
        else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(0==strcmp(result[0], "cancel")){
        strcpy((*cmd)->cmd_type, "cancel");
        if(0==strcmp(result[1], "-l") && 0==strcmp(result[3], "-d")){
            strcpy((*cmd)->name, result[2]);
            strcpy((*cmd)->date, result[4]);
        }
        else if(0==strcmp(result[3], "-l") && strcmp(result[1], "-d")){
            strcpy((*cmd)->name, result[4]);
            strcpy((*cmd)->date, result[2]);
        }
        else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(0==strcmp(result[0], "query")){
        strcpy((*cmd)->cmd_type, "query");
        if(0==strcmp(result[1], "signedup") || 0==strcmp(result[1], "unsignedup")){
            strcpy((*cmd)->others[0], result[1]);
            return (*cmd);
        }

        if(0==strcmp(result[1], "-n") && 0==strcmp(result[3], "-d")){
            strcpy((*cmd)->name, result[2]);
            strcpy((*cmd)->date, result[4]);
        }
        else if(0==strcmp(result[3], "-n") && 0==strcmp(result[1], "-d")){
            strcpy((*cmd)->name, result[4]);
            strcpy((*cmd)->date, result[2]);
        }
        else {
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(0==strcmp(result[0], "add")){
        strcpy((*cmd)->cmd_type, "add");
        if(0==strcmp(result[1], "-n") && 0==strcmp(result[3], "-d")){
            strcpy((*cmd)->name ,result[2]);
            strcpy((*cmd)->date , result[4]);
        }
        else if(0==strcmp(result[3], "-n") && 0==strcmp(result[1], "-d")){
            strcpy((*cmd)->name ,result[4]);
            strcpy((*cmd)->date ,result[2]);
        }
        else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(0==strcmp(result[0], "del")){
            strcpy((*cmd)->cmd_type, "del");
        if(0==strcmp(result[1], "-n") && 0==strcmp(result[3], "-d")){
            strcpy((*cmd)->name ,result[2]);
            strcpy((*cmd)->date ,result[4]);
        }
        else if(0==strcmp(result[3], "-n") && 0==strcmp(result[1], "-d")){
            strcpy((*cmd)->name, result[4]);
            strcpy((*cmd)->date, result[2]);
        }
        else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }

    else if(0==strcmp(result[0], "count")){
        if(0==strcmp(result[1], "groups") || 0==strcmp(result[1], "tourists")){
            strcpy((*cmd)->cmd_type, "count");
            strcpy((*cmd)->others[0], result[1]);
        }else{
            strcpy((*cmd)->cmd_type, "unknow");
        }
    }
    else{
        strcpy((*cmd)->cmd_type, "unknow");
    }

}











