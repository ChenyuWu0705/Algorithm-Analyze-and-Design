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
int dis(int a, int b) {//������֮��ľ��� 
	return (p[a].x - p[b].x) * (p[a].x - p[b].x) + (p[a].y - p[b].y) * (p[a].y - p[b].y);
}
void merge(int l, int r) {//�鲢����l��r�����ڵĵ� 
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
	if (l >= r)return INT_MAX;//���ֻ��һ���㷵������� 
	if (l + 1 == r) {//���ֻ��������Ļ���l�����£�r������ 
		if (p[l].y > p[r].y) {
			swap(p[l], p[r]);
		}
		return dis(l, r);
	}
	int mid = l + r >> 1;
	int PointMid_x = p[mid].x;
	int cnt = 0;
	int d = min(GetMinDistance(l, mid), GetMinDistance(mid + 1, r));//������������ȡ������� 
	merge(l, r);//�鲢���� 
	for (int i = l;i <= r;++i) {//�ҳ��������߾���Ϊd֮��ĵ� 
		if ((p[i].x - PointMid_x) * (p[i].x - PointMid_x) < d) {
			interpoint[++cnt] = i;
		}
	}
	for (int i = 1;i <= cnt;++i) {//�����ҳ��ĵ㣬�޸���Сֵd 
		for (int j = i + 1;j <= cnt;++j) {
			int dist = (p[interpoint[j]].x - p[interpoint[i]].x) * (p[interpoint[j]].y - p[interpoint[i]].y);
			if (dist >= d)break;
			d = min(d, dis(interpoint[i], interpoint[j]));
		}
	}
	return d;//������Сֵd 
}
void run() {
	cin >> n;
	for (int i = 1;i <= n;++i) {//��������� 
		cin >> p[i].x >> p[i].y;
	}
	sort(p + 1, p + 1 + n, cmp);//�Ȱ���x��������С����������x����ͬ����y���С�������� 
	double ans = sqrt(GetMinDistance(1, n));
	cout << "ƽ�������Եľ���Ϊ��"<<ans << endl;

}
int main() {
	run();
	return 0;
}


