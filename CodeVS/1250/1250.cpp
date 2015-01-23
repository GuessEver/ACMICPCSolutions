#include<cstdio>
#include<cstring>

int n,mod;
struct Matrix{
	long long c[5][5];
	Matrix operator * (Matrix b)
	{
		Matrix res;
		res.c[1][1]=c[1][1]*b.c[1][1]+c[1][2]*b.c[2][1];
		res.c[1][2]=c[1][1]*b.c[1][2]+c[1][2]*b.c[2][2];
		res.c[2][1]=c[2][1]*b.c[1][1]+c[2][2]*b.c[2][1];
		res.c[2][2]=c[2][1]*b.c[1][2]+c[2][2]*b.c[2][2];
		return res;
	}
	Matrix getans(Matrix b)
	{
		Matrix res;
		res.c[1][1]=c[1][1]*b.c[1][1]+c[1][2]*b.c[2][1];
		res.c[2][1]=c[2][1]*b.c[1][1]+c[2][2]*b.c[2][1];
		return res;
	}
	Matrix operator % (int mod)
	{
		c[1][1]%=mod;c[1][2]%=mod;
		c[2][1]%=mod;c[2][2]%=mod;
		return *this;
	}
};

Matrix mul(Matrix x,int y,int mod)
{
	if(y==1) return x;
	if(y&1) return mul(x*x%mod,y/2,mod)%mod*x;
	else return mul(x*x%mod,y/2,mod)%mod;
}

long long calc()
{
	if(n==1||n==0) return 1;
	Matrix a;
	a.c[1][1]=a.c[1][2]=a.c[2][1]=1;
	a.c[2][2]=0;
	a=mul(a,n-1,mod);
	Matrix b; b.c[1][1]=b.c[2][1]=1;
	a=a.getans(b);
	return a.c[1][1]%mod;
}

int main()
{
	freopen("1250.in","r",stdin);
	freopen("1250.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&mod);
		printf("%lld\n",calc());
	}
	return 0;
}
