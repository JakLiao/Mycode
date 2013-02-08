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

int Partition(SqList &L,int low,int high){
    L.r[0] = L.r[low];
    int pivotkey=L.r[low].key;
    while(low<high){
        while(low<high&&L.r[high].key>=pivotkey) --high;
        L.r[low] = L.r[high];
        while(low<high&&L.r[low].key<=pivotkey) ++low;
        L.r[high] = L.r[low];
    }
    L.r[low] = L.r[0];
    print(L);
    return low;
}

void QSort(SqList &L,int low,int high){
    int pivotloc;
    if(low<high)
    {
        pivotloc = Partition(L,low,high);
        //printf("%d\n",pivotloc);
        QSort(L,low,pivotloc-1);
        QSort(L,pivotloc+1,high);

    }
}

void QuickSort(SqList &L){
    QSort(L,1,L.length);
}

int main()
{
    SqList L;
    Creat_list(L);
    QuickSort(L);
    return 0;
}
