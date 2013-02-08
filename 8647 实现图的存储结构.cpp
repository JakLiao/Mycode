#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"malloc.h"

#define INFINITY 32768
#define MAX_VERTEX_NUM 20
#define OK 1
#define ERROR -1
#define FALSE 0
#define TRUE 1

typedef int VertexData;
typedef int AdjType;
typedef int OtherInfo;
typedef struct ArcNode{
	AdjType adj;
	OtherInfo info;
}ArcNode;
typedef struct{
	VertexData vexs[MAX_VERTEX_NUM];
	ArcNode arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vexnum,arcnum;
}AdjMatrix;

int LocateVertex(AdjMatrix *G,VertexData v)
{
	int j=ERROR,k;
	for(k=0;k<G->vexnum;k++)
		if(G->vexs[k]==v)
		{
			j=k;
			break;
		}
    return(j);
}

int CreteUDG(AdjMatrix *G)
{
	int i,j,weight;
	int k;
	VertexData v1,v2;
	scanf("%d%d",&G->vexnum,&G->arcnum);
	for(i=0;i<G->arcnum;i++)
		for(j=0;j<G->arcnum;j++)
			G->arcs[i][j].adj=INFINITY;
    for(i=0;i<G->arcnum;i++)
        scanf("%d",&G->vexs[i]);
    for(k=0;k<G->vexnum;k++)
    {
        scanf("%d%d%d",&v1,&v2,&weight);
        i=LocateVertex(G,v1);
        j=LocateVertex(G,v2);
        G->arcs[i][j].adj=weight;
    }
    return(OK);
}
int PrintUDG(AdjMatrix *G)
{

}

int main()
{
    AdjMatrix G;
	CreteUDG(&G);
	PrintUDG(&G);
    return 0;
}
