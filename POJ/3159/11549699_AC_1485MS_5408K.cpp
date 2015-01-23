#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=30000+10;

int n,m;
struct link{int y,z;link *next;}*head[N];
int dist[N],inst[N];
int relax[N];
int st[N],top;

void inlink(int x,int y,int z)
{
	link *tmp=new link;
	tmp->y=y;tmp->z=z;
	tmp->next=head[x];
	head[x]=tmp;
}

bool spfa()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;
	top=0; st[top++]=1;
	while(top)
	{
		int x=st[--top];
		inst[x]=0;
		for(link *node=head[x];node;node=node->next)
			if(dist[node->y]>dist[x]+node->z)
			{
				dist[node->y]=dist[x]+node->z;
				if(++relax[node->y]>=n) return 0;
				if(!inst[node->y])
				{
					inst[node->y]=1;
					st[top++]=node->y;
				}
			}
	}
	return 1;
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
	spfa();
	//for(int i=1;i<=n;i++) printf("%d ",dist[i]);
	printf("%d\n",dist[n]);
	return 0;
}