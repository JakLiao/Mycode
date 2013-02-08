#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

void SelectSort(int r[],int n){
    int i,j=1,tmp,k;
    int min=0,p;
    for(i=0;i<n-1;++i)
    {
        p=i;
        min=r[i];
        for(j=i+1;j<n;++j)
            if(min>r[j])
            {
                min=r[j];
                p=j;
            }
        tmp = r[i];
        r[i]= r[p];
        r[p]= tmp;
        for(k=0;k<n-1;k++)
            printf("%d ",r[k]);
        printf("%d\n",r[n-1]);
    }
}

int main()
{
    int r[100];
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&r[i]);
    }
    SelectSort(r,n);
    /*for(i=0;i<n-1;i++)
        printf("%d ",r[i]);
    printf("%d\n",r[n-1]);*/
    return 0;
}
