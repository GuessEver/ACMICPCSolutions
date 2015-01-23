#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
const int N=500000+10;
const int inf=0x3f3f3f3f;
int n,m,k[N];
struct link{int y,z;link *next;}*head[N];
queue<int> q;
int dist[N];
bool inQ[N];

void inlink(int x,int y,int z)
{
	link *tmp=new link;
	tmp->y=y;tmp->z=z;
	tmp->next=head[x];
	head[x]=tmp;
}

int spfa()
{
	for(int i=1;i<=n;i++) dist[i]=-inf;
	dist[0]=0; q.push(0);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();inQ[x]=0;
		for(link *node=head[x];node;node=node->next)
			if(dist[node->y]<dist[x]+node->z)
			{
				dist[node->y]=dist[x]+node->z;
				if(!inQ[node->y])
				{
					inQ[node->y]=1;
					q.push(node->y);
				}
			}
	}
	for(int i=1;i<=n;i++) printf("%d ",dist[i]); puts("");
	return dist[n];
}

int main()
{
	freopen("1768.in","r",stdin);
	freopen("1768.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);a--;
		inlink(a,b,c); //b-a>=c  ->  a-b<=-c
	}
	for(int i=1;i<=n;i++)
	{
		inlink(i-1,i,0); //i-(i-1)>=0  ->  (i-1)-i<=0
		inlink(i,i-1,-k[i]); //i-(i-1)<=k
	}
	printf("%d\n",spfa());
	return 0;
}
