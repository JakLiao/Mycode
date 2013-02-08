#include"stdio.h"
#include"stdlib.h"
#include"math.h"

int main()
{
    int a,b,c,n,i,count;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        count=0;
        for(c=(a*a+1)/2;c>=a+1;c--)
        {
            b=c*c-a*a;
            if((int)sqrt(b)*(int)sqrt(b)==b) {printf("%d,%d\n",c,(int)sqrt(b));count++;}
        }
        for(c=a-1;c*c>=a*a/2;c--)
        {
            if(c==0) break;
            b=a*a-c*c;
            if((int)sqrt(b)*(int)sqrt(b)==b) {printf("%d,%d\n",c,(int)sqrt(b));count++;}
        }
        if(count==0) printf("\n");
        if(i!=n-1) printf("\n");
    }
    return 0;
}
