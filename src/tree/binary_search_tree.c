#include "binary_search_tree.h"

/**
*   ���塾���ξ��㡿�ڵ㣬�����������ƣ�����ʱ�䣬����
*/
struct TouristAttraction{
    char name[50];                  //tourist attraction's name
    char go_off[10];                //go-off, format: yyyy-mm-dd
    unsigned int tourists_number;   // The number of tourists
    struct TouristAttraction *lchild;//Pointer of left child
    struct TouristAttraction *rchild;//Pointre of right child
};

/**
*   ���ܣ� ����������
*   ������ pAttraction root �����������ĸ��ڵ�
*          char *name      ��������
*          char *go_off     ����ʱ��
*   ����ֵ�����ҵ����򷵻ؽڵ�ָ�룻���򷵻ؿ�ָ��
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
*   ���ܣ����������в���ڵ�
*   ������ pAttraction root    �������ĸ��ڵ�
*           pAttaction e        ������Ľڵ�
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
