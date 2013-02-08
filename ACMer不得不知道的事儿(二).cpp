#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int a[100005],b[100005],c[100005];
    int T,n;
    int i,j,t;
    int s=0,m=0,max,min;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%d",&n);
        for(t=0;t<n;t++)
            scanf("%d",&a[t]);
        max=a[0];
        min=a[n-1];
        s=0;m=0;

        for(j=0;j<n;j++)
        {
            if(max>=a[j]) continue;
            else {max=a[j];b[s++]=j;}
        }

        for(j=n-2;j>=0;j--)
        {
            if(min<=a[j]) continue;
            else {min=a[j];c[m++]=j;}
        }

        printf("%d\n",s+1);
        printf("0 ");
        for(j=0;j<s;j++)
            printf("%d ",b[j]);
        printf("\n");

        printf("%d\n",m+1);
        for(j=m-1;j>=0;j--)
            printf("%d ",c[j]);
        printf("%d\n",n-1);
    }
    return 0;
}
