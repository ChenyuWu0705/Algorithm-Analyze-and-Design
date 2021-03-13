#include<bits/stdc++.h>
using namespace std;
const int N=5050;
const int M=10010;
struct Edge{
	int u, v, w;
}edge[M];//{u,v,w}代表从u->v有一条长度为w的边 
int fa[N], n, m;
int find(int x){
	return x == fa[x] ? x : fa[x]=find(fa[x]);//路径压缩+查找祖先节点 
}
bool cmp(Edge a, Edge b){//排序方式，边长短的在前面 
	return a.w < b.w;
}
int kruskal(){
	int ans = 0,cnt = 0;
	sort(edge, edge + m, cmp);//给边排序 
	for ( int i = 0;i < m;i++){
		int fu = find(edge[i].u);//查找顶点u的祖先节点 
		int fv = find(edge[i].v);//查找顶点v的祖先节点 
		if (fu != fv){//如果不构成环，在MST中加上该条边 
			ans += edge[i].w;
			fa[fv] = fu;//跟新顶点v的父节点 
			if (++cnt == n - 1)return ans;// 找到MST返回MST的权值 
		}
	}
	return -1;
}
int main(){
	cin>>n>>m;
	for ( int i = 1;i <= n;i++)fa[i] = i;//初始化父亲节点 
	for ( int i = 0;i < m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;//读入边 
	}
	int val=kruskal();
	if (val == -1)cout << "Can't build MST"<<endl;
	else cout << "tha val of MST = " << val << endl;
	return 0;
}
