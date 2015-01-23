#include<cstdio>
#define max(a,b) ((a)>(b)?(a):(b))
const int N=1000+10;

int n,V,G;
int w[N],v[N],g[N];
int f[N][N];

void read()
{
	scanf("%d%d",&V,&G);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&w[i],&v[i],&g[i]);
}

void work()
{
	for(int i=1;i<=n;i++)
		for(int j=V;j>=v[i];j--)
			for(int k=G;k>=g[i];k--)
				f[j][k]=max(f[j][k],f[j-v[i]][k-g[i]]+w[i]);
	int res=0;
	for(int j=V;j>=0;j--)
		for(int k=G;k>=0;k--)
			res=max(res,f[j][k]);
	printf("%d\n",res);
}

int main()
{
	freopen("1669.in","r",stdin);
	freopen("1669.out","w",stdout);
	read();
	work();
	return 0;
}
