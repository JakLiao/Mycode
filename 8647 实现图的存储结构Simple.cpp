#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"string.h"
#include"malloc.h"

int arcs[100][100];
int main()
{
    int i,j;
    int v1,v2;
    int vexnum,arcnum;
    memset(arcs,0,sizeof(arcs));
    scanf("%d%d",&vexnum,&arcnum);
    for(i=1;i<=arcnum;i++)
    {
        scanf("%d%d",&v1,&v2);
        arcs[v1][v2]=1;
    }
    for(i=1;i<=vexnum;i++)
    {
        for(j=1;j<=vexnum;j++)
            printf("%d ",arcs[i][j]);
        printf("\n");
    }
    return 0;
}
