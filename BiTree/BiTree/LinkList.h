#pragma once
#define NULL 0
#define STACK_INIT_SIZE 2
#define L (sizeof(Type))
#define OK 1
#define FALSE 0
#define OVERFLOW 2
typedef int status;
template<class T>

/*������*/
struct Node
{
	T data;
	Node<T> * next;
};


/*��������*/
template<class T>
class LinkList
{
private:
	Node<T> head;
public:
	LinkList();
	status getElement(int i, T &e);
	status listInsert(T e, int i);
	status listDelete(T &e, int i);
	~LinkList();
};

//���캯��
template<class T>
LinkList<T>::LinkList()
{
	head = new Node<T>;
	head->data = NULL;
	head->next = NULL;
}

//��ȡ��i��Ԫ��
template<class T>
status LinkList<T>::getElement(int i, T &e)
{
	Node<T> * p=&head;
	while ((i--) > 0)
	{
		if(p->next) p = p->next;
		else return FALSE;
	}
	e = p->data;
	return OK;
}

template<class T>
status LinkList<T>::listInsert(T e, int i)
{
	Node<T> * p = head;
	while ((i--) > 1)
	{
		if (p->next) p = p->next;
		else return FALSE;
	}
	Node<T> tempt = new Node<T>;
	tempt->next = p->next;
	p->next = tempt;
	return OK;
}

/*ɾ����i���ڵ�*/
template<class T>
status LinkList<T>::listDelete(T &e, int i)
{
	Node<T> * p = head;
	while ((i--) > 1)
	{
		if (p->next) p = p->next;
		else return FALSE;
	}
	Node<T> * tempt = p->next;
	p->next = tempt->next;
	e = tempt->data;
	delete tempt;
	return OK;
}

//��������
template<class T>
LinkList<T>::~LinkList()
{
	Node<T> * p=&head;
	Node<T> * t;
	while (p)
	{
		t = p;
		delete p;
		p = t->next;
	}
}