#include<iostream>
#include<queue>
using namespace std;

int a[26][2];
void preorder(int root)
{
	cout << char(root + 'A');
	if (a[root][0] >= 0)
		preorder(a[root][0]);
	if (a[root][1] >= 0)
		preorder(a[root][1]);
	return;
}
void inorder(int root)
{
	if (a[root][0] >= 0)
		inorder(a[root][0]);
	cout << char(root + 'A');
	if (a[root][1] >= 0)
		inorder(a[root][1]);
	return;
}
void postorder(int root)
{
	if (a[root][0] >= 0)
		postorder(a[root][0]);
	if (a[root][1] >= 0)
		postorder(a[root][1]);
	cout << char(root + 'A');
	return;
}
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char x, y, z;
		cin >> x >> y >> z;
		if (y == '.')
		{
			a[x - 'A'][0] = -1;
		}
		else
		{
			a[x - 'A'][0] = int(y - 'A');
		}
		if (z == '.')
		{
			a[x - 'A'][1] = -1;
		}
		else
		{
			a[x - 'A'][1] = int(z - 'A');
		}
	}
	preorder(0);
	cout << endl;
	inorder(0);
	cout << endl;
	postorder(0);
	cout << endl;
	return 0;
}