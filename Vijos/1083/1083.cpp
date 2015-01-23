#include<cstdio>
#include<algorithm>
using namespace std;
const int N=500000+10;

int n,m;
struct node{int left,right,mid,sum;}val[N*4];

void renew(int p)
{
	//sum[]
	val[p].sum=val[p<<1].sum+val[(p<<1)+1].sum;
	//left
	val[p].left=max(val[p<<1].left,val[p<<1].sum+val[(p<<1)+1].left);
	//right
	val[p].right=max(val[(p<<1)+1].right,val[(p<<1)+1].sum+val[p<<1].right);
	//mid
	val[p].mid=max(val[p<<1].right+val[(p<<1)+1].left,max(val[p<<1].mid,val[(p<<1)+1].mid));
}

void change(int p,int l,int r,int a,int c)
{
	if(l==r&&l==a)
	{
		val[p].left=val[p].right=val[p].mid=val[p].sum=c;
		return;
	}
	int m=(l+r)>>1;
	if(a<=m) change(p<<1,l,m,a,c);
	if(a>m) change((p<<1)+1,m+1,r,a,c);
	renew(p);
}

node query(int p,int l,int r,int a,int b)
{
	if(a<=l&&b>=r) return val[p];
	int m=(l+r)>>1;
	if(b<=m)
	{
		return query(p<<1,l,m,a,b);
	}
	else if(a>m)
	{
		return query((p<<1)+1,m+1,r,a,b);
	}
	else{
		node res1,res2,res;
		res1=query(p<<1,l,m,a,b);
		res2=query((p<<1)+1,m+1,r,a,b);
		res.sum=res1.sum+res2.sum;
		res.left=max(res1.left,res1.sum+res2.left);
		res.right=max(res2.right,res2.sum+res1.right);
		res.mid=max(res1.right+res2.left,max(res1.mid,res2.mid));
		return res;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x; scanf("%d",&x);
		change(1,1,n,i,x);
	}
	while(m--)
	{
		int op,a,b;
		scanf("%d%d%d",&op,&a,&b);
		if(op==1)
		{
			if(a>b) swap(a,b);
			printf("%d\n",query(1,1,n,a,b).mid);
		}
		else change(1,1,n,a,b);
	}
	return 0;
}
