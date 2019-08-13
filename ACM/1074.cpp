#include<iostream>

using namespace std;
int N, r, c;
int res = 0;
int power2(int n)
{
	return (1 << n);
}

void solve(int y, int x, int n)
{
	if (n == 2 && y <= r && r < y + 2 && x <= c && c < x + 2)
	{
		res+=(2*(r-y)+(c-x));
		cout << res << endl;
		return;
	}
	else
	{
		int m = n / 2;
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				if (!(r < y + (i+1) * m && c < x + (j+1) * m))
				{
					res += m * m;
				}
				else
				{
					solve(y + i * m, x + j * m, m);
					return;
				}
			}
	}
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
	
	cin >> N >> r >> c;
	int n = power2(N);
	solve(0, 0, n);

	return 0;
}