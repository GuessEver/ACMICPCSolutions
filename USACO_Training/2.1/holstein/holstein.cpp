/*
LANG: C++
TASK: holstein
ID: jiangzh15
*/
#include<cstdio>
#include<string>
using std::string;
const int N=50;

int V,G,need[N],offer[N][N];
int tmp[N],ok[N];

bool check(int *a)
{
	for(int j=1;j<=V;j++)
	{
		int now=0;
		for(int i=1;i<=G;i++)
			if(a[i]) now+=offer[i][j];
		if(now<need[j]) return 0;
	}
	return 1;
}
bool smaller(int *a,int *b)
{
	string sa="",sb="";
	for(int i=1;i<=G;i++)
	{
		if(a[i]) sa+=(i+'0');
		if(b[i]) sb+=(i+'0');
	}
	return sa<sb;
}

void dfs(int x,int sum)
{
	if(sum>ok[0]) return;
	if(x>G)
	{
		if(check(tmp) && (sum<ok[0] || (sum==ok[0] && smaller(tmp,ok))) )
		{
			ok[0]=sum;
			for(int i=1;i<=G;i++) ok[i]=tmp[i];
		}
		return;
	}
	tmp[x]=1;
	dfs(x+1,sum+1);
	tmp[x]=0;
	dfs(x+1,sum);
}

int main()
{
	freopen("holstein.in","r",stdin);
	freopen("holstein.out","w",stdout);
	scanf("%d",&V);
	for(int i=1;i<=V;i++) scanf("%d",&need[i]);
	scanf("%d",&G);
	for(int i=1;i<=G;i++)
		for(int j=1;j<=V;j++)
			scanf("%d",&offer[i][j]);
	ok[0]=G; for(int i=1;i<=G;i++) ok[i]=1;
	dfs(1,0);
	printf("%d ",ok[0]);
	for(int i=1;i<=G;i++) if(ok[i])
	{
		printf("%d",i);
		if(--ok[0]) printf(" ");
	}
	printf("\n");
	return 0;
}
