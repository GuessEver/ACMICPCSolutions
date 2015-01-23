#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define maxn 350+10
#define maxm 120+10

int n,m,sum[6],a[maxn],f[2][maxm][maxm][maxm];// “1 ”的卡片用01滚动 

void init()
{ 
  freopen("tortoise.in","r",stdin);
  freopen("tortoise.out","w",stdout);  
}
void read()
{
  scanf("%d%d",&n,&m);
  int i,x;
  memset(sum,0,sizeof(sum));
  for(i=1;i<=n;i++) scanf("%d",&a[i]);
  for(i=1;i<=m;i++) {scanf("%d",&x);sum[x]++;}
}

void work()
{
  int s,i,j,k,t;
  for(s=0,i=0;s<=sum[1];s++,i=1-i)
    for(j=0;j<=sum[2];j++)
      for(k=0;k<=sum[3];k++)
        for(t=0;t<=sum[4];t++)
        { 
          if(s>=1) f[i][j][k][t]>?=f[1-i][j][k][t]+a[s+j*2+k*3+t*4];
          if(j>=1) f[i][j][k][t]>?=f[i][j-1][k][t]+a[s+j*2+k*3+t*4-1];
          if(k>=1) f[i][j][k][t]>?=f[i][j][k-1][t]+a[s+j*2+k*3+t*4-2];
          if(t>=1) f[i][j][k][t]>?=f[i][j][k][t-1]+a[s+j*2+k*3+t*4-3];//计算起点得分 
        }
  printf("%d",f[1-i][sum[2]][sum[3]][sum[4]]+a[n]);//加上最后终点得分 
 }

int main()
{
  //init();
  read();
  work();
  return 0;
}

