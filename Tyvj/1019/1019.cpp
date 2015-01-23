#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::sort;
const int N = 10000 + 10;

int n, a[N], b[N];

int main()
{
	freopen("1019.in", "r", stdin);
	freopen("1019.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
	sort(a+1, a+1+n);
	sort(b+1, b+1+n);
	int res = 0;
	for(int i = 1, j = n; i <= n; i++, j--)
		res += abs(a[i] - b[j]);
	printf("%d\n", res);
	return 0;
}
