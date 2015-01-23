#include <cstdio>
#include <cstring>
#include <algorithm>
using std::min;

int n, cap[50][50];
int tot;
int friends[50];

int check(int S)
{
	int status = 0, steps = 0;
	for(int i = 1; i <= n; i++)
	{
		int ONE = S & 1; S >>= 1;
		if(!ONE) continue;
		steps++;
		status |= friends[i];
	}
	if(status == tot-1) return steps;
	else return -1;
}

void solve()
{
	tot = 1 << n;
	int ans = n;
	for(int S = 0; S < tot; S++)
	{
		int tmp = check(S);
		if(tmp == -1) continue;
		//printf("%d\n", tmp);
		ans = min(ans, tmp);
	}
	printf("%d\n", ans);
}

int main()
{
	int T; scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		memset(cap, 0, sizeof(cap));
		memset(friends, 0, sizeof(friends));
		for(int i = 1; i <= n; i++)
		{
			friends[i] |= (1 << (i-1));
			int d; scanf("%d", &d);
			while(d--)
			{
				int j; scanf("%d", &j);
				cap[i][j] = cap[j][i] = 1;
				friends[i] |= (1 << (j-1));
				friends[j] |= (1 << (i-1));
			}
		}
		solve();
	}
	return 0;
}
