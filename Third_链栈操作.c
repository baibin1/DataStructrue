#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct LNode{
	int data;
	struct LNode * next;
}LNode,*LinkNode;

LinkNode InitStack(); 
int isEmpty(LinkNode lst);
void Push(LinkNode lst);
void Pop(LinkNode lst);
int GetLength(LinkNode lst);
int GetTop(LinkNode lst);

int main(){
	LinkNode lst = NULL;
	lst = InitStack();
	GetTop(lst);
	isEmpty(lst);
	Push(lst);
	GetTop(lst);
	Push(lst);
	GetTop(lst);
	GetLength(lst);
	isEmpty(lst);
	Pop(lst);
	isEmpty(lst);
	GetLength(lst);
	GetTop(lst);

	return 0;
}

LinkNode InitStack(){
	LinkNode lst = (LinkNode)malloc(sizeof(LNode));
	lst->next = NULL;
	return lst; 
}

int isEmpty(LinkNode lst){
	if(lst->next == NULL)
	{	
		printf("Empty!\n");
		return 1; 
	}
	else
	{
		printf("Not Empty!\n");
		return 0;
	}
}

void Push(LinkNode lst){
	LinkNode p = (LinkNode)malloc(sizeof(LNode));
	p->next = NULL;
	printf("请输入要入栈的元素值：\n");
	int e;
	scanf("%d",&e);
	p->data = e;
	p->next = lst->next;
	lst->next = p;
}

void Pop(LinkNode lst){
	LinkNode p;
	if(lst->next == NULL)
	{
		printf("栈空！\n");
	}
	else
	{
		p = lst->next;
		int x;
		x = p->data;
		lst->next = p->next;
		free(p);
	}
}

int GetLength(LinkNode lst){
	int times = 0;
	LinkNode p;
	p = lst;
	while(p->next != NULL){
		p = p->next;
		times++;
	}
	printf("栈长%d\n",times);
	return times;
}

int GetTop(LinkNode lst){
	if(lst->next == NULL)
	{
		printf("栈空！\n");
		return 0;
	}
	else
	{
		LinkNode p; 
		int x;
		p = lst->next;
		x = p->data;
		printf("栈顶元素值为：%d\n",x);
		return x;
	}
}
