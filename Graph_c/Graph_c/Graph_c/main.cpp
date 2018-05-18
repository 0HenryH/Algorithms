#pragma once
#include<iostream>
#include<iomanip>
//#include"LinkQueue.h"
using namespace std;

#define OVERFLOW -2
#define OK 1
#define FALSE 0
#define ERROR 0
#define NULL 0
typedef int status;

#define INFINITY 1000
#define MAX_VERTEX_NUM 20
typedef enum { DG = 1, DN = 2, UDG = 3, UDN = 4 } GraphKind;
//typedef int GraphKind;
typedef int VRType;
typedef char InfoType;

struct ArcCell
{
	VRType adj;//
	InfoType *info;
}; //ArcCell,AdjMatrix
typedef ArcCell AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef char VErtexType;
struct MGraph
{
	VErtexType vexs[MAX_VERTEX_NUM]; //�������� ������Ϣ
	AdjMatrix arcs;
	int vexnum, arcnum;
	GraphKind kind;
};

int Locate(MGraph G, VErtexType v)
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (v == G.vexs[i]) return i;
	}
	//return -1;
} //�������Ҳ����ڵ�����

status CreateUDN(MGraph &G)
{
	VRType w;
	VErtexType v1, v2;
	int i, j, k;
	cout << "������-������" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "���붥��" << endl;
	for (i = 0; i < G.vexnum; i++) cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { INFINITY, NULL };
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "v1<char>" << endl;
		cin >> v1;
		cout << "v2<char>" << endl;
		cin >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		cout << "����Ȩ��" << endl;
		cin >> w;
		G.arcs[i][j].adj = w;
		//�����Ϣʡ��
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateDN(MGraph &G)
{
	VRType w;
	VErtexType v1, v2;
	int i, j, k;
	cout << "������-������" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "���붥��" << endl;
	for (i = 0; i < G.vexnum; i++) cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { INFINITY, NULL };
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "��ʼ��v1<char>" << endl;
		cin >> v1;
		cout << "�յ�v2<char>" << endl;
		cin >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		cout << "����Ȩ��" << endl;
		cin >> w;
		G.arcs[i][j].adj = w;
		//�����Ϣʡ��
		//G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateDG(MGraph &G)
{
	VRType w = 1;
	VErtexType v1, v2;
	int i, j, k;
	cout << "������-������" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "���붥��" << endl;
	for (i = 0; i < G.vexnum; i++) cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { 0, NULL };
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "��ʼ��v1<char>" << endl;
		cin >> v1;
		cout << "�յ�v2<char>" << endl;
		cin >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		//cout << "����Ȩ��" << endl;
		//cin >> w;
		G.arcs[i][j].adj = w;
		//�����Ϣʡ��
		//G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateUDG(MGraph &G)
{
	VRType w = 1;
	VErtexType v1, v2;
	int i, j, k;
	cout << "������-������" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "���붥��" << endl;
	for (i = 0; i < G.vexnum; i++) cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { 0, NULL };
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "v1<char>" << endl;
		cin >> v1;
		cout << "v2<char>" << endl;
		cin >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		//cout << "����Ȩ��" << endl;
		//cin >> w;
		G.arcs[i][j].adj = w;
		//�����Ϣʡ��
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateGraph(MGraph &G)
{
	int Kind;
	cout << "����ͼ������" << endl;
	cout << "1-����ͼ 2-������ 3-����ͼ 4-������" << endl;
	//cin >> G.kind;
	cin >> Kind;
	G.kind = (GraphKind)(Kind);
	switch (G.kind)
	{
	case DG: return CreateDG(G);
	case DN: return CreateDN(G);
	case UDG: return CreateUDG(G);
	case UDN: return CreateUDN(G);
	default: return ERROR;
	}
}

/*����*/

bool visited[MAX_VERTEX_NUM];   // ���ʱ�־����
status(*VisitFunc)(int v, const MGraph &G);    // ��������

status Visit(int v, const MGraph &G)
{
	cout << G.vexs[v];
	return OK;
}
int FirstAdjVex_N(const MGraph &G, int v) //��
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.arcs[v][i].adj != INFINITY) return i;
	}
	return -1;
}

int NextAdjVex_N(const MGraph &G, int v, int w)
{
	int i;
	for (i = w + 1; i < G.vexnum; i++)
	{
		if (G.arcs[v][i].adj != INFINITY) return i;
	}
	return -1;
}

void DFS_N(const MGraph &G, int v) {  // �㷨7.5
	// �ӵ�v����������ݹ��������ȱ���ͼG��
	int w;
	visited[v] = true;   VisitFunc(v, G);  // ���ʵ�v������
	for (w = FirstAdjVex_N(G, v); w != -1; w = NextAdjVex_N(G, v, w)) //��һ��û�˾�д��-1
	if (!visited[w])   // ��v����δ���ʵ��ڽӶ���w�ݹ����DFS
		DFS_N(G, w);
}
void DFSTraverse_N(const MGraph &G, status(*Visit)(int v, const MGraph &G)) {  // �㷨7.4
	// ��ͼG��������ȱ�����
	int v;
	VisitFunc = Visit; // ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ�����
	for (v = 0; v<G.vexnum; ++v) visited[v] = false; // ���ʱ�־�����ʼ��
	for (v = 0; v<G.vexnum; ++v)
	if (!visited[v]) DFS_N(G, v);         // ����δ���ʵĶ������DFS
}

int FirstAdjVex_G(const MGraph &G, int v) //��
{
	int i;
	for (i = 0; i < G.vexnum; i++)
	{
		if (G.arcs[v][i].adj == 1) return i;
	}
	return -1;
}

int NextAdjVex_G(const MGraph &G, int v, int w)
{
	int i;
	for (i = w + 1; i < G.vexnum; i++)
	{
		if (G.arcs[v][i].adj == 1) return i;
	}
	return -1;
}

void DFS_G(const MGraph &G, int v) {  // �㷨7.5
	// �ӵ�v����������ݹ��������ȱ���ͼG��
	int w;
	visited[v] = true;   VisitFunc(v, G);  // ���ʵ�v������
	for (w = FirstAdjVex_G(G, v); w != -1; w = NextAdjVex_G(G, v, w)) //��һ��û�˾�д��-1
	if (!visited[w])   // ��v����δ���ʵ��ڽӶ���w�ݹ����DFS
		DFS_G(G, w);
}

void DFSTraverse_G(const MGraph &G, status(*Visit)(int v, const MGraph &G)) {  // �㷨7.4
	// ��ͼG��������ȱ�����
	int v;
	VisitFunc = Visit; // ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ�����
	for (v = 0; v<G.vexnum; ++v) visited[v] = false; // ���ʱ�־�����ʼ��
	for (v = 0; v<G.vexnum; ++v)
	if (!visited[v]) DFS_G(G, v);         // ����δ���ʵĶ������DFS
}

/*
void BFSTraverse_G(MGraph G)
{
int v, u, w;
for (v = 0; v<G.vexnum; ++v) visited[v] = FALSE; //��ʼ����־
LinkQueue<int> Q; // �ÿյĸ�������Q
for (v = 0; v < G.vexnum; ++v)
{
if (!visited[v])
{ // v ��δ����
visited[v] = true;
Visit(v, G); // ����v
Q.EnQueue(v); // v�����
while (!Q.isEmpty())
{
Q.DeQueue(u); // ��ͷԪ�س��Ӳ���Ϊu
for (w = FirstAdjVex_G(G, u); w >= 0; w = NextAdjVex_G(G, u, w))
{
if (!visited[w])
{ // wΪu����δ�����ʵ��ڽӶ���
visited[w] = true; Visit(w, G); // ����w
Q.EnQueue(w); // ���ʵĶ���w�����
} // if
}
} // while
} // if
}
} // BFSTraverse
*/
/*
void BFSTraverse_N(MGraph G)
{
int v, u, w;
for (v = 0; v<G.vexnum; ++v) visited[v] = FALSE; //��ʼ����־
LinkQueue<int> Q; // �ÿյĸ�������Q
for (v = 0; v < G.vexnum; ++v)
{
if (!visited[v])
{ // v ��δ����
visited[v] = true;
Visit(v, G); // ����v
Q.EnQueue(v); // v�����
while (!Q.isEmpty())
{
Q.DeQueue(u); // ��ͷԪ�س��Ӳ���Ϊu
for (w = FirstAdjVex_N(G, u); w >= 0; w = NextAdjVex_N(G, u, w))
{
if (!visited[w])
{ // wΪu����δ�����ʵ��ڽӶ���
visited[w] = true; Visit(w, G); // ����w
Q.EnQueue(w); // ���ʵĶ���w�����
} // if
}
} // while
} // if
}
} // BFSTraverse
*/

void displayGraph(MGraph G)
{
	cout << "===============================" << endl;
	cout << "Matrix : " << endl;
	cout << "===============================" << endl;
	int i, j;
	for (i = 0; i < G.vexnum; i++)
	{
		for (j = 0; j < G.vexnum; j++)
		{
			cout << setw(6) << G.arcs[i][j].adj;
		}
		cout << endl;
	}
	cout << "===============================" << endl;
}

/*Prim Algorithm*/
struct record
{
	VErtexType adjvex; //U���еĶ���
	VRType lowcost; //�ߵ�Ȩֵ
};
typedef record closedge[MAX_VERTEX_NUM];

//�ڸ�������������С��Ȩ
int min(const closedge &edge,const int &vexnum)
{
	int minimum=INFINITY;
	int result;
	int i;
	for (i = 0; i < vexnum; i++)
	{
		if (edge[i].lowcost == 0) continue;
		else if (edge[i].lowcost < minimum) { result = i; minimum = edge[i].lowcost; }
	}
	return result;
	//���������ȨֵΪ0�ᱻ����
}

void Prim(const MGraph &G, VErtexType v)
{
	closedge edge;
	int i, j, k;
	k = Locate(G, v);
	for (j = 0; j < G.vexnum; j++)
	{
		if (j != k) { edge[j].adjvex = v;  edge[j].lowcost = G.arcs[k][j].adj; } 
		//��ʼ��Ϊ�������������Ȩ��
	}
	edge[k].lowcost = 0;
	for (i = 1; i < G.vexnum; i++)
	{
		k = min(edge,G.vexnum);
		cout << edge[k].adjvex << "->" << G.vexs[k] << endl;
		edge[k].lowcost = 0;//�¶��㲢��U
		for (j = 0; j < G.vexnum; j++)
		{
			if (G.arcs[k][j].adj < edge[j].lowcost)
			{
				edge[j].adjvex = G.vexs[k];
				edge[j].lowcost = G.arcs[k][j].adj;
			}//if
		}//for
	}//for
}




int main()
{
	MGraph G;
	CreateGraph(G);
	//displayGraph(G);
	/*
	cout << "������ȱ��� : " << endl;
	if (G.kind == 1 || G.kind == 3) DFSTraverse_G(G, Visit);
	else DFSTraverse_N(G, Visit);
	cout << endl;
	*/
	VErtexType a = 'a';
	Prim(G, a);
	system("pause");
	return 0;
}