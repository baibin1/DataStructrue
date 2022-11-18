/*
*���һ���޸���2022��11��2��16��58�֣������ݽṹѧ��debug���ɲο����bվ��Ƶ 
*/ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {Link,Thread} PointerTag;	//Link == 0��ָ�룬Thread == 1:���� 

typedef struct ThreadNode{
	char data;
	PointerTag ltag,rtag;				//���ұ�־ 
	struct ThreadNode *lchild,*rchild; 	//���Һ���ָ�� 
}ThreadNode,*ThreadTree;

void CreateThreadTree(ThreadTree *T);					//��ʼ������������
void InThread(ThreadTree T,ThreadTree pre); 			//����������������
void CreateInThread(ThreadTree T);						//ͨ���������������������� 
ThreadTree First(ThreadTree T);							//�������еĵ�һ����� 
ThreadTree Next(ThreadTree T); 							//�����µĺ����� 
void Inorder(ThreadTree T); 							//���� 
 

int main(){
	
	ThreadTree T = (ThreadTree)malloc(sizeof(ThreadNode));
	CreateThreadTree(&T); 
	CreateInThread(T);
	Inorder(T);
	
	return 0;
} 
//������������ʼ�� 
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
//���������������� 
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
