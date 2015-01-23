#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
const int N=100;
const int M=100*100*100;
const int inf=0x3f3f3f3f;
int worker,costomer,map[N][N];
struct EG{int from,to,flow,cost,next;}edge[M];
int head[M],L,S,T;
int dist[M],inQ[M],pre[M];
queue<int> Q;

void add_edge(int a,int b,int c,int d)
{
	edge[L]=(EG){a,b,c,+d,head[a]};
	head[a]=L++;
	edge[L]=(EG){b,a,0,-d,head[b]};
	head[b]=L++;
}

void read()
{
	memset(head,-1,sizeof(head));
	scanf("%d%d",&worker,&costomer);
	for(int i=1;i<=costomer;i++)
		for(int j=1;j<=worker;j++)
			scanf("%d",&map[j][i]);
	int cnt=costomer;
	for(int i=1;i<=worker;i++)
		for(int k=1;k<=costomer;k++)
		{
			++cnt;
			for(int j=1;j<=costomer;j++)
				add_edge(cnt,j,1,k*map[i][j]);
		}
	S=0;T=cnt+1;
	for(int i=costomer+1;i<=cnt;i++)
		add_edge(S,i,1,0);
	for(int i=1;i<=costomer;i++)
		add_edge(i,T,1,0);
}

bool spfa()
{
	memset(dist,0x3f,sizeof(dist));
	memset(inQ,0,sizeof(inQ));
	dist[S]=0; Q.push(S);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop(); inQ[x]=0;
		for(int i=head[x];i!=-1;i=edge[i].next)
			if(edge[i].flow>0 && dist[edge[i].to]>dist[x]+edge[i].cost)
			{
				pre[edge[i].to]=i;
				dist[edge[i].to]=dist[x]+edge[i].cost;
				if(!inQ[edge[i].to])
				{
					inQ[edge[i].to]=1;
					Q.push(edge[i].to);
				}
			}
	}
	return dist[T]!=inf;
}

void work()
{
	int mincost=0;
	while(spfa())
	{
		int res=inf;
		for(int i=T;i!=S;i=edge[pre[i]].from)
			res=std::min(res,edge[pre[i]].flow);
		for(int i=T;i!=S;i=edge[pre[i]].from)
		{
			edge[pre[i]].flow-=res;
			edge[pre[i]^1].flow+=res;
		}
		mincost+=dist[T]*res;
	}
	//printf("%d\n",mincost);
	printf("%.2lf\n",(double)mincost/costomer);
}

int main()
{
	freopen("repair.in","r",stdin);
	freopen("repair.out","w",stdout);
	read();
	work();
	return 0;
}
