#include <cstdio>
#include <cmath>
#include <algorithm>
using std::min;

const int N = 100000 + 10;

int n, m, a[N];
int f[N][40];

void RmqInit()
{
	for(int i = 1; i <= n; i++) f[i][0] = a[i];
	for(int j = 1; j <= (int)log2(1.0*n); j++)
		for(int i = 1; i+(1<<j)-1 <= n; i++)
			f[i][j] = min(f[i][j-1], f[i+(1<<(j-1))][j-1]);
}

int query(int l, int r)
{
	int k = (int)log2(1.0*(r-l+1));
	return min(f[l][k], f[r-(1<<k)+1][k]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	RmqInit();
	for(int i = 1; i <= m; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%d", query(x, y));
		if(i != m) printf(" "); else printf("\n");
	}
	return 0;
}
