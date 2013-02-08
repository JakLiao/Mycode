#include<iostream>
using namespace std;
const int MaxVertexes=20;  //最大的顶点数
const int b=10000;
template <class Type> class Graph ;
struct ArcNode{//定义边结点
    friend class Graph <class Type>;
    int adjvex;                     //和边（或弧）相关联的另一个顶点序号
    int weight;                     //边（或弧）上的信息
    ArcNode *nextarc ;              //指向下一条边结点的指针
ArcNode(int v,int w ) : adjvex( v ),weight(w),nextarc( NULL ){ }
};//构造函数
template <class Type>
struct VertexNode{// 定义顶点结点
friend class Graph <class Type>;
    Type data;                      //顶点的信息
    ArcNode *firstarc ;             //指向依附该顶点的边链表
};
template <class Type>class Graph
{
 VertexNode<Type> * VTable;      //顶点表
    int CurrentNumVertexes;         //当前的顶点数
    int CurrentNumArcs;             //当前的边（或弧）数
public:
 int GetVertexPos( const Type &v );// 取顶点v在数组中的位置
    Graph(Type v[],int num=MaxVertexes); //构造函数
    Type GetValue(int v);            //取图中顶点v的值，如果顶点v不存在则返回空
    int Getweight(int v1,int v2);   //取边（或弧）上的权值
    int GetFirstNeighbor(int v);    //取图中顶点v的第一个邻接点的序号。如果不存在返回-1
int GetNextNeighbor(int v1, int v2);  //取图中下一个邻接点
int Arcs[MaxVertexes][MaxVertexes];//用数组记录每个边的信息
    int InVertex(Type &v);          //在图中插入结点
    int InsertArc(int v1, int v2,int w);//在图中插入依附于v1和v2的边或弧，w是信息
    int NumberOfVertexes( ){return CurrentNumVertexes; } //返回当前的顶点数
    int NumberOfArcs(){ return CurrentNumArcs; }  //返回当前的边（或弧）数
 int *dist;                      //最短路径长度数组
    int *InDegree;                  //入度数组，记录每个顶点的入度
    int *path;                      //最短路径的数组
 int *s;                         //最短路径终点数组
void link();                   //输出邻接链表
   void DFS(const int v,int visited[]);//深度优先搜索
   void DFTraverse ();            //深度遍历
   void TopologicalOrder();       //拓扑排序
void ShortestPath(int n,int v);//最短路径
};
///////////////////////////////////////////////////////////////////////////////////
template<class Type>int Graph<Type>::
GetVertexPos(const Type &v ){    //根据顶点v查找该顶点在邻接表中的位置
 for(int i=0;i<CurrentNumVertexes;i++)
  if(VTable[i].data==v)   return i;
  return -1;
}
template<class Type>Graph<Type>::Graph( Type v[] , int num=MaxVertexes) :
CurrentNumVertexes(0), CurrentNumArcs(0)
{
 Type tail, head;
    int i=0,e,h,t,w,p=0;
 while(p<MaxVertexes){
  for(int j=0;j<MaxVertexes;j++){
   Arcs[p][j]=b;
   if(p==j)  {Arcs[p][j]=0;}
  }
  p++;
 }
 InDegree=new int[MaxVertexes];
    VTable=new VertexNode<Type>[MaxVertexes];//创建顶点表
    for(i=0;i<num;i++)             //输入各顶点信息
 {  InVertex(v[i]);            //在顶点表中插入顶点v[i]
  InDegree[i]=0;
 }
 cout<<"输入边的条数:";  cin >> e;//输入边的条数
 cout<<endl;
 for(i=0;i< e;i++){             //逐条输入边
  cout<<"输入第"<<i+1<<"条边:(弧头,弧尾,权值)";
  cin>>tail>>head>>w;        //输入一条边
  int j=GetVertexPos(head);
  while((t=GetVertexPos(tail))==-1)
   cout<<"输入的顶点(tail)不存在";
  while((h = GetVertexPos(head ))==-1)
          cout<<"输入的顶点(head)不存在";
        InsertArc (t,h,w);        //插入一条边
     InDegree[j]++;            //顶点j的入度加1
  cout<<endl;
 }
}
template<class Type>Type Graph<Type>::
GetValue(int v){                 //取图中顶点v的值，如果顶点v不存在，则返回空
 if(v>=0&&v<CurrentNumVertexes) return VTable[v].data;
 return NULL;
}
template<class Type>int Graph<Type>::
Getweight(int v1,int v2)
{//取出以顶点v1和v2为两端点的边上的权值
 if(v1>=0&&v1<CurrentNumVertexes&&v2>=0&&v2<CurrentNumVertexes){
      ArcNode *p=VTable[v1].firstarc;
   while(p!=NULL){
    if(p->adjvex==v2)  {return p->weight;}
    else               {p=p->nextarc;    }
   }
 } return NULL;
}
template<class Type>int Graph<Type>::
GetFirstNeighbor(int v){//查找顶点v的第一个邻接顶点的位置
 if(v>=0&&v<CurrentNumVertexes){
       ArcNode *p=VTable[v].firstarc;
    if(p!=NULL)  return p->adjvex;
    }
 return -1;
}
template<class Type>int Graph<Type>::
GetNextNeighbor(int v1,int v2){//查找顶点v1的在v2之后的下一个邻接顶点，如果不存在返回-1
 if (v1!=-1){
  ArcNode *p=VTable[v1].firstarc;
  while(p!=NULL){
   if(p->adjvex==v2&&p->nextarc!=NULL)
    return p->nextarc->adjvex;//返回下一个邻接顶点在邻接表中的位置
   else p=p->nextarc;
  }
    }
    return -1;//没有查到下一个邻接顶点返回-1
}

