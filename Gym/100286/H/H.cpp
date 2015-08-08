#include <cstdio>
#include <algorithm>
const int N = 100000 + 10;

int n;
struct Node{
	int a, idx;
	bool operator < (const Node &b) const
	{
		return a > b.a;
	}
}a[N];
long long tot = 0;
bool add[N];

bool dfs(int x, long long sum)
{
	if(sum > tot) return 0;
	if(sum == tot)
	{
		puts("Yes");
		for(int i = 1; i <= n; i++)
		{
			if(add[i]) printf("1"); else printf("-1");
			putchar(i == n ? '\n' : ' ');
		}
		return 1;
	}
	if(x > n) return 0;
	add[a[x].idx] = 1;
	if(dfs(x + 1, sum + a[x].a)) return 1;
	add[a[x].idx] = 0;
	if(dfs(x + 1, sum)) return 1;
	return 0;
}

bool solve()
{
	if(tot % 2 != 0) return 0;
	std::sort(a+1, a+1+n);
	if((tot /= 2) < a[1].a) return 0;
	return dfs(1, 0);
}

int main()
{
	freopen("hell.in", "r", stdin);
	freopen("hell.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].a);
		tot += a[i].a;
		a[i].idx = i;
	}
	if(!solve()) puts("No");
	return 0;
}
