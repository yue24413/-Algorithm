#include <stdio.h>
#define N 3    //物品的数量
#define C 16        //背包的容量
注意：下面的数组从1开始使用，用-1给下标是0的位置占上，-1没有意义。
int w[N+1]={-1,10,8,5};  //每个物品的重量
int v[N+1]={-1,5,4,1};   //每个物品的价值
int x[N+1]={-1,0,0,0};   //x[i]=1代表物品i放入背包，0代表不放入
int CurWeight = 0;  //当前放入背包的物品总重量
int CurValue = 0;   //当前放入背包的物品总价值
int BestValue = 0;  //最优值；当前的最大价值，初始化为0
int BestX[N+1]; //最优解；BestX[i]=1代表物品i放入背包，0代表不放入
void backtrack(int t)
{
   if(t>N)
    {
       if(CurValue>BestValue)
      {
        BestValue = CurValue;
		for(int i=1;i<=N;++i)
		BestX[i] = x[i];
      }
    }
   else
   {  //左子树
   if((CurWeight+w[t])<=C)
    {
   X[t]=1;
   CurWeight += w[t];
   CurValue += v[t];
   backtrack(t+1);
   CurWeight -= w[t];
   CurValue -= v[t];
    }
   //右子树
    if(bound(t+1)>BestValue)    //增加的代码
    {
    X[t]=0;
    backtrack(t+1);
    }
   }
}

int bound(int t)
{
   int cleft=C-CurWeight;
   int b=CurValue;
   while( t<=n  && w[t]<=cleft)
   {
     cleft=cleft-w[t];
     b=b+v[t];
     t++;
    }
    if( t<=n)  b=b+v[t]*cleft/w[t];
    return b;
}
void sort(int w,int v,int N){

}
int main()
{
    sort(w,v,N);  //依物品单位重量价值排序
    backtrack(1);
    printf("最优值：%d\n",BestValue);
    for(int i=1;i<=N;i++)
    {	printf("最优解：%-3d",BestX[i]);	}
    return 0;

}


