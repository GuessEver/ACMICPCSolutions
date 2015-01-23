#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
const int N=1000;
const int inf=0x3f3f3f3f;
#define sqr(_) ((_)*(_))
typedef long long LL;
int K,n;
struct node{char name[50];int x,y;}p[N];
int cap[N][N],cost[N][N];
int S,T;
int dist[N],h[N],pre[N];
queue<int> q;

void predoing(char *s)
{
	int len=strlen(s);
	for(int i=0;i<len;i++) s[i]=tolower(s[i]);
}

void read()
{
	scanf("%d%d\n",&K,&n);
	for(int i=1;i<=n*2;i++)
	{
		scanf("%d%d%s\n",&p[i].x,&p[i].y,p[i].name);
		predoing(p[i].name);
	}
}

int find(char *s)
{
	for(int i=1;i<=n*2;i++)
	if(!strcmp(s,p[i].name)) return i;
}

double dis(int x1,int y1,int x2,int y2)
{
	return sqrt((double)sqr((LL)x1-x2)+(double)sqr((LL)y1-y2));
}

bool check(int i,int j)
{
	int x1=p[i].x,y1=p[i].y;
	int x2=p[j].x,y2=p[j].y;
	if(dis(x1,y1,x2,y2)>(double)K) return false;
	for(int i=1;i<=n+n;i++)
	{
		if(p[i].x==x1&&p[i].y==y1) continue;
		if(p[i].x==x2&&p[i].y==y2) continue;
		int x0=p[i].x,y0=p[i].y;
		if((x0-x1)*(x0-x2)<=0 && (y0-y1)*(y0-y2)<=0 && (x0-x1)*(y2-y1)==(y0-y1)*(x2-x1)) return false;
	}
	return true;
}

void build_map()
{
	char b[50],g[50];
	for(int i=1;i<=n;i++)
	for(int j=n+1;j<=n+n;j++)
	if(dis(p[i].x,p[i].y,p[j].x,p[j].y)<=K)
	{
		cap[i][j]=1;
		cost[i][j]=1;
		cost[j][i]=-1;
	}
	int x,y,w;
	while(1)
	{
		memset(b,0,sizeof(b));
		memset(g,0,sizeof(g));
		scanf("%s",b);if(!strcmp(b,"End")) break;
		scanf("%s%d\n",g,&w);
		predoing(b);predoing(g);
		x=find(b);y=find(g);
		if(x>y) swap(x,y);
		if(check(x,y))
		{
			//printf("distance=%.2lf\n",dis(x,y));
			cost[x][y]=w;
			cost[y][x]=-w;
		}
	}
	S=0;T=n+n+1;
	for(int i=1;i<=n;i++) {cap[S][i]=1;cost[S][i]=0;}
	for(int i=n+1;i<=n+n;i++) {cap[i][T]=1;cost[i][T]=0;}
}

bool spfa()
{
	for(int i=S;i<=T;i++) dist[i]=-inf;
	dist[S]=0;q.push(S);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();h[x]=false;
		for(int i=S;i<=T;i++)
		if(cap[x][i]>0 && dist[i]<dist[x]+cost[x][i])
		{
			pre[i]=x;
			dist[i]=dist[x]+cost[x][i];
			if(!h[i])
			{
				h[i]=true;
				q.push(i);
			}
		}
	}
	return dist[T]!=-inf;
}

void work()
{
	build_map();
	int maxcost=0;
	while(spfa())
	{
		//printf("dist=%d  :",dist[T]);
		int res=inf;
		//printf("%d",T);
		for(int i=T;i!=S;i=pre[i])
		{
			//printf("->%d",pre[i]);
			res=min(res,cap[pre[i]][i]);
		}//puts("");
		for(int i=T;i!=S;i=pre[i])
		{
			cap[pre[i]][i]-=res;
			cap[i][pre[i]]+=res;
		}
		maxcost+=res*dist[T];
	}
	printf("%d\n",maxcost);
}

int main()
{
	read();
	work();
	return 0;
}
