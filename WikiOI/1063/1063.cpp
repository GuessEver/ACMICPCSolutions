#include<cstdio>
#include<queue>
using namespace std;

int n;
priority_queue<int> q;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a;scanf("%d",&a);
		q.push(-a);
	}
	int res=0;
	for(int i=1;i<n;i++)
	{
		int x=-q.top();q.pop();
		int y=-q.top();q.pop();
		q.push(-(x+y));
		res+=(x+y);
	}
	printf("%d\n",res);
	return 0;
}
