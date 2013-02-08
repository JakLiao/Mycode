#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
int f(long long n,int m)
{
    if(n/m*m==n)
        return 1;
    else return 0;
}
int main()
{
    long long n=0;
    int T;
    scanf("%d",&T);
    for(int cas=0;cas<T;cas++)
    {
        scanf("%lld",&n);
        long long total=0;
        /*for(long long i=1;i<=n;i++)
        {
            total=(total+i*i)%20111111;
        }*/
        long long a=n,b=2*n+1,c=n+1;
        if(f(a,2)) a=a/2;
            else if(f(b,2)) b=b/2;
                else if(f(c,2)) c=c/2;
        if(f(a,3)) a=a/3;
            else if(f(b,3)) b=b/3;
                else if(f(c,3)) c=c/3;
        total=(a*b%20111111)*c%20111111;
        printf("%lld\n",total%20111111);
    }
    return 0;
}
