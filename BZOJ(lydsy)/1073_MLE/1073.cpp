#include<cstdio>
#include<cstring>
#include<queue>
using std::queue;
using std::priority_queue;
const int N=50+10;
const int inf=0x3f3f3f3f;

int n,m,K,S,T;
struct Link{int y,z;Link *next;}*head[N],*tail[N];
int dist[N],inQ[N];
queue<int> que;
struct ND{
	int x,g,h,vis[N];
	char way[1000];
	bool operator < (const ND &a) const
	{
		//if(g+h==a.g+a.h) return x>a.x;
		return g+h>a.g+a.h;
	}
};
priority_queue<ND> Q;
int enque_times[N];
char ans[1000];

void inhead(int x,int y,int z)
{
	Link *p=new Link;
	p->y=y; p->z=z;
	p->next=head[x];
	head[x]=p;
}
void intail(int x,int y,int z)
{
	Link *p=new Link;
	p->y=y; p->z=z;
	p->next=tail[x];
	tail[x]=p;
}

void read()
{
	scanf("%d%d%d%d%d",&n,&m,&K,&S,&T);
	while(m--)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		inhead(x,y,z);
		intail(y,x,z);
	}
}

bool spfa()
{
	memset(dist,0x3f,sizeof(dist));
	memset(inQ,0,sizeof(inQ));
	dist[T]=0; que.push(T);
	while(!que.empty())
	{
		int x=que.front();que.pop();
		inQ[x]=0;
		for(Link *p=tail[x];p;p=p->next)
			if(dist[p->y]>dist[x]+p->z)
			{
				dist[p->y]=dist[x]+p->z;
				if(!inQ[p->y])
				{
					inQ[p->y]=1;
					que.push(p->y);
				}
			}
	}
	return dist[S]!=inf;
}

bool solve()
{
	if(!spfa()) return 0;
	ND start=(ND){S,0,dist[S]};
	memset(start.way,0,sizeof(start.way));
	memset(start.vis,0,sizeof(start.vis));
	start.vis[S]=1;
	sprintf(start.way,"%d",S);
	memset(enque_times,0,sizeof(enque_times));
	Q.push(start);
	int flag=inf;
	while(!Q.empty())
	{
		ND tmp=Q.top();Q.pop();
		int x=tmp.x;
		//printf("x=%d  g=%d  h=%d : ",tmp.x,tmp.g,tmp.h);puts(tmp.way);
		enque_times[x]++;
		if(tmp.x==T && (enque_times[T]==K ||tmp.g==flag))
		{
			flag=tmp.g;
			//if(strlen(tmp.way)==n*2-1) 
				if(ans[0]=='\0' || strcmp(ans,tmp.way)<0)
					strcpy(ans,tmp.way);
			//printf("g=%d h=%d ",tmp.g,tmp.h);puts(tmp.way);
		}
		if(tmp.g>flag) break;
		for(Link *p=head[x];p;p=p->next)
		{
			ND tt=tmp;
			tt.x=p->y; tt.g+=p->z; tt.h=dist[p->y];
			if(tt.vis[p->y]) continue;
			tt.vis[p->y]=1;
			int len=strlen(tt.way);
			sprintf(&tt.way[len],"-%d",p->y);
			Q.push(tt);
		}
	}
	if(ans[0]!='\0'){puts(ans);return 1;}
	return 0;
}

int main()
{
	freopen("1073.in","r",stdin);
	freopen("1073.out","w",stdout);
	read();
	if(!solve()) printf("No\n");
	return 0;
}
