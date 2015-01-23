#include<cstdio>

int n,a[20];
bool h[20];

void dfs(int x)
{
	if(x>n)
	{
		for(int i=1;i<n;i++) printf("%d ",a[i]);
		printf("%d\n",a[n]);
		return;
	}
	for(int i=1;i<=n;i++)
	if(!h[i])
	{
		a[x]=i;h[i]=true;
		dfs(x+1);
		h[i]=false;
	}
}

int main()
{
	scanf("%d",&n);
	dfs(1);
	return 0;
}
