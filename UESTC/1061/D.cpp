#include <cstdio>
#include <set>
using std::set;

int n, m;
set<int> l1, l2;

int main()
{
	scanf("%d%d", &n, &m);
	l1.insert(n+1); l2.insert(0);
	while(m--)
	{
		int op, x; scanf("%d%d", &op, &x);
		if(op == 0) { l1.insert(x); l2.insert(-x); }
		else if(op == 1) { l1.erase(x); l2.erase(-x); }
		else{
			set<int>::iterator ed = l1.lower_bound(x);
			if(*ed == x) printf("%d\n", 0);
			else{
				set<int>::iterator st = l2.lower_bound(-x);
				printf("%d\n", *ed - (-*st) - 1);
			}
		}
	}
	return 0;
}
