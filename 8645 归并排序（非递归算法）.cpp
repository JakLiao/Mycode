#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

typedef int redtype;

void Merge(redtype sr[],redtype tr[],int first,int mid,int last)
{
    int p=first,q=mid+1;
    int pos=first;
    while(p<=mid&&q<=last)
    {
        if(sr[p]<sr[q]) {tr[pos++]=sr[p++];}
            else {tr[pos++]=sr[q++];}
    }
    if(p>mid)
    {
        while(q<=last) {tr[pos++]=sr[q++];}
    }
    else
    {
        while(p<=mid) {tr[pos++]=sr[p++];}
    }
}

void MergePass(redtype a[],redtype b[],int gap,int n)
{//一定的步长对数据合并
    int i=0,j;
    while(i<=n-2*gap+1)
    {
        Merge(a,b,i,i+gap-1,i+2*gap-1);
        i+=2*gap;
    }
    if(i<(n-gap))
        Merge(a,b,i,i+gap-1,n-1);
    else
        for(j=i;j<n;j++)
            b[j]=a[j];

    for(int i=0;i<n-1;i++)
        printf("%d ",b[i]);
    printf("%d\n",b[n-1]);
}

void MergeSort(redtype a[],redtype b[],int n)
{
    int gap=1;
    while(gap<n)
    {
        MergePass(a,b,gap,n);
        gap*=2;
        MergePass(b,a,gap,n);
        gap*=2;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int data[n],cp[n];
    for(int i=0;i<n;i++)
        scanf("%d",&data[i]);
    MergeSort(data,cp,n);
    return 0;
}
