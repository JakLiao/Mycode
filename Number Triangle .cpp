#include<stdio.h>
#include<string.h>
int dp[1001][1001];
int MAX(int a,int b)
{
    int max;
    max=a>b?a:b;
    return max;
}
int main()
{
    int n,a,max=0;
    int i,j;
    while(~scanf("%d",&n))
    {
        for(i=0;i<1001;++i)
            for(j=0;j<1001;++j)
                dp[i][j]=0;
        //memset(dp,0,sizeof(dp));
        for(i=1;i<=n;++i)
            for(j=1;j<=i;++j)
            {
                scanf("%d",&a);
                dp[i][j]=MAX(dp[i-1][j-1],dp[i-1][j])+a;
                if(dp[i][j]>max) max=dp[i][j];
            }
        printf("%d\n",max);
    }
    return 0;
}
