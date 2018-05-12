#pragma once
#include "Graph_lnk.h"
template<class vertextype>
class Graph_L_UDG :
	public Graph_lnk<vertextype>
{
public:
	Graph_L_UDG(int vexn,int arcn);
	//~Graph_L_UDG();	
};
template<class vertextype>
Graph_L_UDG<vertextype>::Graph_L_UDG(int vexn, int arcn)
{
	ArcNode * s;
	int i;
	vertextype v1,v2;
	kind = UDG;
	vexnum = vexn;
	arcnum = arcn;
	cout << "ÊäÈë¶¥µã" << endl;
	for (i =0 ; i < vexn; i++)
	{
		cin >> VErtices[i].data;
		VErtices[i].firstarc = NULL;
	}
	cout << "ÊäÈë±ß" << endl;
	for (i = 0; i < arcn; i++)
	{
		s = new ArcNode;
		cout << "v1<char>" << endl;
		cin >> v1;
		cout << "v2<char>" << endl;
		cin >> v2;
		s->weight = 1;
		s->adjvex = Location(v2);
		s->nextarc = VErtices[Location(v1)].firstarc;
		VErtices[Location(v1)].firstarc = s;
		s = new ArcNode;
		s->weight = 1;
		s->adjvex = Location(v1);
		s->nextarc = VErtices[Location(v2)].firstarc;
		VErtices[Location(v2)].firstarc = s;
	}
}

