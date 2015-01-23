#include<cstdio>
#include<queue>
using namespace std;

int n,m,g;
char map[100][100];
int sx,sy;
int dx[2000],dy[2000];
int flag[100][100][2000];

bool check(int x,int y)
{
	if(map[x][y]=='X') return false;
	if(x<0||x>=n) return false;
	if(y<0||y>=m) return false;
	return true;
}

void dfs(int x,int y,int num)
{
	if(num>g){map[x][y]='*';return;}
	int x1=x+dx[num],y1=y+dy[num];
	while(check(x1,y1) && !flag[x1][y1][num])
	{
		flag[x1][y1][num]=1;
		dfs(x1,y1,num+1);
		x1+=dx[num];
		y1+=dy[num];
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
		for(int j=0;j<m;j++)
			if(map[i][j]=='*')
			{
				map[i][j]='.';
				sx=i,sy=j;
			}
	}
	scanf("%d",&g);
	for(int i=1;i<=g;i++)
	{
		char s[100];
		scanf("%s",s);
		if(s[0]=='N') dx[i]=-1,dy[i]= 0;
		if(s[0]=='S') dx[i]=+1,dy[i]= 0;
		if(s[0]=='W') dx[i]= 0,dy[i]=-1;
		if(s[0]=='E') dx[i]= 0,dy[i]=+1;
	}

	dfs(sx,sy,1);

	for(int i=0;i<n;i++) puts(map[i]);
	
	return 0;
}
