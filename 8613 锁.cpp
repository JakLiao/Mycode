#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
int a[100001];

int main()
{
    int i,j,N,ans=0,temp,num;
    scanf("%d",&N);
    while(N!=0)
    {
        ans=0;
        for(i=0;i<N;i++)
            scanf("%d",&a[i]);
        for(i=0;i<N;i++)
            for(j=i+1;j<N;j++)
            {
                num=(N-(j-i))<(j-i)?(N-(j-i)):(j-i);
                temp=a[i]+a[j]+num;
                if(temp>ans) ans=temp;
            }
        printf("%d\n",ans);
        scanf("%d",&N);
    }
    return 0;
}
