#include<cstdio>
#include<cstring>

struct Matrix{
	long long c[4][4];
	void clear() { memset(c,0,sizeof(c)); }
};

void Read(Matrix &a,int n,int m)
{
	a.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",&a.c[i][j]);
}
void Print(Matrix &a,int n,int m)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) printf("%lld ",a.c[i][j]);
		printf("\n");
	}
	printf("\n");
}

Matrix solve(Matrix &a,Matrix &b,int n,int m,int t)
{
	Matrix res; res.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=t;j++)
		{
			int first=1,second=1;
			while(first<=m)
			{
				res.c[i][j]+=a.c[i][first]*b.c[second][j];
				first++;second++;
			}
		}
	return res;
}
int main()
{
	freopen("1028.in","r",stdin);
	freopen("1028.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)
	{
		int a,b,c; scanf("%d%d%d",&a,&b,&c);
		Matrix x,y;
		Read(x,a,b); Read(y,b,c);
		x=solve(x,y,a,b,c);
		Print(x,a,c);
	}
	return 0;
}
