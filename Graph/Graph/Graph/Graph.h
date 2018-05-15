#pragma once
#include<iostream>
#include"LinkQueue.h"
#include"adaptedQ.h"
#define OVERFLOW -2
#define OK 1
#define FALSE 0
#define ERROR 0
#define NULL 0
#define INFINITY 1000
#define MAX_VERTEX_NUM 20

using namespace std;

typedef int status;
typedef enum { DG = 1, DN = 2, UDG = 3, UDN = 4 } GraphKind;
//typedef int GraphKind;
typedef int VRType;
typedef char InfoType;

template<class vertextype>
class Graph
{
public:
	Graph()
	{

	}
	//~Graph();
	int get_vexnum();
	int get_arcnum();
	virtual int Location(vertextype v)=0;
	virtual status depthTraverse() = 0;
	virtual status DFS(int v) = 0;
	virtual status Visit(int v) = 0;
	virtual status breadthTraverse() = 0;
	virtual vertextype get_vex(int i)=0;
protected:
	GraphKind kind;
	int vexnum, arcnum;
	bool visited[MAX_VERTEX_NUM];
};

/*template<class vertextype>
Graph<vertextype>::Graph()
{

}*/

template<class vertextype>
int Graph<vertextype>::get_arcnum()
{
	return arcnum;
}

template<class vertextype>
int Graph<vertextype>::get_vexnum()
{
	return vexnum;
}

