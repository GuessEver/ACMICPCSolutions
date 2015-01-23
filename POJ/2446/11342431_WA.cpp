#include<cstdio>
#include<cstring>
const int N=50;

int n,m,k;
int total;
int map[N*N];
struct link{int y;link *next;}*head[N*N*N];
int h[N*N*N];
int pre[N*N*N];

inline int getnum(int x,int y)
{
	return (x-1)*m+y;
}

void inlink(int x,int y)
{
	link *node=new link;
	node->y=y;
	node->next=head[x];
	head[x]=node;
}

void read()
{
	scanf("%d%d%d",&n,&m,&k);
	total=n*m;
	for(int i=1;i<=k;i++)
	{
		int x,y; scanf("%d%d",&y,&x);
		map[getnum(x,y)]=true;
		map[getnum(x,y)+N]=true;
		total--;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(!map[getnum(i,j)])
	{
		if(i-1>=1&&!map[getnum(i-1,j)])	inlink(getnum(i,j),getnum(i-1,j)+N);
		if(i+1<=n&&!map[getnum(i+1,j)])	inlink(getnum(i,j),getnum(i+1,j)+N);
		if(j-1>=1&&!map[getnum(i,j-1)])	inlink(getnum(i,j),getnum(i,j-1)+N);
		if(j+1<=m&&!map[getnum(i,j+1)])	inlink(getnum(i,j),getnum(i,j+1)+N);
	}
}

bool search(int x)
{
	for(link *node=head[x];node;node=node->next)
	if(!h[node->y])
	{
		h[node->y]=true;
		if(pre[node->y]==-1||search(pre[node->y]))
		{
			//printf("%d <-> %d\n",x,node->y);
			pre[node->y]=x;
			return true;
		}
	}
	return false;
}

void work()
{
	int res=0;
	memset(pre,-1,sizeof(pre));
	for(int i=1;i<=n*m;i++)
	{
		memset(h,0,sizeof(h));
		if(search(i)) res++;
		//printf("res=%d\n",res);
	}
	if(res==total) puts("YES");
	else puts("NO");
}

int main()
{
	read();
	work();
	return 0;
}
