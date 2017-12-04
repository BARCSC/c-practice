#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SSIZE 500
typedef int elemtype;
typedef struct _stack {
    elemtype element[SSIZE];
    int top;
}stack;
char ch[] = "+-*/()\n";
int f1[] = {3, 3, 5, 5, 1, 6, 0};
int f2[] = {2, 2, 4, 4, 6, 1, 0};
void initstack(stack* s)
{
    s->top = -1;
}
int isempty(stack* s)
{
    if(s->top < 0) return 1;
    return 0;
}
int push(stack* s, elemtype value)
{
    if(s->top >= SSIZE - 1) return 0;
    s->element[++s->top] = value;
return 1;
}
elemtype gettop(stack* s)
{
    return s->element[s->top];
}
elemtype pop(stack* s)
{
    return s->element[s->top--];
}
elemtype cton(char c) {
switch(c)
{
case '+': return 0;
case '-': return 1;
case '*': return 2;
case '/': return 3;
case '(': return 4;
case ')': return 5;
default: return 6;
}
}
char compare(char c1, char c2)
{
int i1 = cton(c1);
int i2 = cton(c2);
if(f1[i1] > f2[i2]) return '>';
else if(f1[i1] < f2[i2]) return '<';
else return '=';
}
int operate(elemtype a, elemtype t, elemtype b)
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
int evaluate() {
char c;
int i = 0, sum = 0;
elemtype x, t, a, b;
stack optr, opnd;
initstack(&optr);
push(&optr, cton('\n'));
initstack(&opnd);
c = getchar();
if(c==' ') c=getchar();
while((c != '\n') || (ch[gettop(&optr)] != '\n'))
    {
    if(isdigit(c)) {
    sum = 0;
        while(isdigit(c)) {
            sum = sum * 10 + (c - '0');
            c = getchar();
            if(c==' ') c=getchar();
            }
    push(&opnd, sum);
    }
    else {
        switch(compare(ch[gettop(&optr)], c))
        {
            case '<': push(&optr, cton(c));
            c = getchar();
            if(c==' ') c=getchar();
            break;
            case '=': x = pop(&optr);
            c = getchar();
            if(c==' ') c=getchar();
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
int main() {
    int t;
    scanf("%d",&t);
    getchar();
    while(t--)
    {
        int result = evaluate();
        printf("%d\n", result);
    }
    return 0;
}
