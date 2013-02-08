#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

#define OK 1
#define ERROR 0
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define MAX_VERTEX_NUM 10
#define ElemType int
typedef struct LNode
{
    int data;
	struct LNode *next;
}LNode,*LinkList;
typedef struct ArcCell
{
	LinkList Q;
}ArcCell,AdjMatrix[MAX_VERTEX_NUM];
int CreateLink_L(LinkList &L,int e)
{
	LinkList p;
		p=(LinkList)malloc(sizeof(LNode));
		p->data=e;
		p->next=NULL;
		p->next=L->next;
		L->next=p;
	return OK;
}
typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;
int InitList_Sq(SqList &L)
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)return ERROR;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return OK;
}

int Link_length(LinkList L)
{
	int i=0;
	L=L->next;
	while(L!=NULL)
	{
		i++;
		L=L->next;
	}
	return i;
}
int main()
{
	SqList L,La;
	int i,j,m=1,t=10,key,k,a,b,c,d,max=0,flag,ma,ba,we;
	InitList_Sq(L);AdjMatrix arcs;LinkList p;InitList_Sq(La);
	scanf("%d",&L.length);
	for(i=1;i<=L.length;i++)
	{
		scanf("%d",&L.elem[i]);
        flag=L.elem[i];
		ma=0;
		while(flag!=0)
		{
			flag=flag/10;
			ma++;

		}
		if(max<ma)max=ma;
	}
	for(i=0;i<10;i++)
	{
		arcs[i].Q=(LinkList)malloc(sizeof(LNode));
		arcs[i].Q->next=NULL;
	}
    while(Link_length(arcs[0].Q)!=L.length)

	{
	    	for(i=0;i<10;i++)
			{
	        	arcs[i].Q->next=NULL;
			}

    	for(i=1;i<=L.length;i++)
		{
           key=L.elem[i]/m%t;

		   CreateLink_L(arcs[key].Q,L.elem[i]);

		}

		m=m*10;
		a=1;
		for(k=0;k<10;k++)
		{
		    b=Link_length(arcs[k].Q);
			p=arcs[k].Q->next;
			c=1;
            while(p!=NULL)

			{

                La.elem[c]=p->data;c++;
	    		p=p->next;
			}
			for(d=b;d>=1;d--)
			{
                 L.elem[a]=La.elem[d];a++;
			}
		}
		if(Link_length(arcs[0].Q)!=L.length)
		{
			for(j=1;j<=L.length;j++)
			{
				we=L.elem[j];
		    	ba=1;
				for(i=1;i<max;i++)
				{
                     ba=ba*10;
				}
		    	for(i=1;i<=max;i++)
				{
			    	printf("%d",we/ba);
						we=we-we/ba*ba;
			            ba=ba/10;
				}
				printf(" ");
			}
			printf("\n");
		}
		}


	return 1;
}
