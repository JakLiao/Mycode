#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int a[31][31];
    int i,j,n;

    for(i=1;i<=30;i++)
        for(j=1;j<=30;j++)
            a[i][j]=0;
    for(i=1;i<=30;i++)
        a[i][i]= a[i][0]=1;
    for(i=3;i<=30;i++)
        for(j=2;j<=30;j++)
            a[i][j]=a[i-1][j]+a[i-1][j-1];
    scanf("%d",&n);
    printf("1\n");
    for(i=3;i<=n+1;i++)
    {
        for(j=2;j<i;j++)
            printf("%d,",a[i][j]);
        printf("%d\n",a[i][j++]);
    }
    return 0;
}
