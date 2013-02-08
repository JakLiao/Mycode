#include<stdio.h>
#include<malloc.h>
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
    q=(LinkList)malloc(sizeof(LNode));
    q=L;
    for (i=0; i<n; i++)
    {
        scanf("%d", &e);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=NULL;
        q->next=p;
        q=p;
    }
    return OK;
}

int LoadLink_L(LinkList &L)
{
    LinkList p = L->next;
    if(p==NULL)printf("The List is empty!");
    else
    {
        while(p!=NULL)
        {
            printf("%d ",p->data);
            p=p->next;
        }
    }
    printf("\n");
    return OK;
}


int main()
{
    LinkList la,p,q;
    int n,i;
    scanf("%d",&n);
    CreateLink_L(la,n);
    p=la;
    printf("The List is:");
    LoadLink_L(la);

    printf("The turned List is:");
    for(i=0;i<n;i++)
    {
        for(p=la;p->next!=NULL;q=p,p=p->next);
        printf("%d ",p->data);
        q->next=NULL;
        free(p);
    }
    return OK;
}
