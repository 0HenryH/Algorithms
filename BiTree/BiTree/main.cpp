#include<iostream>
#include"STACK_S.h"
using namespace std;
#define OVERFLOW -2
#define OK 1
#define FALSE 0
typedef int Status;
typedef char ElemType;
typedef  struct BiTNode {
	ElemType          data;
	struct BiTNode    *lchild, *rchild; //左右孩子指针
}BiTNode, *BiTree;  //定义了两个此结构的类型别名


Status CreateBiTree(BiTree &T);
//先序构造二叉树
Status Visit(ElemType e);
Status PreOrderTraverse(BiTree T, Status(*Visit)(ElemType));


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
		T->data = ch;  //生成根节点
		CreateBiTree(T->lchild);//构造左子树
		CreateBiTree(T->rchild);//构造右子树
	}
	return OK;
}
Status Visit(ElemType e)
{

	cout << e;
	return OK;

}
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

Status InOrderTraverse(BiTree T, Status(*Visit)(ElemType)) //非递归
{
	STACK_S<BiTree> stack;
	BiTree p = T;
	while (p || (!stack.is_empty()))
	{
		if (p)
		{
			stack.push(p);
			p = p->lchild;
		}
		else
		{
			stack.pop(p);
			if(!Visit(p->data)) return FALSE;
			p = p->rchild;
		}
	}
	return OK;
}

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

void main()
{
	cout << "Create a BiTree" << endl;
	BiTree T = NULL;
	CreateBiTree(T);
	cout << "S!" << endl;
	cout << "测试先序遍历 : ";
	PreOrderTraverse(T, Visit);
	cout << endl;
	cout << "测试中序遍历 : ";
	MidOrderTraverse(T, Visit);
	InOrderTraverse(T, Visit);
	cout << endl;
	cout << "测试后序遍历 : ";
	PostOrderTraverse(T, Visit);
	cout << endl;
	system("pause");
}