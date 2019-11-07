#include<iostream>
using namespace std;

int inorder[100001];
int postorder[100001];
int position[100001];

void solve(int is, int ie, int ps, int pe)
{
	if (is > ie || ps > pe)
		return;
	cout << postorder[pe] << " ";
	int ir = position[postorder[pe]];
	int left = ir - is;

	solve(is, ir - 1, ps, ps + left - 1);
	solve(ir + 1, ie, ps + left, pe - 1);
}

int main(void)
{
	cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> inorder[i];
	for (int i = 0; i < N; i++)
		cin >> postorder[i];
	for (int i = 0; i < N; i++)
		position[inorder[i]] = i;
	
	solve(0, N - 1, 0, N - 1);
	cout << endl;

	return 0;
}