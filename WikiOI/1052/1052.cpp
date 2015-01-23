#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

int n;
struct node{int t,g;}a[1000];
priority_queue<int> q;

bool cmp(node a,node b)
{
	if(a.t==b.t) return a.g>b.g;
	return a.t<b.t;
}

int main()
{
	freopen("1052.in","r",stdin);
	freopen("1052.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].t);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].g);
	sort(a+1,a+1+n,cmp);
	int total=0;
	int j=n;
	for(int i=a[j].t;i>0;i--)
	{
		while(a[j].t==i) q.push(a[j--].g);
		
		if(!q.empty())
		{
			total+=q.top();
			q.pop();
		}
	}
	printf("%d\n",total);
	return 0;
}
