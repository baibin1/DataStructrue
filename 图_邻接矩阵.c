//----------ͼ���ڽӾ����ʾ����------------ 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define Max_Vertrx_Num 20				//��󶥵����
#define INFINITY 0						//�޴�·����ʾ0 
typedef enum {DG,DN,UDG,UDN} GraphKind;	//{����ͼ��������������ͼ��������}
typedef struct ArcCell{
	int adj;
	char *info;
}ArcCell,AdjMatrix[Max_Vertrx_Num][Max_Vertrx_Num];
typedef struct MGrap{
	int vexs[Max_Vertrx_Num];			//��������
	AdjMatrix arcs;						//�ڽӾ���
	int vexnum,arcnum;					//ͼ��ǰ�Ķ������ͻ��� 
	int kind;							//ͼ������
}MGrap; 

MGrap CreateGraph(MGrap G);				//�����ڽӾ���ķ�������ͼG
MGrap CreateDG(MGrap G); 				//�����ڽӾ���ķ�����������ͼG
MGrap CreateDN(MGrap G); 				//�����ڽӾ���ķ�������������G
MGrap CreateUDG(MGrap G); 				//�����ڽӾ���ķ�����������ͼG
MGrap CreateUDN(MGrap G); 				//�����ڽӾ���ķ�������������G
MGrap GG();								//��������
int LocateVex(MGrap G,int v);			//ȷ��Ԫ��v��ͼG�е�λ�� 
void vist(MGrap G);						//����ͼG

int main(){
	MGrap G;
	G = CreateGraph(G);					//����ͼ G
	vist(G);							//����ͼ G 
	return 0;
} 

MGrap CreateGraph(MGrap G){
	//�������飨�ڽӾ��󣩱�ʾ��������ͼG
	printf("��������Ҫ�����ͼ�����ͣ�\n1������ͼDG\n2��������DN\n3������ͼUDG\n4��������UDN\n");
	scanf("%d",&G.kind);
	switch(G.kind){
		case 1: return CreateDG(G);			//��������ͼ
		case 2: return CreateDN(G);			//����������
		case 3: return CreateUDG(G);		//��������ͼ
		case 4: return CreateUDN(G);		//����������
		default : return GG();
	}
}

MGrap CreateDG(MGrap G){
	//�����ڽӾ���ķ�����������ͼG
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
	printf("������һ���������Ķ��㣺\n");	
	for(int k = 0;k<G.arcnum;k++)	//�����ڽӾ���
	{	
		printf("�������%d���ߵĶ���(ע�ⷽ��)��\n",k+1);
		scanf(" %d%d",&v1,&v2);	//����һ���������Ķ���
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		G.arcs[x][y].adj = 1;
	}
	return G;
}
 
MGrap CreateUDG(MGrap G){
	//�����ڽӾ���ķ�����������ͼG
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
	printf("������һ���������Ķ��㣺\n");	
	for(int k = 0;k<G.arcnum;k++)	//�����ڽӾ���
	{	
		printf("�������%d���ߵĶ��㣺\n",k+1);
		scanf(" %d%d",&v1,&v2);	//����һ���������Ķ���
		int x = LocateVex(G,v1);
		int y = LocateVex(G,v2);
		G.arcs[x][y].adj = 1;
		G.arcs[y][x] = G.arcs[x][y];
	}
	return G;
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
		G.arcs[x][y].adj = w;
		G.arcs[y][x] = G.arcs[x][y];
	}
	return G;
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

MGrap GG(){
	MGrap G;
	printf("����ȷ���룡\n");
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
