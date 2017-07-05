//#define TEST_BINARY_SEARCH_TREE

/**
*   二叉排序树单元测试
*/

#ifdef TEST_BINARY_SEARCH_TREE

#include "../tree/binary_search_tree.h"

#include "../tree/tree_traversal.h"

int test_compare_node(){
    pAttraction l = (pAttraction)malloc(sizeof(Attraction));
    pAttraction r = (pAttraction)malloc(sizeof(Attraction));

    int return_val;
    int expect_val = -1;
    strcpy(l->name, "JiangXi");
    strcpy(r->name, "ShangHai");

    if( return_val = compare_node(l,r) != expect_val){
        printf("error - In function compare_node : Expected %d , get %d ", expect_val, return_val);
        return 0;
    }

    expect_val = 1;
    if( return_val = compare_node(r,l) != expect_val){
        printf("error - In function compare_node : Expected %d , get %d ", expect_val, return_val);
        return 0;
    }

    strcpy(l->name, "ShangHai");
    strcpy(l->go_off , "2017-06-28");
    strcpy(r->name , "ShangHai");
    strcpy(r->go_off , "2017-06-29");
    expect_val = -1;
    if( return_val = compare_node(l,r) != expect_val){
        printf("error - In function compare_node : Expected %d , get %d ", expect_val, return_val);
        return 0;
    }
    return 1;
}

/** 判断是否为二叉排序树 */
int isBST(pAttraction root){
    if(root == NULL) return 1;

    if(root->lchild != NULL && compare_node(root,root->lchild) < 0) {
        return 0;    //左子树不满足
    }else{
        return isBST(root->lchild);
    }
    if(root->rchild != NULL && compare_node(root, root->rchild) > 0 ){ //右子树不满足
        return 0;
    }else{
        return isBST(root->rchild);
    }
}

int test_BSTinsert(){
    pAttraction root = NULL;
    create_BST(&root);
    if(isBST(root)){
        return 1;
    }else{
        return 0;
    }
}

void create_BST(pAttraction *root){
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
        BSTInsert(root, e);
    }
}

int test_BSTsearch(){
    pAttraction root = NULL;

    create_BST(&root);

    char name[50];
    char go_off[11];

    strcpy(name, "ShangHai");       //能找到
    strcpy(go_off, "2017-07-20");
    pAttraction rst = BSTSearch(root, name, go_off);

    if(!(rst!=NULL && !strcmp(rst->name,name) && !strcmp(rst->go_off, go_off))){
        return 0;
    }

    strcpy(name, "ShangHais");      //不能找到
    strcpy(go_off, "2017-07-20");
    rst = BSTSearch(root, name,go_off);
    if(rst != NULL){
        return 0;
    }

    strcpy(name, "ShangHai\0");      //不能找到
    strcpy(go_off, "2017-07-30");
    rst = BSTSearch(root, name,go_off);
    if(rst != NULL){
        return 0;
    }

    return 1;
}

int test_BSTDelete(){
    pAttraction root = NULL;
    create_BST(&root);
    if(!(BSTDelete(&root, "ShangHai", "2017-07-20", NULL) == 1 && BSTSearch(root, "ShangHai", "2017-07-20")==NULL)){
        return 0;
    }
    if(!(BSTDelete(&root, "ShangHai", "2017-07-20", NULL) == 0)){
        return 0;
    }
    return 1;
}

int main(){

    if(test_compare_node()){
        printf("Test function \"compare_node\", OK.\n" );
    }else{
        printf("Test function \"compare_node\", failed.\n");
    }

    if(test_BSTinsert()){
        printf("Test function \"BSTInsert\", OK.\n" );
    }else{
        printf("Test function \"BSTInsert\", failed.\n");
    }

    if(test_BSTsearch()){
        printf("Test function \"BSTSearch\", OK.\n" );
    }else
    {
        printf("Test function \"BSTSearch\", failed.\n");
    }


    if(test_BSTDelete()){
        printf("Test function \"BSTDelete\", OK.\n" );
    }else
    {
        printf("Test function \"BSTDelete\", failed.\n");
    }


    pAttraction root = NULL;
    create_BST(&root);
    display_inorder(root);

    BSTDelete(&root, "ShangHai", "2017-07-20", NULL);
    printf("======== Delet ShangHai 0720\n");
    display_inorder(root);

    BSTDelete(&root, "ShangHai", "2017-07-28", NULL);
    printf("======== Delet ShangHai 0728\n");
    display_inorder(root);



    system("pause");
}



#endif // TEST_BINARY_SEARCH_TREE



