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
    }
}
int main()
{
    int a[10];
    int i;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    SelectSort(a,10);
    printf("%d\n%d\n%d",a[9],a[8],a[7]);
    return 0;
}
