#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
int a[1000002],b[1000002];
int min(int a,int b)
{
    return a<=b?a:b;
}
int main()
{
    int i=0,j=0,k=1,n,total=0,max1=0,max2=0;
    scanf("%d",&n);
    //memset(b,0,sizeof(b));
    for(i=0;i<n;i++)    {scanf("%1d",&a[i]);}
    a[n]=a[n+1]=1;
    for(i=0;i<=n;i++)
    {
        if(a[i]==1) continue;
            else    j++;
        if(a[i]==0&&a[i+1]==1)
        {
            b[k]=j;
            j=0;
            k++;
        }
    }
    /*for(i=0;i<k;i++)
        printf("%d ",b[i]);
    printf("\n");*/
    b[0]=0;
    if(k==1)
    {
        printf("%d",b[0]);
    }
    else
    {
        for(i=0;i<k;i++)
        {
            if(b[i]>=b[max1])
            max1=i;
        }
        for(j=0;j<k;j++)
        {
            if((b[j]>=b[max2])&&(j!=max1))
            max2=j;
        }
        //printf("%d %d\n",max1,max2);
        total=b[max1]+b[max2];
        printf("%d\n",total);
    }
    return 0;
}
