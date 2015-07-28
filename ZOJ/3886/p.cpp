#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;
const int P = 10000000;

bool nico[P+10], h[P+10];
int pri[P+10], Cnt;

void init()
{
	for(int i = 0; i <= 8; i++) nico[i] = 1;
	for(int i = 1; (1 << i) <= P; i++) nico[(1 << i)] = 1;
	for(int i = 2; i <= P; i++)
	{
		if(!h[i])
		{
			pri[Cnt++] = i;
			nico[i] = 1;
		}
		for(int j = 0; j < Cnt && pri[j] <= P / i; j++)
		{
			h[i * pri[j]] = 1;
			if(i % pri[j] == 0) break;
		}
	}
}

int n, m, a[N];

int main()
{
	init();
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
		scanf("%d", &m);
		while(m--)
		{
			int op; scanf("%d", &op);
			if(op == 1)
			{
				int l, r; scanf("%d%d", &l, &r);
				int res = 0;
				for(int i = l; i <= r; i++) res += nico[a[i]];
				printf("%d\n", res);
			}
			else if(op == 2)
			{
				int l, r, v; scanf("%d%d%d", &l, &r, &v);
				for(int i = l; i <= r; i++) a[i] %= v;
			}
			else if(op == 3)
			{
				int p, v; scanf("%d%d", &p, &v);
				a[p] = v;
			}
		}
	}
	return 0;
}
