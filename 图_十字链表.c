/*
*--------有向图的十字链表存储表示----------
*十字链表是有向图的另一种链式存储结构
*可以看成是将有向图的邻接表和逆邻接表结合起来得到的一种结构
*创建于2022年11月2日17点05分
*Author：bjb 
*/ 
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MAX_VERTEX_NUM 20 
typedef struct ArcBox{
	int tailvex,headvex;				//该弧的尾和头顶点的位置
	struct ArcBox *hlink,*tlink;		//为别为弧头相同和弧尾相同的弧的链域 
	char *info;							//该弧相关信息的指针 
}ArcBox;
typedef struct VexNode{
	int data;
	ArcBox *firstin,*firstout;			//分别指向该顶点第一条入弧和出弧 
}VexNode;
typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];		//表头向量
	int vexnum,arcnum;					//有向图的当前顶点数和弧数 
}OLGraph; 

OLGraph CreateDG(OLGraph G);			//用十字链表存储表示，构造有向图G 
int LocateVex(OLGraph G,int v);			//确定v在G中的位置 

int main(){
	
	OLGraph G;
	G = CreateDG(G); 
	
	return 0;
}

OLGraph CreateDG(OLGraph G) {
	printf("请输入图的顶点数：\n");
	scanf("%d",&G.vexnum);
	printf("请输入图的弧数：\n");
	scanf("%d",&G.arcnum);
	for(int i = 0;i<G.vexnum;i++){
		printf("请输入第%d个表头向量的值：\n",i+1);
		scanf("%d",&G.xlist[i].data);	//构造表头向量
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;		//初始化指针 
	}
	for(int k = 0;k<G.arcnum;k++){		//输入各弧并构造十字链表 
		int v1,v2;
		printf("输入第%d条弧的始点和终点：\n",k+1);
		scanf("%d%d",&v1,&v2);			//输入一条弧的始点和终点
		int x,y;
		x = LocateVex(G,v1);
		y = LocateVex(G,v2);			//确定v1，v2在图G中的位置
		ArcBox* p = (ArcBox *)malloc(sizeof(ArcBox));
//		*p = {x,y,G.xlist[y].firstin,G.xlist[x].firstout,NULL}; 	//对弧结点赋值
		(*p).tailvex = x;
		(*p).headvex = y;
		(*p).hlink = G.xlist[y].firstin;
		(*p).tlink = G.xlist[x].firstout;
		(*p).info = NULL; 
		G.xlist[y].firstin = G.xlist[x].firstout = p;				//完成在入弧和出弧链头的插入 
	} 
	return G; 
}

int LocateVex(OLGraph G,int v){
	int i = 0;
	while(G.xlist[i].data != v)
		i++;
	return i;
} 
