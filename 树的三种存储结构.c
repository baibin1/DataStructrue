#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100			//树中最多节点数
typedef int ElemType;
//树的双亲表示法的存储结构如下 
typedef struct PTNode{		//树的结点定义 
	ElemType data;			//数据元素 
	int parent;				//双亲位置域 
}PTNode;
typedef struct PTree{		//树的类型定义 
	PTNode nodes[MaxSize];	//双亲的表示 
	int n;					//结点数 
}PTree; 

/*
*孩子表示法：
*将每个结点的孩子都用单链表链接起来形成一个线性结构 
*/ 

//孩子兄弟表示法
typedef struct CSNode{
	ElemType data;			//数据域 
	struct CSNode *Firstchild,*Nextchild; 		//第一个孩子结点和右兄弟指针 
}CSNode,*CSTree; 

int main(){
	return 0;
} 
