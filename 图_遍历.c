/*
*----------ͼ�ı����������������BFS�������������DFS
*�����ڣ�2022��11��3��15��53��
*Author��bjb
*���һ���޸��ڣ� 2022��11��6��00:41:41
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTEX_NUM 20
//������������ʵ�������� 
typedef int QEleType; 
typedef struct QNode{
	QEleType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front;			//��ͷָ��		 
	QueuePtr rear;			//��βָ�� 
}LQueue,*LinkQueue; 
//ͼ���ڽӱ�洢�ṹ����
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

ALGraph CreateGraphUDG(ALGraph G);		//�����ڽӱ�洢�ṹ����ͼ UDG 
int LocateGraph(ALGraph G,int v);		//��ȡĳԪ����ͼG�е�λ��
void vistGraph(ALGraph G);				//��ӡͼG
LinkQueue InitQueue();					//��ʼ������ 
bool isEmptyQueue(LinkQueue Q);			//�ж϶����Ƿ�Ϊ�� 
void enQueue(LinkQueue Q,int v);		//���
int deQueue(LinkQueue Q);				//���� 
bool visited[MAX_VERTEX_NUM];			//���ʱ������
void BFSTraverse(ALGraph G);			//��ͼG���й����������
void BFS(LinkQueue Q, ALGraph G,int v);	//�Ӷ����v������������ȱ���ͼG
void BFS_MIN_Distance(ALGraph G,int u);	//������������·��
void DFSTraverse(ALGraph G);			//��ͼG���������������
void DFS( ALGraph G,int v);				//�Ӷ���v������������ȱ���ͼG
int FirstNeighbor(ALGraph G,int v);		//����v�ĵ�һ���ڽӶ���
int NextNeighbor(ALGraph G,int v,int w);//����v����һ���ڽӶ���

int main(){

	ALGraph G;
	G = CreateGraphUDG(G);
	vistGraph(G);
	BFSTraverse(G);
	printf("\n");
	DFSTraverse(G);
	printf("\n");
	int u = 0;
	BFS_MIN_Distance(G,u);
	// for(int i = 0; i < G.vexnum ; i++)
	// {
	// 	if(visited[i] == true)
	// 		printf("1");
	// 	else
	// 		printf("0");
	// }
	return 0;
} 

ALGraph CreateGraphUDG(ALGraph G){
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
	return G;
}

int LocateGraph(ALGraph G,int v){
	int res;
	if(v == 0)
		return -1;
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

void vistGraph(ALGraph G){
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

LinkQueue InitQueue(){
	LinkQueue Q = (LinkQueue)malloc(sizeof(LQueue));
	Q->front = Q->rear = NULL;
}

bool isEmptyQueue(LinkQueue Q){
	if(Q->front == NULL || Q->rear == NULL)
	{
		// printf("Empty!\n");
		return true;
	}
	else
	{
		// printf("Not Empty!\n");
		return false;
	}
} 

void enQueue(LinkQueue Q,int v){
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	p->data = v;
	p->next = NULL;
	if(Q->rear == NULL)
		Q->front = Q->rear = p;
	else
	{
		Q->rear->next = p;
		Q->rear = p;
	} 
} 

int deQueue(LinkQueue Q){
	QueuePtr p;
	if(Q->rear == NULL)
	{
		printf("�ӿգ�\n");
		return 0;
	}
	else
		p = Q->front;
	if(Q->front == Q->rear)
	{
		int x;
		x = Q->front->data;
		Q->front = Q->rear = NULL;
		// printf("����Ԫ��Ϊ��%d\n",x);
		return x;

	}
	else
	{
		Q->front = Q->front->next;
		int x;
		x = p->data;
		free(p);
		// printf("����Ԫ��Ϊ��%d\n",x);
		return x;
	}
} 

void BFSTraverse(ALGraph G){
	for (int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
		// printf("���ʱ�������ʼ����ɣ�\n");
	}
	LinkQueue Q;
	Q = InitQueue(Q);
	for (int i = 0; i < G.vexnum; i++)
		if (! visited[i])
		{
			// printf("BFS����ִ�У�\n");
			BFS(Q,G,i);						//iΪ�����Ӧ�±�
		}
}

void BFS(LinkQueue Q, ALGraph G,int v){		//vΪ�����Ӧ�±�
	
	printf("%d ",G.vertices[v].data);
	visited[v] = true;						//vΪ�����Ӧ�±�
	enQueue(Q,v);							//vΪ�����Ӧ�±�
	while (! isEmptyQueue(Q))
	{
		v = deQueue(Q);						//vΪ�����Ӧ�±�
		for (int w = FirstNeighbor(G,v) ; w >= 0 ; w = NextNeighbor(G,v,w) )
		{
			if(! visited[w])
			{
				printf("%d ",G.vertices[w].data);
				visited[w] = true;
				enQueue(Q,w);
			}
		}
	}
}

void BFS_MIN_Distance(ALGraph G, int u){
	LinkQueue Q;
	Q = InitQueue();
	int d[MAX_VERTEX_NUM];
	for( int i = 0; i < G.vexnum; i++)
	{
		visited[i] = false;
		d[i] = -1;
	}
	visited[u] = true;
	d[u] = 0;
	enQueue(Q,u);
	while (! isEmptyQueue(Q))
	{
		u = deQueue(Q);
		for (int w = FirstNeighbor(G,u); w >= 0; w = NextNeighbor(G,u,w))
			if(! visited[w])
			{
				visited[w] = true;
				d[w] = d[u] + 1;
				enQueue(Q,w);
			}
	}
	for (int i = 0; i < G.vexnum; i++)
		printf("%d ",d[i]);
}

void DFSTraverse(ALGraph G){
	for( int i = 0; i < G.vexnum ; i++)
		visited[i] = false;
	for( int v = 0; v < G.vexnum ; v++)
		if(! visited[v])
			DFS(G,v);
}

void DFS( ALGraph G,int v){
	printf("%d ",G.vertices[v].data);
	visited[v] = true;
	for (int w = FirstNeighbor(G,v) ; w >= 0 ; w = NextNeighbor(G,v,w) )
		if(! visited[w])
		{
			DFS(G,w);
		}		
}

int FirstNeighbor(ALGraph G,int v){
	int res;
	ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
	p = G.vertices[v].firstarc;
	if(p == NULL)
		return -1;
	else
		res = p->adjvex;
	return res;
}

int NextNeighbor(ALGraph G,int v,int w){
	int res;
	ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
	p = G.vertices[v].firstarc;
	while(p->adjvex != w)
		p = p->nextarc;
	p = p->nextarc;
	if(p == NULL)
		return -1;
	else
		res = p->adjvex;
	return res;				
}