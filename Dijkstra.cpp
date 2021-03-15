#include<bits/stdc++.h>
using namespace std;
const int N=1010;
#define inf 0x3f3f3f3f
int mp[N][N];
int n,m,x,y,d,start,target;
bool vis[N];
int dis[N];
void Dijkstra(int mp[][1010],bool* vis,int start,int target,int* dis){
	//mp[][]��ʾ����֮��ֱ�������ľ���
	//vis[]��Ǿ���
	//dis[]������㵽ĳ�������̾��� 
	for(int i=1;i<=n;i++)vis[i]=false,dis[i]=inf;//��ʼ������ 
	vis[start]=true; 
	for(int i=1;i<=n;i++)dis[i]=mp[start][i];//������ֱ�ӵ���ĵ㸳��ֵ 
	for(int i=1;i<=n;i++){
		int minn=inf;
		int pos=-1;
		for(int j=1;j<=n;j++){
			if(vis[j]==0 && dis[j]<minn){//Ѱ��δ����Ҿ����������ĵ㣬������Сֵ����¼�¸õ� 
				minn=dis[j];
				pos=j;
			}
		}
		vis[pos]=1;
		for(int i=1;i<=n;i++){
			if(dis[i]>dis[pos]+mp[pos][i]){//�����ҵ���������ɳڸ����㵽���ľ��� 
				dis[i]=dis[pos]+mp[pos][i];
			}
		}
	}
}
int main(){
	cin>>n>>m>>start>>target;
	for (int i = 1;i < N;i++){ //��ʼ������
		for (int j = 1;j < N;j++) {
			if(i==j)mp[i][j] = 0;
			else mp[i][j] = inf;
		}
	}
	for (int i = 1;i <= m;i++){
		cin>>x>>y>>d;
		if (mp[x][y] > d)mp[x][y] = mp[y][x] = d;//��ƽ�б� ����Ϊ��С�ı�Ȩ
	}
	Dijkstra(mp,vis,start,target,dis);
	printf("��%d����%d����̾���Ϊ:%d\n",start,target,dis[target]);
}
/*
7 12 2 5
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
