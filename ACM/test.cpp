#include<iostream>
using namespace std;
int reverse(int x) {
	int sign = x < 0 ? -1 : 1;
	/*if (x == 2147483648*-1) 
		return 0;*/
	int temp(sign * x);
	int ans = 0;
	int len = 0;
	while (temp > 0)
	{
		if (ans <= 214748364)
		{
			len++;
			if (len == 9 && ((temp % 10 > 7 && sign == 1) || (temp % 10 > 8 && sign == -1)))
				return 0;
			ans *= 10;
			ans += temp % 10;
			temp /= 10;
		}
		else return 0;
	}

	return sign * ans;
}
int main(void)
{
	cout << reverse(-900000) << endl;
}