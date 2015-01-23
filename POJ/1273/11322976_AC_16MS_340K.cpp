#include<cstdio>
#include<cstring>
const int N=200+10;
const int inf=0x3f3f3f3f;
#define min(a,b) ((a)<(b)?(a):(b))
int n,m;
int g[N][N];
int h[N],v[N];

int dfs(int x,int flow)
{
	if(x==n) return flow;
	int res=0;
	for(int i=1;i<=n;i++)
	if(g[x][i]>0 && h[x]==h[i]+1)
	{
		int t=dfs(i,min(g[x][i],flow-res));
		g[x][i]-=t;g[i][x]+=t;res+=t;
		if(res==flow) return res;
	}
	if(h[1]>=n) return res;
	if(--v[h[x]]==0) h[1]=n;
	v[++h[x]]++;
	return res;
}

int main()
{
	//freopen("ditch.in","r",stdin);
	//freopen("ditch.out","w",stdout);
	while(scanf("%d%d",&m,&n)==2)
	{
		memset(g,0,sizeof(g));
		memset(h,0,sizeof(h));
		memset(v,0,sizeof(v));
		for(int i=1;i<=m;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			g[x][y]+=z;
		}
		int res=0;
		v[0]=n;
		while(h[1]<n) res+=dfs(1,inf);
		printf("%d\n",res);
	}
	return 0;
}
