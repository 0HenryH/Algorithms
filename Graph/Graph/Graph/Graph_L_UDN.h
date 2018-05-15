#pragma once
#include "Graph_lnk.h"


template<class vertextype>
class Graph_L_UDN :
	public Graph_lnk<vertextype>
{
public:
	Graph_L_UDN(int vexn, int arcn);
	Graph_L_UDN(const Graph_L_UDN & G);
	//~Graph_L_UDN();	
};
template<class vertextype>
Graph_L_UDN<vertextype>::Graph_L_UDN(int vexn, int arcn)
{
	ArcNode * s;
	int i,w;
	vertextype v1, v2;
	kind = UDN;
	vexnum = vexn;
	arcnum = arcn;
	cout << "输入顶点" << endl;
	for (i = 0; i < vexn; i++)
	{
		cin >> VErtices[i].data;
		VErtices[i].firstarc = NULL;
	}
	cout << "输入边" << endl;
	for (i = 0; i < arcn; i++)
	{
		s = new ArcNode;
		cout << "v1<char>" << endl;
		cin >> v1;
		cout << "v2<char>" << endl;
		cin >> v2;
		cout << "权重" << endl;
		cin>>w;
		s->weight = w;
		s->adjvex = Location(v2);
		s->nextarc = VErtices[Location(v1)].firstarc;
		VErtices[Location(v1)].firstarc = s;
		s = new ArcNode;
		s->weight = w;
		s->adjvex = Location(v1);
		s->nextarc = VErtices[Location(v2)].firstarc;
		VErtices[Location(v2)].firstarc = s;
	}
}

template<class vertextype>
Graph_L_UDN<vertextype>::Graph_L_UDN(const Graph_L_UDN<vertextype> &G)
{
	int i;
	this->arcnum = G.get_arcnum();
	this->vexnum = G.get_vexnum();
	this->kind = UDN;
	for (i = 0; i < this->vexnum; i++) this->VErtices[i].data = G.get_vex(i);
}