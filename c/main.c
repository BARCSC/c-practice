#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[14],b[14],c[14],ans[7][14];
    int i,j,k=1;
    for(i=1;i<=13;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=13;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=13;i++)
        for(j=1;j<=13;j++)
        if(a[i]==b[j])
    {
        c[k]=j;
        k++;
    }
    for(k=1;k<=13;k++)
        ans[0][k]=b[k];
    for(i=1;i<=6;i++)
        for(j=1;j<=13;j++)
        ans[i][c[j]]=ans[i-1][j];
    for(i=1;i<=12;i++)
        printf("%d ",ans[6][i]);
        printf("%d",ans[6][13]);
    return 0;
}
