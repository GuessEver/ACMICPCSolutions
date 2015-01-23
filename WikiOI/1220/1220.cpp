#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
const int N=100+10;
int n;
int a[N][N];
int f[N][N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			scanf("%d",&a[i][j]);
    for(int j=1;j<=n;j++) f[n][j]=a[n][j];
	for(int i=n-1;i>=1;i--)
	    for(int j=1;j<=i;j++)
	    {
			f[i][j]=a[i][j]+max(f[i+1][j],f[i+1][j+1]);
		}
	int res=0;
	printf("%d\n",f[1][1]);
	return 0;
}
