#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<algorithm>
using std::queue;
typedef long long LL;
const int N=100000+10;
const int M=1000000+10;
int n,m,h[N];
struct EG{int x,y,z;}edge[M*2];
int L;
int vis[N];
struct Link{int y,z;Link *next;}*head[N];
int f[N];

void add_edge(int x,int y,int z)
{
	edge[L++]=(EG){x,y,z};
	Link *p=new Link;
	p->y=y; p->z=z;
	p->next=head[x];
	head[x]=p;
}

int bfs()
{
	queue<int> Q;
	int number=0;
	Q.push(1); vis[1]=1;
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		if((++number)==n) return number;
		for(Link *p=head[x];p;p=p->next)
			if(!vis[p->y])
			{
				vis[p->y]=1;
				Q.push(p->y);
			}
	}
	return number;
}

bool cmp(EG a,EG b)
{
	if(h[a.y]==h[b.y]) return a.z<b.z;
	return h[a.y]>h[b.y];
}

int getroot(int x) { return f[x]==x ? x : f[x]=getroot(f[x]); }
inline void merge(int x,int y) { f[getroot(x)]=getroot(y); }

LL solve()
{
	for(int i=1;i<=n;i++) f[i]=i;
	std::sort(edge,edge+L,cmp);
	LL tot=0;
	for(int i=0;i<L;i++)
	{
		int x=edge[i].x;
		int y=edge[i].y;
		if(!vis[x] || !vis[y]) continue;
		if(getroot(x)==getroot(y)) continue;
		merge(x,y);
		tot+=edge[i].z;
	}
	return tot;
}

int main()
{
	freopen("ski.in","r",stdin);
	freopen("ski.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&h[i]);
	while(m--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(h[a]>=h[b]) add_edge(a,b,c);
		if(h[b]>=h[a]) add_edge(b,a,c);
	}
	//printf("%d %lld\n",bfs(),solve());
	printf("%d ",bfs());
	printf("%lld\n",solve());
	return 0;
}
