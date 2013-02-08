#include "stdio.h"
#include "malloc.h"
#define OK  1
#define ERROR  0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10   // 存储空间分配增量
#define MAXQSIZE 100        // 最大队列长度(对于循环队列，最大队列长度要减1)

typedef int  Status;
typedef int  ElemType;

typedef struct BiTNode     //树节点结构
{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

struct SqStack                  //栈节点结构
{
     BiTree *base; // 在栈构造之前和销毁之后，base的值为NULL
     BiTree *top;  // 栈顶指针
     int stacksize;   // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

typedef struct
{
   BiTree *base; // 初始化的动态分配存储空间
   int front;       // 头指针,若队列不空,指向队列头元素
   int rear;        // 尾指针,若队列不空,指向队列尾元素的下一个位置
 }SqQueue;


//================================栈部分的函数============================

Status InitStack(SqStack &S)
{
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base=(BiTree*)malloc(STACK_INIT_SIZE*sizeof(BiTree));
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,BiTree e)
{
// 在栈S中插入元素e为新的栈顶元素
    if((S.top-S.base)>=S.stacksize)
    {
        S.base=(BiTree*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(BiTree));
        if(!S.base) return ERROR;
            S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;

}

Status Pop(SqStack &S,BiTree &e)
{
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

Status StackEmpty(SqStack &S)
{
// 若栈空，并返回OK；否则返回ERROR
    if(S.top==S.base) return OK;
    return ERROR;
}

//================================循环队列部分的函数=========================

Status InitQueue(SqQueue &Q)
{
// 构造一个空队列Q，该队列预定义大小为MAXQSIZE
    Q.base=(BiTree*)malloc(MAXQSIZE*sizeof(BiTree));
    if(!Q.base) return ERROR;
    Q.front=Q.rear=0;
    return OK;
}

Status EnQueue(SqQueue &Q,BiTree e)
{
// 插入元素e为Q的新的队尾元素
    if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, BiTree &e)
{
// 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

Status GetHead(SqQueue Q, BiTree &e)
{
// 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
// 请补全代码
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    return OK;
}

Status QueueEmpty(SqQueue &Q)
{
// 若队列空, 返回OK; 否则返回ERROR
    if(Q.front==Q.rear) return OK;
    return ERROR;
}
//================================树部分的函数============================
Status CreateBiTree(BiTree &T)
{
    ElemType ch;
    BiTree Uf,U,V;
    int n,i=0;
    scanf("%d",&n);
    if (n==0) {T = NULL;return OK;}
    else
    {
        scanf("%d",&ch);
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        T->data=ch;T->lchild=NULL;T->rchild=NULL;
    }
    for(;n>1;n--)
    {
        U=T;
        scanf("%d",&ch);
        if (!(V=(BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        V->data=ch;V->lchild=NULL;V->rchild=NULL;
        while(U!=NULL)
        {
            if(V->data<U->data)
                {Uf=U;U=U->lchild;}
            else
                {Uf=U;U=U->rchild;}
        }
        if(V->data<Uf->data)
            Uf->lchild=V;
        else
            Uf->rchild=V;
    }
    return OK;
} // CreateBiTree


Status PrintElement( ElemType e )
{  // 输出元素e的值
    printf("%d ", e );
    return OK;
}// PrintElement


Status PreOrderTraverse(BiTree T)
{
   if(T)
   {
       if(PrintElement(T->data))
          if(PreOrderTraverse(T->lchild))
            if(PreOrderTraverse(T->rchild))
                return OK;
       return ERROR;
   }else return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T )
{
   if(T)
   {
       if(InOrderTraverse(T->lchild))
          if(PrintElement(T->data))
            if(InOrderTraverse(T->rchild))
                return OK;
       return ERROR;
   }else return OK;

} // InOrderTraverse

Status PostOrderTraverse( BiTree T)
{
   if(T)
   {
        if(PostOrderTraverse(T->lchild))
          if(PostOrderTraverse(T->rchild))
            if(PrintElement(T->data))
       return OK;
       return ERROR;
   }else return OK;

} // PostOrderTraverse

Status judge(BiTree T,ElemType a)
{
    //判断函数
    if(T)
    {
        if(a==T->data||judge(T->lchild,a)||judge(T->rchild,a))
            return OK;
        else
            return ERROR;
   }else return ERROR;
}

Status Insert(BiTree &T,ElemType ins)
{
    //插入函数
    BiTNode *Uf,*U,*V;
    U=T;
    if (!(V=(BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        V->data=ins;V->lchild=NULL;V->rchild=NULL;
    while(U!=NULL)
    {
        if(V->data<U->data)
            {Uf=U;U=U->lchild;}
        else
            {Uf=U;U=U->rchild;}
    }
    if(V->data<Uf->data)
        Uf->lchild=V;
    else
        Uf->rchild=V;
    return OK;
}

Status NRInOrderTraverse(BiTree T)
{
    BiTree p;
    SqStack S;
    InitStack(S);
    p=T;
    while(p||!StackEmpty(S))
    {
        if(p){Push(S,p);p=p->lchild;}
        else
        {
            Pop(S,p);
            PrintElement(p->data);
            p=p->rchild;
        }
    }
    return OK;

} // NRInOrderTraverse

Status LevelOrderTraverse( BiTree T)
{
    BiTree p;
    SqQueue Q;
    InitQueue(Q);
    p=T;
    EnQueue(Q,p);
    while(p->lchild||p->rchild||!QueueEmpty(Q))
    {
        if(p->lchild) EnQueue(Q,p->lchild);
        if(p->rchild) EnQueue(Q,p->rchild);
        DeQueue(Q,p);
        PrintElement(p->data);
        GetHead(Q,p);
    }
}



int main()   //主函数
{
    BiTree T;
    ElemType a,b,ins;
    if(!CreateBiTree(T))return ERROR;
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&ins);
    PreOrderTraverse(T); //前中后序遍历
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    printf("%d\n%d\n",judge(T,a),judge(T,b));
    Insert(T,ins);
    PreOrderTraverse(T); //插入后前中后序遍历
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    NRInOrderTraverse(T);
    printf("\n");
    LevelOrderTraverse(T);
    return OK;
}//main
