#include <cstdio>
#include <iostream>
#include <iostream>

int n;
int rh, rv, sh, sv;

long long solve(int rhi, int rvi, int shi, int svi)
{
	long long h = std::max((rh + rhi - 1) / rhi, (sh + shi - 1) / shi);
	long long w = std::max((rv + rvi - 1) / rvi, (sv + svi - 1) / svi);
	return h * w;
}

int main()
{
	freopen("giant.in", "r", stdin);
	freopen("giant.out", "w", stdout);
	scanf("%d%d%d%d", &rh, &rv, &sh, &sv);
	scanf("%d", &n);
	long long res = -1;
	for(int i = 1; i <= n; i++)
	{
		int rhi, rvi, shi, svi, pi;
		scanf("%d%d%d%d%d", &rhi, &rvi, &shi, &svi, &pi);
		long long num = std::min(solve(rhi, rvi, shi, svi), solve(rvi, rhi, svi, shi));
		if(res == -1 || num * pi < res) res = num * pi;
	}
	std::cout << res << std::endl;
	return 0;
}
