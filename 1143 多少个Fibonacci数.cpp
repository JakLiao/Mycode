#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    double ch1,ch2;
    double f1,f2,fn;
    scanf("%lf %lf",&ch1,&ch2);
    while(ch1!=0&&ch2!=0)
    {
        int count=0;
        f1=0;
        f2=1;
        fn=1;
        while(fn<ch1)
        {
            f1=f2;
            f2=fn;
            fn=f1+f2;
        }
        while(fn<ch2)
        {
            count++;
            f1=f2;
            f2=fn;
            fn=f1+f2;
        }
        printf("%d\n",count);
        scanf("%lf %lf",&ch1,&ch2);
    }
    return 0;
}
