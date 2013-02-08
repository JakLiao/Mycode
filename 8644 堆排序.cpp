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
}HeapType;

void Creat_Heap(HeapType &L){
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&L.r[i]);
    }
    L.length=n;
}

void print(HeapType &L){
    int j;
    for(j=1;j<L.length;j++)
        printf("%d ",L.r[j]);
    printf("%d\n",L.r[L.length]);
}

void HeapAdjust(HeapType &H,int s, int m)
{
    redtype rc=H.r[s];
    int j;
    for(j=2*s;j<=m;j*=2)
    {
        if(j<m&&(H.r[j].key<H.r[j+1].key))  j++;
        if(rc.key>=H.r[j].key) break;
        H.r[s]=H.r[j];
        s=j;
    }
    H.r[s] = rc;
}

void HeapSort(HeapType &H)
{
    int i;
    redtype tmp;
    for(i=H.length/2;i>0;i--)
        HeapAdjust(H,i,H.length);
    print(H);
    for(i=H.length;i>1;i--)
    {
        tmp = H.r[1];
        H.r[1] = H.r[i];
        H.r[i] = tmp;
        HeapAdjust(H,1,i-1);
        print(H);
    }
}

int main()
{
    HeapType H;
    Creat_Heap(H);
    HeapSort(H);
    return 0;
}
