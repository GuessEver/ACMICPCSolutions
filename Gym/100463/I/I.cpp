#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, m;
int a[N], b[N];

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool check(int g)
{
	if(g > 2) return 0;
	int cnt = 0;
	for(int i = 1; i <= n; i++) cnt += (a[i] % 2);
	if(g == 2 && cnt == 0) return 0;
	std::sort(a+1, a+1+n);
	std::sort(b+1, b+1+m);
	if(!(a[1] - b[m] < 0)) return 0;
	if(!(a[n] - b[1] > 0)) return 0;
	return 1;
}

int main()
{
	int cas = 0;
	while(scanf("%d%d", &n, &m) == 2 && (n || m))
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= m; i++) scanf("%d", &b[i]);
		int g = a[1] - b[1];
		for(int i = 2; i <= n; i++) g = gcd(g, a[i] - b[1]);
		for(int j = 2; j <= m; j++) g = gcd(g, b[j] - b[1]);
		if(g < 0) g = -g;
		if(!check(g)) printf("Case %d: YES\n", ++cas);
		else printf("Case %d: NO\n", ++cas);
	}
	return 0;
}
