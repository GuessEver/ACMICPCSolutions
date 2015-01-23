#include <cstdio>
#include <set>
using std::set;

int n, m;
set<int> l;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		l.insert(x);
	}
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		if(l.count(x)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
