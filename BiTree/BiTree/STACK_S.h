#pragma once
#define NULL 0
#define STACK_INIT_SIZE 2
#define L (sizeof(Type))
#define OK 1
#define FALSE 0
typedef int status;
template<class Type>
class STACK_S
{
private:
	Type * base;
	Type * top;
	int stack_size;
public:
	STACK_S();
	status is_empty();
	void increse_size();
	int stack_length();
	status clear_stack();
	status get_top(Type &e);
	status push(Type e);
	status pop(Type &e);
	~STACK_S();
};

template<class Type>
STACK_S<Type>::STACK_S()
{
	stack_size = STACK_INIT_SIZE;
	base = top = new Type[STACK_INIT_SIZE];
}
template<class Type>
status STACK_S<Type>::is_empty()
{
	if (base == top)
	{
		return OK;
	}
	else
		return FALSE;
}
template<class Type>
void STACK_S<Type>::increse_size()
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
int STACK_S<Type>::stack_length()
{
	return (top - base);
}
template<class Type>
status STACK_S<Type>::clear_stack()
{
	int i;
	if (!stack_length())
	{
		for (i = 0; i < stack_length(); i++)
		{
			base[i] = NULL;
		}
		return OK;
	}
	else
		return FALSE;  //The stack is already empty
}
template<class Type>
status STACK_S<Type>::get_top(Type &e)
{
	if (!is_empty())
	{
		e = *(top - 1);
		return OK;
	}
	else
	{
		return FALSE;
	}
}

template<class Type>
status STACK_S<Type>::push(Type e)
{
	if (stack_length() >= stack_size)
	{
		increse_size();
		if (!base) return FALSE;
	}
	*(top++) = e;
	return OK;
}
template<class Type>
status STACK_S<Type>::pop(Type &e)
{
	if (!is_empty())
	{
		e = *(--top);
		*top = NULL;
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
		return OK;
	}
	else
		return FALSE;
}
template<class Type>
STACK_S<Type>::~STACK_S()
{
	top = base = NULL;
}

