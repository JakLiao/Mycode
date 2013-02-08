#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

void SelectSort(int r[],int n){
    int i,j=1,tmp,k;
    int min=0,p;
    for(i=0;i<n-1;++i)
    {
        p=i;
        min=r[i];
        for(j=i+1;j<n;++j)
            if(min>r[j])
            {
                min=r[j];
                p=j;
            }
        tmp = r[i];
        r[i]= r[p];
        r[p]= tmp;
    }
}

int funnum(int k)
{
    int a[4];
    int minnum,maxnum;
    for(int i=0;i<4;i++)
    {
        a[i]=k%10;
        k=k/10;
    }
    SelectSort(a,4);
    minnum=a[0]*1000+a[1]*100+a[2]*10+a[3];
    maxnum=a[3]*1000+a[2]*100+a[1]*10+a[0];
    return maxnum-minnum;
}
int main()
{
    int i,k,m;
    scanf("%d",&k);
    while(1)
    {
        m=k;
        k=funnum(k);
        if(m==k) break;
    }
    printf("%d",k);
    return 0;
}
