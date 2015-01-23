#include<cstdio>
#include<algorithm>
const int N=100;

int n;
struct Link{int y;Link *next;}*head[N];
int cnt[N];
int maxdeep=0,maxwidth=0;

void inLink(int x,int y)
{
	Link *p=new Link;
	p->y=y; p->next=head[x];
	head[x]=p;
}

void calc(int x,int deep)
{
	cnt[deep]++;
	for(Link *p=head[x];p;p=p->next)
	{
		calc(p->y,deep+1);
	}
	maxdeep=std::max(maxdeep,deep);
}

int main()
{
	freopen("1501.in","r",stdin);
	freopen("1501.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b; scanf("%d%d",&a,&b);
		if(a!=0) inLink(i,a);
		if(b!=0) inLink(i,b);
		n=std::max(n,std::max(a,b));
	}
	calc(1,1);
	for(int i=1;i<=n;i++) maxwidth=std::max(maxwidth,cnt[i]);
	printf("%d %d\n",maxwidth,maxdeep);
	return 0;
}
