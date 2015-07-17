#include <cstdio>
#include <algorithm>
using std::min;

int n, m, p[1010];

int main()
{
	scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int x; scanf("%d", &x);
		if(x == 1) p[++n] = i;
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i == 1) { cnt++; continue; }
		cnt += min(2, p[i] - p[i-1]);
	}
	printf("%d\n", cnt);
	return 0;
}
