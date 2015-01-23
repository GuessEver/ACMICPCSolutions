#include<cstdio>
#include<cstring>
const int N=100+10;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};

int n,m,K;
int map[N][N];
int g[N*N][N*N];
bool h[N*N];
int pre[N*N];

inline int Get(int x,int y) { return (x-1)*m+y; }

void read()
{
	scanf("%d%d",&n,&m);
	scanf("%d",&K);
	for(int i=1;i<=K;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		map[x][y]=true;
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	{
		if(map[i][j]) continue;
		for(int k=0;k<4;k++)
		{
			int x=i+dx[k];
			int y=j+dy[k];
			if(x<1||x>n||y<1||y>m) continue;
			if(map[x][y]) continue;
			g[Get(i,j)][Get(x,y)]=true;
		}
	}
}

bool search(int x)
{
	for(int i=1;i<=n*m;i++)
		if(g[x][i] && !h[i])
		{
			h[i]=true;
			if(pre[i]==-1||search(pre[i]))
			{
				pre[i]=x;
				return true;
			}
		}
	return false;
}

void work()
{
	memset(pre,-1,sizeof(pre));
	int res=0;
	for(int i=1;i<=n*m;i++)
	{
		memset(h,0,sizeof(h));
		if(search(i)) res++;
	}
	printf("%d\n",res/2);
}

int main()
{
	read();
	work();
	return 0;
}
