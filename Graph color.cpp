#include<bits/stdc++.h>
using namespace std;
int c[100][100]; //�ڽӾ���
int color[100];  //��¼ÿ���������ɫ 
int count,m,n; //count��¼������ n������ m����ɫ 
int Check(int k){    //����i���������ɫ�Ƿ��������� 
	for(int i=1;i<=k;i++){
		if(c[k][i]==1&&color[i]==color[k]) //k��i֮����������i�������ɫ��k�������ɫ��ͬ 
		return 0;	
	}	
	return 1;	
} 
 
void GraphColor(int step)  {
	if(step==n+1){  //��ʾǰ�����еĶ�����ɫ���Ѿ����� 
		for(int i=1;i<=n;i++)
			printf("%d ",color[i]);
		count++;
		printf("\n");
		return ;
	}else{
		for(int i=1;i<=m;i++){
			color[step]=i;   //���Ƚ����������ɫ��Ϊi 
			if(Check(step)==1){  //����Ƿ�������� 
				GraphColor(step+1); //��������������һ�� 
			}		
			color[step]=0;  //���� ��Ϊ0 
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
 
