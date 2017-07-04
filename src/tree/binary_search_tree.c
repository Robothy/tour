#include "binary_search_tree.h"

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
        return BSTSearch(root->rchild, name, go_off);
    }
    else{
        return BSTSearch(root->lchild, name, go_off);
    }
}


/**
*   功能：往二叉树中插入节点
*   参数： pAttraction root    二叉树的根节点
*           pAttaction e        待插入的节点
*
*/
void BSTInsert(pAttraction *root, pAttraction e){
    if((*root) == NULL || e == NULL){
        (*root) = e;
    }
    else if(compare_node(*root,e) < 0){ //应该放到右边
        BSTInsert(&((*root)->rchild), e);
    }else if(compare_node(*root, e) > 0){ //应该放到左边
        BSTInsert(&((*root)->lchild), e);
    }else{  //不插入,提示警告信息
        printf("Can not insert, The node with name %s , go_off %s already exists.\n",e->name, e->go_off);
    }
}

/** 删除节点 ***/
int BSTDelete(pAttraction*root, char* name, char* go_off, pAttraction *parent){

    if((*root) == NULL){
        return 0;
    }
    if((strcmp((*root)->name,name)==0 && strcmp((*root)->go_off, go_off)==0)){//找到了待删除的节点
        pAttraction l = (*root)->lchild;
        pAttraction r = (*root)->rchild;
        pAttraction self = *root;    //待删除的节点
        if(parent == NULL){ //树的根节点即为要删除的节点
            if(l == NULL){
                *root = r;
            }else{
                BSTInsert(&l, r);   //将右子树合并到左子树上
                *root = l;
            }
        }else{
            if(l == NULL) (*root) = r;
            else if(r == NULL) (*root) = l;
            else{   //左右子树均不为空
                pAttraction temp = r;
                while(temp->lchild!=NULL){
                    temp = temp->lchild;
                }
                temp->lchild = l;   //将左子树放到右子树的最左边
                (*root) = r;
            }
        }
        free(self);//释放内存
        return 1;
    }
    else if(strcmp((*root)->name, name)<0 ||
            (strcmp((*root)->name, name)==0 && strcmp((*root)->go_off, go_off)<0)){
        return BSTDelete(&((*root)->rchild), name, go_off, root);
    }
    else{
        return BSTDelete(&((*root)->lchild), name, go_off, root);
    }
}


/**
*   自定义比较两个节点大小的规则
**/
int compare_node(pAttraction l, pAttraction r){
    if(strcmp(l->name,r->name) > 0){    //景点名称左边大于右边
        return 1;
    }else if(strcmp(l->name, r->name) < 0 ){    //景点名称左边小于右边
        return -1;
    }else{  //景点名称左右两边相等， 比较出发时间
        if(strcmp(l->go_off, r->go_off)>0){
            return 1;
        }else if(strcmp(l->go_off, r->go_off)<0){
            return -1;
        }else{
            return 0;
        }
    }
}
