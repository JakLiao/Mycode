#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int gcd(int p,int q)
{
    if(p==q) return p;
        else if(p>q) return gcd(p-q,q);
            else return gcd(p,q-p);
}

int main()
{
    int a,b,c,d,e,f;
    int gcd1,lcm_1,lcm_2;
    while(1)
    {
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        if(a==0) break;
        gcd1=gcd(gcd(a,b),c);
        lcm_1=d*e/gcd(d,e);
        lcm_2=lcm_1*f/gcd(lcm_1,f);
        if(lcm_2%gcd1==0) printf("YES\n");
            else printf("NO\n");
      }
      return 0;
}
