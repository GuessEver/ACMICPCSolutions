#include <cstdio>
#include <cstring>
#include <algorithm>

int v1, v2, t, d;
int v[1000];

int calc(int m, int delta)
{
	memset(v, 0, sizeof(v));
	int now = v1 - d;
	for(int i = 1; i <= m; i++)
	{
		now += d;
		v[i] = now;
	}
	v[m+1] = (now += delta);
	for(int i = m + 2; i <= t; i++)
	{
		if(now >= v2 && now - d < v2) now = v2;
		else now -= d;
		v[i] = now;
	}
	if(v[t] != v2) return 0;
	int res = 0;
	for(int i = 1; i <= t; i++) res += v[i];
	return res;
}

int main()
{
	scanf("%d%d%d%d", &v1, &v2, &t, &d);
	int res = 0;
	for(int i = 1; i < t; i++)
		for(int j = -d; j <= d; j++)
		{
			res = std::max(res, calc(i, j));
			//printf("m = %d, delta = %d, res = %d\n", i, j, res);
		}
	printf("%d\n", res);
	return 0;
}
