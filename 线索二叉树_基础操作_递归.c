/*
*最后一次修改于2022年11月2日16点58分，待数据结构学完debug，可参考徐斌b站视频 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {Link,Thread} PointerTag;	//Link == 0：指针，Thread == 1:线索 

typedef struct ThreadNode{
	char data;
	PointerTag ltag,rtag;				//左右标志 
	struct ThreadNode *lchild,*rchild; 	//左右孩子指针 
}ThreadNode,*ThreadTree;

void CreateThreadTree(ThreadTree *T);					//初始化线索二叉树
void InThread(ThreadTree T,ThreadTree pre); 			//线索二叉树线索化
void CreateInThread(ThreadTree T);						//通过中序遍历建立中序二叉树 
ThreadTree First(ThreadTree T);							//中序序列的第一个结点 
ThreadTree Next(ThreadTree T); 							//中序下的后序结点 
void Inorder(ThreadTree T); 							//遍历 
 

int main(){
	
	ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));
	CreateThreadTree(&T); 
	CreateInThread(T);
	Inorder(T);
	
	return 0;
} 
//线索二叉树初始化 
void CreateThreadTree(ThreadTree *T){
	char ch;
	scanf("%c",&ch);
	if(ch == '#') *T = NULL;
	else
	{
		*T = (ThreadTree)malloc(sizeof(ThreadNode));
		(*T)->data = ch;
		(*T)->ltag = Link;
		(*T)->rtag = Link;
		CreateThreadTree(&((*T)->lchild));
		CreateThreadTree(&((*T)->rchild)); 
	}
}
//线索二叉树线索化 
void InThread(ThreadTree T,ThreadTree pre){
	if(T!=NULL)
	{
		InThread(T->lchild,pre);
		if(T->lchild == NULL)
		{
			T->lchild = pre;
			T->ltag = Thread;
		}
		if(pre!=NULL && T->rchild == NULL)
		{
			pre->rchild = T;
			pre->rtag = Thread; 
		}
		pre = T;
		InThread(T->rchild,pre);
	}
} 

void CreateInThread(ThreadTree T){
	ThreadTree pre = (ThreadTree)malloc(sizeof(ThreadNode));
	if(T != NULL)
	{
		InThread(T,pre);
		pre->rchild = NULL;
		pre->rtag = Thread;
	}
} 

ThreadTree First(ThreadTree T){
	while(T->ltag == Link)
		T = T->lchild;
	return T;
}

ThreadTree Next(ThreadTree T){
	if(T->rtag == Link)
		return First(T->rchild);
	else
		return T->rchild;
}

void Inorder(ThreadTree T){
	for(ThreadTree p =First(T);p!=NULL;p = Next(p))
		printf("%c ",p->data);
}
