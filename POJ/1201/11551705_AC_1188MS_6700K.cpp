#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=50000+10;
const int inf=0x3f3f3f3f;

int s=inf,t=0;
struct link{int y,z;link *next;}*head[N];
int dist[N],inQ[N];
queue<int> Q;

void inlink(int x,int y,int z)
{
	link *tmp=new link;
	tmp->y=y;tmp->z=z;
	tmp->next=head[x];
	head[x]=tmp;
}

void spfa()
{
	for(int i=s;i<=t;i++) dist[i]=-inf;
	dist[s]=0;Q.push(s);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();inQ[x]=0;
		for(link *node=head[x];node;node=node->next)
			if(dist[node->y]<dist[x]+node->z)
			{
				dist[node->y]=dist[x]+node->z;
				if(!inQ[node->y])
				{
					inQ[node->y]=1;
					Q.push(node->y);
				}
			}
	}
}

int main()
{
	int m;scanf("%d",&m);
	while(m--)
	{
		int a,b,c;//b-a>=c
		scanf("%d%d%d",&a,&b,&c);a--;
		s=min(s,a);t=max(t,b);
		inlink(a,b,c);//a-b<=-c
	}
	for(int i=s;i<t;i++)
	{
		inlink(i,i+1,0);
		inlink(i+1,i,-1);
	}
	spfa();
	printf("%d\n",dist[t]-dist[s]);
	return 0;
}