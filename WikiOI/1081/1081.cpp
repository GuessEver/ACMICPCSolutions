#include<cstdio>
const int N=100000+10;
int n,m;
int sum[N*4];

void add(int p,int l,int r,int a,int b,int c)
{
	if(a<=l && b>=r) {sum[p]+=c;return;}
	int m=(l+r)>>1;
	sum[p<<1]+=sum[p];
	sum[(p<<1)+1]+=sum[p];
	sum[p]=0;
	if(a<=m) add(p<<1,l,m,a,b,c);
	if(b>m) add((p<<1)+1,m+1,r,a,b,c);
}

int query(int p,int l,int r,int a)
{
	if(l==r&&l==a) return sum[p];
	int m=(l+r)>>1,x1=0,x2=0;
	sum[p<<1]+=sum[p];
	sum[(p<<1)+1]+=sum[p];
	sum[p]=0;
	if(a<=m) return query(p<<1,l,m,a);
	else return query((p<<1)+1,m+1,r,a);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		add(1,1,n,i,i,x);
	}
	scanf("%d",&m);
	while(m--)
	{
		int op,x,y,z;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d%d",&x,&y,&z);
			add(1,1,n,x,y,z);
		}
		else {
			scanf("%d",&x);
			printf("%d\n",query(1,1,n,x));
		}
	}
	//while(1);
	return 0;
}
