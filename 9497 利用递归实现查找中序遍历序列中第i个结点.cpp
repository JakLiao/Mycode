#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;

typedef int  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status InsertBiTree(BiTree &T,int e) //插入新结点
{
	if(T==NULL){
		T=(BiTNode *)malloc(sizeof(BiTNode));
		T->data=e;T->lchild=NULL;
		T->rchild=NULL;
		return 1;
	}
	if(T->data<e)
		InsertBiTree(T->rchild,e);
	else
		InsertBiTree(T->lchild,e);
	return 0;
}



Status PrintElement( ElemType e ) {  // 输出元素e的值
	printf("%d ", e );
	return OK;
}// PrintElement


Status PreOrderTraverse( BiTree T, Status(*Visit)(ElemType) )//前序遍历二叉树
 {
	if(T==NULL)  return 0;
	Visit( T->data );
	PreOrderTraverse(T->lchild,Visit);
	PreOrderTraverse(T->rchild,Visit);
	return OK;
} // PreOrderTraverse

Status InOrderTraverse( BiTree T, Status(*Visit)(ElemType) ) //中序遍历二叉树
{
	if(T==NULL)  return 0;
	InOrderTraverse(T->lchild,Visit);
	Visit(T->data);
	InOrderTraverse(T->rchild,Visit);
	return 1;
} // InOrderTraverse

Status PostOrderTraverse( BiTree T, Status(*Visit)(ElemType) )//后序遍历二叉树
 {
    if(T==NULL)  return 0;
	PostOrderTraverse(T->lchild,Visit);
	PostOrderTraverse(T->rchild,Visit);
	Visit(T->data);
	return 1;

} // PostOrderTraverse


BiTNode* FindNode( BiTree Ta,i) //查找中序遍历序列中第i个结点。
{
	//补充内容
}





int main()   //主函数
{
	BiTree  T=NULL;
	int i,n,e;
	scanf("%d",&n);//生成二叉排序树Ta
	for(i=0;i<n;i++){
		scanf("%d",&e);
		InsertBiTree(T,e);
	}
    //前、中、后序遍历二叉树
	PreOrderTraverse(T,PrintElement);
	printf("\n");
	InOrderTraverse(T,PrintElement);
	printf("\n");
	PostOrderTraverse(T,PrintElement);
	printf("\n");

    scanf("%d",&i);
}//main
