#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int> q;
int n;
bool odd;

int main()
{
	scanf("%d",&n);
	odd=n&1;
	int x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		q.push(x);
		if(!odd && i>n/2+1) q.pop();
		else if(odd && i>n/2+1) q.pop();
	}
	if(odd) printf("%.1lf\n",(double)q.top());
	else{
		double x=q.top();q.pop();
		x=x+q.top();
		printf("%.1lf\n",x/2.0);
	}
	return 0;
}
