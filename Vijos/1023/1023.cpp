#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=200+10;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

int n;
int map[N][N];
int number,belong[N],dfstime;
int now[N],low[N];
bool hash[N],inst[N];
stack<int> st;

void dfs(int x)
{
	now[x]=low[x]=++dfstime;
	hash[x]=true;st.push(x);inst[x]=true;
	for(int i=1;i<=n;i++) if(map[x][i])
	{
		if(!hash[i])
		{
			dfs(i);
			low[x]=min(low[x],low[i]);
		}
		else if(inst[i]) low[x]=min(low[x],now[i]);
	}
	if(low[x]==now[x])
	{
		while(!st.empty())
		{
			int u=st.top();st.pop();
			belong[u]=number;
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
		}
		number++;
	}
	//for(int i=1;i<=n;i++) printf("%d ",belong[i]);
}

int main()
{
	//freopen("1023.in","r",stdin);
	//freopen("1023out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		while(scanf("%d",&x)==1&&x) map[i][x]=1;
	}
	tarjan();
	printf("%d\n",number);
	//while(1);
	return 0;
}
