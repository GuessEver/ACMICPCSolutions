#include<iostream>
using namespace std;
const int MAX=30005;
const int inf=1<<30;
struct node
{
	int v,w,next;
}g[MAX*10];
int dis[MAX],adj[MAX],s[MAX],vis[MAX];
int n,m,e;
void add(int u,int v,int c)
{
	g[e].v=v; g[e].w=c; g[e].next=adj[u]; adj[u]=e++;
}
void spfa()
{
	int top=0,i,u,v;
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	memset(vis,0,sizeof(vis));
	s[++top]=1;
	vis[1]=1;
	while(top)
	{
		u=s[top--];
		//cout<<u<<endl;
		vis[u]=0;
		for(i=adj[u];i!=-1;i=g[i].next)
		{
			v=g[i].v;
			if(dis[v]>dis[u]+g[i].w)
			{
				dis[v]=dis[u]+g[i].w;
				if(!vis[v])
				{
					s[++top]=v;
					vis[v]=1;
				}
			}
		}
	}
}
int main()
{
	int a,b,c;
	memset(adj,-1,sizeof(adj));
	e=0;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	spfa();
	cout<<dis[n]<<endl;
	return 0;
}