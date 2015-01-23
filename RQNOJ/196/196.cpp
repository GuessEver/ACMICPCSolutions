#include<cstdio>
#include<string>
#define MAXN 100+10
#define oo 99999999

int n,p,ans=0,map[MAXN][MAXN];
bool h[MAXN];

void dfs(int i)
{
  int k,min,j;
  while(true)
  {
    k=0;min=oo;
    for(j=1;j<=n;j++)
      if(!h[j] && map[i][j]>0 && min>map[i][j])
        {min=map[i][j];k=j;}
    if(min==oo) return;
    h[k]=true;
    ans+=map[i][k];//从 i 到 k 
    if(k==p){printf("%d",ans);exit(0);}
    dfs(k);
    ans+=map[i][k];//无路可走时从 k 回到 i 
  }
}

int main()
{
  //freopen("rqn196.in","r",stdin);
  //freopen("rqn196.out","w",stdout);
  scanf("%d%d",&n,&p);
  int i,s,t,l;
  for(i=1;i<=n-1;i++)
  {
    scanf("%d%d%d",&s,&t,&l);
    map[s][t]=l;map[t][s]=l;
  }
  h[0]=true;
  dfs(0);
  printf("%d",ans);
  return 0;
}

