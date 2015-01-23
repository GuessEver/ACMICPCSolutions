#include <cstdio>

int n, a[200];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int res = -1;
	for(int i = 2; i < n; i++)
	{
		int tmp = 0;
		for(int j = 2; j <= n; j++)
		{
			if(j == i) continue;
			int k = j - 1;
			if(k == i) k--;
			if(a[j] - a[k] > tmp) tmp = a[j] - a[k];
		}
		if(res == -1 || res > tmp) res = tmp;
	}
	printf("%d\n", res);
	return 0;
}
