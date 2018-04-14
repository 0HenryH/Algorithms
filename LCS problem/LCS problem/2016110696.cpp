#include<iostream>
#include<string>
using namespace std;
void matrixmethod(int result[], const string a, const string b)
{
	int i=0, j=0;
	int k;
	int alen = a.length();
	int blen = b.length();
	int ** p = new int * [alen];
	for (k= 0;k < alen; k++)
	{
		p[k] = new int [blen];
	}
	for (i = 0; i < alen; i++)
	{
		for (j = 0; j < blen; j++)
		{
			if (a[i] == b[j])
			{
				if (((i - 1) > -1) && ((j - 1) > -1))
				{
					p[i][j] = p[i - 1][j - 1] + 1;
				}
				else
				{
					p[i][j] = 1;
				}
				if (p[i][j] > result[0])
				{
					result[0] = p[i][j];
					result[1] = i;
					result[2] = j;
				}
			}
			else
			{
				p[i][j] = 0;
			}

		}
	}
}
int main()
{
	int i;
	int result0[3] = {0};
	string a, b;
	cout << "ÊäÈëa" << endl;
	cin >> a;
	cout << "ÊäÈëb" << endl;
	cin >> b;
	cout << "LCSÎª:" << endl;
	matrixmethod(result0, a, b);
	for (i = (result0[1] - result0[0] + 1); i <= result0[1]; i++)
	{
		cout << a[i];
	}
	cout << endl;
	system("pause");
	return 0;
}



