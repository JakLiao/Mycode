#include"stdio.h"
#include"stdlib.h"
#include"math.h"

int gcd(int p,int q)
{
    if(p==q) return p;
        else if(p>q) return gcd(p-q,q);
            else return gcd(p,q-p);
}
int sum(int num)
{
    int result=0;
    while(num>0)
   {
      result+=num%10;
      num = num/10;
   }
   return result;
}
int main()
{
    float lucky,password,k;
    int i,n=0;
    int pdsum=0;
    scanf("%f",&lucky);
    for(i=0;i<1000000;i++)
    {
        password=i*lucky;
        if(password<1000000)
        {
            pdsum=sum(password);
            k=lucky/pdsum;
            if(fabs(k-(int)k)<0.0000000001)
            {
                n++;
            }
        }
    }
    printf("%d",n);
    return 0;
}
