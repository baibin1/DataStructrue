#include <stdio.h>
#include <stdlib.h>
#define Max_Vertrx_Num 20				//最大顶点个数
#define INFINITY 1000					//无此路径显示1000 
#define INF 100 
typedef struct ArcCell{
	int adj;
	char *info;
}ArcCell,AdjMatrix[Max_Vertrx_Num][Max_Vertrx_Num];
typedef struct MGrap{
	int vexs[Max_Vertrx_Num];			//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum,arcnum;					//图当前的顶点数和弧数 
}MGrap;

int path[Max_Vertrx_Num];				//保存从v_0到v_i的最短路径上v_i的前一个顶点
int dist[Max_Vertrx_Num];				//当前已找到的从v_0到每个终点v_i的最短路径 
int set[Max_Vertrx_Num];				//标记数组，等于0没有被并入最短路径，等于1已经被并入最短路径 

int Path[][Max_Vertrx_Num];				//A用来记录当前已经求得的任意两个顶点最短路径的长度 
int A[][Max_Vertrx_Num];				//Path用来记录当前两个顶点间最短路经上要经过的中间顶点 

MGrap CreateDN(MGrap G); 				//采用邻接矩阵的方法构造有向网G
int LocateVex(MGrap G,int v);			//确定元素v在图G中的位置 
void vist(MGrap G);						//遍历图G
//迪杰斯特拉算法求某一顶点到其余各顶点的最短路径 
void Dijkstra(MGrap G,int v,int dist[],int path[]); 
//弗洛伊德算法求任意一对顶点间最短距离 
void Floyd(MGrap G,int Path[][Max_Vertrx_Num],int A[][Max_Vertrx_Num]); 

int main(){
	
	MGrap G;
	G = CreateDN(G);
	vist(G);
	int v = 0;
	Dijkstra(G,v,dist,path);
	printf("\n");
	for(int i = 0; i < G.vexnum; i++)
		printf("%d ",dist[i]);
	printf("\n");
	for(int i = 0; i < G.vexnum; i++)
		printf("%d ",path[i]);
	printf("\n");
	Floyd(G,Path,A);
	int times; 
	for(int i = 0; i < G.vexnum; i++)
		for(int j = 0; j < G.vexnum; j++)
		{
			printf("%d ",A[i][j]);
			times++;
			if(times%G.vexnum == 0)
				printf("\n");
		}
	printf("\n");
	for(int i = 0; i < G.vexnum; i++)
		for(int j = 0; j < G.vexnum; j++)
		{
			printf("%d ",Path[i][j]);
			times++;
			if(times%G.vexnum == 0)
				printf("\n");
		}
			

	
	
	return 0;
}  

MGrap CreateDN(MGrap G){
	//采用邻接矩阵的方法构造有向网G
	printf("请输入图的顶点数：\n"); 
	scanf("%d",&G.vexnum);
	printf("请输入图的弧数：\n");
	scanf("%d",&G.arcnum);
	printf("请输入顶点向量：\n");
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("请输入第%d个顶点向量：\n",i+1);
		scanf("%d",&G.vexs[i]);		//构造顶点向量
	}	
	for(int i = 0;i<G.vexnum;i++)	//初始化邻接矩阵
		for(int j = 0;j<G.vexnum;j++)
			{
				if(i == j)
				{
					G.arcs[i][j].adj = 0;
					G.arcs[i][j].info = NULL;
				}
				else
				{ 
					G.arcs[i][j].adj = INFINITY;
					G.arcs[i][j].info = NULL;
				}
			}
	int v1,v2;
	float w;
	printf("请输入一条边依附的顶点以及权值：\n");	
	for(int k = 0;k<G.arcnum;k++)	//构造邻接矩阵
	{	
		printf("请输入第%d条边的顶点以及权值(注意方向！)：\n",k+1);
		scanf(" %d%d%f",&v1,&v2,&w);	//输入一条边依附的顶点以及权值 
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		G.arcs[x][y].adj = w;
	}
	return G;
}

int LocateVex(MGrap G,int v){
	int i=0;
	while(G.vexs[i]!=v)
		i++;
	return i;
} 

void vist(MGrap G){
	int times = 0;
	printf("******************\n"); 
	for(int i = 0;i<G.vexnum;i++)
		for(int j = 0;j<G.vexnum;j++)
			{
				printf("%d ",G.arcs[i][j].adj);
				times++;
				if(times%G.vexnum == 0)
					printf("\n");
			}
	printf("******************\n");
}

void Dijkstra(MGrap G,int v,int dist[],int path[]){
	int set[Max_Vertrx_Num];
	int min,u;
	//对各数组进行初始化
	for(int i = 0; i < G.vexnum; i++)
	{
		dist[i] = G.arcs[v][i].adj;
		set[i] = 0;
		if(G.arcs[v][i].adj < INF)
			path[i] = v;
		else
			path[i] = -1;
	}  
	set[v] = 1;
	path[v] = -1;
	dist[v] = 0;
	//初始化结束
	for(int i = 0; i<G.vexnum - 1; i++)
	{
		min = INF;	
		for(int j = 0; j < G.vexnum; j++)
			if(set[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		set[u] = 1;
		for( int j =0; j < G.vexnum; j++)
		{
			if(set[j] == 0 && dist[u] + G.arcs[u][j].adj < dist[j])
			{
				dist[j] = dist[u] + G.arcs[u][j].adj;
				path[j] = u;
			}
		}
	} 
	for(int i = 0; i < G.vexnum; i++)
		printf("%d ",set[i]);
} 

void Floyd(MGrap G,int Path[][Max_Vertrx_Num],int A[][Max_Vertrx_Num]){
	//对数组A[][]和Pat[][]进行初始化
		for(int i = 0; i < G.vexnum; i++)
			for(int j = 0; j < G.vexnum; j++)
				{
					A[i][j] = G.arcs[i][j].adj;
					Path[i][j] = -1; 
				} 
	//以k为中间点对所有顶点对(i,j)进行检测和修改 
		for(int k = 0; k < G.vexnum; k++)
			for(int i = 0; i < G.vexnum; i++)
				for(int j = 0; j < G.vexnum; j++)
					if(A[i][j] > A[i][k] + A[k][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						Path[i][j] = k;
					}
}
