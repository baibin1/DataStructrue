#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode{
	ElemType data;
	struct DNode *prior,*next;
}DNode,*DLinklist; 

DLinklist CreateDNode();
void DisPlay(DLinklist DL);
DLinklist InsterDNode(DLinklist DL);
DLinklist Deletelist(DLinklist DL);
int GetLength(DLinklist DL);

int main(){
	
	DLinklist DL = NULL;
	
	DL = CreateDNode();
	
	DisPlay(DL);
	
//	GetLength(DL);
	DL = InsterDNode(DL);
//	DL = Deletelist(DL);
	DisPlay(DL);
	
	return 0;
} 

DLinklist CreateDNode(){
	int i,value;
	printf("请输入你要创建的结点的个数：\n");
	scanf("%d",&i);
	DLinklist DL = (DLinklist)malloc(sizeof(DNode));
	DL->prior = NULL;
	DL->next = NULL;
	DLinklist r = DL;
	for(int j=0;j<i;j++){
		DLinklist p = (DLinklist)malloc(sizeof(DNode));
		printf("请输入第%d个结点的值：\n",j+1);
		scanf("%d",&value);
		p->data = value;
		p->next = NULL;
		p->prior= NULL;
		
		r->next = p;
		p->prior = r;
		r = r->next;
	}
	return DL;
}

void DisPlay(DLinklist DL){
	DLinklist temp = DL;
	while(temp){
		if(temp->prior != NULL)
		{
			printf("%d ",temp->data);
		}
		temp = temp->next;	
	} 
	printf("\n");
}

DLinklist InsterDNode(DLinklist DL){
	int len,i,e,j=1;
	printf("请输入你要插入结点的位置：\n"); 
	scanf("%d",&i);
	len = GetLength(DL);
	if(i>len+1||i<1){
		printf("Error!\n");
	}
	else
	{
	printf("请输入你要插入的值：\n");
	scanf("%d",&e);	
	DLinklist p = DL->next; 
	if(i == 1){
		DLinklist s = (DLinklist)malloc(sizeof(DNode));
		s->data = e;
		s->next = DL->next;
		DL->next->prior = s;
		s->prior = DL;
		DL->next = s;
		}
	else if( i == len+1){
		while(p->next!=NULL)
			p = p->next; 
		DLinklist s = (DLinklist)malloc(sizeof(DNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		s->prior = p;
	}
	else{
	while(p && j<i-1){
		p=p->next;
		j++;
		}
		DLinklist s = (DLinklist)malloc(sizeof(DNode));
		s->data = e;
		s->next = p->next;
		p->next->prior = s;
		s->prior = p;
		p->next = s;
		}
		return DL;
	}
}

DLinklist Deletelist(DLinklist DL){
	int i,len,j=1;
	len = GetLength(DL);
	printf("请输入你要删除的结点的位置：\n");
	scanf("%d",&i);
	DLinklist p = DL->next; 
	if(i == 1){
		DLinklist s = (DLinklist)malloc(sizeof(DNode));
		s = DL->next;
		DL->next = s->next;
		s->next->prior = DL;
		free(s); 
	}
	else if(i == len)
	{
		while(p->next->next!=NULL) 
			p = p->next;
		DLinklist s = (DLinklist)malloc(sizeof(DNode));
		s = p->next;
		p->next = NULL;
		free(s);	
		
	}
	else{
	while(p && j<i-1){
		p=p->next;
		j++;
	}
	DLinklist s = (DLinklist)malloc(sizeof(DNode));
	s = p->next;
	p->next = s->next;
	s->next->prior = p;
	free(s);
	}
	return DL;
}

int GetLength(DLinklist DL){
	DLinklist p = (DLinklist)malloc(sizeof(DNode));
	p = DL;
	int times=0;
	while(p->next!=NULL){
		p=p->next;
		times++;
	}
	printf("%d",times);
	return times;
}


