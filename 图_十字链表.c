/*
*--------����ͼ��ʮ������洢��ʾ----------
*ʮ������������ͼ����һ����ʽ�洢�ṹ
*���Կ����ǽ�����ͼ���ڽӱ�����ڽӱ��������õ���һ�ֽṹ
*������2022��11��2��17��05��
*Author��bjb 
*/ 
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>
#define MAX_VERTEX_NUM 20 
typedef struct ArcBox{
	int tailvex,headvex;				//�û���β��ͷ�����λ��
	struct ArcBox *hlink,*tlink;		//Ϊ��Ϊ��ͷ��ͬ�ͻ�β��ͬ�Ļ������� 
	char *info;							//�û������Ϣ��ָ�� 
}ArcBox;
typedef struct VexNode{
	int data;
	ArcBox *firstin,*firstout;			//�ֱ�ָ��ö����һ���뻡�ͳ��� 
}VexNode;
typedef struct{
	VexNode xlist[MAX_VERTEX_NUM];		//��ͷ����
	int vexnum,arcnum;					//����ͼ�ĵ�ǰ�������ͻ��� 
}OLGraph; 

OLGraph CreateDG(OLGraph G);			//��ʮ������洢��ʾ����������ͼG 
int LocateVex(OLGraph G,int v);			//ȷ��v��G�е�λ�� 

int main(){
	
	OLGraph G;
	G = CreateDG(G); 
	
	return 0;
}

OLGraph CreateDG(OLGraph G) {
	printf("������ͼ�Ķ�������\n");
	scanf("%d",&G.vexnum);
	printf("������ͼ�Ļ�����\n");
	scanf("%d",&G.arcnum);
	for(int i = 0;i<G.vexnum;i++){
		printf("�������%d����ͷ������ֵ��\n",i+1);
		scanf("%d",&G.xlist[i].data);	//�����ͷ����
		G.xlist[i].firstin = NULL;
		G.xlist[i].firstout = NULL;		//��ʼ��ָ�� 
	}
	for(int k = 0;k<G.arcnum;k++){		//�������������ʮ������ 
		int v1,v2;
		printf("�����%d������ʼ����յ㣺\n",k+1);
		scanf("%d%d",&v1,&v2);			//����һ������ʼ����յ�
		int x,y;
		x = LocateVex(G,v1);
		y = LocateVex(G,v2);			//ȷ��v1��v2��ͼG�е�λ��
		ArcBox* p = (ArcBox *)malloc(sizeof(ArcBox));
//		*p = {x,y,G.xlist[y].firstin,G.xlist[x].firstout,NULL}; 	//�Ի���㸳ֵ
		(*p).tailvex = x;
		(*p).headvex = y;
		(*p).hlink = G.xlist[y].firstin;
		(*p).tlink = G.xlist[x].firstout;
		(*p).info = NULL; 
		G.xlist[y].firstin = G.xlist[x].firstout = p;				//������뻡�ͳ�����ͷ�Ĳ��� 
	} 
	return G; 
}

int LocateVex(OLGraph G,int v){
	int i = 0;
	while(G.xlist[i].data != v)
		i++;
	return i;
} 
