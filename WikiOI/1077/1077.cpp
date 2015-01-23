#include<cstdio>
#include<cstring>
#define min(a,b) ((a)<(b)?(a):(b))

int n;
int a[200][200];

int main()
{
	scanf("%d",&n);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	{
		int x;
		scanf("%d",&x);
		a[i][j]=min(a[i][j],x);
	}
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
	int q; scanf("%d",&q);
	while(q--)
	{
		int x,y; scanf("%d%d",&x,&y);
		printf("%d\n",a[x][y]);
	}
	return 0;
}
