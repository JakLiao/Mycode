#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"
int gcd(int a,int b)
{
    return a%b?gcd(b,a%b):b;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int get(int a,int b,int c)
{
	int m=min(a,min(b, c));

	for(int i=m;i>0;--i)
	{
		if(a%i==0& b%i==0&&c%i==0)
		{
			return i;
		}
	}
	return 1;
}
int main()
{
    int a,b,c,gcd1,gcd2,gcd3,gcd4,x0,y0,z0,x1,y1,z1,ans;
    scanf("%d %d %d %d %d %d",&x0,&y0,&z0,&x1,&y1,&z1);
    a=abs(x0-x1);
    b=abs(y0-y1);
    c=abs(z0-z1);
    gcd1=gcd(a,b);
    gcd2=gcd(b,c);
    gcd3=gcd(a,c);
    gcd4=get(a,b,c);
    ans=a+b+c-gcd1-gcd2-gcd3+gcd4;
    printf("%d",ans);
    return 0;
}
