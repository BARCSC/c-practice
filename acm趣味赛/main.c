#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c,e;
    scanf("%d:%d",&c,&e);
    int d,i;
    d=e/10+(e%10)*10;
    for(i=0;c!=d;)
    {
        i++;
        if(c<=23&&e<=58) {e++;d=e/10+(e%10)*10;}
        else if(c<=22&&e==59) {e=0;c++;d=0;}
        else if(c==23&&e==59) break;
    }
    printf("%d",i);
    return 0;
}
