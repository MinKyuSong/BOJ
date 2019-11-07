#include<iostream>

using namespace std;

int main(void)
{
	int mm, dd, temp=0;
	cin >> mm >> dd;
	
	switch (mm)
	{
	case 1:
		temp += 0;
		break;
	case 2:
		temp += 31;
		break;
	case 3:
		temp += 59;
		break;
	case 4:
		temp += 90;
		break;
	case 5:
		temp += 120;
		break;
	case 6:
		temp += 151;
		break;
	case 7:
		temp += 181;
		break;
	case 8:
		temp += 212;
		break;
	case 9:
		temp += 243;
		break;
	case 10:
		temp += 273;
		break;
	case 11:
		temp += 304;
		break;
	case 12:
		temp += 334;
		break;
	}
	temp += dd;
	temp=temp % 7;
	switch (temp)
	{
	case 0:
		cout << "SUN" << endl;
		break;
	case 1:
		cout << "MON" << endl;
		break;
	case 2:
		cout << "TUE" << endl;
		break;
	case 3:
		cout << "WED" << endl;
		break;
	case 4:
		cout << "THU" << endl;
		break;
	case 5:
		cout << "FRI" << endl;
		break;
	case 6:
		cout << "SAT" << endl;
		break;
	}

	return 0;
}