#include<iostream>
using namespace std;

inline void myswap(int &a, int &b);
void quicksort(int* arr, int low, int high);
int pivot(int* arr, int low, int high);

int main(void)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	int *pnArr = new int[nInput];

	for (int i = 0; i < nInput; i++)
	{
		cin >> pnArr[i];
	}

	quicksort(pnArr, 0, nInput - 1);

	for (int i = 0; i < nInput; i++)
	{
		cout << pnArr[i] << '\n';
	}
	delete[] pnArr;
	return 0;
}

inline void myswap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
	return;
}
void quicksort(int* arr, int low, int high)
{
	if (high - low < 1)
		return;
	int pidx = pivot(arr, low, high);
	quicksort(arr, low, pidx);
	quicksort(arr, pidx + 1, high);
	return;
}
int pivot(int* arr, int low, int high)
{
	int pidx((low + high) / 2);
	int nPivotValue(arr[pidx]);
	int lside(low);
	int rside(high);

	myswap(arr[rside--], arr[pidx]);

	while (lside <= rside)
	{
		if (arr[lside] > nPivotValue)
		{
			myswap(arr[lside], arr[rside]);
			rside--;
		}
		else
		{
			lside++;
		}
	}
	myswap(arr[rside+1], arr[high]);
	return lside;
}
