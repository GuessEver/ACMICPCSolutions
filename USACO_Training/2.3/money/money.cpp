/*
LANG: C++
TASK: money
ID: jiangzh15
*/
#include<cstdio>
const int N=25+10;
const int M=10000+10;
int n,m,a[N];
long long f[M];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=a[i];j<=m;j++)
			f[j]+=f[j-a[i]];
	printf("%lld\n",f[m]);
	return 0;
}
