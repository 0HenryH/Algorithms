#pragma once
#define null 0
#define STACK_INIT_SIZE 2
#define L (sizeof(Type))
template<class Type>
class Mystack
{
private:
	Type * base;
	Type * top;
	int stack_size;
public:
	Mystack();
	bool is_empty();
	void increse_size();
	int stack_length();
	bool clear_stack();
	bool get_top(Type * e);
	bool push(Type e);
	bool pop(Type * e);
	~Mystack();
};

template<class Type>
Mystack<Type>::Mystack()
{
	stack_size = STACK_INIT_SIZE;
	base = top = new Type[STACK_INIT_SIZE];
}
template<class Type>
bool Mystack<Type>::is_empty()
{
	if (base == top)
	{
		return 1;
	}
	else
		return 0;
}
template<class Type>
void Mystack<Type>::increse_size()
{
	Type * temp;
	int i;
	temp = new Type[stack_size *= 2];
	for (i = 0; i < (stack_size / 2); i++)
	{
		temp[i] = base[i];
	}
	top = temp + stack_length();
	delete base;
	base = temp;
}
template<class Type>
int Mystack<Type>::stack_length()
{
	return (top - base);
}
template<class Type>
bool Mystack<Type>::clear_stack()
{
	int i;
	if (!stack_length())
	{
		for (i = 0; i < stack_length(); i++)
		{
			base[i] = null;
		}
		return 1;
	}
	else
		return 0;  //The stack is already empty
}
template<class Type>
bool Mystack<Type>::get_top(Type * e)
{
	if (!is_empty())
	{
		*e = *(top-1);
		return 1;
	}
	else
	{
		return 0;
	}
}

template<class Type>
bool Mystack<Type>::push(Type e)
{
	if (stack_length() >= stack_size)
	{
		increse_size();
		if (!base) return 0;
	}
	*(top++) = e;
	return 1;
}
template<class Type>
bool Mystack<Type>::pop(Type * e)
{
	if (!is_empty())
	{
		*e = *(--top);
		*top = null;
		if (stack_length() < 0.25*stack_size)
		{
			int i;
			Type * temp;
			temp = new Type[stack_size /= 2];
			for (i = 0; i < stack_length(); i++)
			{
				temp[i] = base[i];
			}
			top = temp + stack_length();
			delete base;
			base = temp;
		}
		return 1;
	}
	else
		return 0;
}
template<class Type>
Mystack<Type>::~Mystack()
{
	top = base = null;
}

