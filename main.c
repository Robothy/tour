#define RUN_APP
#ifdef RUN_APP
#include <malloc.h>
#include <string.h>
#include <stdio.h>
//#include<locale.h>
#include "src/tree/binary_search_tree.h"
#include "src/operate/alert_info.h"
#include "src/operate/command.h"


int main()
{
    //setlocale(LC_ALL, "chs");

    pUser u =  NULL; ///当前操作用户
    pUser users = NULL; ///指向所有用户(单链表)
    pAttraction attrs = NULL;///指向所有的旅游团(二叉排序树)
    pCMD cmd = (pCMD)malloc(sizeof(CMD));  ///指向用户输入的命令
    LoadData(&attrs, &users);
    system("cls");
    printf(welcome_info);
    int i;
    while(1){
        ///打印命令输入框
        if(u == NULL){
            printf(">");
        }else{
            printf("%s>", u->name);
        }

        ///获取输入的命令
        get_cmd(&cmd);

        if(strcmp(cmd->cmd_str, "quit")==0){ /// 退出
            break;
        }
        else if(0==strcmp(cmd->cmd_str, "logout")){
            if(u!=NULL){
                printf("%s logout.\n", u->name);
            }
            u = NULL;
        }
        else if(u == NULL){///未登录
            if(0==strcmp(cmd->cmd_type,"login")){
                u = login(cmd, users);
            }
            else if(0==strcmp(cmd->cmd_type, "register")){
                tourist_register(cmd, users);
            }
            else if(0==strcmp(cmd->cmd_type, "help")){
                printf(welcome_panel_help);
            }else{
                system(cmd->cmd_str);
            }
        }else{
            if(0==strcmp(u->id,"111")){///管理员
                if(0==strcmp(cmd->cmd_type, "add")){
                    admin_add_attr(cmd, &attrs);
                }                else if(0==strcmp(cmd->cmd_type, "del")){
                    admin_del_attr(cmd, &attrs);
                }
                else if(0==strcmp(cmd->cmd_type, "count")){
                    count_info(cmd, users, attrs);
                }
                else if(0==strcmp(cmd->cmd_str, "help")){
                    printf(admin_panel_help);
                }else{
                    system(cmd->cmd_str);
                }

            }else{  ///普通游客
                if(0==strcmp(cmd->cmd_type, "signup")){ ///报团
                    user_signup(cmd, users, &attrs, u);
                }
                else if(0==strcmp(cmd->cmd_type, "cancel")){ ///取消
                    user_cancel(cmd, &attrs, u);
                }
                else if(0==strcmp(cmd->cmd_type, "query")){  ///  查询
                    user_query(cmd, &attrs, u);
                }
                else if(0==strcmp(cmd->cmd_str, "help")){
                    printf(tourist_panel_help);
                }
                else{
                    system(cmd->cmd_str);
                }
            }
        }
    }

    printf("Bye.\n");
    system("pause");
    return 0;
}
#endif //RUN_APP
