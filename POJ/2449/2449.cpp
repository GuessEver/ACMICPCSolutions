#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
using std::priority_queue;
#define min(a,b) ((a)<(b)?(a):(b))
const int N=1000+10;
const int inf=0x3f3f3f3f;

int n,m;
struct Link{int y,z;Link *next;}*head[N],*tail[N];
int S,T,K;
int dist[N],inQ[N];
queue<int> que;
int enque_time[N];

struct ND{
	int x,g,h;
	bool operator < (const ND &a) const 
	{
		return g+h>a.g+a.h;
	}
};
priority_queue<ND> Q;

void inhead(int x,int y,int z)
{
	Link *p=new Link;
	p->y=y;p->z=z;
	p->next=head[x];
	head[x]=p;
}
void intail(int x,int y,int z)
{
	Link *p=new Link;
	p->y=y;p->z=z;
	p->next=tail[x];
	tail[x]=p;
}

void read()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		inhead(x,y,z);
		intail(y,x,z);
	}
	scanf("%d%d%d",&S,&T,&K);
}

bool spfa()
{
	memset(dist,0x3f,sizeof(dist));
	memset(inQ,0,sizeof(inQ));
	dist[T]=0; que.push(T);
	while(!que.empty())
	{
		int x=que.front();que.pop();
		inQ[x]=0;
		for(Link *p=tail[x];p;p=p->next)
			if(dist[p->y]>dist[x]+p->z)
			{
				dist[p->y]=dist[x]+p->z;
				if(!inQ[p->y])
				{
					inQ[p->y]=1;
					que.push(p->y);
				}
			}
	}
	return dist[S]!=inf;
}

int solve()
{
	if(!spfa()) return -1;
	if(S==T) K++;//这是一个天坑
	memset(enque_time,0,sizeof(enque_time));
	ND start; start=(ND){S,0,dist[S]};
	Q.push(start);
	while(!Q.empty())
	{
		ND tmp=Q.top(); Q.pop();
		int x=tmp.x;
		enque_time[x]++;
		if(enque_time[T]==K) return tmp.g;
		for(Link *p=head[x];p;p=p->next)
		{
			ND tt=(ND){p->y,tmp.g+p->z,dist[p->y]};
			Q.push(tt);
		}
	}
	return -1;
}

int main()
{
	freopen("2449.in","r",stdin);
	freopen("2449.out","w",stdout);
	read();
	printf("%d\n",solve());
	return 0;
}
