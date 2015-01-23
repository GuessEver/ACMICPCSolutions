#include<cstdio>
#include<string>
using namespace std;
#define MAXN 100010

int n,fs[MAXN],g[MAXN],f[MAXN][2];//f[区间起始位置][区间长度] 

void qs(int a[],int l,int r)
{
  int i=l,j=r,x=a[i+(j-i)/2];
  do
  {
    while(a[i]>x)i++;
    while(a[j]<x)j--;
    if(i<=j)
    {
      swap(a[i],a[j]);
      i++;j--;
    }
  }
  while(i<=j);
  if(i<r)qs(a,i,r);
  if(l<j)qs(a,l,j);
}

void predoing()
{
  int i,j;
  qs(fs,1,n);
  qs(g,1,n);
}

int main()
{
  //freopen("rqn303.in","r",stdin);
  //freopen("rqn303.out","w",stdout);
  int i,j,t,co;
  while(scanf("%d",&n))
  {
    if(n==0)exit(0);
    for(i=1;i<=n;i++) scanf("%d",&fs[i]);
    for(i=1;i<=n;i++) scanf("%d",&g[i]);
    predoing();
    t=0;
    for(i=1;i<=n;i++)
    {
      if(fs[i]<g[n])f[i][t]=-200;
      if(fs[i]>g[n])f[i][t]=200;
      if(fs[i]==g[n])f[i][t]=0;
    }
    t=1-t;
    for(j=2;j<=n;j++,t=1-t)
      for(i=1;i<=n-j+1;i++)
      {
        if(fs[i]>g[n-j+1])co=200;
        if(fs[i]<g[n-j+1])co=-200;
        if(fs[i]==g[n-j+1])co=0;
        
        f[i][t]=co+f[i+1][1-t];
        
        if(fs[i+j-1]>g[n-j+1])co=200;
        if(fs[i+j-1]<g[n-j+1])co=-200;
        if(fs[i+j-1]==g[n-j+1])co=0;
        
        if(f[i][t]<co+f[i][1-t])f[i][t]=co+f[i][1-t];
      }
    printf("%d\n",f[1][1-t]);
  }
  return 0;
}

