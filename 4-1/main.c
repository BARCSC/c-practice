#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int v;
    struct Node *next;
}Node;

/*int convert1(int a)
{
    return (a/1000)*8+((a%1000)/100)*4+((a%100)/10)*2+a%10;
}*/
int main()
{
    Node p;
    p.v=1000;
    //p->next=NULL;
    int a;
    a=p.v;
    //a=convert1(p->value);
    printf("%d",a);
    //free(p);
    return 0;
}
