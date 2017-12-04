#include <stdio.h>
#include <stdlib.h>
typedef struct person
{
    int number;
    int code;
    struct person *next;
};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,n,m,counter;
        struct person *pre,*last,*newnode;
        scanf("%d%d",&n,&m);
        last=(struct person*)malloc(sizeof(struct person));
        last->number=1;
        scanf("%d",&last->code);
        pre=last;
        for(i=2;i<=n;i++)
        {
            newnode=(struct person*)malloc(sizeof(struct person));
            newnode->number=i;
            scanf("%d",&newnode->code);
            pre->next=newnode;
            pre=newnode;
        }
        pre->next=last;
        for(i=0;i<n-1;i++)
        {
            counter=1;
            while(counter<m)
            {
                pre=last;
                last=last->next;
                counter++;
            }
            m=last->code;
            pre->next=last->next;
            printf("%d ",last->number);
            free(last);
            last=pre->next;
        }
        printf("%d\n",last->number);
        free(last);
    }
    return 0;
}
