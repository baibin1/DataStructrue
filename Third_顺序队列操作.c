#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MaxSize 5

typedef struct {
	int data[MaxSize];
	int front;			//��ͷָ��
	int rear;			//��βָ�� 
}SqQueue;

SqQueue InitQueue(SqQueue Q);
bool isEmpty(SqQueue Q);
SqQueue EnQueue(SqQueue Q);
SqQueue DeQueue(SqQueue Q);
int GetLength(SqQueue Q); 
int GetElem(SqQueue Q);


int main(){
	
	SqQueue Q;
	Q = InitQueue(Q);
	isEmpty(Q);
	GetLength(Q);
	Q = EnQueue(Q);
	GetLength(Q);
	Q = EnQueue(Q);
	GetLength(Q);
	Q = EnQueue(Q);
	GetElem(Q);
	GetElem(Q);
	GetElem(Q);
	GetLength(Q);
	isEmpty(Q);
	Q = DeQueue(Q);
	GetLength(Q);
	GetElem(Q);
	GetElem(Q);
	Q = DeQueue(Q);
	GetLength(Q);
	GetElem(Q);
	return 0;
}

SqQueue InitQueue(SqQueue Q){
	Q.front = Q.rear = 0;
	return Q;
}

bool isEmpty(SqQueue Q){
	if(Q.front == Q.rear)
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

SqQueue EnQueue(SqQueue Q){
	if((Q.rear+1)%MaxSize == Q.front)
	{
		printf("������\n");
		return Q;
	}
	else
	{
		printf("������Ҫ��ӵ�ֵ��\n");
		int e;
		scanf("%d",&e);
		Q.rear = (Q.rear+1)%MaxSize;
		Q.data[Q.rear] = e;
		return Q; 
	}
} 

SqQueue DeQueue(SqQueue Q){
	if(Q.front == Q.rear)
	{
		printf("�ӿգ�\n");
		return Q;
	}
	else
	{
		Q.front = (Q.front+1)%MaxSize;
		int x;
		x = Q.data[Q.front];
		printf("%d\n",x);
		return Q;
	}
}

int GetLength(SqQueue Q){
	int times=0;
	while(Q.front != Q.rear){
		times++;
		Q.front = (Q.front+1)%MaxSize;
	}
	printf("�ӳ�Ϊ��%d\n",times);
	return times;
} 

int GetElem(SqQueue Q){
	int len;
	len = GetLength(Q);
	if(len == 0){
		printf("�ӿգ�\n");
		return 0;
	}
	else
	{
		int x,e,i=1;
		printf("��������Ҫ���ҵ�λ�ã�\n");
		scanf("%d",&x);
		if(x<0||x>len){
			printf("GUN��\n");
		}
		else{
			Q.front = (Q.front+1)%MaxSize;
			while(i!=x){
				Q.front = (Q.front+1)%MaxSize;
				i++;
			} 
			e = Q.data[Q.front];
			printf("��%d��λ�õ�ֵΪ��%d\n",x,e);
			return e;
			}
	}
}
