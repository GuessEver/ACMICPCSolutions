#include <cstdio>

const int N = 100000 + 10;

int n, m, a[N], c[N];

bool check(long long res)
{
	for(int j = 1; j <= m; j++) c[j] = a[j];
	int p = 1; long long t = 0;
	for(int j = m; j >= 1; j--) if(c[j])
	{
		if(p > n) return 0;
		if(j > res) return 0;
		if(t == 0) t += j;
		if(t + c[j] <= res)
		{
			t += c[j];
			c[j] = 0;
		}
		else {
			c[j] -= res - t;
			t = 0; p++; j++;
		}
	}
	for(int j = 1; j <= m; j++) if(c[j]) return 0;
	return 1;
}

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; i++) scanf("%d", &a[i]);
	check(2);
	long long low = 0, high = 0x3f3f3f3f3f3f3f3fll;
	while(low < high)
	{
		long long mid = low + (high - low) / 2;
		if(check(mid)) high = mid;
		else low = mid + 1;
	}
	printf("%I64d\n", high);
	return 0;
}
