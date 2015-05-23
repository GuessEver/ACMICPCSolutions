#include <cstdio>

const int N = 100 + 10;

int n, a[N], sum = 0, tot = 0;
double ans[N];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		sum += a[i];
	}
	//double average = 1.0 * sum / (n + 1);
	for(int i = 1; i <= n; i++)
	{
		if(a[i] * (n + 1) <= sum) ans[i] = 0;
		else tot += a[i] * (n + 1) - sum;
	}
	for(int i = 1; i <= n; i++)
		if(a[i] * (n + 1) > sum)
			ans[i] = 100.0 * (a[i] * (n + 1) - sum) / tot;
	for(int i = 1; i < n; i++) printf("%d ", (int)ans[i]);
	printf("%d\n", (int)ans[n]);
	return 0;
}
