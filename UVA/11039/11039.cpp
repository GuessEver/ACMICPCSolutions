#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

const int N = 500000 + 10;

int n;
int a[N];

bool cmp(int a, int b)
{
	return abs(a) < abs(b);
}

void solve()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	std::sort(a+1, a+1+n, cmp);
	int last = a[1];
	int res = 1;
	for(int i = 2; i <= n; i++)
	{
		int tmp1 = a[i] > 0 ? 1 : -1;
		int tmp2 = last > 0 ? 1 : -1;
		if(tmp1 * tmp2 < 0)
		{
			res++;
			last = a[i];
		}
	}
	printf("%d\n", res);
}

int main()
{
	freopen("11039.in", "r", stdin);
	freopen("11039.out", "w", stdout);
	int t; scanf("%d", &t);
	while(t--) solve();
	return 0;
}
