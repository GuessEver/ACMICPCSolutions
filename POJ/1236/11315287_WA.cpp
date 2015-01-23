/*http://blog.csdn.net/jiangzh7
By Jiangzh*/
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int N=100+10;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
//#define bug

int n,m;
int map[N][N],newmap[N][N];
int low[N],now[N],dfstime,belong[N],number;
bool hash[N],inst[N];
stack<int> st;
int in[N],out[N];

void dfs(int x)
{
	now[x]=low[x]=++dfstime;
	hash[x]=true;st.push(x);inst[x]=true;
	for(int i=1;i<=n;i++)if(map[x][i])
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
			belong[u]=number;inst[u]=false;
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
			belong[st.top()]=number;
			st.pop();
		}
		number++;
	}
	#ifdef bug
	for(int k=0;k<number;k++)
	{
		printf("number=%d : ",k);
		for(int i=1;i<=n;i++) if(belong[i]==k) printf("%d ",i);
		puts("");
	}
	#endif
}

void make_new_map()
{
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(map[i][j] && belong[i]!=belong[j])
		newmap[belong[i]][belong[j]]=true;
	/*for(int i=0;i<number;i++)
	{
		for(int j=0;j<number;j++) printf("%d ",newmap[i][j]);
		puts("");
	}*/
	for(int i=0;i<number;i++)
	for(int j=0;j<number;j++)
	if(newmap[i][j])
	{
		in[j]++;out[i]++;
	}
	//for(int i=0;i<number;i++) printf("in=%d out=%d\n",in[i],out[i]);
}

void work()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		while(scanf("%d",&x)==1&&x) map[i][x]=true;
	}
	tarjan();
	make_new_map();
	int resin=0,resout=0;
	for(int i=0;i<number;i++)
	{
		if(!in[i]) resin++;
		if(!out[i]) resout++;
	}
	if(number==1) resout=0;
	else resout=max(resin,resout);
	printf("%d\n%d\n",resin,resout);
}

int main()
{
	freopen("poj1236.in","r",stdin);
	#ifndef bug
	freopen("poj1236.out","w",stdout);
	#endif
	work();
	/*while(scanf("%d",&n)==1)
	{
		memset(map,0,sizeof(map));
		memset(newmap,0,sizeof(newmap));
		memset(low,0,sizeof(low));
		memset(now,0,sizeof(now));
		memset(belong,0,sizeof(belong));
		dfstime=number=0;
		memset(hash,0,sizeof(hash));
		memset(in,0,sizeof(in));
		memset(out,0,sizeof(out));
		while(!st.empty())st.pop();
		work();
	}*/
	#ifdef bug
	while(1);
	#endif
	return 0;
}
