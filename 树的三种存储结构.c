#include <stdio.h>
#include <stdlib.h>
#define MaxSize 100			//�������ڵ���
typedef int ElemType;
//����˫�ױ�ʾ���Ĵ洢�ṹ���� 
typedef struct PTNode{		//���Ľ�㶨�� 
	ElemType data;			//����Ԫ�� 
	int parent;				//˫��λ���� 
}PTNode;
typedef struct PTree{		//�������Ͷ��� 
	PTNode nodes[MaxSize];	//˫�׵ı�ʾ 
	int n;					//����� 
}PTree; 

/*
*���ӱ�ʾ����
*��ÿ�����ĺ��Ӷ��õ��������������γ�һ�����Խṹ 
*/ 

//�����ֵܱ�ʾ��
typedef struct CSNode{
	ElemType data;			//������ 
	struct CSNode *Firstchild,*Nextchild; 		//��һ�����ӽ������ֵ�ָ�� 
}CSNode,*CSTree; 

int main(){
	return 0;
} 
