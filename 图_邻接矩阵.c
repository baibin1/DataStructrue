//----------图的邻接矩阵表示方法------------ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_Vertrx_Num 20				//最大顶点个数
#define INFINITY 0						//无此路径显示0 
typedef enum {DG,DN,UDG,UDN} GraphKind;	//{有向图，有向网，无向图，无向网}
typedef struct ArcCell{
	int adj;
	char *info;
}ArcCell,AdjMatrix[Max_Vertrx_Num][Max_Vertrx_Num];
typedef struct MGrap{
	int vexs[Max_Vertrx_Num];			//顶点向量
	AdjMatrix arcs;						//邻接矩阵
	int vexnum,arcnum;					//图当前的顶点数和弧数 
	int kind;							//图的种类
}MGrap; 

MGrap CreateGraph(MGrap G);				//采用邻接矩阵的方法构造图G
MGrap CreateDG(MGrap G); 				//采用邻接矩阵的方法构造有向图G
MGrap CreateDN(MGrap G); 				//采用邻接矩阵的方法构造有向网G
MGrap CreateUDG(MGrap G); 				//采用邻接矩阵的方法构造无向图G
MGrap CreateUDN(MGrap G); 				//采用邻接矩阵的方法构造无向网G
MGrap GG();								//错误输入
int LocateVex(MGrap G,int v);			//确定元素v在图G中的位置 
void vist(MGrap G);						//遍历图G

int main(){
	MGrap G;
	G = CreateGraph(G);					//创建图 G
	vist(G);							//遍历图 G 
	return 0;
} 

MGrap CreateGraph(MGrap G){
	//采用数组（邻接矩阵）表示法，构造图G
	printf("请输入你要构造的图的类型：\n1：有向图DG\n2：有向网DN\n3：无向图UDG\n4：无向网UDN\n");
	scanf("%d",&G.kind);
	switch(G.kind){
		case 1: return CreateDG(G);			//构造有向图
		case 2: return CreateDN(G);			//构造有向网
		case 3: return CreateUDG(G);		//构造无向图
		case 4: return CreateUDN(G);		//构造无向网
		default : return GG();
	}
}

MGrap CreateDG(MGrap G){
	//采用邻接矩阵的方法构造有向图G
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
	printf("请输入一条边依附的顶点：\n");	
	for(int k = 0;k<G.arcnum;k++)	//构造邻接矩阵
	{	
		printf("请输入第%d条边的顶点(注意方向！)：\n",k+1);
		scanf(" %d%d",&v1,&v2);	//输入一条边依附的顶点
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		G.arcs[x][y].adj = 1;
	}
	return G;
}
 
MGrap CreateUDG(MGrap G){
	//采用邻接矩阵的方法构造无向图G
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
	printf("请输入一条边依附的顶点：\n");	
	for(int k = 0;k<G.arcnum;k++)	//构造邻接矩阵
	{	
		printf("请输入第%d条边的顶点：\n",k+1);
		scanf(" %d%d",&v1,&v2);	//输入一条边依附的顶点
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		G.arcs[x][y].adj = 1;
		G.arcs[y][x] = G.arcs[x][y];
	}
	return G;
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
		G.arcs[x][y].adj = w;
		G.arcs[y][x] = G.arcs[x][y];
	}
	return G;
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

MGrap GG(){
	MGrap G;
	printf("请正确输入！\n");
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
