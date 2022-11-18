/*
*对一个有向无环图进行拓扑排序
*创建于：2022年11月7日14点49分
*Author：bjb
*最后一次修改于：2022年11月7日 
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
#define MAX_VERTEX_NUM 20

typedef struct ArcNode{
	int adjvex;					//该弧所指向的顶点的位置
	struct ArcNode *nextarc;	//指向下一条弧的指针 
	int info;					//权值 
}ArcNode; 
typedef struct VNode{
	int data;					//顶点信息 
	int count;					//统计当前顶点的入度 
	ArcNode *firstarc;			//指向第一条依附该顶点的弧的指针 
}VNode,AdjList[MAX_VERTEX_NUM]; 
typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;			//图当前的定点数和弧数
}ALGraph;

ALGraph CreateDN(ALGraph G);      //创建有向网DN
int LocateGraph(ALGraph G,int v);//返回值为v的顶点在图G中的位置
void vist(ALGraph G);            //按顶点表顺序打印邻接表图
//拓扑排序
void TopSort(ALGraph G); 

int main(){

    ALGraph G;
    G = CreateDN(G);
    vist(G);
    TopSort(G);

    return 0;
}

ALGraph CreateDN(ALGraph G){

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
		G.vertices[i].count = 0;				//初始化count值 
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
		G.vertices[y].count++;
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
	}

    return G;
}

void vist(ALGraph G){
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertices[i].firstarc==NULL)
		{	
				printf("值为%d的顶点并不指向任何顶点~,入度为：%d\n",G.vertices[i].data,G.vertices[i].count);
				continue;
		} 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p = G.vertices[i].firstarc; 
		while(p!=NULL)
		{
			printf("%d【值为：%d】 ",p->adjvex,G.vertices[p->adjvex].data);
			p = p->nextarc;

		}
		printf("第%d个顶点遍历结束~，入度为：%d\n",i+1,G.vertices[i].count);
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

void TopSort(ALGraph G){
	int stack[MAX_VERTEX_NUM],top = -1;			//设置一个栈，用来记录入度为0的顶点
	int n = 0;									//设置一个计数器，用来记录已经输出的顶点数
	ArcNode *p;
	//将入度为0的顶点入栈 
	for(int i = 0; i < G.vexnum ; i++)
		if(G.vertices[i].count == 0)
			stack[++top] = i;
	int x,j;
	while(top!=-1)
	{
		x = stack[top--];
		++n;
		printf("%d ",G.vertices[x].data);
		p = G.vertices[x].firstarc;
		
		//将由此顶点引出的所有边所指向的顶点的入度都减少一，并将之后入度变为0的顶点入栈
		while(p!=NULL)
		{
			j = p->adjvex;
			G.vertices[j].count = G.vertices[j].count - 1;
			if(G.vertices[j].count == 0)
				{
//				printf("%d ",j);
				stack[++top] = j;
				}
			p = p->nextarc;
		} 
	}
	printf("\n");
	if( n == G.vexnum)
		printf("已输出全部顶点！\n") ;
	else
		printf("没有输出全部顶点！\n");
}

