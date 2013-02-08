#include "stdio.h"
#include "malloc.h"
#define OK  1
#define ERROR  0
#define STACK_INIT_SIZE 100 // 栈存储空间初始分配量
#define STACKINCREMENT 10   // 栈存储空间分配增量
#define MAXQSIZE 100        // 队列最大长度

typedef int  Status;        //函数类型
typedef int  ElemType;      //结点元素类型

typedef struct BiTNode      //树节点结构
{
  ElemType data;
  struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;

struct SqStack              //栈节点结构
{
     BiTree *base;          //结点元素类型是BiTree，用以存储树结点的指针
     BiTree *top;
     int stacksize;
};

typedef struct              //栈节点结构
{
   BiTree *base;            //结点元素类型是BiTree，用以存储树结点的指针
   int front;
   int rear;
 }SqQueue;


//================================栈的基本操作============================

Status InitStack(SqStack &S)             // 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
{
    S.base=(BiTree*)malloc(STACK_INIT_SIZE*sizeof(BiTree));
    if(!S.base) return ERROR;
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,BiTree e)         // 在栈S中插入元素e为新的栈顶元素
{
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

Status Pop(SqStack &S,BiTree &e)         // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
{
    if(S.top==S.base) return ERROR;
    e=*--S.top;
    return OK;
}

Status StackEmpty(SqStack &S)            // 若栈空，并返回OK；否则返回ERROR
{
    if(S.top==S.base) return OK;
    return ERROR;
}

//================================循环队列基本操作=========================

Status InitQueue(SqQueue &Q)             // 构造一个空队列Q，该队列预定义大小为MAXQSIZE
{
    Q.base=(BiTree*)malloc(MAXQSIZE*sizeof(BiTree));
    if(!Q.base) return ERROR;
    Q.front=Q.rear=0;
    return OK;
}

Status EnQueue(SqQueue &Q,BiTree e)         // 插入元素e为Q的新的队尾元素
{

    if((Q.rear+1)%MAXQSIZE==Q.front) return ERROR;
    Q.base[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
    return OK;
}

Status DeQueue(SqQueue &Q, BiTree &e)       // 若队列不空, 则删除Q的队头元素, 用e返回其值, 并返回OK; 否则返回ERROR
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return OK;
}

Status GetHead(SqQueue Q, BiTree &e)         // 若队列不空，则用e返回队头元素，并返回OK，否则返回ERROR
{
    if(Q.front==Q.rear) return ERROR;
    e=Q.base[Q.front];
    return OK;
}

Status QueueEmpty(SqQueue &Q)                // 若队列空, 返回OK; 否则返回ERROR
{
    if(Q.front==Q.rear) return OK;
    return ERROR;
}

//================================树的基本操作============================

Status Insert(BiTree &T,ElemType ins);      //插入函数声明

Status CreateBiTree(BiTree &T)               //建树
{
    ElemType ch;
    int n;
    scanf("%d",&n);
    if (n==0) {T = NULL;return OK;}       //当结点树为0，则树为空树，否则先建立树的根节点
    else
    {
        scanf("%d",&ch);
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
        T->data=ch;T->lchild=NULL;T->rchild=NULL;                    //结点初始化
    }
    for(;n>1;n--)                         //插入剩余的n-1个结点
    {
        scanf("%d",&ch);
        Insert(T,ch);
    }
    return OK;
}

Status PrintElement( ElemType e )           // 输出元素e的值
{
    printf("%d ", e );
    return OK;
}

Status PreOrderTraverse(BiTree T)           //递归的方法进行树的先序遍历
{
   if(T)
   {
       if(PrintElement(T->data))
          if(PreOrderTraverse(T->lchild))
            if(PreOrderTraverse(T->rchild))
                return OK;
       return ERROR;
   }else return OK;
}

Status InOrderTraverse( BiTree T )          //递归的方法进行树的中序遍历
{
   if(T)
   {
       if(InOrderTraverse(T->lchild))
          if(PrintElement(T->data))
            if(InOrderTraverse(T->rchild))
                return OK;
       return ERROR;
   }else return OK;

}

Status PostOrderTraverse( BiTree T)         //递归的方法进行树的后续遍历
{
   if(T)
   {
        if(PostOrderTraverse(T->lchild))
          if(PostOrderTraverse(T->rchild))
            if(PrintElement(T->data))
       return OK;
       return ERROR;
   }else return OK;

}

Status judge(BiTree T,ElemType a)           //查找树中是否有元素a
{
    if(T)
    {
        if(a==T->data||judge(T->lchild,a)||judge(T->rchild,a))   //用递归的方法对数的所有结点与a进行比较只要有一个相等，则返回1
            return OK;
        else                                                      //否则返回假
            return ERROR;
   }else return ERROR;                      //当子树为空，返回假
}

Status Insert(BiTree &T,ElemType ins)       //在树中插入结点ins
{
    BiTNode *Uf,*U,*V;
    U=T;
    if (!(V=(BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;      //构建新结点并初始化
        V->data=ins;V->lchild=NULL;V->rchild=NULL;
    while(U!=NULL)          //当子树U不为空 则以下判断U结点与新结点值的大小，把新结点继续与U的左右孩子进行比较
    {
        if(V->data<U->data)
            {Uf=U;U=U->lchild;}
        else
            {Uf=U;U=U->rchild;}
    }
    if(V->data<Uf->data)    //当U的左孩子为空并且新节点比U小，则把新节点插入作为U的左孩子
        Uf->lchild=V;
    else                    //当U的右孩子为空并且新节点比U大，则把新节点插入作为U的右孩子
        Uf->rchild=V;
    return OK;
}

Status NRInOrderTraverse(BiTree T)      //非递归中序遍历树
{
    BiTree p;
    SqStack S;
    InitStack(S);                       //构建辅助栈
    p=T;
    while(p||!StackEmpty(S))
    {
        if(p){Push(S,p);p=p->lchild;}   //当p不为空则入栈，把p指向p的左子树
        else
        {
            Pop(S,p);                  //当p为空则弹出p的父亲结点并输出，此时p指向p已经入栈的父亲结点
            PrintElement(p->data);
            p=p->rchild;                //把p指向p的右子树进行新一轮的判断
        }
    }
    return OK;

}

Status LevelOrderTraverse( BiTree T)    //层次遍历
{
    BiTree p;
    SqQueue Q;
    InitQueue(Q);                   //构建层次遍历的辅助队列
    p=T;
    EnQueue(Q,p);                  //树的头结点入队
    while(p->lchild||p->rchild||!QueueEmpty(Q))
    {
        if(p->lchild) EnQueue(Q,p->lchild);     //树p的左子树不为空则入队
        if(p->rchild) EnQueue(Q,p->rchild);     //树p的右子树不为空则入队
        DeQueue(Q,p);                           //p出队并输出p结点的值
        PrintElement(p->data);
        GetHead(Q,p);                           //把p指向队列的头结点进行新一轮的判断
    }
}

Status TurnC( BiTree T)                 //调换树T的左右子树
{
    BiTree rc;                          //rc为中间变量，用以交换左右子树的指针方向
    rc=T->rchild;
    T->rchild=T->lchild;
    T->lchild=rc;
    return OK;
}

Status TurnT( BiTree T)               //转换树
{
   if(T)
   {
       if(TurnC(T))              //转换树T的左右子树
          if(TurnT(T->lchild))    //用递归的方式遍历所有子树并转换该子树的左右子树
            if(TurnT(T->rchild))
                return OK;
       return ERROR;
   }else return OK;
}

Status leaf(BiTree T,int &l)                          //叶子结点统计
{
    if(T)
    {
        if(T->lchild==NULL&&T->rchild==NULL) l++;     //当结点T的左右子树为空，则判定为叶子结点，叶子结点数l加一
        leaf(T->lchild,l);                            //递遍历整棵树求叶子结点数，并用l返回其值
        leaf(T->rchild,l);
    }else return ERROR;
}

Status deep(BiTree T,int &d,int d2)                   //树的深度计算
{
    if(T)
    {
        d2++;                       //用d2标记各结点的深度，并引用d返回d2的最大值，则d为树的深度。
        if(d2>d) d=d2;
        deep(T->lchild,d,d2);       //递归求左右子树的深度
        deep(T->rchild,d,d2);
    }else return ERROR;             //当T为空，直接返回父亲结点
}

int main()   //主函数
{
    BiTree T;
    ElemType a,b,ins;
    int l=0,d=0,d2=0;
    if(!CreateBiTree(T))return ERROR;               //建树，如果失败直接结束程序
    scanf("%d",&a);          //输入待查找结点
    scanf("%d",&b);
    scanf("%d",&ins);        //输入待插入结点
    PreOrderTraverse(T);     //前中后序遍历
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    printf("%d\n%d\n",judge(T,a),judge(T,b));   //查找并输出结果
    Insert(T,ins);          //插入新结点
    PreOrderTraverse(T);    //插入后前中后序遍历
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    NRInOrderTraverse(T);   //非递归中序遍历
    printf("\n");
    LevelOrderTraverse(T);  //层次遍历
    printf("\n");
    TurnT(T);               // 第一次转换
    PreOrderTraverse(T);    //转换后前中后序遍历
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    printf("\n");
    TurnT(T);               //第二次转换
    PreOrderTraverse(T);    //转换后前中后序遍历
    printf("\n");
    InOrderTraverse(T);
    printf("\n");
    PostOrderTraverse(T);
    deep(T,d,d2);            //求深度d，变量d2为临时变量
    printf("\n%d",d);
    leaf(T,l);               //求叶子结点树l
    printf("\n%d",l);
    return OK;
}
