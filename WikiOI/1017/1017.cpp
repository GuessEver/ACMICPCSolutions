#include<cstdio>
#include<algorithm>
using std::max;
const int N=50;

int n,m;
int a[N];
int f[N][N];

void readit(int i)
{
	char ch;
	scanf("%c",&ch);
	a[i]=ch-'0';
}

int num(int x,int y)
{
	int res=0;
	for(int i=x;i<=y;i++)
	{
		res=res*10+a[i];
	}
	return res;
}

int main()
{
	scanf("%d%d\n",&n,&m);
	for(int i=1;i<=n;i++) readit(i);
	for(int i=1;i<=n;i++) f[i][0]=num(1,i);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<i;k++)
			{
				f[i][j]=max(f[i][j],f[k][j-1]*num(k+1,i));
			}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,f[i][m]);
	printf("%d\n",res);
	return 0;
}
