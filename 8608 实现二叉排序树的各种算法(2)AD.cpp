#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1

#define MAXQSIZE 100
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10 // 存储空间分配增量

typedef int  ElemType;
typedef int  Status;//Status是函数的类型,其值是函数结果状态代码，如OK等

typedef struct BiTNode{//树的结构
    ElemType  data;
    struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

typedef BiTree SElemType; // 定义栈元素类型

typedef struct{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素为单位
}SqStack; // 顺序栈

Status InitStack(SqStack &S){
// 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    S.base=(SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
    if(!S.base) return(ERROR);
    S.top = S.base;
    S.stacksize=STACK_INIT_SIZE;
    return OK;
}

Status Push(SqStack &S,BiTree e){
// 在栈S中插入元素e为新的栈顶元素
    if(S.top-S.base>=S.stacksize)
    {
        S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if(!S.base) return(ERROR);
        S.top=S.base+S.stacksize;
        S.stacksize+=STACKINCREMENT;
    }
    *S.top++=e;
    return OK;
}

Status StackEmpty(SqStack &S){
//  判断栈空
    if(S.top==S.base)
        return TRUE;
    else return FALSE;
}

Status Pop(SqStack &S,SElemType &e){
// 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    if(StackEmpty(S)) return ERROR;
    e=*--S.top;
    return OK;
}

Status SearchBST(BiTree T,int key,BiTree f,BiTree &p){
    //在根指针T所指的二叉树中递归地查找其大小等于key的数据元素，若查找成功，
    //则指针p指向该数据元素结点，并返回TRUE，否则指针p指向查找路径上访问的
    //最后一个结点并返回FALSE，指针f指向T的双亲，其初始调用值为NULL
    if (!T)  {p=f;return FALSE;}//查找不成功
    else if (key==T->data) {p=T;return TRUE;}//查找成功
    else if (key<T->data)   return SearchBST(T->lchild,key,T,p);//在左子树中继续查找
    else  return SearchBST(T->rchild,key,T,p);//在右子树中继续查找
}

Status InsertBST(BiTree &T,ElemType e){
    //当二叉排序树T中不存在大小的等于e的数据元素时，插入e，并返回TRUE
    //否则返回FALSE
    BiTNode *p,*s;
	if(!SearchBST(T,e,NULL,p)){     //查找不成功
		s = (BiTNode *)malloc(sizeof(BiTNode));//构建新结点
		s->data = e;s->lchild = NULL;s->rchild = NULL;
		if(!p) T = s;               //被插结点*s为新的根结点
		else if(e < p->data) p->lchild = s;//被插结点*s为左孩子
		else p->rchild = s;//被插结点*s为右结点
		return TRUE;
	}
	else return FALSE;//树中已有关键字相同的结点，不再插入
}

Status CreateBiTree(BiTree &T,int e) {//创建树
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=e;
    T->lchild=NULL;
    T->rchild=NULL;
    return OK;
}

Status PrintElement( ElemType e ) {//输出元素e的值
    printf("%d ", e );
    return OK;
}// PrintElement

Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) ){
   // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit
    if(T==NULL)  return 0;
	Visit(T->data );
	PreOrderTraverse(T->lchild,Visit);
	PreOrderTraverse(T->rchild,Visit);
	return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ){
     // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    if(T==NULL)  return 0;
	InOrderTraverse(T->lchild,Visit);
	Visit(T->data);
	InOrderTraverse(T->rchild,Visit);
	return OK;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) {
     // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    if(T==NULL)  return 0;
	PostOrderTraverse(T->lchild,Visit);
	PostOrderTraverse(T->rchild,Visit);
	Visit(T->data);
	return OK;
} // PostOrderTraverse

