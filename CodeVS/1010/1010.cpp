#include<cstdio>
const int dx[]={-2,-1,+1,+2,+2,+1,-1,-2};
const int dy[]={+1,+2,+2,+1,-1,-2,-2,-1};

int n,m,a,b;
int f[100][100];
int map[100][100];

int main()
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	map[a][b]=1;
	for(int k=0;k<8;k++)
	{
		int x=a+dx[k];
		int y=b+dy[k];
		if(x<0||x>n||y<0||y>m) continue;
		map[x][y]=1;
	}
	f[0][0]=1;
	for(int i=0;i<=n;i++)
	for(int j=0;j<=m;j++)
	{
		if(map[i][j]) continue;
		if(i>=1) f[i][j]+=f[i-1][j];
		if(j>=1) f[i][j]+=f[i][j-1];
	}
	printf("%d\n",f[n][m]);
	return 0;
}
