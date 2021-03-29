#include<bits/stdc++.h>
const int N=1e5+100;
int A[N];
int B[N];
void merge(int L, int R) {//��������Ĺ鲢
	int len = (L + R >> 1) - L+1;
	int posl = L;//L�������ʼλ��
	int posr = L + len;//R�������ʼλ��
	int posb = L;
	while (posl < L + len && posr <= R) {
		//�ӿ�ʼλ�ñȽϣ����L�����Ԫ�ش���R���飬��L�����Ԫ�ش��ȥһ����Ȼ��λ��+1�������෴
		if (A[posl] <= A[posr])
			B[posb++] = A[posl++];
		else
			B[posb++] = A[posr++];
	}
	while (posl < L + len)//���L����û�з����ֱ�ӷ��������
		B[posb++] = A[posl++];
	while (posr <= R )//���R����û�з����ֱ�ӷ��������
		B[posb++] = A[posr++];
}
void mergesort(int L, int R) {
	if (R == L)  return;//�ݹ鵽ÿ��ֻ��һ��Ԫ�ط��أ���Ϊ��ʱ�ض�����
	int mid = L + R >> 1;//�ҵ�ÿ���ֿ���м�ֵ
	mergesort(L, mid);//��ߵݹ���з���ͺϲ�
	mergesort(mid+1, R);//�ұߵݹ���з���ͺϲ�
	merge(L, R);//���Һϲ�
	for (int i = L; i <= R;++i)A[i] = B[i];//�ź���Ľ������A����
}
int main() {
	int length = 100;
	for (int i = 1;i <= length;i++)A[i] = rand() % 10000;//�������100��С��10000������ 
	printf("ԭ����:\n");
	for (int i = 1;i <= length;i++)printf("%d ", A[i]);
	printf("\n���������:\n");
	mergesort(1, length);//�鲢����
	for (int i = 1;i <= length;i++)printf("%d ", B[i]);
}
