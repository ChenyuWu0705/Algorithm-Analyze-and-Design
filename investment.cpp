#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m;
int f[N][N],F[N][N];
int main() {
	cin>>n>>m;
	for (int j=1;j<=m;j++) 
		for (int i=1;i<=n;i++) 
			cin>>f[i][j];
	for (int i=1;i<=n;i++) { //ö��Ͷ�ʸ��� 
		for (int j=0;j<=m;j++) {//ö��ǰi��Ͷ�ʵ�Ǯ 
			for (int k=0;k<=j;k++) {//ö�ٵ�i��Ͷ�ʵ�Ǯ 
				F[i][j] = max(F[i][j],F[i-1][j-k] + f[i][k]);
			}
		}
	}
	printf("max reward is %d\n",F[n][m]);
	return 0;
}
