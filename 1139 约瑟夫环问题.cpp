#include"stdio.h"
#include"malloc.h"
#define LEN (struct node)
typedef struct node
{
    int number;
    struct node *next;
}NODE;

void create_link(NODE *p,int n)
{
    NODE *q;
    for(;n>1;n--)
    {
        q=(NODE *)malloc(sizeof LEN);
        q->number=n;
        q->next=p->next;
        p->next=q;
    }
}
struct node *select_number(NODE *p,int m,int n)
{
    NODE *q;
    for(;m>2;m--)
        p=p->next;
    q=p->next;
    p->next=q->next;//½«pÉ¾³ı
    if(n==1)
        printf("%d ",q->number);
    free(q);
    return(p->next);
}
int main()
{
    NODE *p,*q;
    int n,m,s;
    p=(NODE*)malloc(sizeof LEN);
    p->number=1;
    p->next=p;
    scanf("%d %d %d",&n,&s,&m);
    create_link(p,n);
    for(;s>1;s--)
        p=p->next;
    for(;n>0;n--)
        p=select_number(p,m,n);
    return 0;
}
