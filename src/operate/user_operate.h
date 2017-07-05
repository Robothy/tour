#ifndef USER_OPERATE_H
#define USER_OPERATE_H

#include "../tree/singly_linked_list_user.h"
#include "../tree/singly_linked_list_signup.h"
#include "../tree/binary_search_tree.h"
#include "command.h"

int SignUp(pUser users,char *uid,pAttraction root, char *aname, char *adate);

/** 用户登录，从用户单链表查询用户信息 */
pUser login(pCMD cmd, pUser users);

/** 用户注册，数据插入到用户单链表 */
void tourist_register(pCMD cmd, pUser users);

/** 用户报团 */
void user_signup(pCMD cmd, pUser users, pAttraction*attrs, pUser u);

/** 取消报团 **/
void user_cancel(pCMD cmd, pAttraction *attrs, pUser u);

/** 游客查询 **/
void user_query(pCMD cmd, pAttraction *attrs, pUser u);

/** 查询报团信息 ***/
void query_signedup(pCMD cmd, pAttraction *attrs, pUser u);

/** 查询可报团信息 **/
void query_unsignedup(pCMD cmd, pAttraction *attrs, pUser u);

/** 管理员添加信息 **/
void admin_add_attr(pCMD cmd, pAttraction *attrs);

/** 管理员删除信息 **/
void admin_del_attr(pCMD cmd, pAttraction*attrs);

/** 管理员统计信息 */
void count_info(pCMD cmd, pUser users, pAttraction attrs);

/** 管理员统计游客报名信息 **/
void count_tourists(pCMD cmd, pUser users, pAttraction attrs);

/** 管理员统计报团信息 **/
void count_groups(pCMD cmd, pUser users, pAttraction attrs);



#endif // USER_OPERATE_H