Status LevelOrderTraverse(BiTree T){
    //二叉树的层次遍历
    BiTree Queue[MAXQSIZE],p;
    int front=0,rear=0;
    if(T)
    {
        Queue[rear++]=T;
        while(front!=rear)
        {
            p=Queue[front++];
            printf("%d ",p->data);
            if(p->lchild!=NULL) Queue[rear++]=p->lchild;
            if(p->rchild!=NULL) Queue[rear++]=p->rchild;
        }
    }
    return OK;
} // LevelOrderTraverse

SqStack S;

Status Dif_InOrder( BiTree T){
    //采用二叉链表存储结构，Visit是对数据元素操作的应用函数
    //中序遍历二叉树T的非递归算法，对每个数据元素调用函数Visit
    BiTree p;
    SqStack S;
    InitStack(S);
    p = T;
    while(p||!StackEmpty(S)){
        if(p) {Push(S,p);p = p->lchild;}//根指针进栈，遍历左子树
        else{       //根指针退栈，访问根结点，遍历右子树
            Pop(S,p);
            printf("%d ",p->data);
            p=p->rchild;
        }//else
    }//While
    return OK;
}

Status PreOrderd(BiTree T){
    //递归先序,但不输出
    if(T)
    {
        PreOrderd(T->lchild);
        PreOrderd(T->rchild);
    }
    return OK;
}

void changeleaf(BiTree  T){
    //交换左右子树
	if(T!=NULL)
	{
        BiTree p;
        p=T->lchild;
        T->lchild=T->rchild;
        T->rchild=p;
        changeleaf(T->lchild);
        changeleaf(T->rchild);
    }
}

int deep(BiTree  T) {
    //二叉树的深度
	int deepth,ldeep,rdeep;
	if(!T) deepth=0;
	else
	{
        ldeep=deep(T->lchild);
        rdeep=deep(T->rchild);
        if(ldeep>rdeep) deepth=1+ldeep;
            else    deepth=1+rdeep;
	}
    return deepth;
}

Status leaves(BiTree T,int &m){
    //m为叶子结点数
    if(!T) return ERROR;
    {
        if(T->lchild==NULL&&T->rchild==NULL) m++;
        else {leaves(T->lchild,m);leaves(T->rchild,m);}
    }
    return OK;
}

int main()
{
    BiTNode *T;
    int n,key0,key1,leavesnum=0,in,d;
    int i,m;
    BiTree p,f;
    scanf("%d",&n);
    int *a;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
	CreateBiTree(T,a[0]);
	for(i=1;i<n;i++)
	{
       SearchBST(T,a[i],f,p);
       InsertBST(T,a[i]);
	}

	PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");

    scanf("%d",&key0); m=SearchBST(T,key0,f,p); printf("%d\n",m);//搜寻结果
    scanf("%d",&key1);m=SearchBST(T,key1,f,p);printf("%d\n",m);
    scanf("%d",&in);
    SearchBST(T,in,f,p);
    InsertBST(T,in);//插入结点
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");
    Dif_InOrder(T);
    printf("\n");
    LevelOrderTraverse(T);
	printf("\n");

    changeleaf(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");

    changeleaf(T);
    PreOrderTraverse(T,PrintElement);
    printf("\n");
    InOrderTraverse(T,PrintElement);
    printf("\n");
    PostOrderTraverse(T,PrintElement);
    printf("\n");

	d=deep(T);
	printf("%d\n",d);
	leaves(T,leavesnum);
	printf("%d\n",leavesnum);
	return 0;
 }

/*Sample Input
7
40 20 60 18 50 56 90
18
35
30

Sample Output
40 20 18 60 50 56 90
18 20 40 50 56 60 90
18 20 56 50 90 60 40
1
0
40 20 18 30 60 50 56 90
18 20 30 40 50 56 60 90
18 30 20 56 50 90 60 40
18 20 30 40 50 56 60 90
40 20 60 18 30 50 90 56
40 60 90 50 56 20 30 18
90 60 56 50 40 30 20 18
90 56 50 60 30 18 20 40
40 20 18 30 60 50 56 90
18 20 30 40 50 56 60 90
18 30 20 56 50 90 60 40
4
4
*/
