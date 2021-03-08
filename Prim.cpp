#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int graph[N][N];
bool vis[N];
int dis[N];
int Prim(int graph[][N], bool vis[], int dis[],int n) {
	//graph[]里面存储的是点之间的距离  
	//dis[]存储的是初始点到各点的距离
	//vis[]存储该点是否被标记过
	//n代表点的个数

	int ans = 0;//最小生成树的权值和

	for (int i = 1;i <= n;i++) {
		vis[i] = false;
		dis[i] = graph[1][i];
	}//初始化操作
	vis[1] = true;//标记初始点
	for (int i = 2;i <= n;i++) {
		int minn = 0x3f3f3f3f;
		int index = -1;
		for (int j = 1;j <= n;j++) {
			if (vis[j] == false && dis[j] < minn) {
				//寻找未标记点集合中距离已标记点集合最近的点，若找到，记录下标，修改minn
				minn = dis[j];
				index = j;
			}
		}
		if (index == -1) {//未找到可以进行标记的点，说明该图不连通
			return -1;
		}
		vis[index] = true;//找到的点打上标记
		ans +=minn;//加上该段距离的权值
		for (int j = 1;j <= n;j++) {
			//通过找到的点对所有未标记的点进行松弛操作
			if (vis[j] == false && graph[index][j] < dis[j]) {
				dis[j] = graph[index][j];
			}
		}
	}
	return ans;//返回权值和
}
void run() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			graph[i][j] = 0x3f3f3f3f;
			if (i == j)graph[i][j] = 0;
		}
	}//初始化图的距离 
	for(int i=1;i<=m;i++){
		//读入数据 
		int u,v,w;
		cin >> u >> v >> w;
		if(w<graph[u][v])graph[u][v] = graph[v][u] = w; 
	}
	int val=Prim(graph, vis, dis, n);
	if (val == -1)cout << "Can't build MST"<<endl;
	else cout << "tha val of MST = " << val << endl;
}
int main() {
		run();
	return 0;
}
