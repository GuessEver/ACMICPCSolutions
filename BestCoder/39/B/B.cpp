#include <cstdio>
#include <cstring>
#include <map>
using std::map;

const int N = 10000 + 10;

int pri[N], l;
int h[N];

void make_prime_list(int maxp) // O(2*N)
{
	for(int i = 2; i <= maxp; i++)
	{
		if(!h[i]) pri[l++] = i;
		for(int j = 0; j < l && pri[j] <= maxp / i; j++)
		{
			h[i * pri[j]] = true;
			if(i % pri[j] == 0) break;
		}
	}
}

int n, a[N], pre[N];

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) pre[i] = 0;
		int res = 0;
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1; i <= n; i++)
		{
			for(int j = i + 1; j <= n; j++)
				if(a[j] % a[i] == 0)
				{
					pre[i] = j;
					break;
				}
			res += pre[i];
		}
		printf("%d\n", res);
	}
	return 0;
}
