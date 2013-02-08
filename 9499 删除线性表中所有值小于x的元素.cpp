#include<malloc.h>
#include<iostream>

using namespace std;


#define OK 1
#define ERROR 0
#define ElemType int
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 10

typedef struct
{
	int *elem;
	int length;
	int listsize;
}SqList;

int InitList_Sq(SqList &L)
{
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(SqList));
	if(!L.elem) return ERROR;
	L.length=0;
	L.listsize=LIST_INIT_SIZE;
	return 0;
}

int Load_Sq(SqList &L)
{
	int i;
	if(!L.length) printf("The List is empty!");
	else
	{
		for(i=1;i<L.length+1;++i)
			cout<<L.elem[i-1]<<' ';
	}
	printf("\n");
	return OK;
}

int ListInsert_Sq(SqList &L,int i,int e)
{
	ElemType *newbase;
	ElemType *p,*q;
	if(i<1||i>L.length+1) return ERROR;
	if(L.length>=L.listsize)
	{
		newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(SqList));
		if(!newbase) return 0;
		L.elem=newbase;
		L.listsize+=LISTINCREMENT;
	}
	q=&(L.elem[i-1]);
	for(p=&(L.elem[L.length-1]);p>=q;--p)
		*(p+1)=*p;
	*q=e;
	++L.length;
	return OK;
}

int ListDelete_Sq(SqList &L,int e)
{
	int i,j;
	for(i=1;i<=L.length;)
	{
		if(L.elem[i-1]<e)
		{
			for(j=i;j<=L.length;j++)
				L.elem[j-1]=L.elem[j];
			L.length--;
		}
		else i++;
	}
	return OK;
}


int main()
{
	int n,i,e,d;
	SqList L;
	InitList_Sq(L);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>e;
		ListInsert_Sq(L,i,e);
	}
	cin>>d;
	Load_Sq(L);
	ListDelete_Sq(L,d);
	Load_Sq(L);
	return 0;
}
