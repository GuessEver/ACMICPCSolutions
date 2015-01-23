#include<cstdio>
#include<cstring>

long long n,mod=1000000007;
long long a,b,c;

long long calc()
{
	a=b=1;n--;
	for(long long i=2;i<=n;i++)
	{
		c=a+b;c%=mod;
		a=b;b=c;
	}
	return c%mod;
}

int main()
{
	freopen("1732.in","r",stdin);
	freopen("std.out","w",stdout);
	while(scanf("%lld",&n)==1)
		printf("%lld\n",calc());
	return 0;
}
