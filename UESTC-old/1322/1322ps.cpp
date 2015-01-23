#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
const int N=200+10;
const int Q=10000+10;
const int inf=0x3f3f3f3f;

int n,m,g[N][N],h[N][N];
int hash[N];
int q;

void read()
{
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z<g[x][y]) g[x][y]=g[y][x]=z;
	}
}

void floyd()
{
	for(int k=1;k<=n;k++)if(!hash[k])
		for(int i=1;i<=n;i++)if(!hash[i])
			for(int j=1;j<=n;j++)if(!hash[j])
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);
}

void work()
{
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) h[i][j]=g[i][j];
	floyd();
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int op,x,y;
		scanf("%d%d",&op,&x);
		if(op==0)
		{
			scanf("%d",&y);
			if(g[x][y]==inf||hash[x]||hash[y]) printf("-1\n");
			else printf("%d\n",g[x][y]);
		}
		if(op==1)
		{
			hash[x]=1;
			for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) g[i][j]=h[i][j];
			floyd();
		}
	}
}

int main()
{
	freopen("1322.in","r",stdin);
	freopen("1322ps.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)
	{
		memset(hash,0,sizeof(hash));
		read();
		work();
		printf("\n");
	}
	return 0;
}
