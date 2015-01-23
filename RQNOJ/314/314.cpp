#include<cstdio>
#include<algorithm>
using std::max;

int n;
int map[20][20];
int f[20][20][20][20];

int main()
{
	//freopen("rqn314.in","r",stdin);
	//freopen("rqn314.out","w",stdout);
	scanf("%d",&n);
	int x,y,z;
	while(scanf("%d%d%d",&x,&y,&z)==3&&x&&y&&z) map[x][y]=z;
	f[1][1][1][1]=map[1][1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	for(int t=1;t<=n;t++)
	for(int k=1;k<=n;k++)
	if((i!=t||j!=k)||(i==n&&j==n))
	{
		f[i][j][t][k]=max(f[i][j][t][k],f[i-1][j][t-1][k]);
		f[i][j][t][k]=max(f[i][j][t][k],f[i-1][j][t][k-1]);
		f[i][j][t][k]=max(f[i][j][t][k],f[i][j-1][t-1][k]);
		f[i][j][t][k]=max(f[i][j][t][k],f[i][j-1][t][k-1]);
		f[i][j][t][k]+=map[i][j]+map[t][k];
	}
	printf("%d\n",f[n][n][n][n]-map[n][n]);
	return 0;
}

