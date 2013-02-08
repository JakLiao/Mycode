#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
#define MAXQSIZE 100
#define Elemtype int

typedef int  Status;

typedef struct BiTNode{//树的结构
  int  data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;



Status SearchBST(BiTree T, int key, BiTree f, BiTree &p) {
  if (!T)  { p = f;  return FALSE; }
  else
        if (key==T->data) { p = T;  return TRUE; }
        else
            if (key<T->data)   return SearchBST(T->lchild, key, T, p);
            else  return SearchBST(T->rchild, key, T, p);
}



Status InsertBST(BiTree &T, Elemtype e)
{
	BiTNode *p;
	BiTNode *s;
	if(!SearchBST(T, e, NULL, p))
	{
		s = (BiTNode *)malloc(sizeof(BiTNode));//构建新结点
		s->data = e;
		s->lchild = NULL;
		s->rchild = NULL;
		if(!p) T = s;
		else if(e < p->data) p->lchild = s;
		else p->rchild = s;
		return TRUE;
	}
	else return FALSE;
}

Status CreateBiTree(BiTree &T,int e) //创建树
{
  if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
  T->data=e;
  T->lchild=NULL;
  T->rchild=NULL;
  return OK;
}

Status PreOrder(BiTree T ) {//递归先序
  if(T)
   {  printf("%d ",T->data);
      PreOrder(T->lchild);
      PreOrder(T->rchild);
   }
  return OK;
}


Status InOrder (BiTree T)//递归中序
{
	if(T)
   {
      InOrder(T->lchild);
	  printf("%d ",T->data);
      InOrder(T->rchild);
	}
   return OK;
}

Status PostOrder( BiTree  T ) {//递归后序
	if(T)
   {
	  PostOrder(T->lchild);
      PostOrder(T->rchild);
	  printf("%d ",T->data);
	}
	return OK;
}

Status LayerTraverse(BiTree T)  //层次遍历
{
BiTree q[100];
q[0]=T;
int front=0,rear=1;
while(front<rear)
{  if(q[front])
 {
 printf("%d ",q[front]->data);
 q[rear++]=q[front]->lchild;
 q[rear++]=q[front]->rchild;
 front++;
 }
 else front++;
}
return OK;
}

Status PreOrderd(BiTree T ) {//递归先序,但不输出
  if(T)
   {
      PreOrderd(T->lchild);
      PreOrderd(T->rchild);
   }
  return OK;
}

Status leave(BiTree T,int &m ) {
//递归先序,但不输出
    if(!T) return ERROR;
   {
      if(T->lchild==NULL&&T->rchild==NULL) m++;
	  else {leave(T->lchild,m);leave(T->rchild,m);}
   }
  return OK;
}



int deep( BiTree  T ) //树的叶子结点
{

	int deepth,ldeep,rdeep;
	if(!T) deepth=0;
	else
	{
	   ldeep=deep(T->lchild);
	   rdeep=deep(T->rchild);
       if(ldeep>rdeep) deepth=1+ldeep;
	   else            deepth=1+rdeep;
	}
return deepth;

}

void changeleaf(BiTree  T)
{
	if(T!=NULL)
	{BiTree p;
      p=T->lchild;
	  T->lchild=T->rchild;T->rchild=p;
     changeleaf(T->lchild);
	 changeleaf(T->rchild);	 }
}

int main()
{
	BiTNode *T;
    int n,i,key,key1,m,in,d,l=0;
    BiTree p,f;
    scanf("%d",&n);
    int *a;
    a=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
	CreateBiTree(T,a[0]);
	for(i=1;i<n;i++)
	{
       SearchBST(T, a[i], f,p);
       InsertBST(T, a[i]);
	}


	PreOrder(T);
	printf("\n");
    InOrder(T);
	printf("\n");
    PostOrder(T);
	printf("\n");


	scanf("%d",&key); m=SearchBST(T,key,f,p); printf("%d\n",m);//搜寻结果
	scanf("%d",&key1);m=SearchBST(T,key1,f,p);printf("%d\n",m);



	scanf("%d",&in);
	SearchBST(T,in,f,p);InsertBST(T, in);//插入结点


	PreOrder(T);
	printf("\n");
    InOrder(T);
	printf("\n");
    PostOrder(T);
	printf("\n");
    InOrder(T);
	printf("\n");
    LayerTraverse(T);
	printf("\n");

    changeleaf(T);
    PreOrder(T);
	printf("\n");
    InOrder(T);
	printf("\n");
    PostOrder(T);
	printf("\n");


    changeleaf(T);
    PreOrder(T);
	printf("\n");
    InOrder(T);
	printf("\n");
    PostOrder(T);
	printf("\n");



	d=deep(T);
	printf("%d\n",d);
	leave(T,l);
	printf("%d\n",l);
	return 0;
 }
