#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int dp[N];
int cost[N];//任务所花费的时间
int vis[N][N];//标记数组 
int check[N];//任务归属哪个机器 
int n;//任务的数量
int sum = 0;//代表总共花费的时间
void FindSchedule(int n, int sum) {
	//DFS回溯来查找方案 
	if (n == 0)return;
	if (vis[n][sum] == 0) {
		FindSchedule(n - 1, sum);
	}
	else {
		FindSchedule(n - 1, sum - cost[n]);
		check[n] = 1;
	}
}
void run() {
	printf("请输入任务的数量:\n");
	scanf("%d", &n);
	puts("-------------------");
	for (int i = 1;i <= n;i++) {
		printf("请输入任务%d的加工时间:\n", i);
		scanf("%d", &cost[i]);
		sum += cost[i];
	}
	puts("-------------------");
	vis[0][0] = 1; 
	for (int i = 1;i <= n;i++) { //01背包 
		for (int j = sum / 2;j >= cost[i];j--) {
			dp[j] = max(dp[j - cost[i]] + cost[i], dp[j]);
			if (dp[j] == dp[j - cost[i]] + cost[i]) {
				vis[i][j] = 1;
			}
		}
	}
	FindSchedule(n, sum / 2);
	printf("机器1的加工的任务:\n");
	for (int i = 1;i <= n;i++) {
		if (check[i])printf("%d ", i);
	}
	puts("\n-------------------");
	printf("机器2的加工的任务:\n");
	for (int i = 1;i <= n;i++) {
		if (!check[i])printf("%d ", i);
	}
	puts("\n-------------------");
	printf("最少需要花费的加工时间:%d\n", sum - dp[sum / 2]);
}
int main() {
	run();
	return 0;
}
