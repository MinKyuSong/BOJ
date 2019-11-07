#include<iostream>
constexpr long long MAXN = 1000000;
class Heap
{
public:
	Heap()
		:count(0)
	{
		
	}
	~Heap() {}
	int findParent(int i)
	{
		if (i <= 0 || i >= count)
			return -1;
		return (i - 1) / 2;
	}
	int leftChild(int i)
	{
		int left = (2 * i) + 1;
		if (left >= count)
			return -1;
		return left;
	}
	int rightChild(int i)
	{
		int right = (2 * i) + 2;
		if (right >= count)
			return -1;
		return right;
	}
	int getMaximum() {
		if (count == 0) return -1;
		return dataList[0];
	}
	void percolateDown(int i) {
		int l, r, max, temp;
		l = leftChild(i);
		r = rightChild(i);
		if (l != -1 && dataList[l] > dataList[i])
			max = l;
		else
			max = i;
		if (r != -1 && dataList[r] > dataList[max])
			max = r;
		if (max != i) {
			temp = dataList[i];
			dataList[i] = dataList[max];
			dataList[max] = temp;
			percolateDown(max);
		}
	}
	int deleteMax() {
		int data;
		if (count == 0)
			return -1;
		data = dataList[0];
		dataList[0] = dataList[count - 1];
		count--;
		percolateDown(0);
		return data;
	}
	int insert(int data) {
		int i;
		count++;
		i = count - 1;
		while (i >= 0 && data > dataList[(i - 1) / 2]) {
			dataList[i] = dataList[(i - 1) / 2];
			i = (i - 1) / 2;
		}
		dataList[i] = data;
	}
	void buildHeap(int A[], int n) {
		for (int i = 0; i < n; i++)
			dataList[i] = A[i];
		count = n;
		for (int i = (n - 1) / 2; i >= 0; i--)
			percolateDown(i);
	}
	
private:
	int count;
	int dataList[MAXN];
};
