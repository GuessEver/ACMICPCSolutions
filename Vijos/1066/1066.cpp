#include<cstdio>
#include<algorithm>
using namespace std;
const int N=32000+10;

int n;
struct node{int x,y;}a[N];
int maxp=0;
int level[N];
int sum[N*4];

bool cmp(node a,node b)
{
	if(a.y==b.y) return a.x<b.x;
	return a.y<b.y;
}

void intree(int p,int l,int r,int a)
{
	if(l==r&&l==a) {sum[p]++;return;}
	int m=(l+r)>>1;
	if(a<=m) intree(p<<1,l,m,a);
	if(a>m) intree((p<<1)+1,m+1,r,a);
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
}

int query(int p,int l,int r,int a,int b)
{
	if(a<=l&&b>=r) return sum[p];
	int m=(l+r)>>1,x1=0,x2=0;
	if(a<=m) x1=query(p<<1,l,m,a,b);
	if(b>m) x2=query((p<<1)+1,m+1,r,a,b);
	return x1+x2;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		maxp=max(maxp,a[i].x);
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int res=query(1,0,maxp,0,a[i].x);
		level[res]++;
		intree(1,0,maxp,a[i].x);
	}
	for(int i=0;i<n;i++) printf("%d\n",level[i]);
	return 0;
}
