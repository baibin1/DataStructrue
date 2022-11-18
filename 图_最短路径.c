#include <stdio.h>
#include <stdlib.h>
#define Max_Vertrx_Num 20				//��󶥵����
#define INFINITY 1000					//�޴�·����ʾ1000 
#define INF 100 
typedef struct ArcCell{
	int adj;
	char *info;
}ArcCell,AdjMatrix[Max_Vertrx_Num][Max_Vertrx_Num];
typedef struct MGrap{
	int vexs[Max_Vertrx_Num];			//��������
	AdjMatrix arcs;						//�ڽӾ���
	int vexnum,arcnum;					//ͼ��ǰ�Ķ������ͻ��� 
}MGrap;

int path[Max_Vertrx_Num];				//�����v_0��v_i�����·����v_i��ǰһ������
int dist[Max_Vertrx_Num];				//��ǰ���ҵ��Ĵ�v_0��ÿ���յ�v_i�����·�� 
int set[Max_Vertrx_Num];				//������飬����0û�б��������·��������1�Ѿ����������·�� 

int Path[][Max_Vertrx_Num];				//A������¼��ǰ�Ѿ���õ����������������·���ĳ��� 
int A[][Max_Vertrx_Num];				//Path������¼��ǰ������������·����Ҫ�������м䶥�� 

MGrap CreateDN(MGrap G); 				//�����ڽӾ���ķ�������������G
int LocateVex(MGrap G,int v);			//ȷ��Ԫ��v��ͼG�е�λ�� 
void vist(MGrap G);						//����ͼG
//�Ͻ�˹�����㷨��ĳһ���㵽�������������·�� 
void Dijkstra(MGrap G,int v,int dist[],int path[]); 
//���������㷨������һ�Զ������̾��� 
void Floyd(MGrap G,int Path[][Max_Vertrx_Num],int A[][Max_Vertrx_Num]); 

int main(){
	
	MGrap G;
	G = CreateDN(G);
	vist(G);
	int v = 0;
	Dijkstra(G,v,dist,path);
	printf("\n");
	for(int i = 0; i < G.vexnum; i++)
		printf("%d ",dist[i]);
	printf("\n");
	for(int i = 0; i < G.vexnum; i++)
		printf("%d ",path[i]);
	printf("\n");
	Floyd(G,Path,A);
	int times; 
	for(int i = 0; i < G.vexnum; i++)
		for(int j = 0; j < G.vexnum; j++)
		{
			printf("%d ",A[i][j]);
			times++;
			if(times%G.vexnum == 0)
				printf("\n");
		}
	printf("\n");
	for(int i = 0; i < G.vexnum; i++)
		for(int j = 0; j < G.vexnum; j++)
		{
			printf("%d ",Path[i][j]);
			times++;
			if(times%G.vexnum == 0)
				printf("\n");
		}
			

	
	
	return 0;
}  

MGrap CreateDN(MGrap G){
	//�����ڽӾ���ķ�������������G
	printf("������ͼ�Ķ�������\n"); 
	scanf("%d",&G.vexnum);
	printf("������ͼ�Ļ�����\n");
	scanf("%d",&G.arcnum);
	printf("�����붥��������\n");
	for(int i = 0;i<G.vexnum;i++)
	{
		printf("�������%d������������\n",i+1);
		scanf("%d",&G.vexs[i]);		//���춥������
	}	
	for(int i = 0;i<G.vexnum;i++)	//��ʼ���ڽӾ���
		for(int j = 0;j<G.vexnum;j++)
			{
				if(i == j)
				{
					G.arcs[i][j].adj = 0;
					G.arcs[i][j].info = NULL;
				}
				else
				{ 
					G.arcs[i][j].adj = INFINITY;
					G.arcs[i][j].info = NULL;
				}
			}
	int v1,v2;
	float w;
	printf("������һ���������Ķ����Լ�Ȩֵ��\n");	
	for(int k = 0;k<G.arcnum;k++)	//�����ڽӾ���
	{	
		printf("�������%d���ߵĶ����Լ�Ȩֵ(ע�ⷽ��)��\n",k+1);
		scanf(" %d%d%f",&v1,&v2,&w);	//����һ���������Ķ����Լ�Ȩֵ 
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		G.arcs[x][y].adj = w;
	}
	return G;
}

int LocateVex(MGrap G,int v){
	int i=0;
	while(G.vexs[i]!=v)
		i++;
	return i;
} 

void vist(MGrap G){
	int times = 0;
	printf("******************\n"); 
	for(int i = 0;i<G.vexnum;i++)
		for(int j = 0;j<G.vexnum;j++)
			{
				printf("%d ",G.arcs[i][j].adj);
				times++;
				if(times%G.vexnum == 0)
					printf("\n");
			}
	printf("******************\n");
}

void Dijkstra(MGrap G,int v,int dist[],int path[]){
	int set[Max_Vertrx_Num];
	int min,u;
	//�Ը�������г�ʼ��
	for(int i = 0; i < G.vexnum; i++)
	{
		dist[i] = G.arcs[v][i].adj;
		set[i] = 0;
		if(G.arcs[v][i].adj < INF)
			path[i] = v;
		else
			path[i] = -1;
	}  
	set[v] = 1;
	path[v] = -1;
	dist[v] = 0;
	//��ʼ������
	for(int i = 0; i<G.vexnum - 1; i++)
	{
		min = INF;	
		for(int j = 0; j < G.vexnum; j++)
			if(set[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		set[u] = 1;
		for( int j =0; j < G.vexnum; j++)
		{
			if(set[j] == 0 && dist[u] + G.arcs[u][j].adj < dist[j])
			{
				dist[j] = dist[u] + G.arcs[u][j].adj;
				path[j] = u;
			}
		}
	} 
	for(int i = 0; i < G.vexnum; i++)
		printf("%d ",set[i]);
} 

void Floyd(MGrap G,int Path[][Max_Vertrx_Num],int A[][Max_Vertrx_Num]){
	//������A[][]��Pat[][]���г�ʼ��
		for(int i = 0; i < G.vexnum; i++)
			for(int j = 0; j < G.vexnum; j++)
				{
					A[i][j] = G.arcs[i][j].adj;
					Path[i][j] = -1; 
				} 
	//��kΪ�м������ж����(i,j)���м����޸� 
		for(int k = 0; k < G.vexnum; k++)
			for(int i = 0; i < G.vexnum; i++)
				for(int j = 0; j < G.vexnum; j++)
					if(A[i][j] > A[i][k] + A[k][j])
					{
						A[i][j] = A[i][k] + A[k][j];
						Path[i][j] = k;
					}
}
