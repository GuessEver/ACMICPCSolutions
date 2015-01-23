#include<cstdio>
#include<cstring>

int n,mod;
int f[10000000];

int calc()
{
	f[0]=f[1]=1;
	for(int i=2;i<=n;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	return f[n]%mod;
}

int main()
{
	freopen("1250.in","r",stdin);
	freopen("std.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&mod);
		printf("%d\n",calc());
	}
	return 0;
}
