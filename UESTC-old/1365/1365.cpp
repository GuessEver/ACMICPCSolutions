#include<cstdio>
#include<cstdlib>
#include<algorithm>
const int N=100+10;
int n,L;
struct node{char name[20];int pos;}a[N];
int time[N];

bool cmp_abs(int a,int b) { return abs(a)<abs(b); }
bool cmp_node(node a,node b) { return a.pos<b.pos; }

void work()
{
	scanf("%d%d",&n,&L);
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d",a[i].name,&a[i].pos);
		char op[10]; scanf("%s",op);
		if(op[0]=='L') time[i]=a[i].pos;
		else time[i]=-(L-a[i].pos);
	}
	std::sort(time+1,time+1+n,cmp_abs);
	std::sort(a+1,a+1+n,cmp_node);
	int head=1,tail=n;
	for(int i=1;i<=n;i++)
	{
		if(time[i]>0)
		{
			printf("%d %s\n",time[i],a[head].name);
			head++;
		}
		else{
			printf("%d %s\n",-time[i],a[tail].name);
			tail--;
		}
	}
}

int main()
{
	freopen("1365.in","r",stdin);
	freopen("1365.out","w",stdout);
	int T; scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		printf("Case #%d:\n",cas);
		work();
	}
	return 0;
}
