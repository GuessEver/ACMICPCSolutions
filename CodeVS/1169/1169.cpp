#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))

int n,m;
int f[100][100][100][100];
int a[100][100];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	f[1][1][1][1]=a[1][1];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
		for(int t=1;t<=n;t++)
		for(int k=1;k<=m;k++)
		{
			int &ff=f[i][j][t][k];
			ff=max(ff,f[i-1][j][t-1][k]);
			ff=max(ff,f[i-1][j][t][k-1]);
			ff=max(ff,f[i][j-1][t-1][k]);
			ff=max(ff,f[i][j-1][t][k-1]);
			ff+=a[i][j];
			if(!(i==t && j==k)) ff+=a[t][k];
		}
	printf("%d\n",f[n][m][n][m]);
	return 0;
}
