#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
const int N = 10000 + 10;

int n, L, W;
struct Node{double L, R;} a[N];

bool cmp(const Node &a, const Node &b)
{
	if(a.L == b.L) return a.R > b.R;
	return a.L < b.L;
}

void read()
{
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		int p, r;
		scanf("%d%d", &p, &r);
		if(2 * r < W) continue;
		double leng = sqrt(1.0 * r * r - W * W / 4.0);
		a[++cnt] = (Node) {std::max(0.0,p-leng), std::min(L * 1.0,p+leng)};
	}
	n = cnt;
	std::sort(a+1, a+1+n, cmp);
}

int solve()
{
	if(a[1].L > 0) return -1;
	int now = 1, res = 1;
	double len = a[1].R;
	while(len < L && now < n)
	{
		int k = -1;
		for(int i = now+1; i <= n; i++)
		{
			if(a[i].L > a[now].R) break;
			if(k == -1 || a[i].R > a[k].R) k = i;
		}
		if(k == -1) return -1;
		len = a[k].R; now = k; res++;
	}
	if(len < L) return -1;
	return res;
}

int main()
{
	freopen("10382.in", "r", stdin);
	while(scanf("%d%d%d", &n, &L, &W) == 3)
	{
		memset(a, 0, sizeof(a));
		read();
		printf("%d\n", solve());
	}
	return 0;
}
