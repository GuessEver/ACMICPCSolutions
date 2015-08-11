#include <cstdio>

namespace prime{
	const int N = 10000000 + 10;
	int pri[N], h[N], Cnt;
	void make(int maxp) // O(2*N)
	{
		for(int i = 2; i <= maxp; i++)
		{
			if(!h[i]) pri[Cnt++] = i;
			for(int j = 0; j < Cnt && pri[j] <= maxp / i; j++)
			{
				h[i * pri[j]] = true;
				if(i % pri[j] == 0) break;
			}
		}
	}
}

bool check_prime(int x)
{
	if(x == 1) return 0;
	return !prime::h[x];
	for(int i = 2; i < x; i++)
		if(x % i == 0) return 0;
	return 1;
}
bool check_palin(int x)
{
	int y = 0, xx = x;
	while(xx)
	{
		y = y * 10 + xx % 10;
		xx /= 10;
	}
	return x == y;
}

int p, q;

int main()
{
	int maxp = 10000000;
	prime::make(maxp);
	scanf("%d%d", &p, &q);
	int cnt1 = 0, cnt2 = 0, ans = 1;
	for(int i = 1; i <= maxp; i++)
	{
		cnt1 += check_prime(i);
		cnt2 += check_palin(i);
		//printf("%d : %d %d\n", i, cnt1, cnt2);
		//if(cnt1 <= cnt2) printf("%d : %d %d  !!!!!!!!!!!!!!!!!!!!!!!!!!\n", i, cnt1, cnt2);
		if(1ll * cnt1 * q <= 1ll * cnt2 * p) ans = i;
	}
	//printf("%d %d\n", cnt1, cnt2);
	if(ans == maxp) puts("Palindromic tree is better than splay tree");
	else printf("%d\n", ans);
	return 0;
}
