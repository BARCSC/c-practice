#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    int i,sum=0;
    int a[100009];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    if(a[i]>=a[m]) sum=sum+a[i]-a[m]+1;
    printf("%d",sum-1);
}
