#include<cstdio>
const int N=100000+10;
int n,m;
int sum[N*4];

void add(int p,int l,int r,int a,int c)
{
	if(l==r&&l==a) {sum[p]+=c;return;}
	int m=(l+r)>>1;
	if(a<=m) add(p<<1,l,m,a,c);
	else add((p<<1)+1,m+1,r,a,c);
	sum[p]=sum[p<<1]+sum[(p<<1)+1];
}

int query(int p,int l,int r,int a,int b)
{
	if(a<=l && b>=r) return sum[p];
	int m=(l+r)>>1,x1=0,x2=0;
	if(a<=m) x1=query(p<<1,l,m,a,b);
	if(b>m) x2=query((p<<1)+1,m+1,r,a,b);
	return x1+x2;
}

int main()
{
	//freopen("c.in","r",stdin);
	//freopen("c.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(1,1,n,i,x);
	}
	scanf("%d",&m);
	while(m--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1) add(1,1,n,x,y);
		else printf("%d\n",query(1,1,n,x,y));
	}
	//while(1);
	return 0;
}
