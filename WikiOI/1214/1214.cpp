#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int N=100+10;

int n;
struct EG{int l,r;}edge[N];

struct _cmp{
	int operator() (EG a,EG b) { return a.r<b.r; }
};

priority_queue<EG,vector<EG>,_cmp> q;

bool cmp(EG a,EG b)
{
	if(a.l==b.l) return a.r<b.r;
	return a.l<b.l;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		edge[i]=(EG){min(x,y),max(x,y)};
	}
	sort(edge+1,edge+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(i==1) {q.push(edge[i]);continue;}
		if(edge[i].l>=q.top().r) q.push(edge[i]);
		else{
			if(q.top().r>edge[i].r)
			{
				q.pop();
				q.push(edge[i]);
			}
		}
	}
	printf("%d\n",q.size());
	return 0;
}
