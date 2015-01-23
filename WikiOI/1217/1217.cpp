/*
C++ Code
http://blog.csdn.net/jiangzh7
By Jiangzh
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=1000000+10;

int n,m;
int val[4*MAXN],sum[4*MAXN];

void init()
{
	freopen("classroom.in","r",stdin);
	freopen("classroom.out","w",stdout);
}

void init_tree(int p,int l,int r,int a,int c)
{
	if(l==r && l==a) {val[p]=c;return;}
	int m=(l+r)>>1;
	if(a<=m) init_tree(p<<1,l,m,a,c);
	if(a>m) init_tree((p<<1)+1,m+1,r,a,c);
	val[p]=min(val[p<<1],val[(p<<1)+1]);
}

void change(int p,int l,int r,int a,int b,int c,int k)
{
	if(a<=l && b>=r)
	{
		if(sum[p]<0)sum[p]=0;
		sum[p]+=c;val[p]-=c;
		return;
	}
	//标记下传
	sum[p<<1]+=sum[p];val[p<<1]=val[p<<1]-sum[p];
	sum[(p<<1)+1]+=sum[p];val[(p<<1)+1]=val[(p<<1)+1]-sum[p];
	sum[p]=0;val[p]=0;
	
	int m=(l+r)>>1;
	if(a<=m) change(p<<1,l,m,a,b,c,k);
	if(b>m) change((p<<1)+1,m+1,r,a,b,c,k);
	val[p]=min(val[p<<1],val[(p<<1)+1]);
	if(val[p]<0) {printf("-1\n%d",k);exit(0);}
}

void work()
{
	memset(val,0x3f,sizeof(val));
	memset(sum,0,sizeof(sum));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		init_tree(1,1,n,i,x);//在第i天的位置初始化插入值x
	}
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&c,&a,&b);
		change(1,1,n,a,b,c,i);
		//for(int i=1;i<=10;i++) printf("%d ",val[i]); printf("\n");
		//for(int i=1;i<=10;i++) printf("%d ",sum[i]); printf("\n");printf("\n");
	}
	printf("0");
}

int main()
{
	//init();
	work();
	return 0;
}
