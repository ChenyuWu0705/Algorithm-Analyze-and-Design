#include<bits/stdc++.h>
using namespace std;
const int num=100;
int n,c1,c2,w[num];// n个集装箱，A,B货轮载重量分别为C1，C2，W[i],第i个集装箱的重量
int cw,bw,rw;//cw，当前集装箱货物重量；bw，最优载重重量，rw，剩余集装箱重量；
int x[num],bx[num];//x[]，A货轮的当前结果；bx[]，A货轮的最优结果；
void BackTrack(int i) {
    //处理完了前n个集装箱；
    if(i>n){
        if(cw>bw){//cw，目前A中装了cw重量的集装箱；
        //更新最优解；
            bw=cw;
            for(int i=1;i<=n;i++) bx[i]=x[i];
        }    
        return;
    }
    //rw表示处理完第i个之后（选或不选），还剩下rw-w[i]重量的集装箱未处理；
    rw-=w[i];
    if(cw+w[i]<=c1){//cw，第i个货箱之前的重量 + 第i个货箱小于A的最大重量C1；
        cw+=w[i];//加上
        x[i]=1;//标记i被选
        BackTrack(i+1);
        cw-=w[i];//减去重量
        x[i]=0;//撤销标记；
    }
    //不选择第i个物品的话；
    //if cw：表示[1:i)的数据  rw:表示(i,n]的数据 ，不包括第i个的数据
    //如果不包括第i的数据的和（cw+rw） 大于  目前最优解bw，则可以递归下去；
    if(cw+rw > bw){
        x[i]=0;
        BackTrack(i+1);
    }

    //处理完第i个物品当前的情况了；
    //因为再上一层，有两种情况；
    //1；选择第i物品；
    //2：不选择第i个物品
    //如果目前处理的是上一层第1种情况，那么我们就有必要加上这个w[i];
    //否则会影响上一层处理第2种情况；
    rw+=w[i];
    return ;
}
int main(){
    scanf("%d%d%d",&n,&c1,&c2);
    for(int i=1;i<=n;i++) {
        scanf("%d",&w[i]);
        rw+=w[i];//rw表示目前最优集装箱的剩余重量；
    }
    //递归回溯
    BackTrack(1);
    //bw表示A货轮装下的货物重量；剩余的重量 > B可以放下的最多，则不可；
    if(rw-bw>c2){
        printf("没有装载方案\n");
    }else{
        printf("货轮A：\n");
        for(int i=1;i<=n;i++) {
			if(bx[i]) {
				printf("%d ",i);
			}
		} 
        printf("\n货轮B：\n");
        for(int i=1;i<=n;i++) {
			if(0==bx[i]) {
				printf("%d ",i);
			}
		} 
    }
    return 0;   
}
