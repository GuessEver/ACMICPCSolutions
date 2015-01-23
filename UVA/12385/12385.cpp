#include <cstdio>
#include <set>
using std::set;

set<int> l;

int n;

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		int res = 0;
		l.clear();
		for(int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			if(l.count(x))
			{
				l.clear();
				res++;
				l.insert(x);
			}
			else l.insert(x);
		}
		printf("%d\n", res);
	}
	return 0;
}
