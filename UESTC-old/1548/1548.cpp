#include<cstdio>
typedef long long LL;
const int M=1000000007;
int mul(int x,int y,int mod)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=((LL)ans*x)%mod;
		x=((LL)x*x)%mod;
		y>>=1;
	}
	return ans;
}

int main()
{
	freopen("1548.in","r",stdin);
	freopen("1548.out","w",stdout);
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c)==3)
	{
		int t=mul(b,c,M-1);
		int ans=mul(a,t,M);
		printf("%d\n",ans);
	}
	return 0;
}
