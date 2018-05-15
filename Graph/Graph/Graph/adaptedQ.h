#pragma once
#include "LinkQueue.h"
template<class Type>
class adaptedQ :
	public LinkQueue<Type>
{
public:
	adaptedQ();
	status EnQueue(Type e);
	status DeQueue(Type &e);
	~adaptedQ();
};

template<class Type>
status adaptedQ<Type>::EnQueue(Type e)
{
	rear->next = new QNode<Type>;
	if (!(rear->next)) return FALSE;
	rear = rear->next;
	rear->data = e;
	rear->next = NULL;
	rear->priou = front;
	return OK;
}

template<class Type>
status adaptedQ<Type>::DeQueue(Type &e)
{
	if (isEmpty()) return FALSE;
	e = front->next->data;
	//QNode<Type> * p = front->next;
	//if (!(front->next = front->next->next)) rear = front; //防止只有一个元素时的出队导致链表断裂
	//return OK;
	front = front->next;
	return OK;
}



