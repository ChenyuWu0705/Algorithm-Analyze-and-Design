#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 100;
int Array[N];
int n, k;
int KthNumber(int left, int right, const int& k);

/* 区间快排，各组返回中位数下标 */
int GetPivotIndex(int left, int right) {
	sort(Array + left, Array + right + 1);
	return ((right - left) >> 1) + left;
}

/* 返回中位数的中位数下标 */
int GetPivotOfPivotIndex(int left, int right) {
	if (right - left < 5)
		return GetPivotIndex(left, right);
	int pos = left - 1;
	for (int i = left; i + 4 <= right; i += 5) {
		int index = GetPivotIndex(i, i + 4);  //找到五个元素的中位数的下标
		swap(Array[++pos], Array[index]);   //依次放在左侧
	}
	return KthNumber(left, pos, ((pos - left + 1) >> 1) + 1);
}

/* 利用中位数的中位数的下标进行划分，返回分界线下标 */
int Partition(int left, int right, int pivot_index) {
	swap(Array[pivot_index], Array[right]);  //把基准放置于末尾
	int divide_index = left;  //跟踪划分的分界线
	for (int i = left; i < right; i++) {
		if (Array[i] < Array[right])
			swap(Array[divide_index++], Array[i]);  //比基准小的都放在左侧
	}
	swap(Array[divide_index], Array[right]);  //最后把基准换回来
	return divide_index;
}

int KthNumber(int left, int right, const int& k) {
	int pivot_index = GetPivotOfPivotIndex(left, right);   //得到中位数的中位数下标
	int divide_index = Partition(left, right, pivot_index);  //进行划分，返回划分边界
	int num = divide_index - left + 1;
	if (num == k)//如果分界线刚好在k位置，直接返回该下标
		return divide_index;
	else if (num > k)//如果分界线在k左边，递归左区间
		return KthNumber(left, divide_index - 1, k);
	else //如果分界线在k右边，递归右区间，并修改k值
		return KthNumber(divide_index + 1, right, k - num);
}

void run() {
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;++i) {
		cin >> Array[i];
	}
	printf("第%d小的值为:%d\n", k, Array[KthNumber(0, n - 1, k)]);
}

int main() {
	run();
	return 0;
}

