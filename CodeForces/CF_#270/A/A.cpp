#include <cstdio>
#include <algorithm>
using std::max;
using std::min;

int n;
int hash[1000010];
int pri[1000010], l;

void mkp(int maxp)
{
	for(int i = 2; i <= maxp; i++)
	{
		if(!hash[i]) pri[l++] = i;
		for(int j = 0; j < l && pri[j] <= maxp / i; j++)
		{
			hash[i * pri[j]] = true;
			if(i % pri[j] == 0) break;
		}
	}
}

int main()
{
	mkp(1000000);
	scanf("%d", &n);
	for(int i = 4; i <= n; i++)
	{
		int j = n - i;
		if(hash[i] && hash[j])
		{
			printf("%d %d\n", min(i, j), max(i, j));
			break;
		}
	}
	return 0;
}
