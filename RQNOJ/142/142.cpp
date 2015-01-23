#include<cstdio>
#include<cstring>
using namespace std;
#define MAX 100+10
#define oo 99999;
int dist[MAX],map[MAX][MAX],n;
bool h[MAX];

int main()
{
  //freopen("rqn142.in","r",stdin);
  //freopen("rqn142.out","w",stdout);
  int i,j,x;
  scanf("%d",&n);    
  memset(map,63,sizeof(map));
  for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
      scanf("%d",&x);
      if(i==j)continue;
      map[i][j]=x;
    }
  memset(dist,63,sizeof(dist));
  dist[1]=0;
  int k,min;
  int total=0;
  for(i=1;i<=n;i++)
  {
    //find min
    k=0;min=oo;
    for(j=1;j<=n;j++)
      if(!h[j] && min>dist[j]){min=dist[j];k=j;}
    //color
    h[k]=true;
    total+=dist[k];
	//renew
    for(j=1;j<=n;j++)
      if(!h[j] && dist[j]>map[k][j])dist[j]=map[k][j];
  }
  printf("%d",total);
  return 0;
}

