#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=200+10;

int n;
int a[N],sum[N];
int f[N][N];
bool vis[N][N];

int merge(int l,int r)
{
	if(l==r) return 0;
	if(vis[l][r]) return f[l][r];
	vis[l][r]=true;
	for(int k=l;k<r;k++)//[l,k] & [k+1,r]
	{
		f[l][r]=min(f[l][r],merge(l,k)+merge(k+1,r)+(sum[r]-sum[l-1]));
	}
	return f[l][r];
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i+n]=a[i];
	}
	for(int i=1;i<=n+n;i++) sum[i]=sum[i-1]+a[i];
	memset(f,0x3f,sizeof(f));
	printf("%d\n",merge(1,n));
	return 0;
}
