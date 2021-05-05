#include<bits/stdc++.h>
using namespace std;
const int N = 10;
int n,p[N];
int m[N][N], s[N][N];
void MatrixChainOrder(int* p, int Length){
	int q, n = Length - 1;
	for (int i = 1;i <= n;i++) m[i][i] = 0;
	for (int l = 2;l <= n;l++) { /* ö�پ������ĳ��� */
		for (int i = 1;i <= n - l + 1;i++){ /* ö����� */
			int j = i + l - 1;         
			m[i][j] = INT_MAX;  /*m[i][j]��ֵΪ����� */
			for (int k = i;k <= j - 1;k++){ /* ö�ٷָ�� */
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]){/*�����ǰֵ��С���޸Ĵ𰸣�����¼�·ָ�� */
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
}
void PrintChain(int i, int j){
	if (i == j) cout << "A" << i;
	else{
		cout << "(";
		PrintChain(i, s[i][j]);
		PrintChain(s[i][j] + 1, j);
		cout << ")";
	}
}
int main(){
	cin >> n;
	for (int i = 0;i <=n;i++)cin >> p[i];
	MatrixChainOrder(p, N);
	cout << "��n="<<n<<"ʱ���Ž�Ϊ: \n" << m[1][n]<<endl;
	cout << "���Ż�����Ϊ��"<<endl;
	PrintChain(1, n);
	return 0;
}
