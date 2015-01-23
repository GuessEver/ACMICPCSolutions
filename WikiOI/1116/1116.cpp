#include<cstdio>

int n;
int ans=0;
int a[100][100];
int c[100];

void dfs(int x)
{
	if(x>n) {ans++;return;}
	bool h[6]={0};
	for(int i=1;i<x;i++)
		if(a[x][i]) h[c[i]]=1;
	for(int i=1;i<=4;i++)
		if(!h[i])
		{
			c[x]=i;
			dfs(x+1);
			c[x]=0;
		}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
