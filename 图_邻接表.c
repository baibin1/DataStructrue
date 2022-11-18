/*----------图的邻接表存储表示----------  
*创建于：2022年11月2日16点57分
*Author：bjb
*最后一次修改于： 2022年11月3日15点32分 
*/ 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

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

ALGraph CreateAlGraph(ALGraph G);	//用邻接表创建图G
ALGraph CreateDG(ALGraph G); 		//创建有向图G 
ALGraph CreateUDG(ALGraph G);		//创建无向图G 
ALGraph Error();					//错误返回 
void vist(ALGraph G);				//打印图 
int LocateGraph(ALGraph G,int v);	//获取v在图中的位置 


int main(){

	ALGraph G;
	G = CreateAlGraph(G);
	vist(G);
	 

	return 0;
}

ALGraph CreateAlGraph(ALGraph G){
	printf("请输入你要创建的图的类型：\n1.有向图DG\n2.无向图UDG\n");
	scanf("%d",&G.kind);
	switch(G.kind){
		case 1:return CreateDG(G);
		case 2:return CreateUDG(G);
		default:return Error();
	} 
}

ALGraph CreateDG(ALGraph G){
	//采用邻接表构造有向图G 
	//按弧输入 
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
		printf("请输入第%d条边的始顶点和尾顶点的值(注意顺序)：\n",i+1);
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		int x,y;
		x = LocateGraph(G,v1);
		y = LocateGraph(G,v2); 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
	}
	
//按一个顶点指向的另一个顶点的值输入 
 
//	for(int j = 0;j<G.vexnum;j++)
//	{	
//		G.vertices[j].firstarc = NULL;
//		int k = 1;
//		while(true)
//		{
//			int v;
//			printf("请输入值为%d的顶点指向的第%d个顶点的值：\n",G.vertices[j].data,k);
//			scanf(" %d",&v);
//			if(v == 0) break;
//			int z=0;
//			for(int n = 0;n<G.vexnum;n++)
//			{
//				if(G.vertices[n].data == v)
//					break;
//				z++;
//			}
//			printf("值%d对应的顶点为第%d个顶点\n",v,z+1);
//			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
//			p->adjvex = z;  
//			p->nextarc = G.vertices[j].firstarc;
//			G.vertices[j].firstarc = p;
//			k++;
//		}
//	}
	return G;
}

ALGraph CreateUDG(ALGraph G){
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
//	for(int j = 0;j<G.vexnum;j++)
//	{	
//		G.vertices[j].firstarc = NULL;
//		int k = 1;
//		while(true)
//		{
//			int v;
//			printf("请输入值为%d的顶点相连的第%d个顶点的值：\n",G.vertices[j].data,k);
//			scanf(" %d",&v);
//			if(v == 0) break;
//			int z=0;
//			for(int n = 0;n<G.vexnum;n++)
//			{
//				if(G.vertices[n].data == v)
//					break;
//				z++;
//			}
//			printf("值%d对应的顶点为第%d个顶点\n",v,z+1);
//			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
//			p->adjvex = z;  
//			p->nextarc = G.vertices[j].firstarc;
//			G.vertices[j].firstarc = p;
//			k++;
//		}
//	}
	return G;
}

ALGraph Error(){
	ALGraph G;
	printf("输入错误！\n");
	return G;
} 

void vist(ALGraph G){
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

int LocateGraph(ALGraph G,int v){
	int res;
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
