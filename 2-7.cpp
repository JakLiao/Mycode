#include<malloc.h>
#include<stdio.h>
#define OK 1
#define ERROR 0
typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
typedef int QElemType;
#define MAXQSIZE 100 // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef struct
{
    QElemType *base; // 初始化的动态分配存储空间
    int front; // 头指针,若队列不空,指向队列头元素
    int rear; // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;

Status InitQueue(SqQueue &Q)
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
// 请补全代码
    Q.base=(QElemType*)malloc(MAXQSIZE*sizeof(QElemType));
    if(!Q.base) return ERROR;
    Q.front=Q.rear=0;
    return OK;
}

Status EnQueue(SqQueue &Q,QElemType e)
{
// 插入元素e为Q的新的队尾元素
// 请补全代码
    if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
// 请补全代码
    if(Q.rear==Q.front) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
// 请补全代码
    if(Q.rear==Q.front) return ERROR;
    e=Q.base[Q.front];
    return OK;
}

int QueueLength(SqQueue Q)
{
// 返回Q的元素个数
    return (Q.rear-Q.front+MAXQSIZE)%MAXQSIZE;
}

Status QueueTraverse(SqQueue Q)
{
// 若队列不空，则从队头到队尾依次输出各个队列元素，并返回OK；否则返回ERROR.
	int i;
	i=Q.front;
	if(Q.rear==Q.front)printf("The Queue is Empty!");  //请填空
	else{
		printf("The Queue is: ");
		while(i!=Q.rear)     //请填空
		{
			printf("%d ",Q.base[i]);   //请填空
			i =(i+1)%MAXQSIZE;   //请填空
		}
	}
	printf("\n");
	return OK;
}

int main()
{
    int i,a,p,q,e,r;
    SqQueue S;
    float t,s=0;
    InitQueue(S);
    scanf("%d",&a);
    getchar();
    for(i=1;i<=a*2;i++)
    {
        scanf ("%d",&e);getchar();
        EnQueue(S,e);
    }
    p=S.base[S.front];
    while (S.rear>S.front)
    {
        q=p+S.base[S.front+1];
        DeQueue(S,e);
        DeQueue(S,e);
        if (S.front==S.rear) break;
        r=q-S.base[S.front];
        if(r<0)
        {
            r=0;
            p=S.base[S.front];
            continue;
        }
        s=s+r;
        p=q;
    }
    t=s/a;
    printf("%.2f\n",t);
    return OK;
}
