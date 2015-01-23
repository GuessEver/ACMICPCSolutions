#include <cstdio>
#include <queue>
#include <algorithm>
using std::priority_queue;
using std::sort;

const int N = 100000 + 10;

int n, a[N], b[N];
struct Node{
	int sum, b;
	bool operator < (const Node &a) const
	{
		return sum > a.sum;
	}
};
priority_queue<Node> q;

int main()
{
	freopen("1245.in", "r", stdin);
	freopen("1245.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
	for(int i = 1; i <= n; i++)
		q.push((Node){a[i]+b[1], 1});
	for(int i = 1; i <= n; i++)
	{
		Node t = q.top(); q.pop();
		printf("%d", t.sum);
		if(i != n) printf(" "); else printf("\n");
		q.push((Node){t.sum-b[t.b]+b[t.b+1], t.b+1});
	}
	return 0;
}
