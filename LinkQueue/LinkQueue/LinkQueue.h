#pragma once
#define NULL 0
#define STACK_INIT_SIZE 2
#define L (sizeof(Type))
#define OK 1
#define FALSE 0
#define OVERFLOW 2
typedef int status;
template<class Type>
struct QNode
{
public:
	Type data;
	QNode<Type> * next;
};

template<class Type>
class LinkQueue
{

private:

	QNode<Type> * front; //队头和队尾指针
	QNode<Type> * rear;
public:
	LinkQueue();
	status isEmpty();
	status clearQueue();
	//int QLength();
	//status getHead(Type &e);
	status EnQueue(Type e);
	status DeQueue(Type &e);
	~LinkQueue();
};

template<class Type>
LinkQueue<Type>::LinkQueue()
{
	front = rear = new QNode<Type>;
	front->next = NULL;
}

template<class Type>
status LinkQueue<Type>::isEmpty()
{
	if (front->next == NULL) return OK;
	else return FALSE;
}

template<class Type>
status LinkQueue<Type>::EnQueue(Type e)
{
	/*QNode<Type> * q = new QNode<Type>;
	if (!q) return FALSE;
	q->data = e;
	q->next = NULL;
	rear->next = q;
	rear = q;
	return OK;*/
	rear->next = new QNode<Type>;
	if (!(rear->next)) return FALSE;
	rear = rear->next;
	rear->data = e;
	rear->next = NULL;
	return OK;
}

template<class Type>
status LinkQueue<Type>::DeQueue(Type &e)
{
	if (isEmpty()) return FALSE;
	e = front->next->data;
	QNode<Type> * p = front->next;
	if (!(front->next = front->next->next)) rear = front; //防止只有一个元素时的出队导致链表断裂
	delete p;
	return OK;
}

template<class Type>
status LinkQueue<Type>::clearQueue()
{
	Type t;
	while (front->next)
	{
		DeQueue(t);
	}
	return OK;
}

template<class Type>
LinkQueue<Type>::~LinkQueue()
{
	clearQueue();
	delete front, rear;
}
