#include<cstdio>
#define oo 99999999

int n,m,l,t[110],v[110],f[1010][110];

int main()
{
  //freopen("rqn95.in","r",stdin);
  //freopen("rqn95.out","w",stdout);
  scanf("%d%d%d",&n,&m,&l);
  int i,j,k;
  for(i=0;i<=l;i++)
    for(j=0;j<=m;j++)
      f[i][j]=-oo;
  f[0][0]=0;
  for(i=1;i<=n;i++)scanf("%d%d",&t[i],&v[i]);
  for(i=1;i<=n;i++)
    for(j=l;j>=t[i];j--)
      for(k=m;k>=1;k--)
        f[j][k]>?=f[j-t[i]][k-1]+v[i];
  int max=-oo;
  for(i=1;i<=l;i++)if(max<f[i][m])max=f[i][m];
  if(max>0)printf("%d",max);else printf("0");
  return 0;
}

