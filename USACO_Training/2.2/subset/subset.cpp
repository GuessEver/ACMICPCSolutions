/*
LANG: C++
TASK: subset
ID: jiangzh15
*/
#include<cstdio>
#include<algorithm>
const int N=39+10;
const int S=780+10;

int n;
int total;
long long f[S];

int main()
{
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) total+=i;
	if(total&1) goto writeans;
	f[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=total;j>=i;j--)
		{
			f[j]=f[j]+f[j-i];
		}
	/*for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=total;j++) printf("%5d ",f[j]);
		puts("");
	}puts("");*/
writeans:;
	printf("%lld\n",f[total/2]/2);
	return 0;
}
