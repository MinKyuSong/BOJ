#include<iostream>
#include<string>
#include<array>
#include<vector>
using namespace std;

void Swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
	return;
}

int main(void)
{
	string szSrc;
	string* arrDst;

	cin >> szSrc;
	int nLen = szSrc.length();
	arrDst = new string[nLen];

	for (int i = 0; i < nLen; i++)
	{
		arrDst[i]=szSrc.substr(i);
	}
	for (int i = 0; i < nLen; i++)
	{
		for(int j=0;j<nLen-i-1;j++)
			if(arrDst[j]>arrDst[j+1])
				Swap(arrDst[j], arrDst[j+1]);
	}
	for (int i = 0; i < nLen; i++)
	{
		cout << arrDst[i] << endl;
	}
	delete[] arrDst;
	return 0;
}