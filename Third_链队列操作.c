#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int QEleType; 

typedef struct QNode{
	QEleType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;			//队头指针		 
	QueuePtr rear;			//队尾指针 
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
	printf("请输入要插入的值：\n");
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
		printf("队空！\n");
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
	printf("出队元素为：%d\n",x);
	return lqu;
}

int GetLength(LinkQueue lqu){
	if(lqu->front == NULL || lqu->rear == NULL)
	{
		printf("队长为：0！\n");
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
		printf("队长为：%d\n",times);
		return times;	
	}
}

int GetElem(LinkQueue lqu){
	if(lqu->front == NULL || lqu->rear == NULL)
	{
		printf("队空！\n");
		return 0;
	}
	else
	{
		printf("请输入你要查找的位置：\n");
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
		printf("该位置元素值为：%d\n",p->data);
		return p->data;	
		
	}
} 
