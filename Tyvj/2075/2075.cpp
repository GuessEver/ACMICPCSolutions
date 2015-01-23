#include<cstdio>
#include<cstring>
#include<algorithm>
using std::sort;
using std::min;
using std::max;
const int N=1000+10;
const int inf=0x3f3f3f3f;
int n,st;
struct node{int d,w;}a[N];
int f[N][N][2];
int sum[N];

bool cmp(node a,node b){return a.d<b.d;}

int calc(int l,int r,int k)
{
	if(l==1 && r==n)
	{
		return 0;
	}
	if(f[l][r][k]!=-1) return f[l][r][k];
	f[l][r][k]=inf;
	if(k==0)
	{
		if(l-1>=1)
		{
			int t=calc(l-1,r,0)+(a[l].d-a[l-1].d)*(sum[n]-sum[r]+sum[l-1]);
			f[l][r][k]=min(f[l][r][k],t);
		}
		if(r+1<=n)
		{
			int t=calc(l,r+1,1)+(a[r+1].d-a[l].d)*(sum[n]-sum[r]+sum[l-1]);
			f[l][r][k]=min(f[l][r][k],t);
		}
	}
	else{
		if(l-1>=1)
		{
			int t=calc(l-1,r,0)+(a[r].d-a[l-1].d)*(sum[n]-sum[r]+sum[l-1]);
			f[l][r][k]=min(f[l][r][k],t);
		}
		if(r+1<=n)
		{
			int t=calc(l,r+1,1)+(a[r+1].d-a[r].d)*(sum[n]-sum[r]+sum[l-1]);
			f[l][r][k]=min(f[l][r][k],t);
		}
	}
	return f[l][r][k];
}

int main()
{
	scanf("%d%d",&n,&st);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].d,&a[i].w);
		sum[i]=sum[i-1]+a[i].w;
	}
	sort(a+1,a+1+n,cmp);
	memset(f,-1,sizeof(f));
	int ans=min(calc(st,st,0),calc(st,st,1));
	printf("%d\n",ans);
	return 0;
}
