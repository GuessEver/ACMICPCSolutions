#include <cstdio>
#include <algorithm>

const int N = 200000 + 10;
const int inf = 0x3f3f3f3f;

int n, K;
int num[N*4], cnt[N];

void update(int p, int l, int r, int a)
{
	if(l == r && l == a)
	{
		num[p]++;
		return;
	}
	int m = (l + r) / 2;
	if(a <= m) update(p*2, l, m, a);
	else update(p*2+1, m+1, r, a);
	num[p] = std::min(num[p*2], num[p*2+1]);
}
int query(int p, int l, int r, int a, int b)
{
	if(a <= l && b >= r) return num[p];
	int m = (l + r) / 2, x1 = inf, x2 = inf;
	if(a <= m) x1 = query(p*2, l, m, a, b);
	if(b > m) x2 = query(p*2+1, m+1, r, a, b);
	return std::min(x1, x2);
}

int main()
{
	//freopen("nice.in", "r", stdin);
	//freopen("nice.out", "w", stdout);
	scanf("%d%d", &n, &K);
	int res = 0;
	for(int i = 1; i <= n; i++)
	{
		int a; scanf("%d", &a);
		cnt[a]++;
		update(1, 0, n, a);
		if(!a) { res = i; continue; }
		int q = query(1, 0, n, 0, a-1);
		if(q >= cnt[a] - K) res = i;
		else break;
	}
	printf("%d\n", res);
	return 0;
}
