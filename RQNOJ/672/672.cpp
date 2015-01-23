#include<cstdio>

int n,ans;
bool h[20],lie[20],ys[50],zs[100];

void dfs(int i)
{
  if(i>n){ans++;return;}
  for(int j=1;j<=n;j++)
    if(!h[i] && !lie[j] && !ys[i+j] && !zs[i-j+40])//[i-j+40]保证下标不为负数 
    {
      h[i]=true;lie[j]=true;ys[i+j]=true;zs[i-j+40]=true;
      dfs(i+1);
      h[i]=false;lie[j]=false;ys[i+j]=false;zs[i-j+40]=false;
    }
}

int main()
{
  //freopen("rqn672.in","r",stdin);
  //freopen("rqn672.out","w",stdout);
  scanf("%d",&n);
  dfs(1);
  printf("%d",ans);
  return 0;
}

