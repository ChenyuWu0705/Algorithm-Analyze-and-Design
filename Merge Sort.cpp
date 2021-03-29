#include<bits/stdc++.h>
const int N=1e5+100;
int A[N];
int B[N];
void merge(int L, int R) {//有序数组的归并
	int len = (L + R >> 1) - L+1;
	int posl = L;//L数组的起始位置
	int posr = L + len;//R数组的起始位置
	int posb = L;
	while (posl < L + len && posr <= R) {
		//从开始位置比较，如果L数组的元素大于R数组，则将L数组的元素存进去一个，然后位置+1，否则相反
		if (A[posl] <= A[posr])
			B[posb++] = A[posl++];
		else
			B[posb++] = A[posr++];
	}
	while (posl < L + len)//如果L数组没有放完就直接放在最后面
		B[posb++] = A[posl++];
	while (posr <= R )//如果R数组没有放完就直接放在最后面
		B[posb++] = A[posr++];
}
void mergesort(int L, int R) {
	if (R == L)  return;//递归到每组只有一个元素返回，因为此时必定有序
	int mid = L + R >> 1;//找到每个分块的中间值
	mergesort(L, mid);//左边递归进行分离和合并
	mergesort(mid+1, R);//右边递归进行分离和合并
	merge(L, R);//左右合并
	for (int i = L; i <= R;++i)A[i] = B[i];//排好序的结果传给A数组
}
int main() {
	int length = 100;
	for (int i = 1;i <= length;i++)A[i] = rand() % 10000;//随机生成100个小于10000的整数 
	printf("原数组:\n");
	for (int i = 1;i <= length;i++)printf("%d ", A[i]);
	printf("\n排序后数组:\n");
	mergesort(1, length);//归并排序
	for (int i = 1;i <= length;i++)printf("%d ", B[i]);
}
