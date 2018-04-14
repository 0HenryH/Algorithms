#include<iostream>
#include "Mystack.h"
#define e 15
using namespace std;
int main()    //test the basic operation of stack 
{
	int show;
	Mystack<int> S1;
	S1.push(e);
	S1.get_top(&show);
	cout << show <<"  "<< S1.stack_length() << endl;
	S1.push(e);
	S1.push(e);
	S1.get_top(&show);
	cout << show << "  " << S1.stack_length() << endl;
	S1.pop(&show);
	S1.pop(&show);
	cout << show << "  " << S1.stack_length() << endl;
	system("pause");
	return 0;
}