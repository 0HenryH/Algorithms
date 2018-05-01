#include<iostream>
#include"STACK_S.h"
#include"LinkQueue.h"
#include"LinkList.h"
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
	while (!stack.is_empty())
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

/*��Ҷ�ӽڵ�*/
void CountLeaf(BiTree T, int &count)
{
	if (T)
	{
		if ((!T->lchild) && (!T->rchild)) count++;
		CountLeaf(T->lchild, count);
		CountLeaf(T->rchild, count);
	}
}

/*���������*/
int Depth(BiTree T)
{
	int depthval, depthRight, depthLeft;
	if (!T) depthval = 0;
	else
	{
		depthLeft = Depth(T->lchild);
		depthRight = Depth(T->rchild);
		depthval = 1 + (depthLeft > depthRight ? depthLeft : depthRight);
	}
	return depthval;
}
/*�ж���ĸ����*/
status In(char ch)
{
	if (((ch >= 'a')&&(ch <= 'z')) || ((ch >= 'A')&&(ch <= 'Z')))
		return OK;
	else
		return FALSE;
}

/*ǰ׺���ʽ����*/
status CreateBiTree2(BiTree &T)
{
	char ch;
	ch = getchar();
	if (In(ch))
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else
	{
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data = ch;  //���ɸ��ڵ�
		CreateBiTree2(T->lchild);//����������
		CreateBiTree2(T->rchild);//����������
	}
	return OK;
}

/*Search���ڵ�*/
int Search(char ino[], char ch)
{
	int i=0;
	while (ino[i])
	{
		if (ch == ino[i++]) return (i-1);
	}
	return -1;
}

/*�������򴴽�������*/
status PICrtBT(BiTree &T, char pre[], char ino[], int ps, int is, int n)
{
	int k;
	if (n == 0) T = NULL;
	else
	{
		k = Search(ino, pre[ps]);
		if (k == -1) T = NULL;
		else
		{
			T = (BiTNode*)malloc(sizeof(BiTNode));
			T->data = pre[ps];
			if (k == is) T->lchild = NULL;
			else PICrtBT(T->lchild, pre, ino, ps + 1, is, k - is);
			if (k ==is + n - 1) T->rchild = NULL;
			else PICrtBT(T->rchild, pre, ino, ps + 1 + (k - is), k + 1, n - (k - is) - 1);
		}
	}
	return OK;
}

/*������򴴽�������*/
status ILCrtBT(BiTree &T, char ino[], char lao[], int is, int ls, int n)
{
	int k;
	if (n == 0) T = NULL;
	else
	{
		k = Search(ino, lao[ls]);
		if (k == -1) T = NULL;
		else
		{
			T = (BiTNode*)malloc(sizeof(BiTNode));
			T->data = lao[ls];
			if (k == is) T->lchild = NULL;
			else ILCrtBT(T->lchild, ino, lao, is, ls-n+k-is, k - is);
			if (k == is + n - 1) T->rchild = NULL;
			else ILCrtBT(T->rchild, ino, lao, k+1, ls-1, n - (k - is) - 1);
		}
	}
	return OK;
}

/*ƥ�����������ַ���*/
status Match(LinkList<char> a, LinkList<char> b)
{
	int i=1, j=1;
	status flag;
	char m, n;
	while (a.getElement(i++, m))
	{
		flag = FALSE;
		j = 1;
		while (b.getElement(j++, n))
		{
			if (m == n)
			{
				flag = OK;
				break;
			}
		}
		if (!flag) return FALSE;
	}
	return OK;
}

void main()
{
	cout << "Create a BiTree" << endl;
	BiTree T = NULL;
	CreateBiTree2(T);
	cout << "---------Success!---------" << endl;
	//cout << "����������� : ";
	////PreOrderTraverse(T, Visit);
	//PreOrderTraverse2(T, Visit);
	//cout << endl;
	//cout << "����������� : ";
	////MidOrderTraverse(T, Visit);
	//MidOrderTraverse2(T, Visit);
	//cout << endl;
	cout << "���Ժ������ : ";
	//PostOrderTraverse(T, Visit);
	PostOrderTraverse2(T, Visit);
	cout << endl;
	/*cout << "���Բ������ : ";
	LevelTraverse(T, Visit);
	cout << endl;*/
	cout << "---------End Test---------" << endl;

	/*�����к�����*/
	/*����ǰ׺����������*/
	cout << "�����к����� : " << endl;
	T = NULL;
	int n = 9;
	int is = 0,ls = 8;
	char ino[] = { 'a','+','b','*','c','-','d','/','e' };
	char lao[] = { 'a','b','+','c','*','d','e','/','-' };
	if (ILCrtBT(T, ino, lao, is, ls, n)) cout << "Success ! ";
	MidOrderTraverse2(T, Visit);
	cout << endl;
	
	/*������������*/
	/*����ǰ׺����������*/
	cout << "������������ : " << endl;
	T = NULL;
	n = 9;
	is = 0;
	int ps = 0;
	char pre[]  = { '-','*','+','a','b','c','/','d','e' };
	if(PICrtBT(T, pre, ino, ps, is, n)) cout<<"Success ! ";
	MidOrderTraverse2(T, Visit);
	cout << endl;
	system("pause");
}