#include"stdio.h"
#include"stdlib.h"
#include"math.h"

double f(double x)
{
    double y;
    if (x==0.0)y=1;
        else y=sin(x)/x;
    return (y);
}

int main()
{

    //double f(double x);
    int i,n=300000,k;
    double a,b,h,T,Tn;
    scanf("%d",&k);
    while(k>0)
    {
        scanf("%lf %lf",&a,&b);
        h=(b-a)/n;
        T=(f(a)+f(b))/2;
        for(i=1;i<n;i++)
        T=T+f(a+i*h);
        Tn=T*h;
        printf("%.4f\n",Tn);
        k--;
    }
    return 0;
}
