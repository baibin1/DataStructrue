/*
*��С����������������ķ��prim���㷨�Ϳ�³˹������kruskal���㷨 
*����ʱ�䣺2022��11��6��15��22��
*Author��bjb
*����޸�ʱ�䣺2022��11��6��19��41�� 
*/
#include <stdio.h>
#include <stdlib.h> 
#define INF 100
#define Max_Vertrx_Num 20				//��󶥵����
#define INFINITY 1000					//�޴�·����ʾ1000 
typedef struct ArcCell{
	int adj;
	char *info;
}ArcCell,AdjMatrix[Max_Vertrx_Num][Max_Vertrx_Num];
typedef struct MGrap{
	int vexs[Max_Vertrx_Num];			//��������
	AdjMatrix arcs;						//�ڽӾ���
	int vexnum,arcnum;					//ͼ��ǰ�Ķ������ͻ��� 
}MGrap; 
typedef struct {
	int a,b;							//a,bΪһ���ߵ��������� 
	int w;								//�ߵ�Ȩֵ 
}Road;

MGrap CreateUDN(MGrap G); 				//�����ڽӾ���ķ�������������G
int LocateVex(MGrap G,int v);			//ȷ��Ԫ��v��ͼG�е�λ�� 
void vist(MGrap G);						//����ͼG
void Prim(MGrap G,int v0);				//Prim�㷨������С������ 
Road road[Max_Vertrx_Num];
void insert(Road road[],int N);
int v[Max_Vertrx_Num];					//���岢�鼯����
int getRoot(int a);						//���鼯���Ҹ���� 
void sort(Road road[], int E);			//��road�����е�E���߰���Ȩֵ��С���� 
void Kruskal(MGrap G,Road road[]);		//Kruskal�㷨������С������ 

int main(){
	Road road[Max_Vertrx_Num];
	MGrap G;
	G = CreateUDN(G);
	vist(G);
	int v0 = 0; 
	Prim(G,v0);
	printf("\n");
	int E = G.arcnum;
	insert(road,E);
	sort(road,E);
	printf("\n");
//	int a,b;
//	for(int i = 0; i < E; i++)
//		v[i] = i;
//	a = getRoot(road[0].w);
//	b = getRoot(road[1].w);
//	printf("\n%d %d ",a,b);
//	sort(road,E);
	Kruskal(G,road);
	
	
	return 0;
} 

MGrap CreateUDN(MGrap G){
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
				G.arcs[i][j].adj = INFINITY;
				G.arcs[i][j].info = NULL;
			}
	int v1,v2;
	float w;
	printf("������һ���������Ķ����Լ�Ȩֵ��\n");	
	for(int k = 0;k<G.arcnum;k++)	//�����ڽӾ���
	{	
		printf("�������%d���ߵĶ����Լ�Ȩֵ��\n",k+1);
		scanf(" %d%d%f",&v1,&v2,&w);	//����һ���������Ķ����Լ�Ȩֵ 
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
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

void Prim(MGrap G,int v0){
	int lowcost[Max_Vertrx_Num],vset[Max_Vertrx_Num], v;
	int i,j,k,min,sum;
	v = v0;
	for( i = 0; i < G.vexnum ; i++)
	{
		lowcost[i] = G.arcs[v0][i].adj;
		vset[i] = 0;
	}
	vset[v0] = 1;
	sum = 0;
	for( i = 0; i < G.vexnum -1 ; i++)
	{
		min = INF;
		for( j = 0; j < G.vexnum ; j++)
			if( vset[j] == 0 && lowcost[j] < min )
				{
					min = lowcost[j];
					k = j;
				}
		vset[k] = 1;
		v = k;
		sum = sum + min;
		printf("%d ",sum);
		for( j = 0; j < G.vexnum ; j++)
			if(vset[j] == 0 && G.arcs[v][j].adj < lowcost[j] )
				lowcost[j] = G.arcs[v][j].adj; 
	}
} 

int getRoot( int a){
	while(a!=v[a])
		a = v[a];
	return a;
} 

void Kruskal(MGrap G,Road road[]){
	int i,j;
	int N,E,a,b,sum;
	N = G.vexnum;
	E = G.arcnum;
	sum = 0;
	for(i = 0; i < N; i++)
		v[i] = i;
	sort(road,E);
	for( j = 0; j < N; j++)
	{
		a = getRoot(road[j].a);
		b = getRoot(road[j].b);
		if(a!=b)
		{
			v[a] = b;
			sum = sum + road[j].w;
			printf("%d ",sum);
		} 
	}
}

void sort(Road road[],int E){
	int t;
	for(int i = 0; i < E-1 ; i++)
		for(int j = 0; j < E -1 - i ; j++)
			if(road[j].w > road[j+1].w)
				{
					t = road[j].w;
					road[j].w = road[j+1].w;
					road[j+1].w = t;
				}
				printf("������Ϊ��");
				for(int i = 0; i < E; i++)
					printf("%d ",road[i].w);
				printf("\n");
} 

void insert(Road road[],int N){
	int v1,v2;
	float w;
	printf("������һ���������Ķ����Լ�Ȩֵ��\n");	
	for(int k = 0;k<N;k++)
	{	
		printf("�������%d���ߵĶ����Լ�Ȩֵ��\n",k+1);
		scanf(" %d%d%f",&v1,&v2,&w);	//����һ���������Ķ����Լ�Ȩֵ 
//		int x = LocateVex(G,v1);
//		int y = LocateVex(G,v2);
		road[k].a = v1;
		road[k].b = v2;
		road[k].w = w;
		printf("%d \n",road[k].w);
	}
}
