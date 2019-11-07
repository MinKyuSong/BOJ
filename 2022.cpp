#include<cstdio>
#include<cmath>

using namespace std;

int main(void)
{
	double x, y, c;
	scanf("%lf %lf %lf", &x, &y, &c);
	double l = 0;
	double r = x < y ? x : y;

	while (abs(r - l) > 1e-6)
	{
		double mid = l + (r - l) / 2;
		double h1 = sqrt(x * x - mid * mid);
		double h2 = sqrt(y * y - mid * mid);

		double h = (h1 * h2) / (h1 + h2);
		if (h > c)
		{
			l = mid;
		}
		else
		{
			r = mid;
		}
	}
	printf("%.3lf\n",l);
	return 0;
}