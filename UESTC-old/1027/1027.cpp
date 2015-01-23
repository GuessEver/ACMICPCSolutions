#include<cstdio>
#include<cstring>

struct Matrix{
	long long c[4][4];
	void clear() { memset(c,0,sizeof(c)); }
	void Read()
	{
		clear();
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
				scanf("%lld",&c[i][j]);
	}
	Matrix operator * (const Matrix &a) const
	{
		Matrix res;res.clear();
		for(int i=1;i<=3;i++)
			for(int j=1;j<=3;j++)
			{
				int first=1,second=1;
				while(first<=3)
				{
					res.c[i][j]+=c[i][first]*a.c[second][j];
					first++;second++;
				}
			}
		return res;
	}
	void Print()
	{
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++) printf("%lld ",c[i][j]);
			printf("\n");
		}
		printf("\n");
	}
};

int main()
{
	freopen("1027.in","r",stdin);
	freopen("1027.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--)
	{
		Matrix a,b;
		a.Read(); b.Read();
		(a*b).Print();
	}
	return 0;
}
