#include<cstdio>
#include<cstring>
#include<stack>
using std::stack;
#define min(a,b) ((a)<(b)?(a):(b))
const int N=10000+10;
int n,m;
struct Link{int y;Link *next;}*head[N];
bool hash[N],inst[N];
stack<int> st;
int belong[N],number,peo[N];
int low[N],now[N],dfstime;
int out[N];

void inLink(int x,int y)
{
	Link *p=new Link;
	p->y=y; p->next=head[x];
	head[x]=p;
}

void dfs(int x)
{
	low[x]=now[x]=++dfstime;
	st.push(x); inst[x]=1; hash[x]=1;
	for(Link *p=head[x];p;p=p->next)
	{
		if(!hash[p->y])
		{
			dfs(p->y);
			low[x]=min(low[x],low[p->y]);
		}
		else if(inst[p->y]) low[x]=min(low[x],now[p->y]);
	}
	if(low[x]==now[x])
	{
		while(!st.empty())
		{
			int u=st.top();st.pop();
			belong[u]=number; inst[u]=0;
			peo[number]++;
			if(u==x) break;
		}
		number++;
	}
}

void tarjan()
{
	for(int i=1;i<=n;i++)
		if(!hash[i]) dfs(i);
	if(!st.empty())
	{
		while(!st.empty())
		{
			int u=st.top();st.pop();
			belong[u]=number; inst[u]=0;
			peo[number]++;
		}
		number++;
	}
}

int solve()
{
	tarjan();
	for(int i=1;i<=n;i++)
	{
		for(Link *p=head[i];p;p=p->next)
		{
			if(belong[i]==belong[p->y]) continue;
			out[belong[i]]++;
		}
	}
	int k=-1;
	for(int i=0;i<number;i++) if(out[i]==0)
	{
		if(k!=-1) return 0;
		if(k==-1) k=i;
	}
	if(k==-1) return 0;
	return peo[k];
}

int main()
{
	freopen("1317.in","r",stdin);
	freopen("1317.out","w",stdout);
	while(scanf("%d%d",&n,&m)==2)
	{
		memset(head,0,sizeof(head));
		memset(belong,0,sizeof(belong));
		memset(peo,0,sizeof(peo));
		memset(out,0,sizeof(out));
		memset(hash,0,sizeof(hash));
		memset(inst,0,sizeof(inst));
		memset(peo,0,sizeof(peo));
		number=dfstime=0;
		memset(low,0,sizeof(low));
		memset(now,0,sizeof(now));
		for(int i=1;i<=m;i++)
		{
			int x,y; scanf("%d%d",&x,&y);
			inLink(x,y);
		}
		printf("%d\n",solve());
	}
	return 0;
}
