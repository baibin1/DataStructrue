#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode * next;
}LNode,* LinkList;

LinkList CreateLink();		//	ͷ�巨����������
LinkList Create_Link();		//	β�巨���������� 
void PutLink(LinkList L);	//	����������������ֵ 
LinkList FreeLinkedList(LinkList L);	//	�ͷŶ�̬����Ŀռ� 
LinkList GetElem(LinkList L);			//����Ų��ҽ��ֵ 
LinkList LocateElem(LinkList L);		//��ֵ���ұ��� 
LinkList InsertList(LinkList L);		//���Ĳ���	
LinkList DeleteList(LinkList L);		//����ɾ�� 
int GetLength(LinkList L);				//��ȡ�� 

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
	printf("������Ҫ�����Ľ������\n");
	scanf("%d",&n);
	LinkList L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for(int i=n;i>0;i--){
		printf("�������%d��Ԫ�ص�ֵ��\n",i);
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
	printf("������Ҫ�����Ľ������\n");
	scanf("%d",&n);
	LinkList L = (LinkList)malloc(sizeof(LNode));
	LinkList r = L;
	for(int i=0;i<n;i++){
		LinkList p = (LinkList)malloc(sizeof(LNode));
		printf("�������%d��Ԫ�ص�ֵ��\n",i+1);
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

LinkList GetElem(LinkList L){
	int j=1,i;
	LinkList p = L->next;
	printf("��������Ҫ���ҵĽ��ֵ����ţ�\n");
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
	printf("��������Ҫ���ҵ�ֵ��\n");
	int value;
	scanf("%d",&value);
	while(p!=NULL  && p->data!=value)
		p=p->next;
	return p;
} 

LinkList InsertList(LinkList L){
	int i,e,j=1;
	printf("��������Ҫ�������λ�ã�\n"); 
	scanf("%d",&i);
	int len;
	len = GetLength(L);
	if(i>len+1||i<1){
		printf("Error!\n");
	}
	else
	{
	printf("��������Ҫ�����ֵ��\n");
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
	printf("��������Ҫɾ���Ľ���λ�ã�\n");
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
	printf("��Ϊ��%d\n",sum);
	return sum;
} 
