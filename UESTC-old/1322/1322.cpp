#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))
const int N=200+10;
const int Q=10000+10;
const int inf=0x3f3f3f3f;

int n,m,q,g[N][N];
int destroyed[N];
int x[Q],y[Q],op[Q];
int ans[Q],Cnt;

void read()
{
	scanf("%d%d",&n,&m);
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++) g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(z<g[x][y]) g[x][y]=g[y][x]=z;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&op[i],&x[i]);
		if(op[i]==0)
			scanf("%d",&y[i]);
		if(op[i]==1) destroyed[x[i]]=1;
	}
}

void floyd(int k)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(g[i][j]>g[i][k]+g[k][j])
				g[i][j]=g[i][k]+g[k][j];
}

void work()
{
	for(int i=1;i<=n;i++)
		if(!destroyed[i]) floyd(i);
	for(int i=q;i>0;i--)
	{
		if(op[i]==1)
		{
			destroyed[x[i]]=0;
			floyd(x[i]);
		}
		else{
			if(destroyed[x[i]]||destroyed[y[i]]) 
				ans[Cnt++]=-1;
			else if(g[x[i]][y[i]]==inf)
				ans[Cnt++]=-1;
			else ans[Cnt++]=g[x[i]][y[i]];
		}
	}
	for(int i=Cnt-1;i>=0;i--)
		printf("%d\n",ans[i]);
}

int main()
{
	freopen("1322.in","r",stdin);
	freopen("1322.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)
	{
		memset(destroyed,0,sizeof(destroyed));
		memset(ans,0,sizeof(ans)); Cnt=0;
		read();
		work();
		printf("\n");
	}
	return 0;
}
