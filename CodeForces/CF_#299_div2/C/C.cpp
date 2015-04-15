#include <cstdio>

const int N = 100000 + 10;

int A, B, n;

int calc(int l, int r, long long std)
{
	int low = l, high = r;
	int i = l, ans = l;
	while(low <= high)
	{
		int j = (low + high) / 2;
		long long y = 1ll * (j - i + 1) * A + 1ll * (i - 1 + j - 1) * (j - i + 1) * B / 2;
		if(y <= std) { ans = j; low = j + 1; }
		else high = j - 1;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d", &A, &B, &n);
	while(n--)
	{
		int l, t, m; scanf("%d%d%d", &l, &t, &m);
		int r = (t - A) / B + 1;
		int tmp = calc(l, r, 1ll * m * t);
		if(tmp < r) r = tmp;
		printf("%d\n", r < l ? -1 : r);
	}
	return 0;
}
