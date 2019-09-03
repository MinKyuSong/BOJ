#include<iostream>
#include<vector>
using namespace std;

int main(void)
{
	int A, B, N;
	cin >> A >> B;
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		sum *= A;
		sum += temp;
	}
	vector<int> v;
	while (sum > 0)
	{
		v.push_back(sum % B);
		sum /= B;
	}
	for (int i = v.size() - 1; i > -1; i--)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}