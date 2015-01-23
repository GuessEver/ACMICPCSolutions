#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int N=1000+10;
int n;
struct link{int y,z;link *next;}*head[N];
int dist[N],inQ[N];
queue<int> q;
int relax[N];

void inlink(int x,int y,int z)
{
	link *tmp=new link;
	tmp->y=y;tmp->z=z;
	tmp->next=head[x];
	head[x]=tmp;
}

int spfa()
{
	memset(dist,0x3f,sizeof(dist));
	dist[1]=0;q.push(1);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();inQ[x]=0;
		for(link *node=head[x];node;node=node->next)
			if(dist[node->y]>dist[x]+node->z)
			{
				dist[node->y]=dist[x]+node->z;
				if(!inQ[node->y])
				{
					inQ[node->y]=1;
					q.push(node->y);
					if(++relax[node->y]>n) return -1;
				}
			}
	}
	if(dist[n]==0x3f3f3f3f) return -2;
	return dist[n];
}

int main()
{
	int m,q;
	scanf("%d%d%d",&n,&m,&q);
	while(m--)
	{
		int a,b,d;scanf("%d%d%d",&a,&b,&d);
		inlink(a,b,d);  // a - b >= -d
	}
	while(q--)
	{
		int a,b,d;scanf("%d%d%d",&a,&b,&d);
		inlink(b,a,-d); // b - a >= d
	}
	for(int i=2;i<=n;i++) inlink(i,i-1,0);// i - (i-1) >= 0
	printf("%d\n",spfa());
	return 0;
}
