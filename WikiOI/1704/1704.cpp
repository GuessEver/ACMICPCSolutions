#include<cstdio>
#include<queue>
using namespace std;

int n;
queue<int> q;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) q.push(i);
	while(q.size()>=2)
	{
		printf("%d ",q.front());
		q.pop();
		int t=q.front();q.pop();
		q.push(t);
	}
	printf("%d\n",q.front());
	return 0;
}
