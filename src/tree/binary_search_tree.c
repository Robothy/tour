#include "binary_search_tree.h"

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
        return BSTSearch(root->rchild, name, go_off);
    }
    else{
        return BSTSearch(root->lchild, name, go_off);
    }
}


/**
*   ���ܣ����������в���ڵ�
*   ������ pAttraction root    �������ĸ��ڵ�
*           pAttaction e        ������Ľڵ�
*
*/
void BSTInsert(pAttraction *root, pAttraction e){
    if((*root) == NULL || e == NULL){
        (*root) = e;
    }
    else if(compare_node(*root,e) < 0){ //Ӧ�÷ŵ��ұ�
        BSTInsert(&((*root)->rchild), e);
    }else if(compare_node(*root, e) > 0){ //Ӧ�÷ŵ����
        BSTInsert(&((*root)->lchild), e);
    }else{  //������,��ʾ������Ϣ
        printf("Can not insert, The node with name %s , go_off %s already exists.\n",e->name, e->go_off);
    }
}

/** ɾ���ڵ� ***/
int BSTDelete(pAttraction*root, char* name, char* go_off, pAttraction *parent){

    if((*root) == NULL){
        return 0;
    }
    if((strcmp((*root)->name,name)==0 && strcmp((*root)->go_off, go_off)==0)){//�ҵ��˴�ɾ���Ľڵ�
        pAttraction l = (*root)->lchild;
        pAttraction r = (*root)->rchild;
        pAttraction self = *root;    //��ɾ���Ľڵ�
        if(parent == NULL){ //���ĸ��ڵ㼴ΪҪɾ���Ľڵ�
            if(l == NULL){
                *root = r;
            }else{
                BSTInsert(&l, r);   //���������ϲ�����������
                *root = l;
            }
        }else{
            if(l == NULL) (*root) = r;
            else if(r == NULL) (*root) = l;
            else{   //������������Ϊ��
                pAttraction temp = r;
                while(temp->lchild!=NULL){
                    temp = temp->lchild;
                }
                temp->lchild = l;   //���������ŵ��������������
                (*root) = r;
            }
        }
        free(self);//�ͷ��ڴ�
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
*   �Զ���Ƚ������ڵ��С�Ĺ���
**/
int compare_node(pAttraction l, pAttraction r){
    if(strcmp(l->name,r->name) > 0){    //����������ߴ����ұ�
        return 1;
    }else if(strcmp(l->name, r->name) < 0 ){    //�����������С���ұ�
        return -1;
    }else{  //������������������ȣ� �Ƚϳ���ʱ��
        if(strcmp(l->go_off, r->go_off)>0){
            return 1;
        }else if(strcmp(l->go_off, r->go_off)<0){
            return -1;
        }else{
            return 0;
        }
    }
}
