#include"stdio.h"
#include"stdlib.h"
#include"math.h"

int main()
{
    int a,b,c,d,e,f,g,h,A,B,C,D,E,F,G,H;
    long i,sum=0;
    scanf("%d %d %d %d %d %d %d %d",&A,&B,&C,&D,&E,&F,&G,&H);
    scanf("%d %d %d %d %d %d %d %d",&a,&b,&c,&d,&e,&f,&g,&h);
    for(i=2;i<pow(2,63);i++)
    {
        if(i%H==h)
        {
            if(i%G==g)
            {
                if(i%F==f)
                {
                    if(i%E==e)
                    {
                        if(i%D==d)
                        {
                            if(i%C==c)
                            {
                                if(i%B==b)
                                {
                                    if(i%A==a)
                                    {
                                        sum=i;
                                        printf("%ld",sum);
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
