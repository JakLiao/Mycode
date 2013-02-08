#include"stdio.h"
#define MAX 100


main()
{
    int k,i,j,m,n;
    int G[MAX][MAX];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        G[i][j]=0;
    for(k=0;k<m;k++)
    {
        scanf("%d%d",&i,&j);
            G[i-1][j-1]=1;
    }
    for(i=0;i<n;i++){
    for(j=0;j<n;j++)
        printf("%d ",G[i][j]);
    printf("\n");
    }
    return 0;
}
