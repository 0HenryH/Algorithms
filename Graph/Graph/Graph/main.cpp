#include<iostream>
#include"Graph_L_UDG.h"
#include"Graph_L_DG.h"
#include"Graph_L_UDN.h"
#include"Graph_L_DN.h"
using namespace std;

status Creategraph()
{
	int vexn, arcn;
	int Kind;
	cout << "输入图的类型" << endl;
	cout << "1-有向图 2-有向网 3-无向图 4-无向网" << endl;
	//cin >> G.kind;
	cin >> Kind;
	cout << "输入顶点数和边数" << endl;
	cin >> vexn >> arcn;
	switch (Kind)
	{
	case 1: 
	{
		Graph_L_DG<char> G(vexn, arcn);
		G.depthTraverse();
		cout << endl;
		G.breadthTraverse();
		break;
	}
	case 2: 
	{
		Graph_L_DN<char> G(vexn, arcn);
		G.depthTraverse();
		cout << endl;
		G.breadthTraverse();
		break;
	}
	case 3: 
	{
		Graph_L_UDG<char> G(vexn, arcn);
		G.depthTraverse();
		cout << endl;
		G.breadthTraverse();
		break;
	}
	case 4: 
	{
		Graph_L_UDN<char> G(vexn, arcn);
		G.depthTraverse();
		cout << endl;
		G.breadthTraverse();
		break;
	}
	default: return ERROR;
	}
	return OK;
}
int main()
{
	Creategraph();
	system("pause");
	return 0;
}