#include<cstdio>
#include<algorithm>
const int N=1000000+10;
#define max(a,b) ((a)>(b)?(a):(b))
typedef long long LL;
int n;
LL val[N*4],add[N*4];

void update(int p)
{
	add[p<<1]+=add[p];
	add[(p<<1)+1]+=add[p];
	add[p]=0;
}

void change(int p,int l,int r,int a,int b,int c)
{
	if(a<=l && b>=r)
	{
		add[p]+=c;
		return;
	}
	int m=(l+r)>>1;
	update(p);
	if(a<=m) change(p<<1,l,m,a,b,c);
	if(b>m) change((p<<1)+1,m+1,r,a,b,c);
	val[p]=max(val[p<<1]+add[p<<1],val[(p<<1)+1]+add[(p<<1)+1]);
}

LL query(int p,int l,int r,int a,int b)
{
	if(a<=l && b>=r) return val[p]+add[p];
	int m=(l+r)>>1; LL x1=0,x2=0;
	update(p);
	if(a<=m) x1=query(p<<1,l,m,a,b);
	if(b>m) x2=query((p<<1)+1,m+1,r,a,b);
	val[p]=max(val[p<<1]+add[p<<1],val[(p<<1)+1]+add[(p<<1)+1]);
	return max(x1,x2);
}

int main()
{
	freopen("1827.in","r",stdin);
	freopen("1827.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		change(1,1,n,i,i,x);
	}
	int q; scanf("%d",&q);
	while(q--)
	{
		int op,x,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(l>r) std::swap(l,r);
		if(l<1) l=1;
		if(r>n) r=n;
		if(op==0)
		{
			scanf("%d",&x);
			change(1,1,n,l,r,x);
		}
		else{
			printf("%lld\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
