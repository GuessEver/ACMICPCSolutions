#include <cstdio>
#include <queue>
using std::queue;

struct ND{int x, y;};
queue<ND> Q;
int n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		ND node = (ND){x, i};
		Q.push(node);
	}
	while(!Q.empty())
	{
		ND now = Q.front();
		Q.pop();
		if(Q.empty())
		{
			printf("%d\n", now.y);
			break;
		}
		now.x -= m;
		if(now.x > 0) Q.push(now);
	}
	return 0;
}
