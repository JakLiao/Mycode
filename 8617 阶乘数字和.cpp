#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int n,i,j;
    int ans[100];
    int c[1000];
    for(i=0;i<100;i++) ans[i]=0;
    for(i=0;i<1000;i++) c[i]=0;
    c[1]=c[0]=1;
    for(j=1;j<=50;j++)
    {
        for(i=1;i<=c[0];i++) c[i]=c[i]*j;
        for(i=1;i<=c[0];i++)
        {
            c[i+1]=c[i+1]+c[i]/10;
            c[i]=c[i]%10;
        }
        while(c[c[0]+1])
        {
            c[0]++;
            c[c[0]+1]=c[c[0]+1]+c[c[0]]/10;
            c[c[0]]=c[c[0]]%10;
        }
        for(i=1;i<=c[0];i++) ans[j]+=c[i];
    }
    scanf("%d",&n);
    while(n!=0)
    {
        printf("%d\n",ans[n]);
        scanf("%d",&n);
    }
    return 0;
}
