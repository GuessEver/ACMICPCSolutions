#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int N=10000+10;
const int M=50000+10;
int n,m;
struct EG{int y,next;}edge[M];
int head[N],LL;
int dfstime,now[N],low[N];
stack<int> st;
bool hash[N];//访问标记
int belong[N],number,num[N];//记录强连通分量
bool degree[N];//出度

void inlink(int x,int y)
{
	edge[LL].y=y;
	edge[LL].next=head[x];
	head[x]=LL++;
}

void dfs(int x)
{
	now[x]=low[x]=++dfstime;
	st.push(x);hash[x]=true;
	for(int p=head[x];p!=-1;p=edge[p].next)
	{
		int y=edge[p].y;
		if(!hash[y]) dfs(y);
		low[x]=min(low[x],low[y]);
	}
	if(now[x]==low[x])
	{
		while(!st.empty())//从栈中弹出当前强连通分量
		{
			int v=st.top();st.pop();
			belong[v]=number;
			num[number]++;
			if(x==v) break;
		}
		number++;
	}
}

void tarjan()
{
	for(int i=1;i<=n;i++) if(!hash[i]) dfs(i);
	if(!st.empty())
	{
		while(!st.empty())//栈中剩下的也是一个强连通分量
		{
			int v=st.top();st.pop();
			belong[v]=number;
			num[number]++;
		}
		number++;
	}
	/*for(int i=0;i<number;i++)
	{
		for(int j=1;j<=n;j++)
		if(belong[j]==i) printf("%d ",j);
		puts("");
	}*/
}

void work()
{
    scanf("%d%d",&n,&m);
	memset(head,-1,sizeof(head));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		inlink(x,y);
	}
	tarjan();//tarjan缩点
	for(int i=1;i<=n;i++)
		if(head[i]!=-1) degree[belong[i]]=true;
	int res=0,k=-1,flag=1;
	for(int i=0;i<number;i++)
	{
		if(k!=-1 && !degree[i]) {flag=0;break;}
		if(k==-1 && !degree[i]) k=i;
	}
	if(k==-1||flag==0) res=0;
	else res=num[belong[k]];
	printf("%d\n",res);
}

int main()
{
	//freopen("poj2186.in","r",stdin);
	//freopen("poj2186.out","w",stdout);
	work();
	return 0;
}
