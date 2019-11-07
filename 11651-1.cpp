#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class corr
{
public:
	corr(int a, int b);
	~corr();
	int a = 0;
	int b = 0;
};

corr::corr(int a, int b)
{
	this->a = a;
	this->b = b;
}

corr::~corr()
{
}

bool compare(corr& l, corr& r)
{
	if (l.a < r.a)
		return true;
	else if (l.a == r.a)
		if (l.b < r.b)
			return true;
	return false;
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<corr>vCorr;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> b >> a;
		vCorr.push_back(corr(a, b));
	}
	sort(vCorr.begin(), vCorr.end(), compare);
	for (int i = 0; i < N; i++)
	{
		cout << vCorr[i].b << " " << vCorr[i].a << "\n";
	}
	return 0;
}