#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode,* LinkList;

LinkList CreateLink();		//	头插法创建单链表
LinkList Create_Link();		//	尾插法创建单链表 
void PutLink(LinkList L);	//	输出单链表各个结点的值 
LinkList FreeLinkedList(LinkList L);	//	释放动态分配的空间 
LinkList GetElem(LinkList L);			//按序号查找结点值 
LinkList LocateElem(LinkList L);		//按值查找表结点 
LinkList InsertList(LinkList L);		//结点的插入	
LinkList DeleteList(LinkList L);		//结点的删除 
int GetLength(LinkList L);				//获取表长 

int main(){
	
	LinkList L = NULL;
	
	L = CreateLink();
	
	PutLink(L);
	
//	FreeLinkedList(L);
//	
//	LinkList L = NULL;
	
//	L = Create_Link(); 
//	
//	PutLink(L);

//	LinkList p = NULL;
//	
//	p = GetElem(L);
//	
//	printf("%d %d\n",p->data,p->next);
//	
//	p = LocateElem(L);
//	
//	printf("%d %d\n",p->data,p->next);

	L = InsertList(L);
	
	GetLength(L);
	
//	L = DeleteList(L);
//	
//	GetLength(L);
//	
	PutLink(L); 
//	return 0;
} 

LinkList CreateLink(){
	int n,value;
	printf("请输入要创建的结点数：\n");
	scanf("%d",&n);
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for(int i=n;i>0;i--){
		printf("请输入第%d个元素的值：\n",i);
		scanf("%d",&value);
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = value;
		s->next = L->next;
		L->next = s; 
	}
	return L;
}

LinkList Create_Link(){
	int n,value;
	printf("请输入要创建的结点数：\n");
	scanf("%d",&n);
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LinkList r = L;
	for(int i=0;i<n;i++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("请输入第%d个元素的值：\n",i+1);
		scanf("%d",&value);
		p->data = value;
		r->next = p;
		r = p;
	}
	r->next = NULL;
	return L; 
}

void PutLink(LinkList L){
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

LinkList GetElem(LinkList L){
	int j=1,i;
	LinkList p = L->next;
	printf("请输入你要查找的结点值的序号：\n");
	scanf("%d",&i);
	if(i == 0)
		return NULL;
	while(p && j<i){
		p=p->next;
		j++;
	}
	return p;
} 

LinkList LocateElem(LinkList L){
	LinkList p = L->next;
	printf("请输入你要查找的值：\n");
	int value;
	scanf("%d",&value);
	while(p!=NULL  && p->data!=value)
		p=p->next;
	return p;
} 

LinkList InsertList(LinkList L){
	int i,e,j=1;
	printf("请输入你要插入结点的位置：\n"); 
	scanf("%d",&i);
	int len;
	len = GetLength(L);
	if(i>len+1||i<1){
		printf("Error!\n");
	}
	else
	{
	printf("请输入你要插入的值：\n");
	scanf("%d",&e);	
	LinkList p = L->next; 
	if(i == 1){
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->data = e;
		s->next = L->next;
		L->next = s;
		}
	else{
	while(p && j<i-1){
		p=p->next;
		j++;
		}
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s->next = p->next;
		s->data = e;
		p->next = s;
		}
	return L;
	}
} 

LinkList DeleteList(LinkList L){
	int i,j=1;
	printf("请输入你要删除的结点的位置：\n");
	scanf("%d",&i);
		LinkList p = L->next; 
	if(i == 1){
		LinkList s = (LinkList)malloc(sizeof(LNode));
		s = L->next;
		L->next = s->next;
		free(s); 
	}
	else{
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	LinkList s = (LinkList)malloc(sizeof(LNode));
	s = p->next;
	p->next = s->next;
	free(s);
	}
	return L;
}

int GetLength(LinkList L){
	LinkList s = L->next;
	int sum = 0;
	while(s){
		s = s->next;
		sum++;
	}
	printf("表长为：%d\n",sum);
	return sum;
} 
