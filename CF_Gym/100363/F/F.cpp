#include <cstdio>
#include <algorithm>

int n, x[1010], y[1010];
int t[1010];

bool solve()
{
	for(int i = 1; i <= n; i++)
	{
		t[i] = std::min(x[i] / 3, y[i] / 3);
		x[i] -= t[i] * 3;
		y[i] -= t[i] * 3;
		t[i] *= 2;
		int who = 0;
		for( ; ;)
		{
			if(who == 0) // Andrew
			{
				if(x[i] >= 2) x[i] -= 2;
				else break;
				if(y[i] >= 1) y[i]--;
				else y[i]++;
			}
			else { // Peter
				if(y[i] >= 2) y[i] -= 2;
				else break;
				if(x[i] >= 1) x[i]--;
				else x[i]++;
			}
			who = 1 - who;
			t[i]++;
		}
	}
	int res = -1;
	for(int i = 1; i <= n; i++)
		if(res == -1 || t[i] < res) res = t[i];
	return res % 2 == 1;
}

int main()
{
	//freopen("knights.in", "r", stdin);
	//freopen("knights.out", "w", stdout);
	while(scanf("%d", &n) == 1 && n)
	{
		for(int i = 1; i <= n; i++)
			scanf("%d%d", &x[i], &y[i]);
		bool andrew = solve();
		if(andrew) puts("Andrew wins the game");
		else puts("Peter wins the game");
	}
	return 0;
}
