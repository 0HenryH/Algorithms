#include<iostream>
using namespace std;
int * get_next(const char a[], int len)
{
	int i, j;
	i = 1;
	j = -1;
	int * next = new int[len];
	next[0] = -1;
	while (i < len)
	{
		if (j == -1 || a[j] == a[i - 1])
		{
			next[i++] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
	return next;
}

int KMP(const char S[], int Slen, const char T[], int Tlen)
{
	int i, j;
	i = 0;
	j = 0;
	int * next;
	next = get_next(T, Tlen);
	while ((i < Slen) && (j != (Tlen - 1)))
	{
		if ((j == -1) || (S[i] == T[j]))
		{
			++i;
			++j;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == Tlen - 1)
	{
		return (i + 1 - Tlen);
	}
	else
	{
		return -1;
	}
}
int main()
{
	int i;
	int Slen = 10;
	int Tlen = 7;
	char S[12];
	char T[9];
	cout << "ÊäÈëS" << endl;
	for (i = 0; i < 11; i++)
	{
		S[i] = getchar();
	}
	cout << "ÊäÈëT" << endl;
	for (i = 0; i < 8; i++)
	{
		T[i] = getchar();
	}
	cout << KMP(S, Slen, T, Tlen);
	system("pause");
	return 0;
}