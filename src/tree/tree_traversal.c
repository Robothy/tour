#include "tree_traversal.h"

/** ������� **/
void display_inorder(pAttraction root){
    if(root == NULL) return;
    display_inorder(root->lchild);
    printf("%-30s%-12s%d\n",root->name,root->go_off,root->tourists_number);
    display_inorder(root->rchild);
}

/** ������� */
void display_preorder(pAttraction root){
    if(root == NULL) return;
    printf("%-30s%-12s%d\n",root->name,root->go_off,root->tourists_number);
    display_preorder(root->lchild);
    display_preorder(root->rchild);
}

/** ������� */
void display_postorder(pAttraction root){
    ;
}
