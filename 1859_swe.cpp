#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

int main(void)
{
	//�� ����Ƚ�� �Է�
	int nTry;
	cin >> nTry;

	for(int i=0;i<nTry;i++)
	{
		long long nResult=0;
		long long nBuy=0,nSell;
		int j,nDays, nCount=0;

		//�� �� �Է�
		cin >> nDays;
		int *arrPrices = new int[nDays];

		//�����Է�
		for (j = 0; j < nDays; j++)
		{
			cin >> arrPrices[j];
		}

		nSell = arrPrices[nDays-1];

		for (j=nDays-1; j > 0;j--)
		{
			//���
			if (arrPrices[j-1] <= nSell)
			{
				nCount++;
				nBuy += arrPrices[j - 1];
			}
			//�Ǵ�
			else
			{
				//����
				if ((nCount*nSell) - nBuy > 0)
				{
					nResult += (nCount*nSell) - nBuy;
				}

				//�ʱ�ȭ
				nSell = arrPrices[j-1];
				nCount = 0;
				nBuy = 0;
			}
		}
		if ((nCount*nSell) - nBuy > 0)
		{
			nResult += (nCount*nSell) - nBuy;
		}
		cout << "#" << i + 1 << " " << nResult << endl;
		delete[] arrPrices;
	}

	return 0;
}