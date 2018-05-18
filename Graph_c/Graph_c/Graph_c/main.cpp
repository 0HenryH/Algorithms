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
	VErtexType vexs[MAX_VERTEX_NUM]; //顶点向量 顶点信息
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
} //待补充找不到节点的情况

status CreateUDN(MGraph &G)
{
	VRType w;
	VErtexType v1, v2;
	int i, j, k;
	cout << "顶点数-弧个数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "输入顶点" << endl;
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
		cout << "输入权重" << endl;
		cin >> w;
		G.arcs[i][j].adj = w;
		//相关信息省略
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateDN(MGraph &G)
{
	VRType w;
	VErtexType v1, v2;
	int i, j, k;
	cout << "顶点数-弧个数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "输入顶点" << endl;
	for (i = 0; i < G.vexnum; i++) cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { INFINITY, NULL };
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "起始点v1<char>" << endl;
		cin >> v1;
		cout << "终点v2<char>" << endl;
		cin >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		cout << "输入权重" << endl;
		cin >> w;
		G.arcs[i][j].adj = w;
		//相关信息省略
		//G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateDG(MGraph &G)
{
	VRType w = 1;
	VErtexType v1, v2;
	int i, j, k;
	cout << "顶点数-弧个数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "输入顶点" << endl;
	for (i = 0; i < G.vexnum; i++) cin >> G.vexs[i];
	for (i = 0; i < G.vexnum; i++)
	for (j = 0; j < G.vexnum; j++)
		G.arcs[i][j] = { 0, NULL };
	for (k = 0; k < G.arcnum; k++)
	{
		cout << "起始点v1<char>" << endl;
		cin >> v1;
		cout << "终点v2<char>" << endl;
		cin >> v2;
		i = Locate(G, v1); j = Locate(G, v2);
		//cout << "输入权重" << endl;
		//cin >> w;
		G.arcs[i][j].adj = w;
		//相关信息省略
		//G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateUDG(MGraph &G)
{
	VRType w = 1;
	VErtexType v1, v2;
	int i, j, k;
	cout << "顶点数-弧个数" << endl;
	cin >> G.vexnum >> G.arcnum;
	cout << "输入顶点" << endl;
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
		//cout << "输入权重" << endl;
		//cin >> w;
		G.arcs[i][j].adj = w;
		//相关信息省略
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

status CreateGraph(MGraph &G)
{
	int Kind;
	cout << "输入图的类型" << endl;
	cout << "1-有向图 2-有向网 3-无向图 4-无向网" << endl;
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

/*遍历*/

bool visited[MAX_VERTEX_NUM];   // 访问标志数组
status(*VisitFunc)(int v, const MGraph &G);    // 函数变量

status Visit(int v, const MGraph &G)
{
	cout << G.vexs[v];
	return OK;
}
int FirstAdjVex_N(const MGraph &G, int v) //网
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

void DFS_N(const MGraph &G, int v) {  // 算法7.5
	// 从第v个顶点出发递归地深度优先遍历图G。
	int w;
	visited[v] = true;   VisitFunc(v, G);  // 访问第v个顶点
	for (w = FirstAdjVex_N(G, v); w != -1; w = NextAdjVex_N(G, v, w)) //下一个没了就写成-1
	if (!visited[w])   // 对v的尚未访问的邻接顶点w递归调用DFS
		DFS_N(G, w);
}
void DFSTraverse_N(const MGraph &G, status(*Visit)(int v, const MGraph &G)) {  // 算法7.4
	// 对图G作深度优先遍历。
	int v;
	VisitFunc = Visit; // 使用全局变量VisitFunc，使DFS不必设函数指针参数
	for (v = 0; v<G.vexnum; ++v) visited[v] = false; // 访问标志数组初始化
	for (v = 0; v<G.vexnum; ++v)
	if (!visited[v]) DFS_N(G, v);         // 对尚未访问的顶点调用DFS
}

int FirstAdjVex_G(const MGraph &G, int v) //网
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

void DFS_G(const MGraph &G, int v) {  // 算法7.5
	// 从第v个顶点出发递归地深度优先遍历图G。
	int w;
	visited[v] = true;   VisitFunc(v, G);  // 访问第v个顶点
	for (w = FirstAdjVex_G(G, v); w != -1; w = NextAdjVex_G(G, v, w)) //下一个没了就写成-1
	if (!visited[w])   // 对v的尚未访问的邻接顶点w递归调用DFS
		DFS_G(G, w);
}

void DFSTraverse_G(const MGraph &G, status(*Visit)(int v, const MGraph &G)) {  // 算法7.4
	// 对图G作深度优先遍历。
	int v;
	VisitFunc = Visit; // 使用全局变量VisitFunc，使DFS不必设函数指针参数
	for (v = 0; v<G.vexnum; ++v) visited[v] = false; // 访问标志数组初始化
	for (v = 0; v<G.vexnum; ++v)
	if (!visited[v]) DFS_G(G, v);         // 对尚未访问的顶点调用DFS
}

/*
void BFSTraverse_G(MGraph G)
{
int v, u, w;
for (v = 0; v<G.vexnum; ++v) visited[v] = FALSE; //初始化标志
LinkQueue<int> Q; // 置空的辅助队列Q
for (v = 0; v < G.vexnum; ++v)
{
if (!visited[v])
{ // v 尚未访问
visited[v] = true;
Visit(v, G); // 访问v
Q.EnQueue(v); // v入队列
while (!Q.isEmpty())
{
Q.DeQueue(u); // 队头元素出队并置为u
for (w = FirstAdjVex_G(G, u); w >= 0; w = NextAdjVex_G(G, u, w))
{
if (!visited[w])
{ // w为u的尚未被访问的邻接顶点
visited[w] = true; Visit(w, G); // 访问w
Q.EnQueue(w); // 访问的顶点w入队列
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
for (v = 0; v<G.vexnum; ++v) visited[v] = FALSE; //初始化标志
LinkQueue<int> Q; // 置空的辅助队列Q
for (v = 0; v < G.vexnum; ++v)
{
if (!visited[v])
{ // v 尚未访问
visited[v] = true;
Visit(v, G); // 访问v
Q.EnQueue(v); // v入队列
while (!Q.isEmpty())
{
Q.DeQueue(u); // 队头元素出队并置为u
for (w = FirstAdjVex_N(G, u); w >= 0; w = NextAdjVex_N(G, u, w))
{
if (!visited[w])
{ // w为u的尚未被访问的邻接顶点
visited[w] = true; Visit(w, G); // 访问w
Q.EnQueue(w); // 访问的顶点w入队列
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
	VErtexType adjvex; //U集中的顶点
	VRType lowcost; //边的权值
};
typedef record closedge[MAX_VERTEX_NUM];

//在辅助数组中找最小的权
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
	//如果本身有权值为0会被忽略
}

void Prim(const MGraph &G, VErtexType v)
{
	closedge edge;
	int i, j, k;
	k = Locate(G, v);
	for (j = 0; j < G.vexnum; j++)
	{
		if (j != k) { edge[j].adjvex = v;  edge[j].lowcost = G.arcs[k][j].adj; } 
		//初始化为根到各个顶点的权重
	}
	edge[k].lowcost = 0;
	for (i = 1; i < G.vexnum; i++)
	{
		k = min(edge,G.vexnum);
		cout << edge[k].adjvex << "->" << G.vexs[k] << endl;
		edge[k].lowcost = 0;//新顶点并入U
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
	cout << "深度优先遍历 : " << endl;
	if (G.kind == 1 || G.kind == 3) DFSTraverse_G(G, Visit);
	else DFSTraverse_N(G, Visit);
	cout << endl;
	*/
	VErtexType a = 'a';
	Prim(G, a);
	system("pause");
	return 0;
}