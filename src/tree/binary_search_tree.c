#include "binary_search_tree.h"

/**
*   定义【旅游景点】节点，包含景点名称，出发时间，人数
*/
struct TouristAttraction{
    char name[50];                  //tourist attraction's name
    char go_off[10];                //go-off, format: yyyy-mm-dd
    unsigned int tourists_number;   // The number of tourists
    struct TouristAttraction *lchild;//Pointer of left child
    struct TouristAttraction *rchild;//Pointre of right child
};

/**
*   功能： 搜索二叉树
*   参数： pAttraction root 二叉排序树的根节点
*          char *name      景点名称
*          char *go_off     出发时间
*   返回值：若找到，则返回节点指针；否则返回空指针
*/
pAttraction BSTSearch(pAttraction root,char *name, char *go_off){
    if(root==NULL ||
       (strcmp(root->name,name)==0 && strcmp(root->go_off, go_off)==0)){
        return root;
    }
    else if(strcmp(root->name, name)<0 ||
            (strcmp(root->name, name)==0 && strcmp(root->go_off, go_off)<0)){
        return BSTSearch(root->lchild, name, go_off);
    }
    else{
        return BSTSearch(root->rchild, name, go_off);
    }
}


/**
*   功能：往二叉树中插入节点
*   参数： pAttraction root    二叉树的根节点
*           pAttaction e        待插入的节点
*
*/

void BSTInsert(pAttraction root, pAttraction e){
    if(root == NULL){
        root = e;
    }
    else if(strcmp(root->name,e->name)<0 ||
    (strcmp(root->name,e->name)==0 && strcmp(root->go_off,e->go_off)<0)){
        BSTInsert(root->lchild, e);
    }
    else{
        BSTInsert(root->rchild, e);
    }
}
