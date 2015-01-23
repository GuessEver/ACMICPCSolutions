#include<cstdio>
#include<string>
#define MAXN 1000+10
#define oo 99999999

int n,map[MAXN][MAXN],dist[MAXN];
bool h[MAXN];

int main()
{
  //freopen("rqn564.in","r",stdin);
  //freopen("rqn564.out","w",stdout);
  scanf("%d",&n);
  int i,j,max=0;
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
      scanf("%d",&map[i][j]);
      max+=map[i][j];
    }
  for(i=1;i<=n;i++)dist[i]=oo;
  dist[1]=0;
  int k,min,sum=0;
  for(i=1;i<=n;i++)
  {
    k=0;min=oo;
    for(j=1;j<=n;j++)
      if(!h[j] && min>dist[j]){min=dist[j];k=j;}
    if(min==oo){sum=-1;break;}
    h[k]=true;
    sum+=dist[k];
    for(j=1;j<=n;j++)
      if(!h[j] && map[k][j]!=0 && dist[j]>map[k][j]) dist[j]=map[k][j];
  }
  if(sum==max) printf("N");
  else printf("Y");
  return 0;
}

