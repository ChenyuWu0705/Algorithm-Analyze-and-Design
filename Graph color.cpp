#include<bits/stdc++.h>
using namespace std;
int c[100][100]; //邻接矩阵
int color[100];  //记录每个顶点的颜色 
int count,m,n; //count记录方案数 n个顶点 m种颜色 
int Check(int k){    //检查第i个顶点的颜色是否满足条件 
	for(int i=1;i<=k;i++){
		if(c[k][i]==1&&color[i]==color[k]) //k与i之间相连并且i顶点的颜色与k顶点的颜色相同 
		return 0;	
	}	
	return 1;	
} 
 
void GraphColor(int step)  {
	if(step==n+1){  //表示前面所有的顶点颜色都已经填完 
		for(int i=1;i<=n;i++)
			printf("%d ",color[i]);
		count++;
		printf("\n");
		return ;
	}else{
		for(int i=1;i<=m;i++){
			color[step]=i;   //首先将这个顶点颜色换为i 
			if(Check(step)==1){  //检查是否符合条件 
				GraphColor(step+1); //符合条件则走下一步 
			}		
			color[step]=0;  //回溯 置为0 
		}
	}
}
 
int main(){
	int a,b;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
				cin>>c[i][j];
	GraphColor(1);
	printf("%d",count);
	return 0;	
}
 
