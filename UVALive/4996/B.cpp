#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;
using std::max;

int n, x, y, z;
long long f[1010];

int main()
{
	int T; scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++)
	{
		scanf("%d%d%d%d", &n, &x, &y, &z);
		f[0] = f[1] = 0;
		for(int i = 2; i <= n; i++)
		{
			f[i] = 0x3f3f3f3f3f3f3f3fll;
			for(int j = 1; j < i; j++)
			{
				long long broken = f[j] + y + x;
				long long unbroken = f[i-j] + z;
				if(i - j == 1) unbroken = y + x - x / 2;
				f[i] = min(f[i], max(broken, unbroken));
			}
		}
		printf("Case %d: %lld\n", cas, f[n]);
	}
	return 0;
}
