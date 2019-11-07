#include<iostream>

using namespace std;

int nArrWine[10001];
int nArrDrink[2][10001];
int main(void)
{
	int N;
	cin >> N;

	nArrWine[0] = 0;
	for (int i = 1; i <= N;i++)
		cin >> nArrWine[i];

	nArrDrink[0][0] = 0; nArrDrink[1][0] = 0;
	nArrDrink[1][0] = 0;
	nArrDrink[1][1] = nArrWine[1];
	for (int i = 2; i <= N; i++)
	{
		int temp0 = nArrDrink[0][i - 2] + nArrWine[i - 1];
		int temp1 = nArrDrink[1][i - 2];
		nArrDrink[1][i] = nArrWine[i]+((temp0 > temp1) ? temp0 : temp1);
		nArrDrink[0][i] = (nArrDrink[0][i - 1] > nArrDrink[1][i - 1]) ? nArrDrink[0][i - 1] : nArrDrink[1][i - 1];
	}

	int nResult= (nArrDrink[0][N] > nArrDrink[1][N]) ? nArrDrink[0][N] : nArrDrink[1][N];
	cout << nResult << endl;
	
	return 0;
}