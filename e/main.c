#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,f,g;
    scanf("%d%d",n,m);
    if(n==1&&m==1) printf("2");
    else{
        if(m=2) f=1+1;
        if(m=3) f=3+1;
        if(m=4) f=6+1+1;
        if(m=5) f=15+1;
        if(m=6) f=31+1;
        if(m=7) f=63+1;

    }
    return 0;
}
