#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int n,m,k;
int w[N],v[N],dp[N];
void run() {
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		cin>>w[i]>>v[i];
	}
	for (int i=1;i<=n;i++) {
		for (int j=w[i];j<=m;j++) {
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[m]<<endl;
}
int main() {
	run();
	return 0;
}


