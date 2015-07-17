#include <cstdio>
#include <algorithm>
using std::max;

int main()
{
	long long n, m, k;
	scanf("%I64d%I64d%I64d", &n, &m, &k);
	long long res = 0;
	if(k > n + m - 2) res = -1;
	else if(k > n - 1 && k > m - 1)
	{
		long long a = m / (k - (n-1) + 1);
		long long b = n / (k - (m-1) + 1);
		res = max(a, b);
	}
	else if(k >= m) res = (n / (k + 1)) * m;
	else if(k >= n) res = (m / (k + 1)) * n;
	else{
		long long a = (m / (k + 1)) * n;
		long long b = (n / (k + 1)) * m;
		res = max(a, b);
	}
	printf("%I64d\n", res);
	return 0;
}
