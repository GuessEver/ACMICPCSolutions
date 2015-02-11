#include <cstdio>
#include <algorithm>

const int N = 100 * 4 + 10;

int n, m, C;
int a[N], b[N], p[N], c[N];
int color[10];

int solve() // a[] --> b[]
{
	//for(int i = 1; i <= m; i++) printf("%d ", b[i]); puts("");
	for(int i = 1; i <= m; i++) p[b[i]] = i;
	for(int i = 1; i <= m; i++) b[i] = p[a[i]];
	//for(int i = 1; i <= m; i++) printf("%d ", b[i]); puts("");
	int len = 0;
	for(int i = 1; i <= m; i++)
	{
		int l = 1, r = len;
		while(l <= r)
		{
			int mid = (l + r) / 2;
			if(b[i] > c[mid]) l = mid + 1;
			else r = mid - 1;
		}
		c[l] = b[i];
		if(l > len) len = l;
	}
	return m - len;
}

int main()
{
	scanf("%d%d", &C, &n);
	m = C * n;
	for(int i = 1; i <= m; i++)
	{
		int col, num;
		scanf("%d%d", &col, &num);
		a[i] = (col - 1) * n + num;
	}
	//for(int i = 1; i <= m; i++)printf("%d ", a[i]); puts("");
	for(int i = 1; i <= C; i++) color[i] = i;
	int ans = -1;
	do{
		for(int i = 1; i <= m; i++)
		{
			int col = color[(i + (n-1)) / n];
			int num = i % n == 0 ? n : i % n;
			b[i] = (col - 1) * n + num;
		}
		int tmp = solve();
		if(ans == -1 || tmp < ans) ans = tmp;
		//for(int i = 1; i <= C; i++) printf("%d ", color[i]); puts("");
	}while(std::next_permutation(color+1, color+1+C));
	printf("%d\n", ans);
	return 0;
}
