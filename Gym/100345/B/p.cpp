#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
using std::set;
using std::map;
int n, a[300];
set<int> sub;
map<int, int> used;
int Cnt = 0;

void dfs(int x)
{
	if(x > n)
	{
		sub.clear();
		sub.insert(abs(a[1]));
		for(int i = 2; i <= n; i++)
		{
			int tmp = abs(a[i]);
			if(sub.find(tmp) != sub.end()) return;
			sub.insert(tmp);
		}
		++Cnt;
		//printf("%3d: ", Cnt); for(int i = 1; i <= n; i++) printf(" %d", a[i]); puts("");
		return;
	}
	for(int i = -n; i <= n; i++)
	{
		if(i == 0 || x == i) continue;
		if(used[i]) continue;
		a[x] = i; used[i] = 1;
		dfs(x + 1);
		used[i] = 0;
	}
}

int main()
{
	//scanf("%d", &n);
	for(n = 1; n <= 20; n++)
	{
		used.clear(); sub.clear(); Cnt = 0;
		dfs(1);
		printf("%d: %d\n", n, Cnt);
	}
	return 0;
}
