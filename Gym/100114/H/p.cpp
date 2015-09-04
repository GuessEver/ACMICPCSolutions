#include <cstdio>
#include <set>
using std::set;
int n, m, a[10010];
set<int> st;

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	while(m--)
	{
		int x, y; scanf("%d%d", &x, &y);
		st.clear();
		for(int i = x; i <= y; i++) st.insert(a[i]);
		printf("%d\n", (int)st.size());
	}
	return 0;
}
