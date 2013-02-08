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
    LinkList la,lb,lc,p,q,r,s;
    int n;
    scanf("%d",&n);
    CreateLink_L(la,n);
    scanf("%d",&n);
    CreateLink_L(lb,n);
    printf("List A:");
    LoadLink_L(la);
    printf("List B:");
    LoadLink_L(lb);
    lc=(LinkList)malloc(sizeof(LNode));
    lc->next=NULL;
    r=lc;
    p=la->next;q=lb->next;
    while(p&&q)
    {
        if(p->data<=q->data)
        {
             s=p;p=p->next;
             r->next=s;r=s;r->next=NULL;
        }
        else
        {
            s=q;q=q->next;
            r->next=s;r=s;r->next=NULL;
        }
    }
    if(p) r->next=p;
    if(q) r->next=q;
    printf("List C:");
    LoadLink_L(lc);
    return OK;
}
