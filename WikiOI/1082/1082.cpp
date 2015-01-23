#include<cstdio>
const int N=200000+10;
int n,q;
long long val[N*4];
long long add[N*4];

void change(int p,int l,int r,int a,int b,int c)
{
	if(a<=l&&b>=r)
	{
		add[p]+=c;
		val[p]+=c*(r-l+1);
		return;
	}
	int m=(l+r)>>1;
	add[p<<1]+=add[p];add[(p<<1)+1]+=add[p];
	val[p<<1]+=add[p]*(m-l+1);
	val[(p<<1)+1]+=add[p]*(r-(m+1)+1);
	add[p]=0;
	if(a<=m) change(p<<1,l,m,a,b,c);
	if(b>m) change((p<<1)+1,m+1,r,a,b,c);
	val[p]=val[p<<1]+val[(p<<1)+1];
}

long long query(int p,int l,int r,int a,int b)
{
	if(a<=l&&b>=r) return val[p];
	int m=(l+r)>>1;
    long long x1=0,x2=0;
	add[p<<1]+=add[p];add[(p<<1)+1]+=add[p];
	val[p<<1]+=add[p]*(m-l+1);
	val[(p<<1)+1]+=add[p]*(r-(m+1)+1);
	add[p]=0;
	if(a<=m) x1=query(p<<1,l,m,a,b);
	if(b>m) x2=query((p<<1)+1,m+1,r,a,b);
	return x1+x2;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		change(1,1,n,i,i,x);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int op,x,y,z;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
		{
			scanf("%d",&z);
			change(1,1,n,x,y,z);
		}
		else printf("%lld\n",query(1,1,n,x,y));
	}
	return 0;
}
