#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
using namespace std;

typedef struct Person
{
	int nAge;
	char szName[101];
}Person;

bool cmp(Person &a, Person &b)
{
	if (a.nAge < b.nAge)
		return true;
	else
		return false;
}
void cpy(Person &from, Person &to)
{
	to.nAge = from.nAge;
	strcpy(to.szName, from.szName);
	return;
}
void mergesort(Person* pPeople, Person* pTemp, int low, int high)
{
	int nSplit = (high + low) / 2;
	if (high - low > 1)
	{
		mergesort(pPeople, pTemp, low, nSplit);
		mergesort(pPeople, pTemp, nSplit + 1, high);
	}

	int i = low; int j = nSplit+1; int k = low;
	while ((i <= nSplit) && (j <= high))
	{
		bool flag = cmp(pPeople[i], pPeople[j]);
		if(flag)
		{
			cpy(pPeople[k], pTemp[i]);
			i++;
		}
		else
		{
			cpy(pPeople[k], pTemp[j]);
			j++;
		}
		k++;
	}
	while (i <= nSplit)
	{
		cpy(pPeople[k], pTemp[i]);
		i++; k++;
	}
	while (j <= high)
	{
		cpy(pPeople[k], pTemp[j]);
		j++; k++;
	}

	for (int l = 0; l <= high; l++)
		cpy(pTemp[l], pPeople[l]);
	return;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int nInput;
	cin >> nInput;

	Person *pPeople = new Person[nInput];
	Person *pTemp = new Person[nInput];
	for (int i = 0; i < nInput; i++)
	{
		cin >> pPeople[i].nAge >> pPeople[i].szName;
	}

	mergesort(pPeople, pTemp, 0, nInput - 1);

	for (int i = 0; i < nInput; i++)
	{
		cout << pPeople[i].nAge << ' ' << pPeople[i].szName << '\n';
	}
	delete[] pPeople;
	delete[] pTemp;
	return 0;
}