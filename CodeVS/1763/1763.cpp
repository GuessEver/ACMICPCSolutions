#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100000+10;
typedef long long LL;

int n;
LL m;
int cost[N],lead[N];
struct link{int y;link *next;}*head[N];
int A[N],L[N],R[N],D[N],cnt[N];
LL sum[N];
LL ans;

void inlink(int x,int y)
{
	link *node=new link;
	node->y=y;
	node->next=head[x];
	head[x]=node;
}

int merge(int x,int y)
{
	if(!x||!y) return x|y;
	if(A[x]<A[y]) swap(x,y);
	R[x]=merge(R[x],y);
	if(D[R[x]]>D[L[x]]) swap(L[x],R[x]);
	cnt[x]=cnt[L[x]]+cnt[R[x]]+1;
	sum[x]=sum[L[x]]+sum[R[x]]+cost[x];
	D[x]=D[R[x]]+1;
	return x;
}

int del(int x)
{
	int t=merge(L[x],R[x]);
	L[x]=R[x]=D[x]=0;
	return t;
}

int work(int x)
{
	int t=x;
	A[x]=sum[x]=cost[x]; cnt[x]=1;
	for(link *node=head[x];node;node=node->next)
		t=merge(t,work(node->y));
	while(sum[t]>m) t=del(t);
	ans=max(ans,(LL)lead[x]*cnt[t]);
	return t;
}

int main()
{
	freopen("1763.in","r",stdin);
	freopen("1763.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int leader;
		scanf("%d%d%d",&leader,&cost[i],&lead[i]);
		inlink(leader,i);
	}
	work(1);
	printf("%lld\n",ans);
	return 0;
}

