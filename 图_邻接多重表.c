/*
*-----------无向图的邻接多重表存储表示-----------
*无向图的另一种链式存储结构
*创建于2022年11月2日21点56分
*Author：bjb 
*/ 
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20
typedef enum {unvisted,visted} VisitIf;
typedef struct EBox{
	VisitIf mark;				//访问标记
	int ivex,jvex;				//该边依附的两个顶点的位置
	struct EBox *ilink,*jlink; 	//分别指向依附这两个顶点的下一条边
	char *info;					//该边信息指针 
}EBox;
typedef struct VexBox{
	int data;
	EBox *firstedge;			//指向第一条依附该顶点的边 
}VexBox;
typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vexnum,edgenum;			//无向图的当前顶点数和边数 
}AMLGraph;

int main(){
	return 0;
} 
 
