#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int n,maxdata=0,maxweight;
    int w[3001],t[1001];
    int i,j,ans=0,p;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&w[i],&t[i]);
        if(maxdata<t[i]) maxdata=t[i];
    }
    //printf("%d\n",maxdata);
    for(i=maxdata;i>0;i--)
    {
        maxweight=0;
        p=0;
        for(j=1;j<=n;j++)
        {
            if(t[j]>=i&&w[j]>maxweight)
            {
                maxweight=w[j];
                p=j;
            }
        }
        //printf("%d\n",maxweight);
        ans+=maxweight;
        w[p]=0;
    }
    printf("%d\n",ans);
    return 0;
}
