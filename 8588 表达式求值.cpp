#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
     SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
     SElemType *top; // 栈顶指针
     int stacksize; // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
// 请补全代码
    S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,SElemType e)
{
// 在栈S中插入元素e为新的栈顶元素
// 请补全代码
    if((S.top-S.base)>=S.stacksize)
    {
        S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return ERROR;
            S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status Pop(SqStack &S,SElemType &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
// 请补全代码
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

Status GetTop(SqStack S)
{
// 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
// 请补全代码
    Status e;
    if(S.top==S.base) return ERROR;
     e=*(S.top-1);
    return e;
}

int StackLength(SqStack S)
{
// 返回栈S的元素个数
// 请补全代码
    int i;
    i=S.top-S.base;
    return i;
}

Status StackTraverse(SqStack S)
{
// 从栈顶到栈底依次输出栈中的每个元素
	SElemType *p = (SElemType *)malloc(sizeof(SElemType));
	p =  S.top;        //请填空
	if(p==S.base) printf("The Stack is Empty!"); //请填空
	else
	{
		//printf("The Stack is: ");
		p--;
		while(p>=S.base)            //请填空
		{
			printf("%d ",*p);
			p--;               //请填空
		}
	}
	printf("\n");
	return OK;
}

Status In(SElemType &c)
{

    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='('||c==')')
        return OK;
    else
        return ERROR;
}

Status Operate(SElemType a,SElemType theta,SElemType b)
{
    switch(theta)
    {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
}

int precede(int a,int b)
{
	if(a=='('&&b==')')
		return '=';
	if(b=='#'||b==')'||a==')')
		return '>';
	if(a=='#'||b=='('||a=='(')
		return '<';
	if(a=='*'||a=='/'||b=='+'||b=='-')
		return '>';
	else
		return '<';
}

int main()
{
     SElemType a,b,c,x,theta;
     SqStack OPTR,OPND;
     InitStack(OPTR);InitStack(OPND);
     Push(OPTR,'#');
     c=getchar();
     while(c!='='||GetTop(OPTR)!='#')
     {

         if(!In(c))
		 {
            c=c-'0';
			Push(OPND,c);
			c=getchar();
		 }
        else
            switch(precede(GetTop(OPTR),c))
            {
                case '<':Push(OPTR,c);c=getchar();break;
                case '=':Pop(OPTR,x); c=getchar();break;
                case '>':Pop(OPTR,theta);
                         Pop(OPND,b);Pop(OPND,a);
                         Push(OPND,Operate(a,theta,b));
                         break;
            }
     }
     StackTraverse(OPND);
     printf("%d",GetTop(OPND));
     return 0;
}
