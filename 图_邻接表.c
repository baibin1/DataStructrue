/*----------ͼ���ڽӱ�洢��ʾ----------  
*�����ڣ�2022��11��2��16��57��
*Author��bjb
*���һ���޸��ڣ� 2022��11��3��15��32�� 
*/ 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 20

typedef struct ArcNode{
	int adjvex;					//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ�� 
	char *info;					//�û��������Ϣ 
}ArcNode; 
typedef struct VNode{
	int data;					//������Ϣ 
	ArcNode *firstarc;			//ָ���һ�������ö���Ļ���ָ�� 
}VNode,AdjList[MAX_VERTEX_NUM]; 
typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;			//ͼ��ǰ�Ķ������ͻ���
	int kind;					//ͼ�������־ 
}ALGraph;

ALGraph CreateAlGraph(ALGraph G);	//���ڽӱ���ͼG
ALGraph CreateDG(ALGraph G); 		//��������ͼG 
ALGraph CreateUDG(ALGraph G);		//��������ͼG 
ALGraph Error();					//���󷵻� 
void vist(ALGraph G);				//��ӡͼ 
int LocateGraph(ALGraph G,int v);	//��ȡv��ͼ�е�λ�� 


int main(){

	ALGraph G;
	G = CreateAlGraph(G);
	vist(G);
	 

	return 0;
}

ALGraph CreateAlGraph(ALGraph G){
	printf("��������Ҫ������ͼ�����ͣ�\n1.����ͼDG\n2.����ͼUDG\n");
	scanf("%d",&G.kind);
	switch(G.kind){
		case 1:return CreateDG(G);
		case 2:return CreateUDG(G);
		default:return Error();
	} 
}

ALGraph CreateDG(ALGraph G){
	//�����ڽӱ�������ͼG 
	//�������� 
	printf("�����붥��ĸ�����\n");
	scanf("%d",&G.vexnum);
	printf("�����뻡��������\n");
	scanf("%d",&G.arcnum);
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("�������%d�������ֵ��\n",i+1);
		scanf(" %d",&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;			//��ʼ��ָ�� 
	}
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("��%d�������ֵΪ��%d\n",i+1,G.vertices[i].data);
	}
	for(int i = 0;i<G.arcnum;i++)
	{
		printf("�������%d���ߵ�ʼ�����β�����ֵ(ע��˳��)��\n",i+1);
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		int x,y;
		x = LocateGraph(G,v1);
		y = LocateGraph(G,v2); 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
	}
	
//��һ������ָ�����һ�������ֵ���� 
 
//	for(int j = 0;j<G.vexnum;j++)
//	{	
//		G.vertices[j].firstarc = NULL;
//		int k = 1;
//		while(true)
//		{
//			int v;
//			printf("������ֵΪ%d�Ķ���ָ��ĵ�%d�������ֵ��\n",G.vertices[j].data,k);
//			scanf(" %d",&v);
//			if(v == 0) break;
//			int z=0;
//			for(int n = 0;n<G.vexnum;n++)
//			{
//				if(G.vertices[n].data == v)
//					break;
//				z++;
//			}
//			printf("ֵ%d��Ӧ�Ķ���Ϊ��%d������\n",v,z+1);
//			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
//			p->adjvex = z;  
//			p->nextarc = G.vertices[j].firstarc;
//			G.vertices[j].firstarc = p;
//			k++;
//		}
//	}
	return G;
}

ALGraph CreateUDG(ALGraph G){
	//�����ڽӱ���������ͼG 
	printf("�����붥��ĸ�����\n");
	scanf("%d",&G.vexnum);
	printf("�����뻡��������\n");
	scanf("%d",&G.arcnum);
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("�������%d�������ֵ��\n",i+1);
		scanf(" %d",&G.vertices[i].data);
		G.vertices[i].firstarc = NULL;			//��ʼ��ָ�� 
	}
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("��%d�������ֵΪ��%d\n",i+1,G.vertices[i].data);
	}
	for(int i = 0;i<G.arcnum;i++)
	{
		printf("�������%d���ߵ����������ֵ��\n",i+1);
		int v1,v2;
		scanf("%d%d",&v1,&v2);
		int x,y;
		x = LocateGraph(G,v1);
		y = LocateGraph(G,v2); 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
		ArcNode *s = (ArcNode *)malloc(sizeof(ArcNode));
		s->adjvex = x;
		s->nextarc = G.vertices[y].firstarc;
		G.vertices[y].firstarc = s; 
	}
//	for(int j = 0;j<G.vexnum;j++)
//	{	
//		G.vertices[j].firstarc = NULL;
//		int k = 1;
//		while(true)
//		{
//			int v;
//			printf("������ֵΪ%d�Ķ��������ĵ�%d�������ֵ��\n",G.vertices[j].data,k);
//			scanf(" %d",&v);
//			if(v == 0) break;
//			int z=0;
//			for(int n = 0;n<G.vexnum;n++)
//			{
//				if(G.vertices[n].data == v)
//					break;
//				z++;
//			}
//			printf("ֵ%d��Ӧ�Ķ���Ϊ��%d������\n",v,z+1);
//			ArcNode *p = (ArcNode*)malloc(sizeof(ArcNode));
//			p->adjvex = z;  
//			p->nextarc = G.vertices[j].firstarc;
//			G.vertices[j].firstarc = p;
//			k++;
//		}
//	}
	return G;
}

ALGraph Error(){
	ALGraph G;
	printf("�������\n");
	return G;
} 

void vist(ALGraph G){
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertices[i].firstarc==NULL)
		{	
				printf("ֵΪ%d�Ķ��㲢��ָ���κζ���~\n",G.vertices[i].data);
				continue;
		} 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p = G.vertices[i].firstarc; 
		while(p!=NULL)
		{
			printf("%d��ֵΪ��%d�� ",p->adjvex,G.vertices[p->adjvex].data);
			p = p->nextarc;

		}
		printf("��%d�������������~\n",i+1);
	}
}

int LocateGraph(ALGraph G,int v){
	int res;
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertices[i].data == v)
		{
			res = i;
			break;
		}	
	}
	return res;
}
