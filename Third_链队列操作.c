#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QEleType; 

typedef struct QNode{
	QEleType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;			//��ͷָ��		 
	QueuePtr rear;			//��βָ�� 
}LQueue,*LinkQueue;

LinkQueue InitQueue();
bool isQueueEmpty(LinkQueue lqu);
LinkQueue enQueue(LinkQueue lqu);
LinkQueue deQueue(LinkQueue lqu);
int GetLength(LinkQueue lqu);
int GetElem(LinkQueue lqu);

int main(){
	
	LinkQueue lqu = (LinkQueue)malloc(sizeof(LQueue));
	lqu = InitQueue(lqu);
	GetLength(lqu);
	isQueueEmpty(lqu);
	enQueue(lqu);
	GetLength(lqu);
	enQueue(lqu);
	GetLength(lqu);
	GetElem(lqu);
	isQueueEmpty(lqu);
	deQueue(lqu);
	GetLength(lqu);
	deQueue(lqu);
	isQueueEmpty(lqu);
	
	
	
	return 0;
} 

LinkQueue InitQueue(){
	LinkQueue lqu = (LinkQueue)malloc(sizeof(LQueue));
	lqu->front = lqu->rear = NULL;
}

bool isQueueEmpty(LinkQueue lqu){
	if(lqu->front == NULL||lqu->rear == NULL)
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

LinkQueue enQueue(LinkQueue lqu){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	printf("������Ҫ�����ֵ��\n");
	int e;
	scanf("%d",&e);
	p->data = e;
	p->next = NULL;
	if(lqu->rear == NULL)
		lqu->front = lqu->rear = p;
	else
	{
		lqu->rear->next = p;
		lqu->rear = p;
	}
	return lqu;
}

LinkQueue deQueue(LinkQueue lqu){
	QueuePtr p;
	if(lqu->rear == NULL)
	{
		printf("�ӿգ�\n");
		return lqu;
	}
	else
		p = lqu->front;
	if(lqu->front == lqu->rear)
		lqu->front = lqu->rear = NULL;
	else
		lqu->front = lqu->front->next;
	int x;
	x = p->data;
	free(p);
	printf("����Ԫ��Ϊ��%d\n",x);
	return lqu;
}

int GetLength(LinkQueue lqu){
	if(lqu->front == NULL || lqu->rear == NULL)
	{
		printf("�ӳ�Ϊ��0��\n");
		return 0;
	}
	else
	{
		QueuePtr p;
		p = lqu->front;
		int times = 1;
		while(p != lqu->rear)
		{
			p = p->next;
			times++;
		}
		printf("�ӳ�Ϊ��%d\n",times);
		return times;	
	}
}

int GetElem(LinkQueue lqu){
	if(lqu->front == NULL || lqu->rear == NULL)
	{
		printf("�ӿգ�\n");
		return 0;
	}
	else
	{
		printf("��������Ҫ���ҵ�λ�ã�\n");
		int x;
		scanf("%d",&x);
		QueuePtr p;
		p = lqu->front;
		int times = 1;
		while(times != x)
		{
			p = p->next;
			times++;
		}
		printf("��λ��Ԫ��ֵΪ��%d\n",p->data);
		return p->data;	
		
	}
} 
