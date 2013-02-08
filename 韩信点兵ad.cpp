#include<stdio.h>
#include<math.h>
double zhengchu(double x,double t)
{
    int i;
    for(i=1;1;i++)
        if(fmod((i*t),x)==1)
            return(i*t);
}
int main()
{
    int x[8],y[8];
    double z[8];
    int max=0,i;
    double total=1,ans=0;
    for(i=0;i<8;i++)
    {
        scanf("%d",&x[i]);
        total*=x[i];
        if(max<x[i]) max=x[i];
    }
    for(i=0;i<8;i++)
        scanf("%d",&y[i]);
    for(i=0;i<8;i++)
    {
        z[i]=y[i]*zhengchu(x[i],total/x[i]);
        //printf("%.0f\n",z[i]);
        ans+=z[i];
        //printf("ans=%.0f\n",ans);
    }
    ans=fmod(ans,total);
       // printf("ans=%.0f\n",ans);
    if(ans<max) ans+=total;
    printf("%.0f\n",ans);
    return 0;
}
/*
Sample Input
2 3 5 7 11 13 17 19
1 1 1 1 1 1 1 1

Sample Output
9699691

double fmod( double x, double y );
The fmod() function returns the remainder of x/y.
*/
