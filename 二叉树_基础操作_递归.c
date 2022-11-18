#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define MaxSize 50 
typedef char TypeData;

typedef struct Bitree{
	TypeData data;
	struct Bitree *lchild,*rchild;
}Bitree,*BiTree;

typedef struct SqQueue{
	BiTree data[MaxSize];
	int front;
	int rear;
}SqQueue;

void CreateTree(BiTree *T);
void preorder(BiTree T);
void inorder(BiTree T);
void postorder(BiTree T);
SqQueue InitQueue(SqQueue Q);
bool isEmpty(SqQueue Q);
SqQueue EnQueue(SqQueue Q,BiTree T);
SqQueue DeQueue(SqQueue Q,BiTree T); 
void Levelorder(BiTree T);

int main(){
	
	BiTree T = (BiTree)malloc(sizeof(Bitree));
	SqQueue Q;
	CreateTree(&T);
	preorder(T);
	printf("\n");
	inorder(T);
	printf("\n");
	postorder(T);
	printf("\n");
	Levelorder(T);
	return 0;
} 

void CreateTree(BiTree *T){
	char ch;
//	BiTree T = NULL;
//	static int i=1;
//	printf("输入第%d个元素的值：\n",i++);
	scanf("%c",&ch);
	if(ch == '#') *T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(Bitree));
		(*T)->data = ch;
		CreateTree(&((*T)->lchild));
		CreateTree(&((*T)->rchild));
	}
//	return T;
}

void preorder(BiTree T){
	if(T)
	{
		printf("%c ",T->data);
		preorder(T->lchild);
		preorder(T->rchild);
	}
}

void inorder(BiTree T){
	if(T)
	{
		inorder(T->lchild);
		printf("%c ",T->data);
		inorder(T->rchild);
	}
}

void postorder(BiTree T){
	if(T)
	{
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c ",T->data);
	}
}

SqQueue InitQueue(SqQueue Q){
	Q.front = Q.rear = 0;
	return Q;
}

bool isEmpty(SqQueue Q){
	if(Q.front == Q.rear)
		return true;
	else
		return false; 
}

SqQueue EnQueue(SqQueue Q,BiTree T){
	if((Q.rear+1)%MaxSize == Q.front)
		return Q;
	else
	{
		Q.rear = (Q.rear+1)%MaxSize;
		Q.data[Q.rear] = T;
		return Q;
	}
}

SqQueue Dequeue(SqQueue Q,BiTree p){
	if(Q.front == Q.rear)
	{
		return Q;
	}
	else
	{
		Q.front = (Q.front+1)%MaxSize;
		p = Q.data[Q.front];
//		printf("%c",p->data);
		return Q;
	}
}

void Levelorder(BiTree T){
	SqQueue Q;
	Q = InitQueue(Q);
	BiTree p;
	Q = EnQueue(Q,T);
	while(!isEmpty(Q)){
		Q = Dequeue(Q,p);
		p = Q.data[Q.front];
		printf("%c ",p->data);
		if(p->lchild!=NULL)
			Q = EnQueue(Q,p->lchild);
		if(p->rchild!=NULL)
			Q = EnQueue(Q,p->rchild);
	}
	
//	int front,rear;
//	BiTree que[MaxSize];
//	front = rear = 0;
//	BiTree q;
//	if(T!=NULL)
//	{
//		rear=(rear+1)%MaxSize;
//		que[rear] = T;
//		while(front != rear)
//		{
//			front = (front+1)%MaxSize;
//			q = que[front];
//			printf("%c ",q->data);
//			if(q->lchild!=NULL)
//			{
//				rear = (rear+1)%MaxSize;
//				que[rear] = q->lchild;
//			}
//			if(q->rchild!=NULL)
//			{
//				rear = (rear+1)%MaxSize;
//				que[rear] = q->rchild;
//			}
//		}
//	}
	  
}
