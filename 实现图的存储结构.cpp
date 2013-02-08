#define MAX_VERTEX_NUM 10
#define INFINITY 32768
#define OK 1
#define ERROR -1
#define FALSE 0
#define TRUE 1
#include <iostream>
#include <malloc.h>
using namespace std;
typedef enum{DG,DN,UDG,UDN}GraphKind;
typedef char VertexData;
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
	GraphKind kind;
}AdjMatrix;
int visited[MAX_VERTEX_NUM];
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
/**************************************************************************************/
#define QueueElementType int
typedef struct Node
{
	QueueElementType data;
	struct Node *next;
}LinkQueueNode;
typedef struct
{
	LinkQueueNode *front;
	LinkQueueNode *rear;
	LinkQueueNode *p;
}LinkQueue;

int InitQueue(LinkQueue *Q)
{
	Q->front=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(Q->front!=NULL)
	{
		Q->rear=Q->front;
		Q->front->next=NULL;
		return(TRUE);
	}
	else
		return(FALSE);
}
int Empty(LinkQueue *Q)
{
	return(Q->front==Q->rear==NULL?TRUE:FALSE);
}
int EnterQueue(LinkQueue *Q,QueueElementType x)
{
	LinkQueueNode *NewNode;
	NewNode=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	if(NewNode!=NULL)
	{
		NewNode->data=x;
		NewNode->next=NULL;
		Q->rear->next=NewNode;
		Q->rear=NewNode;
		return(TRUE);
	}
	else
		return(FALSE);
}
int DeleteQueue(LinkQueue*Q,QueueElementType *x)
{
	LinkQueueNode *p;
	if(Q->front==Q->rear)
		return(FALSE);
	p=Q->front->next;
	Q->front->next=p->next;
	if(Q->rear==p)
		Q->rear=Q->front;
	*x=p->data;
	free(p);
	return(TRUE);
}
int CreteUDG(AdjMatrix *G)
{
	int i,j,weight;
	int k;
	VertexData v1,v2;
	cout<<"请输出顶点和弧度数："<<endl;
	cin>>G->arcnum;
	cin>>G->vexnum;
	cout<<"请输出顶点数据："<<endl;
	for(i=0;i<G->arcnum;i++)
		for(j=0;j<G->arcnum;j++)
			G->arcs[i][j].adj=INFINITY;
		for(i=0;i<G->arcnum;i++)
		{	cin>>G->vexs[i];}

		cout<<"请输入顶点间关系："<<endl;
		for(k=0;k<G->vexnum;k++)
		{
			cin>>v1>>v2>>weight;
			i=LocateVertex(&(*G),v1);
			j=LocateVertex(G,v2);
			G->arcs[i][j].adj=weight;
		}
		return(OK);
}
void DepthFirstSearch(AdjMatrix *g,int v0)
{
	cout<<g->vexs[v0];
	visited[v0]=TRUE;
	for(int vj=0;vj<g->vexnum;vj++)
		if(!visited[vj]&&g->arcs[v0][vj].adj==1)
			DepthFirstSearch(g,vj);

}
int FirstAdj(AdjMatrix *g,int v)
{
	int l;
	int i;
	for(i=0;i<g->arcnum;i++)
	{
		if(g->arcs[v][i].adj==1)
		{
			l=i;
			break;
		}

	}
	return(l);

}
int NextAdj(AdjMatrix *g,int v,int *m)
{

	int k;
	int i,j=1;
	for(i=0;i<g->arcnum;i++)
	{
		if(g->arcs[v][i].adj==1)
		{
			j++;
			if(j==2)
				k=i;
		}
	}
	if(j==1)
		k=-1;
	return(k);

}
void BreadthFirstSearch(AdjMatrix *g,int v0)
{
	LinkQueue *Q;
	int w,v,m=1;
	Q=(LinkQueue*)malloc(sizeof(LinkQueue));
	cout<<g->vexs[v0];
	visited[v0]=TRUE;
	InitQueue(Q);
	EnterQueue(Q,v0);
	while(!Empty(Q))
	{
		DeleteQueue(Q,&v);
		w=FirstAdj(g,v);
		while(w!=-1)
		{
			if(!visited[w])
			{
				cout<<g->vexs[w];
				visited[w]=TRUE;
				EnterQueue(Q,w);
			}
			w=NextAdj(g,v,&m);
		}
	}
}
void TraverseGraph(AdjMatrix *g)
{
	int vi;
	cout<<"深度遍历：";
	for( vi=0;vi<g->arcnum;vi++)visited[vi]=FALSE;
	for( vi=0;vi<g->arcnum;vi++)
		if(!visited[vi])DepthFirstSearch(g,vi);

		cout<<endl;
		cout<<"广度遍历:";
		for( vi=0;vi<g->arcnum;vi++)visited[vi]=FALSE;
		for( vi=0;vi<g->arcnum;vi++)
			if(!visited[vi])BreadthFirstSearch(g,vi);


}

int main()
{
	AdjMatrix G;

	CreteUDG(&G);
	TraverseGraph(&G);
	cout<<endl;
    return 0;
}
/*void TraverseGraph(AdjMatrix *g)
{
	int vi;
    //深度遍历
	for( vi=0;vi<g->arcnum;vi++)visited[vi]=FALSE;
	for( vi=0;vi<g->arcnum;vi++)
		if(!visited[vi])DepthFirstSearch(g,vi);

		printf("\n");
		//广度遍历
		for( vi=0;vi<g->arcnum;vi++)visited[vi]=FALSE;
		for( vi=0;vi<g->arcnum;vi++)
			if(!visited[vi])BreadthFirstSearch(g,vi);


}*/
