#include<iostream>
#include"LinkList.h"
using namespace std;

int main()
{
    LinkList<char> L;
    char e = 'a';
    L.insertElem(e,1);
    e = 'b';
    if(L.getElem(e,1)) cout<<"OK";
    cout<<e<<endl;
    system("pause");
    return 0;
}