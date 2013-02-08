#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int  Status;
typedef char  ElemType;

typedef struct BiTNode
{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T)
{  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;// 生成根结点
    CreateBiTree(T->lchild);    // 构造左子树
    CreateBiTree(T->rchild);  // 构造右子树
  }
  return OK;
} // CreateBiTree


Status PrintElement( ElemType e )
{  // 输出元素e的值
printf("%c", e );
return OK;
}// PrintElement


Status PreOrderTraverse(BiTree T)
{
   // 前序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
   //补全代码,可用多个语句
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
     // 中序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
    //补全代码,可用多个语句
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
     // 后序遍历二叉树T的递归算法，对每个数据元素调用函数Visit。
     //补全代码,可用多个语句
   if(T)
   {
        if(PostOrderTraverse(T->lchild))
          if(PostOrderTraverse(T->rchild))
            if(PrintElement(T->data))
       return OK;
       return ERROR;
   }else return OK;

} // PostOrderTraverse



int main()   //主函数
{
    BiTree T;
    if(!CreateBiTree(T))
        return ERROR;
    else
    {
        PreOrderTraverse(T);
        printf("\n");
        InOrderTraverse(T);
        printf("\n");
        PostOrderTraverse(T);
    }
    return OK;
}//main
