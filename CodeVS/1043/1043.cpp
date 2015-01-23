#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
const int N=40;
int n;
int map[N][N];
int f[N][N][N][N];

int main()
{
	freopen("1043.in","r",stdin);
	freopen("1043.out","w",stdout);
	scanf("%d",&n);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3)
		if(a&&b&&c) map[a][b]=c;
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
		for(int k=1;k<=n;k++)
		for(int t=1;t<=n;t++)
		{
			f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j][k-1][t]);
			f[i][j][k][t]=max(f[i][j][k][t],f[i][j-1][k-1][t]);
			f[i][j][k][t]=max(f[i][j][k][t],f[i-1][j][k][t-1]);
			f[i][j][k][t]=max(f[i][j][k][t],f[i][j-1][k][t-1]);
			f[i][j][k][t]+=map[i][j]+map[k][t];
			if(i==k && j==t) f[i][j][k][t]-=map[k][t];
			//printf("(%d,%d) (%d,%d) : %d\n",i,j,k,t,f[i][j][k][t]);
		}
	printf("%d\n",f[n][n][n][n]);
	return 0;
}
