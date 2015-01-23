/*
C++ Code
http://blog.csdn.net/jiangzh7
By Jiangzh
*/
#include<cstdio>
#include<cstring>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

const int inf=0x3f3f3f3f;
int map[20][20];
int f[20][20][2000];
int ans=inf;

void read()
{
	for(int i=1;i<=10;i++)
		for(int j=1;j<=10;j++)
			scanf("%d",&map[i][j]);
}

void dfs(int x,int y,int S,int sum)
{
	if(x<1||x>10||y<1||y>10) return;
	int st=S|(1<<map[x][y]);
	if(x==10 && y==10)
	{
		if(st==1023) ans=min(ans,sum+map[10][10]);
		return;
	}
	dfs(x+1,y,st,sum+map[x][y]);
	dfs(x,y+1,st,sum+map[x][y]);
}

void work()
{
	dfs(1,1,0,0);
	printf("%d\n",ans);
}

int main()
{
	read();
	work();
	return 0;
}
