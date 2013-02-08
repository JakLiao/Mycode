#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int main()
{
    int i,j,k,n,N,m;
    scanf("%d",&m);
    N=m/2+1;
    for(n=1;n<=N-1;n++)
        printf("*");
    printf(" ");
    printf("\n");

    for(i=0;i<=N-2;i++){
        for(j=0;j<=N-3-i;j++)
            printf("*");
        printf("*");
        for(k=0;k<=2*i;k++)
            printf("*");
        printf(" ");
        printf("\n");
    }

    for(i=0;i<=N-3;i++){
        for(j=0;j<=i;j++)
            printf("*");
        printf(" ");
        for(k=0;k<=2*N-6-2*i;k++)
            printf(" ");
        printf("*");
        printf("\n");
    }

    for(n=1;n<=N-1;n++)
        printf("*");
    printf(" ");
    return 0;
}
