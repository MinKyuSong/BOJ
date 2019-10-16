#include<iostream>
using namespace std;

int tree[27][2];

void preorder(int node)
{
	cout << char(node + 'A');
	if (tree[node][0] >= 0)
		preorder(tree[node][0]);
	if (tree[node][1] >= 0)
		preorder(tree[node][1]);
	return;
}
void inorder(int node)
{
	if (tree[node][0] >= 0)
		inorder(tree[node][0]);
	cout << char(node + 'A');
	if (tree[node][1] >= 0)
		inorder(tree[node][1]);
	return;
}
void postorder(int node)
{
	if (tree[node][0] >= 0)
		postorder(tree[node][0]);
	if (tree[node][1] >= 0)
		postorder(tree[node][1]);
	cout << char(node + 'A');
	return;
}

int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.')
			tree[a - 'A'][0] = b - 'A';
		else
			tree[a - 'A'][0] = -1;
		if (c != '.')
			tree[a - 'A'][1] = c - 'A';
		else
			tree[a - 'A'][1] = -1;
	}
	preorder(0); cout << endl;
	inorder(0); cout << endl;
	postorder(0); cout << endl;

	return 0;
}