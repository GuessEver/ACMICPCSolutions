#include<cstdio>
#include<cstring>
const int N=100000+10;
int n,cnt[N];

int solve()
{
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		for(int j=a;j<=b;j++) cnt[j]++;
	}
	for(int j=n;j>=0;j--)
		if(cnt[j]==j) return j;
	return -1;
}

int main()
{
	freopen("1003.in","r",stdin);
	freopen("1003.out","w",stdout);
	int t; scanf("%d",&t);
	while(t--) printf("%d\n",solve());
	return 0;
}
