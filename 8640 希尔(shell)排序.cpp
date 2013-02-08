#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

#define MAXSIZE 100
typedef int keytype;
typedef struct
{
    keytype key;
}redtype;

typedef struct{
    redtype r[MAXSIZE+1];
    int length;
}SqList;

void Creat_list(SqList &L){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&L.r[i]);
    }
    L.length=n;
}

void print(SqList &L){
    int j;
    for(j=1;j<L.length;j++)
        printf("%d ",L.r[j]);
    printf("%d\n",L.r[L.length]);
}

void Shellsort(SqList &L,int n){
    int i,j,k,dk;
    dk=n/2;
    while(dk>0)
    {
        for(i=dk+1;i<=L.length;i++)
        {
            if(L.r[i].key<=L.r[i-dk].key)
            {
                L.r[0]=L.r[i];
                for(j=i-dk;L.r[0].key<L.r[j].key&&j>0;j-=dk)
                    L.r[j+dk]=L.r[j];
                L.r[j+dk]=L.r[0];
            }
            //print(L);
        }
        print(L);
        dk=dk/2;
    }
}

int main()
{
    SqList L;
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&L.r[i]);
    }
    L.length=n;
    Shellsort(L,n);
    return 0;
}
