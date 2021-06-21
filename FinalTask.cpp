#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int dp[N];
int cost[N];//���������ѵ�ʱ��
int vis[N][N];//������� 
int check[N];//��������ĸ����� 
int n;//���������
int sum = 0;//�����ܹ����ѵ�ʱ��
void FindSchedule(int n, int sum) {
	//DFS���������ҷ��� 
	if (n == 0)return;
	if (vis[n][sum] == 0) {
		FindSchedule(n - 1, sum);
	}
	else {
		FindSchedule(n - 1, sum - cost[n]);
		check[cost[n]] = 1;
	}
}
void run() {
	printf("���������������:\n");
	scanf("%d", &n);
	puts("-------------------");
	for (int i = 1;i <= n;i++) {
		printf("����������%d�ļӹ�ʱ��:\n", i);
		scanf("%d", &cost[i]);
		sum += cost[i];
	}
	puts("-------------------");
	vis[0][0] = 1; 
	for (int i = 1;i <= n;i++) { //01���� 
		for (int j = sum / 2;j >= cost[i];j--) {
			dp[j] = max(dp[j - cost[i]] + cost[i], dp[j]);
			if (dp[j] == dp[j - cost[i]] + cost[i]) {
				vis[i][j] = 1;
			}
		}
	}
	FindSchedule(n, sum / 2);
	printf("����1�ļӹ�������:\n");
	for (int i = 1;i <= n;i++) {
		if (check[i])printf("%d ", i);
	}
	puts("\n-------------------");
	printf("����2�ļӹ�������:\n");
	for (int i = 1;i <= n;i++) {
		if (!check[i])printf("%d ", i);
	}
	puts("\n-------------------");
	printf("������Ҫ���ѵļӹ�ʱ��:%d\n", sum - dp[sum / 2]);
}
int main() {
	run();
	return 0;
}
