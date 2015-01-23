#include <cstdio>
#include <set>
using std::set;

int n, p;
set<int> l;

int main()
{
	while(scanf("%d%d", &n, &p) == 2)
	{
		int res = 0;
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			if(x%p == 0 && l.count(x/p)) continue;
			res++;
			l.insert(x);
		}
		printf("%d\n", res);
	}
	return 0;
}
