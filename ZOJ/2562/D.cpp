#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using std::min;

long long n;
int pri[] = {47, 43, 41, 37, 31, 29, 23, 19, 17, 13, 11, 7, 5, 3, 2};
int Cnt = 15;
long long ans, best;
int num[20];

void dfs(int x, long long now, long long cc)
{
	//printf("%d %lld %lld\n", x, now, cc);
	if(x == Cnt)
	{
		if(ans == -1 || cc > best || (cc == best && ans > now))
		{
			ans = now; best = cc;
		}
		return;
	}
	long long tmp = now;
	dfs(x+1, tmp, cc);
	for(int i = 1; i <= num[x]; i++)
	{
		if(tmp * pri[x] <= n)
		{
			tmp *= pri[x];
			dfs(x+1, tmp, cc*(i+1));
		}
	}
}

int main()
{
	while(scanf("%lld", &n) == 1)
	{
		long long tmp = 1;
		for(int i = 14; i >= 0; i--)
			num[i] = (int)min(30.0, 
					log(1.0 * n) / log(1.0 * (tmp = tmp * pri[i])));
		//for(int i = 0; i < 15; i++) printf("%d ", num[i]);puts("");
		ans = -1;
		dfs(0, 1, 1);
		printf("%lld\n", ans);
	}
	return 0;
}
