#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    char data;
    node *lchild, *rchild;
}bitree;
void createbitree(bitree **bt)
{
    char ch;
    scanf("%c",&ch);
    if(ch=='#')
        *bt=NULL;
    else
    {
        *bt=(node*)malloc(sizeof(node));
        (*bt)->data=ch;
        createbitree(&((*bt)->lchild));
        createbitree(&((*bt)->rchild));
    }
}
void inorder(bitree **bt)
{
    if(bt !=NULL)
    {
        inorder(bt->lchild);
        visit(bt->data);
        inorder(bt->rchild);
    }
}
int main()
{
    printf("Hello world!\n");
    return 0;
}
