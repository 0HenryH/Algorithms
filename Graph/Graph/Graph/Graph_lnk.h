#pragma once
#include "Graph.h"
typedef int Wtype;
struct ArcNode
{
	int adjvex;
	ArcNode *nextarc;
	InfoType *info;
	Wtype weight;
};

template<class vertextype>
struct Vnode
{
	vertextype data;
	ArcNode * firstarc; //指向该节点的第一个邻接弧
};

//template<class vertextype>
//typedef Vnode<vertextype> adjlist[MAX_VERTEX_NUM];

template<class vertextype>
class Graph_lnk :
	public Graph<vertextype>
{
public:
	Graph_lnk():Graph()
	{

	}
	//~Graph_lnk();
	virtual int Location(vertextype v);
	virtual status Visit(int v);
	virtual status depthTraverse();
	virtual status DFS(int v);
	virtual status breadthTraverse();
	virtual vertextype get_vex(int i);
protected:
	Vnode<vertextype> VErtices[MAX_VERTEX_NUM];
};
/*template<class vertextype>
Graph_lnk<vertextype>::Graph_lnk():Graph()
{

}*/

template<class vertextype>
status Graph_lnk<vertextype>::Visit(int v)
{
	cout << VErtices[v].data;
	return OK;
}

template<class vertextype>
int Graph_lnk<vertextype>::Location(vertextype v)
{
	int i;
	for (i = 0; i < vexnum; i++)
	{
		if (VErtices[i].data == v) return i;
	}
	//else return -1;
}

template<class vertextype>
status Graph_lnk<vertextype>::DFS(int v)
{
	ArcNode * p=VErtices[v].firstarc;
	Visit(v);
	visited[v] = true;
	while (p)
	{
		if (!visited[p->adjvex]) DFS(p->adjvex);
		p = p->nextarc;
	}
	return OK;
}

template<class vertextype>
status Graph_lnk<vertextype>::depthTraverse()
{
	int i;
	for (i = 0; i < vexnum; i++) visited[i] = FALSE;
	for (i = 0; i < vexnum; i++)
	{
		if (!visited[i]) DFS(i);
	}
	return OK;
}

template<class vertextype>
status Graph_lnk<vertextype>::breadthTraverse()
{
	ArcNode * p;
	Vnode<vertextype> v;
	int i;
	for (i = 0; i < vexnum; i++) visited[i] = FALSE;
	LinkQueue<Vnode<vertextype>> Q;
	for (i = 0; i < vexnum; i++)
	{
		if (!visited[i])
		{
			Visit(i);
			visited[i] = true;
			Q.EnQueue(VErtices[i]);
			while (!Q.isEmpty())
			{
				Q.DeQueue(v);
				p = v.firstarc;
				while (p)
				{
					if (!visited[p->adjvex])
					{
						Visit(p->adjvex);
						visited[p->adjvex] = true;
						Q.EnQueue(VErtices[p->adjvex]);
					}//if
					p = p->nextarc;
				}//while
			}//while
		}//if
	}//for
	return OK;
}//BFSTraverse

template<class vertextype>
vertextype Graph_lnk<vertextype>::get_vex(int i)
{
	return VErtices[i].data;
}