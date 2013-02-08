#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

double distan(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    int n,i,j;
    double x[50],y[50];
    double min,tmp;
    scanf("%d",&n);
    scanf("%lf%lf",&x[0],&y[0]);
    scanf("%lf%lf",&x[1],&y[1]);
    min=distan(x[0],y[0],x[1],y[1]);
    for(i=2;i<n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
        for(j=0;j<i;j++)
        {
            tmp=distan(x[i],y[i],x[j],y[j]);
            if(tmp<min)
                min=tmp;
        }
    }
    printf("%.3f",min);
    return 0;
}
