#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define ElemType int

typedef struct LNode
{
	int data;
	struct LNode *next;
}LNode,*LinkList;

int CreateLink_L(LinkList &L,int n)
{
	LinkList p,q;
	int i;
	ElemType e;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	q = L;
	for (i=0;i<n;i++)
	{
		scanf("%d",&e);
		p = (LinkList)malloc(sizeof(LNode));
		if(!p)
			return ERROR;
		p->data=e;
		q->next=p;
		p->next=NULL;
		q=p;
	}
	return OK;
}

int LoadLink_L(LinkList &L)
{
	LinkList p = L->next;
	if(!p)
		return ERROR;
	else
	{
		while(p)
		{
		printf("%d ",p->data);
	    p=p->next;
		}
	}
	printf("\n");
	return OK;
}

int LinkDelete_L(LinkList &L)
{
	LinkList p,p1,q;
	p=L,p1=p->next;
	while(p1)
	{
		q=p1->next;
		while(q)
		{
			if(q->data==p1->data)
			{
				p->next=p1->next;
				free(p1);
			}
			else
			{
				q=q->next;
			}
		}
		p=p1;
		p1=p1->next;
	}
	return OK;
}

int LinkDelete_L2(LinkList &L)
{
	LinkList p,q1,q2;
	p=L->next;
	while(p)
	{
		q1=p;
		while(q1->next)
		{
			q2=q1->next;
			if(q2->data==p->data)
			{
				q1->next=q2->next;
				free(q2);
			}
			else
			{
				q1=q2;
				q2=q2->next;
			}
		}
		p=p->next;
	}
	return OK;
}

int main()
{
	int n;
	LinkList L;
	scanf("%d",&n);
	CreateLink_L(L,n);
	LoadLink_L(L);
	LinkDelete_L(L);
	LoadLink_L(L);
	return 0;
}
