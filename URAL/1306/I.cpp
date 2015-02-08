#include <cstdio>
#include <queue>
using std::priority_queue;

priority_queue<int> Q;
int n;

int main()
{
	scanf("%d", &n);
	int tmp = n / 2 + 1;
	for(int i = 1; i <= tmp; i++)
	{
		int x; scanf("%d", &x);
		Q.push(x);
	}
	tmp = n - tmp;
	for(int i = 1; i <= tmp; i++)
	{
		int x; scanf("%d", &x);
		Q.push(x);
		Q.pop();
	}
	if(n % 2) printf("%d.0\n", Q.top());
	else{
		long long a = Q.top(); Q.pop();
		a += Q.top();
		printf("%lld", a/2);
		if(a % 2 == 0) puts(".0");
		else puts(".5");
	}
	return 0;
}
