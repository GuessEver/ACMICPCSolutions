#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
using namespace std;
const int N=30000+10;

int n,m;
struct link{int y,z;link *next;}*head[N];
int dist[N],h[N];
typedef pair<int,int> pii;
priority_queue<pii> q;

void inlink(int x,int y,int z)
{
	link *tmp=new link;
	tmp->y=y;tmp->z=z;
	tmp->next=head[x];
	head[x]=tmp;
}

void dijkstra()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	q.push(make_pair(dist[1],1));
	while(!q.empty())
	{
		int x=q.top().second;q.pop();
		if(h[x]) continue;
		h[x]=1;
		for(link *node=head[x];node;node=node->next)
			if(!h[node->y] && dist[node->y]>dist[x]+node->z)
			{
				//if(dist[node->y]>dist[x]+node->z)
					dist[node->y]=dist[x]+node->z;
				q.push(make_pair(-dist[node->y],node->y));
			}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int a,b,c;// b<=a+c    ->    a-b>=-c
		scanf("%d%d%d",&a,&b,&c);
		inlink(a,b,c);
	}
	dijkstra();
	//for(int i=1;i<=n;i++) printf("%d ",dist[i]);
	printf("%d\n",dist[n]);
	return 0;
}
