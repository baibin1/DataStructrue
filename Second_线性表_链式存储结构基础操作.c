#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

/*
*简单链式存储结构的创建和便遍历
*/

typedef struct  LNode{
	ElemType data;
	struct LNode * next;
}LNode,* LinkList;

LinkList CreateList();		//逆序创建一个链式存储结构
LinkList Create_List();		//顺序创建一个链式存储结构 (头插法） 
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
	printf("请输入你要构建的节点数：\n");
	int n,value;
	scanf("%d",&n);
	for(int i=n;i>0;--i){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("输入第%d个节点的元素值：\n",i);
		scanf("%d",&value);
		p->data = value;
		p->next = L->next;
		L->next = p;
	}
	return L; 
} 

LinkList Create_List(){
	LinkList L = (LinkList)malloc(sizeof(LNode));
	printf("请输入你要构建的节点数：\n");
	int n,value;
	scanf("%d",&n);
	LinkList r = L;
	for(int i=0;i<n;i++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("输入第%d个节点的元素值：\n",i+1);
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
	printf("输出的节点值为：\n");
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
