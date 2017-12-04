#include <stdio.h>
#include <stdlib.h>
#define size 100
typedef struct _stack
{
    int top;
    int element[size];
}stack;
void inistack(stack *s)
{
    s->top=-1;
}
int isempty(stack *s)
{
    return s->top<0;
}
int gettop(stack *s)
{
    return s->element[s->top];
}
int push(stack *s,char c)
{
    if(s->top>=size-1) return 0;
    s->element[++s->top]=c;
    return 1;
}
int pop(stack *s)
{
    return s->element[s->top--];
}
char compare(char c1,char c2)
{
    if(c1=='('&&c2==')') return 0;
    if(c1=='['&&c2==']') return 0;
    return 1;
}
int main()
{
    stack s;
    char c;
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        inistack(&s);
        c=getchar();
        while(c!='\n')
        {
            c=getchar();
            if(c=='('||c=='['||s.top==-1)
                push(&s,c);
            else if(c==']'||c==')')
                {
                if(compare(gettop(&s),c)) break;
                else pop(&s);
                }
        }
        while(c!='\n')
        {
            c=getchar();
        }
        if(s.top==-1) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}
