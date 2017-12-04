#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int a[4],c;
    int i;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&c);
        if(c%8==0) a[3]++;
        else if(c%4==0) a[2]++;
        else if(c%2==0) a[1]++;
        else if(c%2!=0) a[0]++;
    }
    if((a[0]+a[1]>a[2]+a[3]+1)) printf("NO");
    else
    {
    if(a[0]>a[3]+1) printf("NO");
    if(a[0]==(a[3]+1))
    {
        if(a[1]>0||a[2]>0) printf("NO");
        else {
                printf("YES\n");
            printf("1 ");
            for(;a[3]>0;a[3]--)
                printf("8 1 ");
        }
    return 0;
    }
    if(a[0]<=a[3])
    {
            printf("YES\n");
        for(;a[0]>0;)
            {printf("1 8 ");a[0]--;a[3]--;}
        for(;a[1]>0&&a[3]>0;)
            {printf("2 8 ");a[1]--;a[3]--;}
        if(a[1]>0&&a[3]==0){
            for(;a[1]>0;)
                {printf("2 4 ");a[1]--;a[2]--;}
            for(;a[2]>0;a[2]--)
                printf("4 ");
        }
        else if(a[3]>=0&&a[1]==0)
        {
            for(;a[3]>0;a[3]--)
                printf("8 ");
            for(;a[2]>0;a[2]--)
                printf("4 ");
        }
    }
    }
    return 0;
}
