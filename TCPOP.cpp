#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n;
struct Point {
	int x, y;
}p[N], temp[N];
int interpoint[N];
bool cmp(Point a, Point b) {
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}
int dis(int a, int b) {//算两点之间的距离 
	return (p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y);
}
void merge(int l, int r) {//归并排序l到r区间内的点 
	int mid = l + r >> 1;
	int pos1 = l;
	int pos2 = mid + 1;
	int i;
	for (i = l;i <= r;++i) {
		if (p[pos1].y < p[pos2].y)temp[i] = p[pos1++];
		else temp[i] = p[pos2++];
		if (pos1 == mid + 1)break;
		if (pos2 == r + 1)break;
	}
	for (int j = i;j <= r && pos1 <= mid;j++) {
		temp[j] = p[pos1++];
	}
	for (int j = i;j <= r && pos2 <= r;j++) {
		temp[j] = p[pos2++];
	}
	for (int k = l;k <= r;++k)p[i] = temp[i];
}
int GetMinDistance(int l, int r) {
	if (l >= r)return INT_MAX;//如果只有一个点返回无穷大 
	if (l + 1 == r) {//如果只有两个点的话，l点在下，r点在上 
		if (p[l].y > p[r].y) {
			swap(p[l], p[r]);
		}
		return dis(l, r);
	}
	int mid = l + r >> 1;
	int PointMid_x = p[mid].x;
	int cnt = 0;
	int d = min(GetMinDistance(l, mid), GetMinDistance(mid + 1, r));//左右两个区间取最近距离 
	merge(l, r);//归并区间 
	for (int i = l;i <= r;++i) {//找出里中心线距离为d之间的点 
		if ((p[i].x - PointMid_x) * (p[i].x - PointMid_x) < d) {
			interpoint[++cnt] = i;
		}
	}
	for (int i = 1;i <= cnt;++i) {//遍历找出的点，修改最小值d 
		for (int j = i + 1;j <= cnt;++j) {
			int dist = (p[interpoint[j]].x - p[interpoint[i]].x) * (p[interpoint[j]].y - p[interpoint[i]].y);
			if (dist >= d)break;
			d = min(d, dis(interpoint[i], interpoint[j]));
		}
	}
	return d;//返回最小值d 
}
void run() {
	cin >> n;
	for (int i = 1;i <= n;++i) {//读入点坐标 
		cin >> p[i].x >> p[i].y;
	}
	sort(p + 1, p + 1 + n, cmp);//先按照x轴坐标由小到大排序，如x轴相同按照y轴从小到大排序 
	double ans = sqrt(GetMinDistance(1, n));
	cout << "平面最近点对的距离为："<<ans << endl;

}
int main() {
	run();
	return 0;
}


