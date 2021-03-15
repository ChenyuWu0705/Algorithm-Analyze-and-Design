#include<bits/stdc++.h>
using namespace std;
const int N=1010;
#define inf 0x3f3f3f3f
int mp[N][N];
int n,m,x,y,d;
int main(){
	cin>>n>>m;
	for (int i = 1;i < N;i++){ //初始化长度
		for (int j = 1;j < N;j++) {
			if(i==j)mp[i][j] = 0;
			else mp[i][j] = inf;
		}
	}
	for (int i = 1;i <= m;i++){
		cin>>x>>y>>d;
		if (mp[x][y] > d)mp[x][y] = mp[y][x] = d;//有平行边 更新为最小的边权
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
				//利用动态规划的思想松弛两点之间的距离 
			}
		}
	}
	printf("距离矩阵如下：\n");
	printf("    ");
	for(int i=1;i<=n;i++){
		printf("P%-2d ",i);
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("P%-2d ",i);
		for(int j=1;j<=n;j++){
			printf("%-4d",mp[i][j]);
		}
		printf("\n");
	}
}
/*
6 12
1 2 12
1 6 16
1 7 14
2 3 10
2 6 7
3 4 3
3 5 5
3 6 6
4 5 4
5 6 2
5 7 8
6 7 9 
*/
