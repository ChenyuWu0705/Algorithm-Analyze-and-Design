#include<bits/stdc++.h>
using namespace std;
const int N=5050;
const int M=10010;
struct Edge{
	int u, v, w;
}edge[M];//{u,v,w}�����u->v��һ������Ϊw�ı� 
int fa[N], n, m;
int find(int x){
	return x == fa[x] ? x : fa[x]=find(fa[x]);//·��ѹ��+�������Ƚڵ� 
}
bool cmp(Edge a, Edge b){//����ʽ���߳��̵���ǰ�� 
	return a.w < b.w;
}
int kruskal(){
	int ans = 0,cnt = 0;
	sort(edge, edge + m, cmp);//�������� 
	for ( int i = 0;i < m;i++){
		int fu = find(edge[i].u);//���Ҷ���u�����Ƚڵ� 
		int fv = find(edge[i].v);//���Ҷ���v�����Ƚڵ� 
		if (fu != fv){//��������ɻ�����MST�м��ϸ����� 
			ans += edge[i].w;
			fa[fv] = fu;//���¶���v�ĸ��ڵ� 
			if (++cnt == n - 1)return ans;// �ҵ�MST����MST��Ȩֵ 
		}
	}
	return -1;
}
int main(){
	cin>>n>>m;
	for ( int i = 1;i <= n;i++)fa[i] = i;//��ʼ�����׽ڵ� 
	for ( int i = 0;i < m;i++){
		cin>>edge[i].u>>edge[i].v>>edge[i].w;//����� 
	}
	int val=kruskal();
	if (val == -1)cout << "Can't build MST"<<endl;
	else cout << "tha val of MST = " << val << endl;
	return 0;
}
