#include<cstdio>
#include<algorithm>
using namespace std;
const int N=300+10;

int n;
int a[N];
int f[N][N];
bool vis[N][N];

int merge(int l,int r)
{
	if(l==r) return 0;
	if(l+1==r) return a[l]*a[r]*a[r+1];
	if(vis[l][r]) return f[l][r];
	vis[l][r]=true;
	for(int k=l;k<r;k++) // [l,k] & [k+1,r]
	{
		f[l][r]=max(f[l][r],merge(l,k)+merge(k+1,r)+a[l]*a[k+1]*a[r+1]);
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
		a[i+n+n]=a[i];
	}
	int res=0;
	for(int i=1;i<=n;i++) res=max(res,merge(i,i+n-1));
	printf("%d\n",res);
	return 0;
}
