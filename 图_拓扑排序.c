/*
*��һ�������޻�ͼ������������
*�����ڣ�2022��11��7��14��49��
*Author��bjb
*���һ���޸��ڣ�2022��11��7�� 
*/
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 20
#define MAX_VERTEX_NUM 20

typedef struct ArcNode{
	int adjvex;					//�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;	//ָ����һ������ָ�� 
	int info;					//Ȩֵ 
}ArcNode; 
typedef struct VNode{
	int data;					//������Ϣ 
	int count;					//ͳ�Ƶ�ǰ�������� 
	ArcNode *firstarc;			//ָ���һ�������ö���Ļ���ָ�� 
}VNode,AdjList[MAX_VERTEX_NUM]; 
typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;			//ͼ��ǰ�Ķ������ͻ���
}ALGraph;

ALGraph CreateDN(ALGraph G);      //����������DN
int LocateGraph(ALGraph G,int v);//����ֵΪv�Ķ�����ͼG�е�λ��
void vist(ALGraph G);            //�������˳���ӡ�ڽӱ�ͼ
//��������
void TopSort(ALGraph G); 

int main(){

    ALGraph G;
    G = CreateDN(G);
    vist(G);
    TopSort(G);

    return 0;
}

ALGraph CreateDN(ALGraph G){

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
		G.vertices[i].count = 0;				//��ʼ��countֵ 
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
		G.vertices[y].count++;
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = y;
		p->nextarc = G.vertices[x].firstarc;
		G.vertices[x].firstarc = p;
	}

    return G;
}

void vist(ALGraph G){
	for(int i = 0;i<G.vexnum;i++)
	{
		if(G.vertices[i].firstarc==NULL)
		{	
				printf("ֵΪ%d�Ķ��㲢��ָ���κζ���~,���Ϊ��%d\n",G.vertices[i].data,G.vertices[i].count);
				continue;
		} 
		ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
		p = G.vertices[i].firstarc; 
		while(p!=NULL)
		{
			printf("%d��ֵΪ��%d�� ",p->adjvex,G.vertices[p->adjvex].data);
			p = p->nextarc;

		}
		printf("��%d�������������~�����Ϊ��%d\n",i+1,G.vertices[i].count);
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

void TopSort(ALGraph G){
	int stack[MAX_VERTEX_NUM],top = -1;			//����һ��ջ��������¼���Ϊ0�Ķ���
	int n = 0;									//����һ����������������¼�Ѿ�����Ķ�����
	ArcNode *p;
	//�����Ϊ0�Ķ�����ջ 
	for(int i = 0; i < G.vexnum ; i++)
		if(G.vertices[i].count == 0)
			stack[++top] = i;
	int x,j;
	while(top!=-1)
	{
		x = stack[top--];
		++n;
		printf("%d ",G.vertices[x].data);
		p = G.vertices[x].firstarc;
		
		//���ɴ˶������������б���ָ��Ķ������ȶ�����һ������֮����ȱ�Ϊ0�Ķ�����ջ
		while(p!=NULL)
		{
			j = p->adjvex;
			G.vertices[j].count = G.vertices[j].count - 1;
			if(G.vertices[j].count == 0)
				{
//				printf("%d ",j);
				stack[++top] = j;
				}
			p = p->nextarc;
		} 
	}
	printf("\n");
	if( n == G.vexnum)
		printf("�����ȫ�����㣡\n") ;
	else
		printf("û�����ȫ�����㣡\n");
}

