#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int T[110]={0,
1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,
38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,
55,56,57,58,59,60,61,62,63,64,65,66,67,68,69,70,71,
72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,
89,90,91,92,93,94,95,96,97,98,99,100
};
int x,pos;
int main(){
	printf("请输入要查找的数:\n");
	cin>>x;
	l <- 1
	r <- 100
	while(r>=l){
		mid <- (l+r)/2;
		if(T[mid]<=x)l <- mid+1,pos <- mid;
		else r=mid-1;
	} 
	printf("%d在数组中的下标:%d\n",x,pos);
} 
