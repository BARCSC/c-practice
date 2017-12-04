#include <stdio.h>
#include <stdlib.h>
#define lsize 300
typedef struct
{
    int element[lsize];
    int top;
}stack;
char ch[]="+-*/()#";
int f1[]={3,3,5,5,1,6,0};
int f2[]={2,2,4,4,6,1,0};
void initstack(stack*s)
{
    s->top=-1;
}
int isempty(stack*s)
{
    if(s->top<0) return 1;
    return 0;
}
int push(stack* s,int value){
    if(s->top >= lsize- 1) return 0;
    s->element[++s->top] = value;
    return 1;
}
int pop(stack*s)
{
    return s->element[s->top--];
}
int gettop(stack*s)
{
    return s->element[s->top];
}
int cton(char c)
{
    switch(c)
    {
        case'+': return 0;
        case'-': return 1;
        case'*': return 2;
        case'/': return 3;
        case'(': return 4;
        case')': return 5;
    }
}
char compare(char c1,char c2)
{
    int i1=cton(c1);
    int i2=cton(c2);
    if(f1[i1]<f2[i2]) return '<';
    else if(f1[i1]>f2[i2]) return '>';
        else return '=';
}
int operate(int a,int t,int b)
{
int sum;
switch(t) {
case 0: sum = a + b; break;
case 1: sum = a - b; break;
case 2: sum = a * b; break;
default:sum = a / b;
}
return sum;
}
int caculate()
{
    char c;
    int i=0,sum=0,a,b,x,t;
    stack opnd,optr;
    initstack(&optr);
    push(&optr, cton('#'));
    initstack(&opnd);
    c=getchar();
    if(c==' ')
        c=getchar();
    if(c=='\n')
        c='#';
    while((c!='#')||ch[gettop(&optr)]!='#')
    {
        if(isdigit(c)) {
             sum = 0;
             while(isdigit(c)) {
             sum = sum * 10 + (c - '0');
             c = getchar();
             if(c==' ') c=getchar();
             if(c=='\n') c='#';
            }
        push(&opnd, sum);
        }
    else {
        switch(compare(ch[gettop(&optr)], c)) {
        case '<': push(&optr, cton(c));
        c= getchar();
        if(c==' ') c=getchar();
        if(c=='\n') c='#';
        break;
        case '=': x = pop(&optr);
        c = getchar();
        if(c==' ') c=getchar();
        if(c=='\n') c='#';
        break;
        case '>': t = pop(&optr);
        b = pop(&opnd);
        a = pop(&opnd);
        push(&opnd, operate(a, t, b));
        break;
        }
        }
    }
        return (gettop(&opnd));
}
int main()
{
    printf("请输入算术表达式:");
    int result = caculate();
    printf("运算结果为: %d", result);
    return 0;
}
