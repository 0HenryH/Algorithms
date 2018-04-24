#include<iostream>
#include"STACK_S.h"
#include"LinkQueue.h"
using namespace std;
#define OVERFLOW -2
#define OK 1
#define FALSE 0
typedef int Status;
typedef char ElemType;
typedef  struct BiTNode {
	ElemType          data;
	struct BiTNode    *lchild, *rchild; //���Һ���ָ��
}BiTNode, *BiTree;  //�����������˽ṹ�����ͱ���


Status CreateBiTree(BiTree &T);
//�����������
Status Visit(ElemType e);
//Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType));


Status CreateBiTree(BiTree &T)
{
	char ch;
	ch = getchar();
	if (ch == '#')
	{
		T = NULL;
	}
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;  //���ɸ��ڵ�
		CreateBiTree(T->lchild);//����������
		CreateBiTree(T->rchild);//����������
	}
	return OK;
}
Status Visit(ElemType e)
{

	cout << e;
	return OK;

}
/*
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	if (T)
	{
		if (Visit(T->data))
		{
			if (PreOrderTraverse(T->lchild, Visit))
			{
				if (PreOrderTraverse(T->rchild, Visit))
				{
					return OK;
				}
			}
		}
		return FALSE;
	}
	return OK;
}
*/
Status PreOrderTraverse2(BiTree T, Status(*Visit)(ElemType)) //�ǵݹ�
{

	STACK_S<BiTree> stack;
	while (T || (!stack.is_empty()))
	{
		if (T)
		{
			if (!Visit(T->data)) return FALSE;
			stack.push(T);
			T = T->lchild;
		}
		else
		{
			stack.pop(T);
			T = T->rchild;
		}
	}
	return OK;
}
/*
Status MidOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	if (T)
	{
		if (MidOrderTraverse(T->lchild, Visit))     // 
		{
			if (Visit(T->data))
			{
				if (MidOrderTraverse(T->rchild, Visit))
				{
					return OK;
				}
			}
		}
		return FALSE;
	}
	return OK;
}
*/
Status MidOrderTraverse2(BiTree T, Status(*Visit)(ElemType)) //�ǵݹ�
{
	STACK_S<BiTree> stack;
	while (T || (!stack.is_empty()))
	{
		if (T)
		{
			stack.push(T);
			T = T->lchild;
		}
		else
		{
			stack.pop(T);
			if (!Visit(T->data)) return FALSE;
			T = T->rchild;
		}
	}
	return OK;
}
/*
Status PostOrderTraverse(BiTree T, Status(*Visit)(ElemType))
{
	if (T)
	{
		if (PostOrderTraverse(T->lchild, Visit))     // 
		{
			if (PostOrderTraverse(T->rchild, Visit))
			{
				if (Visit(T->data))
				{
					return OK;
				}
			}
		}
		return FALSE;
	}
	return OK;
}
*/
Status PostOrderTraverse2(BiTree T, Status(*Visit)(ElemType))
{
	STACK_S<BiTree> stack;
	BiTree PreVisitNode = NULL;
	stack.push(T);
	while(!stack.is_empty())
	{
		stack.get_top(T);
		if (((!(T->lchild)) && (!(T->rchild))) || (T->lchild == PreVisitNode) || (T->rchild == PreVisitNode))
		{
			if (!Visit(T->data)) return FALSE;
			stack.pop(PreVisitNode);
		}
		else
		{
			if (T->rchild) stack.push(T->rchild);
			if (T->lchild) stack.push(T->lchild);
		}
	}
	return OK;
}

Status LevelTraverse(BiTree T, Status(*Visit)(ElemType))
{
	LinkQueue<BiTree> q;
	if (T) q.EnQueue(T);
	else return FALSE;
	while (!(q.isEmpty()))
	{
		q.DeQueue(T);
		Visit(T->data);
		if (T->lchild) 
			q.EnQueue(T->lchild);
		if (T->rchild) 
			q.EnQueue(T->rchild);
	}
	return OK;
}
void main()
{
	cout << "Create a BiTree" << endl;
	BiTree T = NULL;
	CreateBiTree(T);
	cout << "---------Success!---------" << endl;
	cout << "����������� : ";
	//PreOrderTraverse(T, Visit);
	PreOrderTraverse2(T, Visit);
	cout << endl;
	cout << "����������� : ";
	//MidOrderTraverse(T, Visit);
	MidOrderTraverse2(T, Visit);
	cout << endl;
	cout << "���Ժ������ : ";
	//PostOrderTraverse(T, Visit);
	PostOrderTraverse2(T, Visit);
	cout << endl;
	cout << "���Բ������ : ";
	LevelTraverse(T, Visit);
	cout << endl;
	cout << "---------End Test---------" << endl;
	system("pause");
}