#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
/*寄存运算符*/
typedef struct
{
	int stacksize;
	char *base;
	char *top;
} Stack;
/*寄存凑作数或运算结果*/
typedef struct
{
	int stacksize;
	int *base;
	int *top;
} Stack2;
/* ----------------- 全局变量--------------- */
Stack OPTR;/* 定义运算符栈*/
Stack2 OPND; /* 定义操作数栈 */
char expr[255] = ""; /* 存放表达式串 */
char *ptr = expr;

Status InitStack(Stack &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base=(char *)malloc(STACK_INIT_SIZE * sizeof(char));
    if(!S.base) return(ERROR);
    S.top = S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status InitStack2(Stack2 &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base=(int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!S.base) return(ERROR);
    S.top = S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(Stack &S,char e)
{
// 在栈S中插入元素e为新的栈顶元素
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(char*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(char));
        if(!S.base) return(ERROR);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Push2(Stack2 &S,int e)
{
// 在栈S中插入元素e为新的栈顶元素
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(int*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(int));
        if(!S.base) return(ERROR);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Pop(Stack &S,char &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

Status Pop2(Stack2 &S,int &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

char GetTop(Stack s)//用p返回运算符栈s的栈顶元素
{
	char p=*(s.top-1);
	return p;
}
int GetTop2(Stack2 s) //用p返回操作数栈s的栈顶元素
{
	int p=*(s.top-1);
	return p;
}

Status In(char ch) //判断字符是否是运算符，运算符即返回1
{
	return(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='=');
}

/* 判断运算符优先权，返回优先权高的 */
char Precede(char c1,char c2)
{
	int i=0,j=0;
	static char array[49]={
	'>', '>', '<', '<', '<', '>', '>',
	'>', '>', '<', '<', '<', '>', '>',
	'>', '>', '>', '>', '<', '>', '>',
	'>', '>', '>', '>', '<', '>', '>',
	'<', '<', '<', '<', '<', '#', '!',
	'>', '>', '>', '>', '!', '>', '>',
	'<', '<', '<', '<', '<', '!', '#'};
	switch(c1)
	{
        /* i为下面array的横标 */
        case '+' : i=0;break;
        case '-' : i=1;break;
        case '*' : i=2;break;
        case '/' : i=3;break;
        case '(' : i=4;break;
        case ')' : i=5;break;
        case '=' : i=6;break;
	}

	switch(c2)
	{
        /* j为下面array的纵标 */
        case '+' : j=0;break;
        case '-' : j=1;break;
        case '*' : j=2;break;
        case '/' : j=3;break;
        case '(' : j=4;break;
        case ')' : j=5;break;
        case '=' : j=6;break;
	}
	return (array[7*i+j]); /* 返回运算符 */
}
/*操作函数 */
int Operate(int a,char theta,int b)
{
	switch(theta)
	{
        case '+' : return (a+b);
        case '-' : return (a-b);
        case '*' : return (a*b);
        case '/' : return (a/b);
	}
	return 0;
}

int num(int n)//返回操作数的长度
{
    char p[10];
    //itoa(n,p,10);//把整型转换成字符串型
    n=strlen(p);
    return n;
}
int EvaluateExpression()//主要操作函数
{
    Stack OPTR;
    Stack2 OPND;
    int a,b,d,x;
    char c;
    int i;
    InitStack(OPTR); /* 初始化运算符栈 */
	Push(OPTR,'='); /* 将=压入运算符栈 */
	InitStack2(OPND); /* 初始化操作数栈 */
	c=getchar();
	x=GetTop(OPTR);
	while(c!='='||GetTop(OPTR)!='=')
	{
        if(In(c))
        {
            switch(Precede(GetTop(OPTR),c))
            {
                case '<':Push(OPTR,c);c=getchar();;break;
                case '#':Pop2(OPTR,x);c=getchar();;break;
                case '>':Pop2(OPTR,theta);Pop2(OPND,b); Pop2(OPND,a);Push2(OPND,Operate(a,theta,b));
                break;
            }
        }
        else if
        {
            i=0;
            while(c>='0'&&c<='9')
            {
                z[i++]=c;
                c=getchar();
            }
            z[i]=0;
            d=atoe(z);
            Push(OPND,d);
        }
        else exit(ERROR);
	}
	return GetTop2(OPND);
}
int main( )
{

	printf("%d", EvaluateExpression());
	return 0;
}
