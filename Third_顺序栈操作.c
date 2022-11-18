#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 50

typedef struct {
	int data[MaxSize];
	int top;
}SqStack;

SqStack InitStack(SqStack S);
bool StackEmpty(SqStack S);
SqStack Push(SqStack S); 
SqStack Pop(SqStack S);
int GetTop(SqStack S);

int main(){
	
	SqStack S;
	S = InitStack(S);
	StackEmpty(S);
	S = Push(S);
	S = Push(S);
	StackEmpty(S);
	GetTop(S);
	S = Pop(S);
	GetTop(S);
	S = Pop(S);
	GetTop(S);
	StackEmpty(S);
	S = Push(S);
	GetTop(S);
	return 0;
} 

SqStack InitStack(SqStack S){
	S.top = -1;	
	return S;
}

bool StackEmpty(SqStack S){
	if(S.top == -1)
	{
		printf("Empty!\n");
		return true;
	}
	else
	{
		printf("Not Empty!\n");
		return false;
	}
}

SqStack Push(SqStack S){
	if(S.top == MaxSize-1)
		printf("ջ����\n");
	else
	{	
		printf("������Ҫ��ջ��ֵ��\n");
		int value;
		scanf("%d",&value); 
		S.top++;
		S.data[S.top] = value;
	}
	return S;
}

SqStack Pop(SqStack S){
	if(S.top == -1)
		printf("ջ��!\n");
	else
	{
		int x;
		x = S.data[S.top];
		S.top--;
	}
	return S;
}

int GetTop(SqStack S){
	int x;
	if(S.top == -1)
		printf("ջ�գ�\n");
	else
	{
		x = S.data[S.top];
		printf("ջ����Ԫ��Ϊ��%d\n",x);
		return x;
	}
}
