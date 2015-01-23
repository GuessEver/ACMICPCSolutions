#include<cstdio>
#define MAXN 100+10
#define MAXM 100000+10

int n,m,c[MAXN],r[MAXN],f[MAXM];

int main()
{
  //freopen("rqn671.in","r",stdin);
  //freopen("rqn671.out","w",stdout);
  scanf("%d%d",&n,&m);
  int i,j;
  for(i=1;i<=n;i++)scanf("%d%d",&c[i],&r[i]);
  for(i=1;i<=n;i++)
    for(j=c[i];j<=m;j++)
      f[j]>?=f[j-c[i]]+r[i]-c[i];
  int ans=0;
  for(j=1;j<=m;j++) ans>?=f[j]+m-j;
  printf("%d",ans);
  return 0;
}

