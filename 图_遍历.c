/*
*----------图的遍历，广度优先搜索BFS，深度优先搜索DFS
*创建于：2022年11月3日15点53分
*Author：bjb
*最后一次修改于： 2022年11月6日00:41:41
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 20
//借助辅助队列实现逐层访问 
typedef int QEleType; 
typedef struct QNode{
	QEleType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;			//队头指针		 
	QueuePtr rear;			//队尾指针 
}LQueue,*LinkQueue; 
//图的邻接表存储结构定义
typedef struct ArcNode{
	int adjvex;					//该弧所指向的顶点的位置
	struct ArcNode *nextarc;	//指向下一条弧的指针 
	char *info;					//该弧的相关信息 
}ArcNode; 
typedef struct VNode{
	int data;					//顶点信息 
	ArcNode *firstarc;			//指向第一条依附该顶点的弧的指针 
}VNode,AdjList[MAX_VERTEX_NUM]; 
typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;			//图当前的定点数和弧数
	int kind;					//图的种类标志 
}ALGraph; 

ALGraph CreateGraphUDG(ALGraph G);		//创建邻接表存储结构无向图 UDG 
int LocateGraph(ALGraph G,int v);		//获取某元素在图G中的位置
void vistGraph(ALGraph G);				//打印图G
LinkQueue InitQueue();					//初始化队列 
bool isEmptyQueue(LinkQueue Q);			//判断队列是否为空 
void enQueue(LinkQueue Q,int v);		//入队
int deQueue(LinkQueue Q);				//出队 
bool visited[MAX_VERTEX_NUM];			//访问标记数组
void BFSTraverse(ALGraph G);			//对图G进行广度优先搜索
void BFS(LinkQueue Q, ALGraph G,int v);	//从顶点点v出发，广度优先遍历图G
void BFS_MIN_Distance(ALGraph G,int u);	//广度优先求最短路径
void DFSTraverse(ALGraph G);			//对图G进行深度优先搜索
void DFS( ALGraph G,int v);				//从顶点v出发，深度优先遍历图G
int FirstNeighbor(ALGraph G,int v);		//返回v的第一个邻接顶点
int NextNeighbor(ALGraph G,int v,int w);//返回v的下一个邻接顶点

int main(){

	ALGraph G;
	G = CreateGraphUDG(G);
	vistGraph(G);
	BFSTraverse(G);
	printf("\n");
	DFSTraverse(G);
	printf("\n");
	int u = 0;
	BFS_MIN_Distance(G,u);
	// for(int i = 0; i < G.vexnum ; i++)
	// {
	// 	if(visited[i] == true)
	// 		printf("1");
	// 	else
	// 		printf("0");
	// }
	return 0;
} 

ALGraph CreateGraphUDG(ALGraph G){
	//采用邻接表构造无向向图G 
	printf("请输入顶点的个数：\n");
	scanf("%d",&G.vexnum);
	printf("请输入弧的数量：\n");
	scanf("%d",&G.arcnum);
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("请输入第%d个顶点的值：\n",i+1);
		scanf(" %d",&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;			//初始化指针 
	}
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("第%d个顶点的值为：%d\n",i+1,G.vertices[i].data);
	}
	for(int i = 0;i<G.arcnum;i++)
	{
		printf("请输入第%d条边的两个顶点的值：\n",i+1);
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		int x,y;
		x = LocateGraph(G,v1);
		y = LocateGraph(G,v2); 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
		ArcNode *s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = x;
		s->nextarc = G.vertices[y].firstarc;
		G.vertices[y].firstarc = s; 
	}
	return G;
}

int LocateGraph(ALGraph G,int v){
	int res;
	if(v == 0)
		return -1;
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertices[i].data == v)
		{
			res = i;
			break;
		}	
	}	
	return res;
}

void vistGraph(ALGraph G){
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertices[i].firstarc==NULL)
		{	
				printf("值为%d的顶点并不指向任何顶点~\n",G.vertices[i].data);
				continue;
		} 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p = G.vertices[i].firstarc; 
		while(p!=NULL)
		{
			printf("%d【值为：%d】 ",p->adjvex,G.vertices[p->adjvex].data);
			p = p->nextarc;

		}
		printf("第%d个顶点遍历结束~\n",i+1);
	}
} 

LinkQueue InitQueue(){
	LinkQueue Q = (LinkQueue)malloc(sizeof(LQueue));
	Q->front = Q->rear = NULL;
}

bool isEmptyQueue(LinkQueue Q){
	if(Q->front == NULL || Q->rear == NULL)
	{
		// printf("Empty!\n");
		return true;
	}
	else
	{
		// printf("Not Empty!\n");
		return false;
	}
} 

void enQueue(LinkQueue Q,int v){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = v;
	p->next = NULL;
	if(Q->rear == NULL)
		Q->front = Q->rear = p;
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	} 
} 

int deQueue(LinkQueue Q){
	QueuePtr p;
	if(Q->rear == NULL)
	{
		printf("队空！\n");
		return 0;
	}
	else
		p = Q->front;
	if(Q->front == Q->rear)
	{
		int x;
		x = Q->front->data;
		Q->front = Q->rear = NULL;
		// printf("出队元素为：%d\n",x);
		return x;

	}
	else
	{
		Q->front = Q->front->next;
		int x;
		x = p->data;
		free(p);
		// printf("出队元素为：%d\n",x);
		return x;
	}
} 

void BFSTraverse(ALGraph G){
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
		// printf("访问标记数组初始化完成！\n");
	}
	LinkQueue Q;
	Q = InitQueue(Q);
	for (int i = 0; i < G.vexnum; i++)
		if (! visited[i])
		{
			// printf("BFS函数执行！\n");
			BFS(Q,G,i);						//i为顶点对应下标
		}
}

void BFS(LinkQueue Q, ALGraph G,int v){		//v为顶点对应下标
	
	printf("%d ",G.vertices[v].data);
	visited[v] = true;						//v为顶点对应下标
	enQueue(Q,v);							//v为顶点对应下标
	while (! isEmptyQueue(Q))
	{
		v = deQueue(Q);						//v为顶点对应下标
		for (int w = FirstNeighbor(G,v) ; w >= 0 ; w = NextNeighbor(G,v,w) )
		{
			if(! visited[w])
			{
				printf("%d ",G.vertices[w].data);
				visited[w] = true;
				enQueue(Q,w);
			}
		}
	}
}

void BFS_MIN_Distance(ALGraph G, int u){
	LinkQueue Q;
	Q = InitQueue();
	int d[MAX_VERTEX_NUM];
	for( int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
		d[i] = -1;
	}
	visited[u] = true;
	d[u] = 0;
	enQueue(Q,u);
	while (! isEmptyQueue(Q))
	{
		u = deQueue(Q);
		for (int w = FirstNeighbor(G,u); w >= 0; w = NextNeighbor(G,u,w))
			if(! visited[w])
			{
				visited[w] = true;
				d[w] = d[u] + 1;
				enQueue(Q,w);
			}
	}
	for (int i = 0; i < G.vexnum; i++)
		printf("%d ",d[i]);
}

void DFSTraverse(ALGraph G){
	for( int i = 0; i < G.vexnum ; i++)
		visited[i] = false;
	for( int v = 0; v < G.vexnum ; v++)
		if(! visited[v])
			DFS(G,v);
}

void DFS( ALGraph G,int v){
	printf("%d ",G.vertices[v].data);
	visited[v] = true;
	for (int w = FirstNeighbor(G,v) ; w >= 0 ; w = NextNeighbor(G,v,w) )
		if(! visited[w])
		{
			DFS(G,w);
		}		
}

int FirstNeighbor(ALGraph G,int v){
	int res;
	ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
	p = G.vertices[v].firstarc;
	if(p == NULL)
		return -1;
	else
		res = p->adjvex;
	return res;
}

int NextNeighbor(ALGraph G,int v,int w){
	int res;
	ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
	p = G.vertices[v].firstarc;
	while(p->adjvex != w)
		p = p->nextarc;
	p = p->nextarc;
	if(p == NULL)
		return -1;
	else
		res = p->adjvex;
	return res;				
}