#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SSIZE 500
typedef int elemtype;
typedef struct _stack {
elemtype element[SSIZE];
int top;
}stack;
char ch[] = "+-*/()#"; //下标即表中所述的”对应的数字”
int f1[] = {3, 3, 5, 5, 1, 6, 0};//栈内元素优先级
int f2[] = {2, 2, 4, 4, 6, 1, 0};//栈外元素优先级
void initstack(stack* s) //初始化堆栈
{
s->top = -1;
}
int isempty(stack* s) //判空操作
{
if(s->top < 0) return 1;
return 0;
}
int push(stack* s, elemtype value) {//入栈操作,成功返回1,否则0
if(s->top >= SSIZE - 1) return 0;
s->element[++s->top] = value;
return 1;
}
elemtype gettop(stack* s) {//取栈顶元素
return s->element[s->top];
}
elemtype pop(stack* s) {//出栈操作,返回出栈元素
return s->element[s->top--];
}
elemtype cton(char c) {//把运算符转换为数组ch中的下标
switch(c) {
case '+': return 0;
case '-': return 1;
case '*': return 2;
case '/': return 3;
case '(': return 4;
case ')': return 5;
default: return 6;
}
}
char compare(char c1, char c2) //比较两个运算符的优先级,
{ //便于使用switch语句
int i1 = cton(c1);
int i2 = cton(c2);
if(f1[i1] > f2[i2]) return '>';
else if(f1[i1] < f2[i2]) return '<';
else return '=';
}
int operate(elemtype a, elemtype t, elemtype b) //进行四则运算,
{ //并返回运算结果
int sum;
switch(t) {
case 0: sum = a + b; break;
case 1: sum = a - b; break;
case 2: sum = a * b; break;
default:sum = a / b;
}
return sum;
}
int evaluate(char *d) {//通过调用前面的函数,完成整个表达式的运算
char c;
int i = 0, sum = 0,j=-1;
elemtype x, t, a, b;
stack optr, opnd;
initstack(&optr);
push(&optr, cton('#'));
initstack(&opnd);
c=d[++j];
while((c != '#') || (ch[gettop(&optr)] != '#')) {
if(isdigit(c)) {
sum = 0;
while(isdigit(c)) {
sum = sum * 10 + (c - '0');
c =d[++j];
}
push(&opnd, sum);
}
else {
switch(compare(ch[gettop(&optr)], c)) {
case '<': push(&optr, cton(c)); //栈外运算符优先级
c = d[++j];
break;
case '=': x = pop(&optr); //栈中和栈外的运算符优先级一样高
c = d[++j];
break;
case '>': t = pop(&optr); //栈内的运算符优先级高,开始运算
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
    char m,d[SSIZE];
    int k=0;
    printf("请输入算术表达式(以#结束):");
    while(m!='#')
    {
        k++;
        m=getchar();
        if(m==' ') m=getchar();
        if(m=='\n') m='#';
        d[k]=m;
    }
int result = evaluate(d);
printf("运算结果为: %d", result);
return 0;
}
