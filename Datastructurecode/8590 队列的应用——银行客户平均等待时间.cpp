#include"stdio.h"
main()
{
    int ti,tn,tf=0,i,n;
    double s=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&ti);
        scanf("%d",&tn);
        if(ti<tf)
        {
            s+=tf-ti;
            tf=tf+tn;
        }
        else
            tf=ti+tn;
    }

    printf("%.2f",s/n);
}
