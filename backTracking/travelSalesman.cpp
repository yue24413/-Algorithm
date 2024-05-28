#include<stdio.h>
##define N 4
#define NO_PATH -1
#define Max_WEIGHT 4000
int City_Graph[N+1][N+1];
int x[N+1];//x[i]保存第i步遍历的城市
int isIn[N+1];//i是否加入路径
int bestw;//最有路径总权值
int cw;//当前路径总权值
int bw;//深度搜索完成总权值
int bestx[N+1]；//最优路径
void Travel_Backtrack(int t)
{
int i;
if(t>N)
for(i=1;i<=N;i++)
    printf("%d ",x[i]);
printf("\n");
//计算总权值，非最优
bw=cw+City_Graph[x[N]][1];//最后一个地方走回1点
if(bw<bestw)
{
for(i=1;i<=N;i++)
    bestx[i]=x[i];
    bestw=bw;
}
return ;
}
else{
for(j=2;j<=N;j++)
{
if(City_Graph[x[t-1]][j] != NO_PATH &&
! isIn[j])
{
isIn[j]=1;
x[t]=j;
cw+=City_Graph[x[t-1]][j];
Travel_Backtrack[t+1];
isIn[j]=0;
x[t]=0;
cw-=City_Graph[x[t-1]][j];
}}}}
void main()
{
int i;
//建立邻接矩阵
//City_Graph[1][1]=
//.....
for(i=1;i<=N;i++)
{
x[i]=0;
bestx[i]=0;
isIn[i]=0;
}
x[1]=1;
isIn[1]=1;
bestw=Max_WEIGHT;
cw=0;
Travel_Backtrack(2);
printf("最优值为：%d\n",bestw);
printf("最优解为：");
for(i=1;i<=N;i++)
printf("%d ",bestx[i]);
}