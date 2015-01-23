#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=200+10;
const int inf=0x3f3f3f3f;

int n,m;
int g[N][N];
int w[N][N];
int dist[N];
bool inq[N];
int pre[N];
int S,T;
queue<int> q;

void read()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int x; scanf("%d",&x);
			g[i][j+n]=1;
			w[i][j+n]=x;w[j+n][i]=-x;
		}
	S=0;T=n+m+1;
	for(int i=1;i<=n;i++)
	{
		g[S][i]=1;
		w[S][i]=0;
	}
	for(int j=1;j<=m;j++)
	{
		g[j+n][T]=1;
		w[j+n][T]=0;
	}
}

bool spfa()
{
	for(int i=S;i<=T;i++) dist[i]=-inf;
	memset(inq,0,sizeof(inq));
	dist[S]=0;
	q.push(S);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();inq[x]=false;
		for(int i=S;i<=T;i++)
		{
			if(g[x][i]>0)
			{
				//printf("%d -> %d\n",x,i);
				if(dist[i]<dist[x]+w[x][i])
				{
					pre[i]=x;
					dist[i]=dist[x]+w[x][i];
					if(!inq[i])
					{
						inq[i]=true;
						q.push(i);
					}
					//printf("x=%d -> i=%d : dist[i](%d)=dist[x](%d)+w[x][i](%d)\n",x,i,dist[i],dist[x],w[x][i]);
				}
			}
		}
	}
	return dist[T]!=-inf;
}

void work()
{
	memset(pre,-1,sizeof(pre));
	int maxflow=0,maxcost=0;
	while(spfa())
	{
		//printf("dist=%d\n",dist[T]);
		int res=1;
		for(int i=T;i!=S;i=pre[i])
		{
			g[pre[i]][i]-=res;
			g[i][pre[i]]+=res;
		}
		maxflow+=res;
		maxcost+=res*dist[T];
	}
	printf("%d\n",maxcost);
}

int main()
{
	read();
	work();
	return 0;
}
