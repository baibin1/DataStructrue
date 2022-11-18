#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50
typedef char TypeData;

typedef struct Bitree{
	TypeData data;
	struct Bitree* lchild,* rchild;
}Bitree,*BiTree;

typedef struct Stack{
	BiTree data[MaxSize];
	int top;
}SqStack;

SqStack InitStack(SqStack S);
bool isEmpty(SqStack S);
SqStack Push(SqStack S,BiTree T);
SqStack Pop(SqStack S,BiTree T);
BiTree GetTop(SqStack S);
BiTree CreatBitree(); 
void Preorder(BiTree T);		//先序遍历 
void inoreder(BiTree T); 		//中序遍历 
void Postorder(BiTree T); 		//后序遍历 

int main(){
	
	BiTree T;
	T = CreatBitree();
	Preorder(T);
	printf("\n");
	inoreder(T);
	printf("\n");
	Postorder(T);
	 
	return 0;
} 

SqStack InitStack(SqStack S){
	S.top = -1;
	return S;
}

bool isEmpty(SqStack S){
	if(S.top == -1)
		return true;
	else
		return false;
}

SqStack Push(SqStack S,BiTree T){
	if(S.top == MaxSize-1)
		return S;
	else
	{
	S.top++;
	S.data[S.top] = T;
	return S;
	}
}

SqStack Pop(SqStack S,BiTree T){
	if(S.top == -1)
		return S;
	else
	{
	T = S.data[S.top];
	S.top--;
	return S;
	}
}

BiTree GetTop(SqStack S){
	BiTree T;
	T = S.data[S.top];
	return T;
}

BiTree CreatBitree(){
	char ch;
	BiTree T;
	scanf("%c",&ch);
	if(ch == '#') T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(Bitree));
		T->data = ch;
		T->lchild = CreatBitree();
		T->rchild = CreatBitree();
	}
	return T;
}

void Preorder(BiTree T){
	SqStack S;
	S = InitStack(S);
	BiTree p = T;
	while(p || !isEmpty(S)){
		if(p)
		{
			printf("%c ",p->data);
			S = Push(S,p);
			p = p->lchild;
		}
		else
		{
			S = Pop(S,p);
			p = S.data[S.top+1];	//	链栈可以省？ 
			p = p->rchild;
		 } 
	}

//	if(T != NULL)
//	{
//		BiTree Stack[MaxSize];
//		int top = -1;
//		BiTree p;
//		Stack[++top] = T;
//		while(top!=-1)
//		{
//			p = Stack[top--];
//			printf("%c ",p->data);
//			if(p->rchild!=NULL)
//				Stack[++top] = p->rchild;
//			if(p->lchild!=NULL)
//				Stack[++top] = p->lchild;
//		 } 
//	}
}

void inoreder(BiTree T){
	
/*
引用关于栈的函数 
*/ 
	SqStack S;
	S = InitStack(S);
	BiTree p = T;
	while(p || !isEmpty(S))
	{
		if(p)
		{
			S = Push(S,p);
			p = p->lchild;
		}
		else
		{
			S = Pop(S,p);
			p = S.data[S.top+1];
			printf("%c ",p->data); 
			p = p->rchild;
		}
	}
/*
直接定义栈并使用 
*/
//	if(T!=NULL)
//	{
//		BiTree Stack[MaxSize];
//		int top = -1;
//		BiTree p = T;
//		while(p != NULL|| top != -1)
//		{
//			while(p!=NULL)
//			{
//				Stack[++top] = p;
//				p = p->lchild;
//			}
//			if(top!=-1)
//			{
//				p = Stack[top--];
//				printf("%c ",p->data);
//				p = p->rchild;
//			}
//		}
//	}
} 

void Postorder(BiTree T){
	SqStack S;
	S = InitStack(S);
	BiTree p = T;
	BiTree r = NULL;	//记录最近访问过的结点		
	while(p || !isEmpty(S))
	{
		if(p)
		{
			S = Push(S,p);
			p = p->lchild;
		}
		else
		{
			p = GetTop(S);
			if(p->rchild != NULL&& p->rchild != r)
				p = p->rchild;
			else
			{
				S = Pop(S,p);
				p = S.data[S.top+1];
				printf("%c ",p->data);
				r = p;
				p = NULL;
			 } 
		}
	 } 

//	if(T!=NULL)
//	{
//		BiTree Stack1[MaxSize]; int top1 = -1;
//		BiTree Stack2[MaxSize]; int top2 = -1;
//		BiTree p = NULL;
//		Stack1[++top1] = T;
//		while(top1!=-1)
//		{
//			p = Stack1[top1--];
//			Stack2[++top2] = p;
//			if(p->lchild != NULL)
//				Stack1[++top1] = p->lchild;
//			if(p->rchild != NULL)
//				Stack1[++top1] = p->rchild;
//		}
//		while(top2 != -1)
//		{
//			p = Stack2[top2--];
//			printf("%c ",p->data);
//		}
//	}
}
