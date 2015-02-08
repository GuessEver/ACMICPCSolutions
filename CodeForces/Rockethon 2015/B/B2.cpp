#include <cstdio>

int n;
long long m;
long long tot;
int a[100];

void solve(long long t, long long s, int val, int l, int r)
{
	if(val > n) return;
	if(s * 2 <= t)
	{
		a[l] = val;
		solve(t/2, s, val+1, l+1, r);
	}
	else{
		a[r] = val;
		solve(t/2, s - t/2, val+1, l, r-1);
	}
}

int main()
{
	scanf("%d%I64d", &n, &m);
	tot = 1;
	for(int i = 2; i <= n; i++) tot *= 2;
	solve(tot, m, 1, 1, n);
	for(int i = 1; i < n; i++) printf("%d ", a[i]);
	printf("%d\n", a[n]);
	return 0;
}
