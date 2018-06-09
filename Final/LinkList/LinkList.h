#pragma once
#include<iostream>
using namespace std;
/*----------------------------------//
* 数据结构——函数结果状态代码
* SUFE 2018 Spring
//----------------------------------*/
#ifndef STATUS_H
#define STATUS_H

#define	TRUE		1			
#define	FALSE		0			
#define YES			1			
#define NO          0			
#define	OK			1			
#define	ERROR		0			
#define SUCCESS		1			
#define UNSUCCESS	0			
#define	INFEASIBLE	-1			

#ifndef _MATH_H_ 				 
#define	OVERFLOW	-2			
#define UNDERFLOW	-3			
#endif 
#ifndef NULL
#define NULL ((void*)0)
#endif
typedef int status;
#endif

template<class T>
//节点
struct LNode
{
    T data;
    LNode * next;
};

template<class T>
class LinkList
{
    private:
    LNode<T> * head;
    LNode<T> * tail;
    public:
    LinkList();
    status getElem(T &e,int i);
    status insertElem(const T &e,int i);
};

//构造函数
template<class T>
LinkList<T>::LinkList()
{
    head = new LNode<T>;
    head->next = NULL;
    head->data = NULL;
    tail = head;
}

template<class T>
status LinkList<T>::getElem(T &e,int i)
{
    LNode<T> * p=head;
    while((i--)>0)
    {
        if(p->next) p = p->next;
        else return FALSE;
    }
    e = p->data;
    return OK;
}

template<class T>
status LinkList<T>::insertElem(const T &e, int i)
{
    LNode<T> * N, * p = head;
    N = new LNode<T>;
    N->data = e;
    while((i--)> 1)
    {
        if(p->next) p = p->next;
        else return FALSE;
    }
    N->next = p->next;
    p->next = N;
}


