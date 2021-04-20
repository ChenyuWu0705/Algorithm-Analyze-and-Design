#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e6 + 100;
int Array[N];
int n, k;
int KthNumber(int left, int right, const int& k);

/* ������ţ����鷵����λ���±� */
int GetPivotIndex(int left, int right) {
	sort(Array + left, Array + right + 1);
	return ((right - left) >> 1) + left;
}

/* ������λ������λ���±� */
int GetPivotOfPivotIndex(int left, int right) {
	if (right - left < 5)
		return GetPivotIndex(left, right);
	int pos = left - 1;
	for (int i = left; i + 4 <= right; i += 5) {
		int index = GetPivotIndex(i, i + 4);  //�ҵ����Ԫ�ص���λ�����±�
		swap(Array[++pos], Array[index]);   //���η������
	}
	return KthNumber(left, pos, ((pos - left + 1) >> 1) + 1);
}

/* ������λ������λ�����±���л��֣����طֽ����±� */
int Partition(int left, int right, int pivot_index) {
	swap(Array[pivot_index], Array[right]);  //�ѻ�׼������ĩβ
	int divide_index = left;  //���ٻ��ֵķֽ���
	for (int i = left; i < right; i++) {
		if (Array[i] < Array[right])
			swap(Array[divide_index++], Array[i]);  //�Ȼ�׼С�Ķ��������
	}
	swap(Array[divide_index], Array[right]);  //���ѻ�׼������
	return divide_index;
}

int KthNumber(int left, int right, const int& k) {
	int pivot_index = GetPivotOfPivotIndex(left, right);   //�õ���λ������λ���±�
	int divide_index = Partition(left, right, pivot_index);  //���л��֣����ػ��ֱ߽�
	int num = divide_index - left + 1;
	if (num == k)//����ֽ��߸պ���kλ�ã�ֱ�ӷ��ظ��±�
		return divide_index;
	else if (num > k)//����ֽ�����k��ߣ��ݹ�������
		return KthNumber(left, divide_index - 1, k);
	else //����ֽ�����k�ұߣ��ݹ������䣬���޸�kֵ
		return KthNumber(divide_index + 1, right, k - num);
}

void run() {
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;++i) {
		cin >> Array[i];
	}
	printf("��%dС��ֵΪ:%d\n", k, Array[KthNumber(0, n - 1, k)]);
}

int main() {
	run();
	return 0;
}

