#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
const int N=1000+10;

int n,m,k;
struct node{int price,value,number;}a[N];
set<int> must;
bool h[N];
int f[N];

bool cmp(node a,node b) { return a.number<b.number; }

int main()
{
	scanf("%d%d",&n,&k);
	double x;
	scanf("%lf",&x);m=(int)(x*10);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&x);
		a[i].price=(int)(x*10);
	}
	for(int i=1;i<=n;i++) scanf("%d",&a[i].value);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].number);
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++)
	if(a[i].number==a[i-1].number) h[i]=true;
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		must.insert(x);
	}
	int sum=0;
	for(int i=1;i<=n;i++)
	if(!h[i] && must.count(a[i].number)>0)
	{
		m-=a[i].price;
		sum+=a[i].value;
		h[i]=true;
	}
	/*for(int i=1;i<=n;i++)
	if(!h[i]) printf("%d ",i);
	while(1);*/
	for(int i=1;i<=n;i++)
	{
		if(h[i]) continue;
		for(int j=m;j>=a[i].price;j--)
		f[j]=max(f[j],f[j-a[i].price]+a[i].value);
	}
	printf("%d",f[m]+sum);
	//while(1);
	return 0;
}
