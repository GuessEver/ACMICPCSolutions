#include<cstdio>
#include<string>
using namespace std;
#define MAXN 10000+10
#define oo 99999999

int n,a[MAXN],f[MAXN][1];//f[i][0]当前是爬到的    f[i][1]当前是飞到的 

int main()
{
  //freopen("rqn82.in","r",stdin);
  //freopen("rqn82.out","w",stdout);
  scanf("%d",&n);
  int i;
  for(i=1;i<=n;i++) scanf("%d",&a[i]);  
  f[1][0]=a[1];
  for(i=2;i<=n;i++)
  {
   f[i][0]=min(f[i-1][0]+a[i],f[i-1][1]+a[i]);
   f[i][1]=min(f[i-1][0],f[i-2][0]);
  }
  printf("%d",min(f[n][0],f[n][1]));
  return 0;
}

