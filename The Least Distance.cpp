#include"stdio.h"
#include"math.h"

int main()
{
    double distance,a,b;
    scanf("%lf %lf",&a,&b);
    while(a!=0&&b!=0)
    {
        distance=3*sqrt(a*a/9+b*b);
        printf("%.1f\n",distance);
        scanf("%lf %lf",&a,&b);
    }
    return 0;
}
