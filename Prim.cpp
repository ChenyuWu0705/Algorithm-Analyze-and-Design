#include<bits/stdc++.h>
using namespace std;
const int N=5050;
int graph[N][N];
bool vis[N];
int dis[N];
int Prim(int graph[][N], bool vis[], int dis[],int n) {
	//graph[]����洢���ǵ�֮��ľ���  
	//dis[]�洢���ǳ�ʼ�㵽����ľ���
	//vis[]�洢�õ��Ƿ񱻱�ǹ�
	//n�����ĸ���

	int ans = 0;//��С��������Ȩֵ��

	for (int i = 1;i <= n;i++) {
		vis[i] = false;
		dis[i] = graph[1][i];
	}//��ʼ������
	vis[1] = true;//��ǳ�ʼ��
	for (int i = 2;i <= n;i++) {
		int minn = 0x3f3f3f3f;
		int index = -1;
		for (int j = 1;j <= n;j++) {
			if (vis[j] == false && dis[j] < minn) {
				//Ѱ��δ��ǵ㼯���о����ѱ�ǵ㼯������ĵ㣬���ҵ�����¼�±꣬�޸�minn
				minn = dis[j];
				index = j;
			}
		}
		if (index == -1) {//δ�ҵ����Խ��б�ǵĵ㣬˵����ͼ����ͨ
			return -1;
		}
		vis[index] = true;//�ҵ��ĵ���ϱ��
		ans +=minn;//���ϸöξ����Ȩֵ
		for (int j = 1;j <= n;j++) {
			//ͨ���ҵ��ĵ������δ��ǵĵ�����ɳڲ���
			if (vis[j] == false && graph[index][j] < dis[j]) {
				dis[j] = graph[index][j];
			}
		}
	}
	return ans;//����Ȩֵ��
}
void run() {
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		for (int j = 1;j <= n;j++) {
			graph[i][j] = 0x3f3f3f3f;
			if (i == j)graph[i][j] = 0;
		}
	}//��ʼ��ͼ�ľ��� 
	for(int i=1;i<=m;i++){
		//�������� 
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
