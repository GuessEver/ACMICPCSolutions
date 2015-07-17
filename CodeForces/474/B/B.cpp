#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

struct Node{
	int x, ord, ans;
}q[N];
int n, m, a[N];

bool cmp_num(Node a, Node b) { return a.x < b.x; }
bool cmp_ord(Node a, Node b) { return a.ord < b.ord; }

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] += a[i-1];
	}
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d", &q[i].x);
		q[i].ord = i;
	}
	std::sort(q+1, q+1+m, cmp_num);
	int t = 1;
	for(int i = 1; i <= m; i++)
	{
		for(; t <= n; t++)
		{
			if(a[t] >= q[i].x)
			{
				q[i].ans = t;
				break;
			}
		}
	}
	std::sort(q+1, q+1+m, cmp_ord);
	for(int i = 1; i <= m; i++) printf("%d\n", q[i].ans);
	return 0;
}
