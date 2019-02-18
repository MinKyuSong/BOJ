#include<iostream>
using namespace std;

int GetMax(int a, int b, int c)
{
	int temp = a;
	if (temp < b)
		temp = b;
	if (temp < c)
		temp = c;
	return temp;
}

int main(void) 
{
	int nInput;
	cin >> nInput;

	int *nArray = new int[nInput+1];
	int *nDrink = new int[nInput+1];
	for (int i = 1; i < nInput+1; i++)
	{
		cin >> nArray[i];
	}

	nDrink[0] = nArray[0] = 0;
	nDrink[1] = nArray[1];
	if (nInput > 1)
		nDrink[2] = nArray[1] + nArray[2];

	for (int i = 3; i < nInput+1; i++)
	{
		nDrink[i] = GetMax(nDrink[i-1],nDrink[i-2]+nArray[i],nDrink[i-3]+nArray[i-1]+nArray[i]);
	}

	cout << nDrink[nInput] << endl;

	delete[] nDrink;
	delete[] nArray;
	return 0;
}