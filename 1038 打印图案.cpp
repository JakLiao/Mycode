#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main ()
{
    int n,i,j;
    scanf("%d",&n);
    n--;
    for(i=-n;i<=n;i++)
    {   for(j=0;j<abs(i);j++) printf(" ");
        for(j=-(n-abs(i));j<=n-abs(i);j++) printf("%d",n+1-abs(j)-abs(i));
        printf("\n");
    }
    return 0;
}
