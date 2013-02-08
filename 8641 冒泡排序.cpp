#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

void BubbleSort(int r[],int n){
    int i,j,tmp,k,m;
    int o=0;
    for(i=n;i>1;--i)
    {
        for(m=0,j=1;j<i;++j,++m)
        {
            if(r[m]>r[j])
            {
                o=1;
                tmp = r[m];
                r[m]=r[j];
                r[j]=tmp;
            }
        }
        if(o)
        {
            for(k=0;k<n-1;k++)
                printf("%d ",r[k]);
            printf("%d\n",r[n-1]);
        }
        o=0;
    }
    for(k=0;k<n-1;k++)
        printf("%d ",r[k]);
    printf("%d\n",r[n-1]);
}

int main()
{
    int r[100];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    BubbleSort(r,n);
    /*for(i=0;i<n-1;i++)
        printf("%d ",r[i]);
    printf("%d\n",r[n-1]);*/
    return 0;
}
