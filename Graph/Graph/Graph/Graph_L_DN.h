#pragma once
#include "Graph_lnk.h"


template<class vertextype>
class Graph_L_DN :
	public Graph_lnk<vertextype>
{
public:
	Graph_L_DN(int vexn, int arcn);
	//~Graph_L_DN();	
};
template<class vertextype>
Graph_L_DN<vertextype>::Graph_L_DN(int vexn, int arcn)
{
	ArcNode * s;
	int i;
	vertextype v1, v2;
	kind = DN;
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
		cin >> s->weight;
		s->adjvex = Location(v2);
		s->nextarc = VErtices[Location(v1)].firstarc;
		VErtices[Location(v1)].firstarc = s;
		//s.adjvex = Location(v2);
		//s.nextarc = VErtices[Location(v1)].firstarc;
		//VErtices[Location(v1)].firstarc = s;
	}
}
