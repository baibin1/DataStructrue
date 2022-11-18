#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/*
*����ʽ�洢�ṹ�Ĵ����ͱ����
*/

typedef struct  LNode{
	ElemType data;
	struct LNode * next;
}LNode,* LinkList;

LinkList CreateList();		//���򴴽�һ����ʽ�洢�ṹ
LinkList Create_List();		//˳�򴴽�һ����ʽ�洢�ṹ (ͷ�巨�� 
void TraverseList(LinkList L);
LinkList FreeLinkedList(LinkList L);

int main(){
	LinkList L = NULL;
	
	L = CreateList();
		
	TraverseList(L);
	
	FreeLinkedList(L);
	
	LinkList LI = NULL;
	
	LI = Create_List();
	
	TraverseList(LI);
	
	FreeLinkedList(LI);
		
	return 0;
}

LinkList CreateList(){
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	printf("��������Ҫ�����Ľڵ�����\n");
	int n,value;
	scanf("%d",&n);
	for(int i=n;i>0;--i){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("�����%d���ڵ��Ԫ��ֵ��\n",i);
		scanf("%d",&value);
		p->data = value;
		p->next = L->next;
		L->next = p;
	}
	return L; 
} 

LinkList Create_List(){
	LinkList L = (LinkList)malloc(sizeof(LNode));
	printf("��������Ҫ�����Ľڵ�����\n");
	int n,value;
	scanf("%d",&n);
	LinkList r = L;
	for(int i=0;i<n;i++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("�����%d���ڵ��Ԫ��ֵ��\n",i+1);
		scanf("%d",&value);
		p->data = value;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L; 
} 

void TraverseList(LinkList L){
	LinkList p = L->next;
	printf("����Ľڵ�ֵΪ��\n");
	while(p){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

LinkList FreeLinkedList(LinkList L){
    LinkList P = L;
    LinkList Q = NULL;
    while(P)
    {
        Q = P->next;
        free(P);
        P=Q;
    }
    return NULL;
}
