#include <stdio.h>
#include <stdlib.h>
#define LSIZE 101
typedef struct
{
    int element[LSIZE];
    int elemsize;
    int listsize;
}poly;
void initlist(poly* alist)
{
    alist->listsize = LSIZE;
    memset(alist->element, 0, LSIZE * sizeof(int));
}
void print(int coe, int power)
{
    if(coe)
    {
        if(coe>0)
            if(power==0)
                printf("+%d",coe);
            else if(power==1)
                printf("+%d*x",coe);
            else printf("+%d*x^%d",coe,power);
        else if(coe<0)
            if(power==0)
                printf("-%d",-coe);
            else if(power==1)
                printf("-%d*x",-coe);
            else printf("-%d*x^%d",-coe,power);
    }
}
int main()
{
    int t,n1,n2;
    scanf("%d",&t);
    while(t--)
    {

        int i,j;
        poly poly1,poly2,poly3;
        initlist(&poly1);
        initlist(&poly2);
        initlist(&poly3);
        scanf("%d",&n1);
        for(i=n1;i>=0;i--)
            scanf("%d",&poly1.element[i]);
        scanf("%d",&n2);
        for(i=n2;i>=0;i--)
            scanf("%d",&poly2.element[i]);
        for(i=n1;i>=0;i--)
            for(j=n2;j>=0;j--)
            poly3.element[i+j]+=poly1.element[i]*poly2.element[j];
        if(n1+n2==0&&poly3.element[n1+n2]==0) printf("0");
        if(poly3.element[n1+n2])
            {
            if(poly3.element[n1+n2]>0)
            {
                if(n1+n2==0)
            printf("%d",poly3.element[n1+n2]);
            else if(n1+n2==1)
                printf("%d*x",poly3.element[n1+n2]);
            else
                printf("%d*x^%d",poly3.element[n1+n2],n1+n2);
            }
            if(poly3.element[n1+n2]<0)
            {
                if(n1+n2==0)
            printf("%d",poly3.element[n1+n2]);
            else if(n1+n2==1)
                printf("%d*x",poly3.element[n1+n2]);
            else
                printf("%d*x^%d",poly3.element[n1+n2],n1+n2);
            }
            }
        for(i=n1+n2-1;i>=0;i--)
            print(poly3.element[i],i);
        printf("\n");
    }
    return 0;
}
