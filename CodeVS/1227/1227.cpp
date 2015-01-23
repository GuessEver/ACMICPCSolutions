#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=100+10;
const int P=N*N*5;
const int inf=0x3f3f3f3f;

int n,m,K;
int map[N][N];
struct EG{int from,to,flow,cost,next;}edge[P];
int head[P],L;
int S,T;
bool inQ[P];
int dist[P];
int pre[P];
queue<int> Q;

void read()
{
	scanf("%d%d",&n,&K);m=n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&map[i][j]);
}

inline int In (int x,int y) { return ((x-1)*m+y)*2-1; }
inline int Out(int x,int y) { return ((x-1)*m+y)*2; }

void add_edge(int x,int y,int z,int w)
{
	edge[L]=(EG){x,y,z,w ,head[x]};
	head[x]=L++;
	edge[L]=(EG){y,x,0,-w,head[y]};
	head[y]=L++;
}

void make_map()
{
	memset(head,-1,sizeof(head));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			add_edge(In(i,j),Out(i,j),1,map[i][j]);
			add_edge(In(i,j),Out(i,j),inf,0);
			if(j<m) add_edge(Out(i,j),In(i,j+1),inf,0);
			if(i<n) add_edge(Out(i,j),In(i+1,j),inf,0);
		}
	S=0;T=Out(n,m)+1;
	add_edge(S,In(1,1),K,0);
	add_edge(Out(n,m),T,inf,0);
}

bool spfa()
{
	for(int i=S;i<=T;i++) dist[i]=-inf;
	memset(inQ,0,sizeof(inQ));
	dist[S]=0;Q.push(S);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();inQ[x]=false;
		for(int i=head[x];i!=-1;i=edge[i].next)
		{
			if(edge[i].flow>0 && dist[edge[i].to]<dist[x]+edge[i].cost)
			{
				pre[edge[i].to]=i;
				dist[edge[i].to]=dist[x]+edge[i].cost;
				if(!inQ[edge[i].to])
				{
					inQ[edge[i].to]=true;
					Q.push(edge[i].to);
				}
			}
		}
	}
	return dist[T]!=-inf;
}

void work()
{
	make_map();
	memset(pre,-1,sizeof(pre));
	int maxcost=0,maxflow=0;
	while(spfa())
	{
		int res=inf;
		for(int i=T;i!=S;i=edge[pre[i]^1].to)
		{
			res=min(res,edge[pre[i]].flow);
		}
		for(int i=T;i!=S;i=edge[pre[i]^1].to)
		{
			edge[pre[i]].flow-=res;
			edge[pre[i]^1].flow+=res;
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
