#include<cstdio>
#include<string>
#define MAXN 100+10
#define oo 99999999

int n,m,map[MAXN][MAXN],dist[MAXN],sum;
bool h[MAXN];

int main()
{
  //freopen("rqn370.in","r",stdin);
  //freopen("rqn370.out","w",stdout);
  scanf("%d%d",&n,&m);
  int i,x,y,z;
  for(i=1;i<=m;i++) {scanf("%d%d%d",&x,&y,&z);map[x][y]=z;map[y][x]=z;sum+=z;}
  memset(dist,63,sizeof(dist));
  dist[1]=0;
  int j,k,min,total=0;
  for(i=1;i<=n;i++)
  {
    k=0;min=oo;
    for(j=1;j<=n;j++)
      if(!h[j] && min>dist[j]){min=dist[j];k=j;}
    h[k]=true;
    total+=dist[k];
    for(j=1;j<=n;j++)
      if(!h[j] && map[k][j]!=0 && dist[j]>map[k][j]) dist[j]=map[k][j];
  }
  printf("%d\n",sum-total);
  return 0;
}

