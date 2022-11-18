/*
*最小代价生成树的普里姆（prim）算法和克鲁斯卡尔（kruskal）算法 
*创建时间：2022年11月6日15点22分
*Author：bjb
*最后修改时间：2022年11月6日19点41分 
*/
#include <stdio.h>
#include <stdlib.h> 
#define INF 100
#define Max_Vertrx_Num 20				//最大顶点个数
#define INFINITY 1000					//无此路径显示1000 
typedef struct ArcCell{
	int adj;
	char *info;
}ArcCell,AdjMatrix[Max_Vertrx_Num][Max_Vertrx_Num];
typedef struct MGrap{
	int vexs[Max_Vertrx_Num];			//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum,arcnum;					//图当前的顶点数和弧数 
}MGrap; 
typedef struct {
	int a,b;							//a,b为一条边的两个顶点 
	int w;								//边的权值 
}Road;

MGrap CreateUDN(MGrap G); 				//采用邻接矩阵的方法构造无向网G
int LocateVex(MGrap G,int v);			//确定元素v在图G中的位置 
void vist(MGrap G);						//遍历图G
void Prim(MGrap G,int v0);				//Prim算法构造最小生成树 
Road road[Max_Vertrx_Num];
void insert(Road road[],int N);
int v[Max_Vertrx_Num];					//定义并查集数组
int getRoot(int a);						//并查集中找根结点 
void sort(Road road[], int E);			//对road数组中的E条边按其权值大小排序 
void Kruskal(MGrap G,Road road[]);		//Kruskal算法构造最小生成树 

int main(){
	Road road[Max_Vertrx_Num];
	MGrap G;
	G = CreateUDN(G);
	vist(G);
	int v0 = 0; 
	Prim(G,v0);
	printf("\n");
	int E = G.arcnum;
	insert(road,E);
	sort(road,E);
	printf("\n");
//	int a,b;
//	for(int i = 0; i < E; i++)
//		v[i] = i;
//	a = getRoot(road[0].w);
//	b = getRoot(road[1].w);
//	printf("\n%d %d ",a,b);
//	sort(road,E);
	Kruskal(G,road);
	
	
	return 0;
} 

MGrap CreateUDN(MGrap G){
	//采用邻接矩阵的方法构造无向网G
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
				G.arcs[i][j].adj = INFINITY;
				G.arcs[i][j].info = NULL;
			}
	int v1,v2;
	float w;
	printf("请输入一条边依附的顶点以及权值：\n");	
	for(int k = 0;k<G.arcnum;k++)	//构造邻接矩阵
	{	
		printf("请输入第%d条边的顶点以及权值：\n",k+1);
		scanf(" %d%d%f",&v1,&v2,&w);	//输入一条边依附的顶点以及权值 
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
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

void Prim(MGrap G,int v0){
	int lowcost[Max_Vertrx_Num],vset[Max_Vertrx_Num], v;
	int i,j,k,min,sum;
	v = v0;
	for( i = 0; i < G.vexnum ; i++)
	{
		lowcost[i] = G.arcs[v0][i].adj;
		vset[i] = 0;
	}
	vset[v0] = 1;
	sum = 0;
	for( i = 0; i < G.vexnum -1 ; i++)
	{
		min = INF;
		for( j = 0; j < G.vexnum ; j++)
			if( vset[j] == 0 && lowcost[j] < min )
				{
					min = lowcost[j];
					k = j;
				}
		vset[k] = 1;
		v = k;
		sum = sum + min;
		printf("%d ",sum);
		for( j = 0; j < G.vexnum ; j++)
			if(vset[j] == 0 && G.arcs[v][j].adj < lowcost[j] )
				lowcost[j] = G.arcs[v][j].adj; 
	}
} 

int getRoot( int a){
	while(a!=v[a])
		a = v[a];
	return a;
} 

void Kruskal(MGrap G,Road road[]){
	int i,j;
	int N,E,a,b,sum;
	N = G.vexnum;
	E = G.arcnum;
	sum = 0;
	for(i = 0; i < N; i++)
		v[i] = i;
	sort(road,E);
	for( j = 0; j < N; j++)
	{
		a = getRoot(road[j].a);
		b = getRoot(road[j].b);
		if(a!=b)
		{
			v[a] = b;
			sum = sum + road[j].w;
			printf("%d ",sum);
		} 
	}
}

void sort(Road road[],int E){
	int t;
	for(int i = 0; i < E-1 ; i++)
		for(int j = 0; j < E -1 - i ; j++)
			if(road[j].w > road[j+1].w)
				{
					t = road[j].w;
					road[j].w = road[j+1].w;
					road[j+1].w = t;
				}
				printf("排序结果为：");
				for(int i = 0; i < E; i++)
					printf("%d ",road[i].w);
				printf("\n");
} 

void insert(Road road[],int N){
	int v1,v2;
	float w;
	printf("请输入一条边依附的顶点以及权值：\n");	
	for(int k = 0;k<N;k++)
	{	
		printf("请输入第%d条边的顶点以及权值：\n",k+1);
		scanf(" %d%d%f",&v1,&v2,&w);	//输入一条边依附的顶点以及权值 
//		int x = LocateVex(G,v1);
//		int y = LocateVex(G,v2);
		road[k].a = v1;
		road[k].b = v2;
		road[k].w = w;
		printf("%d \n",road[k].w);
	}
}
