#include <cstdio>
int n, x[30], y[30];

int sqr(int x) { return x * x; }

int dis(int i, int j)
{
	return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

bool check(int p1, int p2, int p3, int p4)
{
	int len1 = dis(p1, p2);
	int len2 = dis(p2, p3);
	int len3 = dis(p3, p1);
	if(len1 == 2 * len2 && len2 == len3)
	{
		int len4 = dis(p1, p4);
		int len5 = dis(p2, p4);
		return len1 == 2 * len4 && len4 == len5;
	}
	else if(len2 == 2 * len1 && len1 == len3)
	{
		int len4 = dis(p2, p4);
		int len5 = dis(p3, p4);
		return len2 == 2 * len4 && len4 == len5;
	}
	else if(len3 == 2 * len1 && len1 == len2)
	{
		int len4 = dis(p3, p4);
		int len5 = dis(p1, p4);
		return len3 == 2 * len4 && len4 == len5;
	}
	return 0;
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
		int res = 0;
		for(int i = 1; i <= n; i++)
			for(int j = i + 1; j <= n; j++)
				for(int k = j + 1; k <= n; k++)
					for(int t = k + 1; t <= n; t++)
						res += check(i, j, k, t);
		printf("%d\n", res);
	}
	return 0;
}
