#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=100+10;

int n;
struct link{int y;link *next;}*head[N];
stack<int> st;
int hash[N];
int dfstime;
int low[N],now[N];
int belong[N],number,num[N];
int in[N],out[N];
bool h1[N][N],h2[N][N];

void inlink(int x,int y)
{
	link *node=new link;
	node->y=y;
	node->next=head[x];
	head[x]=node;
}

void read()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		while(scanf("%d",&x))
		{
			if(x==0) break;
			inlink(i,x);
		}
	}
}

void dfs(int x)
{
	now[x]=low[x]=++dfstime;
	hash[x]=true;st.push(x);
	for(link *node=head[x];node;node=node->next)
	{
		int y=node->y;
		if(!hash[y]) dfs(y);
		low[x]=min(low[x],low[y]);
	}
	if(now[x]==low[x])
	{
		while(!st.empty())
		{
			int u=st.top();st.pop();
			belong[u]=number;
			num[number]++;
			if(u==x) break;
		}
		number++;
	}
}

void tarjan()
{
	for(int i=1;i<=n;i++) if(!hash[i]) dfs(i);
	if(!st.empty())
	{
		while(!st.empty())
		{
			int u=st.top();st.pop();
			belong[u]=number;
			num[number]++;
		}
		number++;
	}
}

void work()
{
	tarjan();
	for(int i=1;i<=n;i++)
	for(link *j=head[i];j;j=j->next)
	{
		if(belong[i]==belong[j->y]) continue;
		if(!h1[belong[i]][belong[j->y]])
		{
			h1[belong[i]][belong[j->y]]=true;
			in[belong[j->y]]++;
		}
		if(!h2[belong[j->y]][belong[i]])
		{
            h2[belong[j->y]][belong[i]]=true;
			out[belong[i]]++;
		}
	}
	int res=0,res2=0;
	for(int k=0;k<number;k++)
	{
		if(!in[k]) res++;
		if(!out[k]) res2++;
	}
	if(number==1) res2=0;
	else res2=max(res,res2);
	printf("%d\n%d\n",res,res2);
}

int main()
{
	//freopen("poj1236.in","r",stdin);
	//freopen("poj1236.out","w",stdout);
	read();
	work();
	//while(1);
	return 0;
}
