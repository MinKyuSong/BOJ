#include<iostream>
using namespace std;

int N, M, K;
static int nums[1000100];
static long long tree[4000400];

long long initTree(int now, int left, int right) {
	if (left == right) {
		tree[now] = nums[left];
	}
	else{
		int mid = (left + right) / 2;
		tree[now] = initTree(now * 2, left, mid) + initTree(now * 2 + 1, mid + 1, right);
	}
	return tree[now];
}

void update(long long diff, int target, int now, int left, int right) {
	if (target < left || right < target) {
		return;
	}
	
	tree[now] += diff;
	
	if (left != right) {
		int mid = (left + right) / 2;
		update(diff, target, now * 2, left, mid);
		update(diff, target, now * 2 + 1, mid + 1, right);
	}
}

long long query(int targetLeft, long long targetRight, int now, int searchLeft, int searchRight) {
	if (targetRight < searchLeft || searchRight < targetLeft) {
		return 0;
	}
	if (targetLeft <= searchLeft && targetRight >= searchRight) {
		return tree[now];
	}
	else {
		int mid = (searchLeft + searchRight) / 2;
		return query(targetLeft, targetRight, now * 2, searchLeft, mid)
			+ query(targetLeft, targetRight, now * 2 + 1, mid + 1, searchRight);
	}
}

int main(void) {
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 1; i < N + 1; i++) {
		cin >> nums[i];
	}
	initTree(1, 1, N);

	for (int i = 0; i < M + K; i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;

		if (a == 1) {
			long long diff = c - nums[b];
			update(diff, b,1, 1, N);
			nums[b] = c;
		}
		else if (a == 2) {
			long long ans = query(b, c, 1, 1, N);
			cout << ans << '\n';
		}
	}
	return 0;
}