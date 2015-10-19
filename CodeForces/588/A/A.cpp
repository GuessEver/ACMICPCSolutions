#include <cstdio>
const int N = 100000 + 10;

int n, a[N], p[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d", &a[i], &p[i]);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int sum = 0, j = i;
		for(j = i; j <= n; j++)
			if(p[j] < p[i])
			{
				break;
			}
			else sum += a[j];
		res += sum * p[i];
		i = j - 1;
	}
	printf("%d\n", res);
	return 0;
}