template<class Type>int Graph<Type>::
InsertArc(int v1,int v2,int w)
{//在图中插入弧<v1,v2>
  if(v1>=0&&v1<CurrentNumVertexes){
   Arcs[v1][v2]=w;
   ArcNode *newnode =new ArcNode(v2,w);
   ArcNode *h=VTable[v1].firstarc;
   if(h!=NULL){
    ArcNode *p=h;
    while(h!=NULL&&h->adjvex<v2){
     p=h;     h=h->nextarc;
    }
    newnode->nextarc=p->nextarc;
    p->nextarc=newnode;
    return 1;
   }
   VTable[v1].firstarc=newnode;
   return 1;
  }
  return -1;
}
template<class Type>int Graph<Type>::
InVertex(Type &v)
{//在图中插入顶点，插入成功则返回1，否则返回0
  if(CurrentNumVertexes<MaxVertexes-1){//若顶点表未满
   VTable[CurrentNumVertexes].data=v;
   VTable[CurrentNumVertexes].firstarc=NULL;
   CurrentNumVertexes++;           return 1;
  }
  return -1;
}
///////////////////////////////////////////////////////////////////////
//以下是实验要求的函数
//输出邻接表
template<class Type>void Graph<Type>::link(){
 cout<<"输出邻接表:"<<endl;
 for(int i=0;i<CurrentNumVertexes;i++){
  cout<<GetValue(i);
  int a=GetFirstNeighbor(i);
  if(a!=-1) cout<<"->"<<GetValue(a)<<Getweight(i,a);
  for(int j=a;j!=-1;j=a){
   a=GetNextNeighbor(i,j);
  if(a!=-1) cout<<"->"<<GetValue(a)<<Getweight(i,a);
  }
  cout<<endl;
 }
}
//拓扑排序
template<class type>void Graph<type>::
TopologicalOrder()
{
 int m=0;//m为输出的顶点数，初始值为0
 for(int i=0;i<CurrentNumVertexes;i++){
  for(int n=0;n<CurrentNumVertexes;n++){
   if(InDegree[n]==0){
    m++;//输出的顶点数加1
    cout<<VTable[n].data<<endl;
    InDegree[n]=-1;
    for(int t=0;t<CurrentNumVertexes;t++){
     if(n>=0&&n<CurrentNumVertexes){
      if(t>=0&&t<CurrentNumVertexes){
       if(Arcs[n][t]!=0&&Arcs[n][t]!=b)
                      InDegree[t]--;
      }
     }
                 }
    for(int h=0;h<CurrentNumVertexes;h++){
     cout<<InDegree[h]<<"  ";
    }  cout<<endl;        break;
   }
  }
 }
 if(m<CurrentNumVertexes)  cout<<"AOV网络中有回路（有向环）！"<<endl;
}
//深度遍历
template<class Type>
void Graph<Type>::
DFS(const int v,int visited[ ])
{
   cout<< VTable[v].data<<"  ";        //访问顶点 v
    visited[v] =1;                     //顶点v 作访问标记
    int w = GetFirstNeighbor (v);
    while (w != -1) {                  //若顶点 w 存在
        if (!visited[w]) DFS (w,visited);
        w = GetNextNeighbor(v,w);
    }                              //重复检测 v 的所有邻接顶点
}
template<class Type>
void Graph <Type> ::
DFTraverse ()
{
 int i, n = NumberOfVertexes() ;    //取图的顶点个数
    int * visited = new int [n];       //定义访问标记数组 visited
    for ( i = 0; i < n; i++ )
        visited [i] = 0;               //访问标记数组 visited 初始化
    for ( i = 0; i < n; i++ )             //对图中的每一个顶点进行判断
      if (!visited [i])  DFS (i, visited );
    delete[ ]visited;                   //释放 visited
}
//求最短路径
template<class Type>void Graph<Type>::
ShortestPath(int n,int v)
{
 int min,u;
 dist=new int[n];   s=new int[n];   path=new int[n];
 for(int j=0;j<n;j++){
  dist[j]=Arcs[v][j];         s[j]=0;
  if(j!=v&&dist[j]<MaxVertexes) path[j]=v;
  else path[j]=-1;           s[v]=1;
 }
 for(int i=0;i<=n-1;i++){
  min=MaxVertexes;      u=v;
  for(int j=0;j<n;j++)
   if(!s[j]&&dist[j]<min){
    u=j;    min=dist[j];
   }
   s[u]=1;
   for(int w=0;w<n;w++)
     if(!s[w]&&dist[u]+Arcs[u][w]<dist[w])
     {
      dist[w]=dist[u]+Arcs[u][w];
      path[w]=u;
     }
     if(v!=i&&dist[i]!=10000&&v!=path[i])
     cout<<GetValue(v)<<"到顶点"<<GetValue(i)<<"的最短路径是:"<<GetValue(v)<<GetValue(path[i])<<GetValue(i)<<endl;
                    else if(v!=i&&dist[i]!=10000)
                    cout<<GetValue(v)<<"到顶点"<<GetValue(i)<<"的最短路径是:"<<GetValue(path[i])<<GetValue(i)<<endl;
  }
       for(int m=0;m<n;m++)
  cout<<GetValue(v)<<"到顶点"<<GetValue(m)<<"的最短路径长度是:"<<dist[m]<<endl;

}
//主函数
void main(){

 char op;
 do{
  int m,i=0,j=0,w;
     char a[20],c;
  cout<<"请你输入顶点的个数:";   cin>>m;
  for(i=0;i<m;i++){
   cout<<"请输入第"<<j<<"个结点:";
   cin>>a[i]; cout<<endl;  j=j+1;
  }
  Graph<char>G(a,m);
  G.link();
  cout<<"深度遍历:"<<endl;
  G.DFTraverse();
  cout<<endl;
  cout<<"拓扑排序:"<<endl;
  G.TopologicalOrder();
  cout<<endl;
  cout<<"输入最小路径的源头结点:"<<endl;
  cin>>c;
  w=G.GetVertexPos(c);
  G.ShortestPath(m,w);
loop:cout<<"是继续？(Y or N)"<<endl;
  cin>>op;
  if(op=='N'||op=='n')break;
  if(op!='Y'&&op!='y'&&op!='N'&&op!='n')goto loop;
 }while(op=='Y'||op=='y');
}
